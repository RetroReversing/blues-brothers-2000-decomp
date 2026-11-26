typedef struct Obj Obj;
struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x64 - 0x14];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    s32 unk74;
    s32 unk78;
    u8 pad7C[0x80 - 0x7C];
    s32 unk80;
    u8 pad84[0xAC - 0x84];
    f32 unkAC;
    f32 unkB0;
    f32 unkB4;
    u8 padB8[0xBC - 0xB8];
    s32 unkBC;
    u8 padC0[0xD0 - 0xC0];
    s32 unkD0;
    u8 padD4[0xD8 - 0xD4];
    void *unkD8;
    f32 unkDC;
    u8 padE0[0x104 - 0xE0];
    f32 unk104;
};

s16 coss(u16);
s16 sins(u16);
s32 func_8002492C(f32, f32);
void func_8002A360(s32, s32);
s32 approachS32(s32, s32, s32);
s32 tickActorTimer(Obj *);
f32 func_8002D858(Obj *, void *);
f32 func_8002DD60(f32);
void func_8002E100(f32 *, f32 *);
void func_8003BF98(Obj *);
s32 animStepKeys(Obj *);
void func_80043328(Obj *, s32, s32);
s32 func_80081188(s32, f32 *, f32 *);
void func_80081990(f32 *, s32, f32);
void func_80081AC0(f32 *, s32, f32);
extern s32 gCamSpeedScale[];
extern f32 D_80008F38;
extern f32 D_80008F3C;
extern f32 D_80008F40;
extern f32 D_80008F44;
extern f32 D_80008F48;
extern f64 D_80008F50;
extern f64 D_80008F58;
extern f32 D_80008F60;
extern f64 D_80008F68;
extern f32 D_80008F70;
extern Obj *gCameraTarget[];
extern s32 gSplinePointCount[];
void func_80043248(void);

/* Advances a chase vehicle along its path, steers it toward the player when close, and runs its ramming and give-up logic. Returns 0 while chasing, 1 when it gives up, 2 when it has been stopped. */
s32 updateChaseVehicle(Obj *veh) {
    f32 dir[4];
    f32 off;
    s32 path;
    s32 hit;
    f32 dist;
    f32 limit;
    f32 accel;
    s32 ang;
    s32 seg;
    f32 dx, dz;

    path = veh->unk70;
    func_80081990(&veh->x, path, veh->unkB4);
    func_80081AC0(dir, path, veh->unkB4);
    func_8002E100(dir, dir);
    veh->x += veh->unkB0 * dir[2];
    veh->z -= veh->unkB0 * dir[0];
    limit = 1.0f;
    accel = 0.0f;
    hit = animStepKeys(veh);
    dist = func_8002D858(veh, &veh->unk10);
    if (dist < D_80008F3C) {
        func_80043328(veh, veh->unk74 + 4, 0x100);
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x16);
        if (veh->unkD0 == veh->unk74 + 4 && veh->unkDC > D_80008F40 && veh->unkDC < D_80008F44 && veh->unk80 == 0) {
            veh->unk80 = 1;
            func_8003BF98(veh);
        }
        if (hit != 0 && veh->unk80 != 0) {
            veh->unk78 = 8;
            veh->unkD8 = func_80043248;
            veh->unk80 = 0;
            func_80043328(veh, veh->unk74 + veh->unk78, 0x100);
            return 0;
        }
    } else {
        ang = func_8002492C(dir[2], dir[0]);
        if (dist < veh->unk104 + veh->unk104) {
            func_80043328(veh, veh->unk74 + 1, 0x100);
            dx = gCameraTarget[0]->x - veh->x;
            dz = gCameraTarget[0]->z - veh->z;
            accel = coss(ang) * dx + sins(ang) * dz;
            sins(ang);
            coss(ang);
            accel = accel / D_80008F50;
            limit = func_8002DD60(veh->unkAC * D_80008F48);
            if (limit < accel) {
                accel = limit;
            }
            if (accel < -limit) {
                accel = -limit;
            }
            veh->unk64 = 500;
        } else {
            seg = func_80081188(path, &gCameraTarget[0]->x, &off);
            if (off > veh->unk104) {
                if (veh->unkD0 != veh->unk74 + 8) {
                    func_80043328(veh, veh->unk74 + 8, 0x100);
                } else if (hit != 0) {
                    veh->unk64 = 0;
                }
            } else {
                func_80043328(veh, veh->unk74 + 2, 0x100);
                accel = seg - veh->unkB4;
                veh->unk10 = approachS32(ang, veh->unk10, gCamSpeedScale[0] << 9);
                limit = func_8002DD60(veh->unkAC / D_80008F58);
                if (limit < D_80008F60) {
                    limit = D_80008F60;
                }
                limit = limit * D_80008F68;
            }
            if (tickActorTimer(veh) != 0) {
                veh->unk78 = 7;
                veh->unkBC = 1;
                veh->unkAC = func_8002DD60(veh->unkAC);
                return 1;
            }
        }
    }
    if (limit < accel) {
        accel = limit;
    }
    if (accel < -limit) {
        accel = -limit;
    }
    veh->unkB4 += accel;
    if (veh->unkB0 > veh->unk104) {
        veh->unkB0 = veh->unk104;
    }
    if (veh->unkB0 < -veh->unk104) {
        veh->unkB0 = -veh->unk104;
    }
    if (gSplinePointCount[path] - D_80008F70 < veh->unkB4) {
        veh->unkB4 = gSplinePointCount[path] - D_80008F70;
    }
    if (veh->unkB4 < 0.0f) {
        veh->unkB4 = 0.0f;
    }
    return 0;
}
