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
s32 func_8002D298(s32, s32, s32);
s32 func_8002D5CC(Obj *);
f32 func_8002D858(Obj *, void *);
f32 func_8002DD60(f32);
void func_8002E100(f32 *, f32 *);
void func_8003BF98(Obj *);
s32 func_8004303C(Obj *);
void func_80043328(Obj *, s32, s32);
s32 func_80081188(s32, f32 *, f32 *);
void func_80081990(f32 *, s32, f32);
void func_80081AC0(f32 *, s32, f32);
extern s32 D_800B9ECC[];
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
extern Obj *D_800BD06C[];
extern s32 D_8014A928[];
void func_80043248(void);

s32 func_8006BB5C(Obj *arg0) {
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

    path = arg0->unk70;
    func_80081990(&arg0->x, path, arg0->unkB4);
    func_80081AC0(dir, path, arg0->unkB4);
    func_8002E100(dir, dir);
    arg0->x += arg0->unkB0 * dir[2];
    arg0->z -= arg0->unkB0 * dir[0];
    limit = 1.0f;
    accel = 0.0f;
    hit = func_8004303C(arg0);
    dist = func_8002D858(arg0, &arg0->unk10);
    if (dist < D_80008F3C) {
        func_80043328(arg0, arg0->unk74 + 4, 0x100);
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x16);
        if (arg0->unkD0 == arg0->unk74 + 4 && arg0->unkDC > D_80008F40 && arg0->unkDC < D_80008F44 && arg0->unk80 == 0) {
            arg0->unk80 = 1;
            func_8003BF98(arg0);
        }
        if (hit != 0 && arg0->unk80 != 0) {
            arg0->unk78 = 8;
            arg0->unkD8 = func_80043248;
            arg0->unk80 = 0;
            func_80043328(arg0, arg0->unk74 + arg0->unk78, 0x100);
            return 0;
        }
    } else {
        ang = func_8002492C(dir[2], dir[0]);
        if (dist < arg0->unk104 + arg0->unk104) {
            func_80043328(arg0, arg0->unk74 + 1, 0x100);
            dx = D_800BD06C[0]->x - arg0->x;
            dz = D_800BD06C[0]->z - arg0->z;
            accel = coss(ang) * dx + sins(ang) * dz;
            sins(ang);
            coss(ang);
            accel = accel / D_80008F50;
            limit = func_8002DD60(arg0->unkAC * D_80008F48);
            if (limit < accel) {
                accel = limit;
            }
            if (accel < -limit) {
                accel = -limit;
            }
            arg0->unk64 = 500;
        } else {
            seg = func_80081188(path, &D_800BD06C[0]->x, &off);
            if (off > arg0->unk104) {
                if (arg0->unkD0 != arg0->unk74 + 8) {
                    func_80043328(arg0, arg0->unk74 + 8, 0x100);
                } else if (hit != 0) {
                    arg0->unk64 = 0;
                }
            } else {
                func_80043328(arg0, arg0->unk74 + 2, 0x100);
                accel = seg - arg0->unkB4;
                arg0->unk10 = func_8002D298(ang, arg0->unk10, D_800B9ECC[0] << 9);
                limit = func_8002DD60(arg0->unkAC / D_80008F58);
                if (limit < D_80008F60) {
                    limit = D_80008F60;
                }
                limit = limit * D_80008F68;
            }
            if (func_8002D5CC(arg0) != 0) {
                arg0->unk78 = 7;
                arg0->unkBC = 1;
                arg0->unkAC = func_8002DD60(arg0->unkAC);
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
    arg0->unkB4 += accel;
    if (arg0->unkB0 > arg0->unk104) {
        arg0->unkB0 = arg0->unk104;
    }
    if (arg0->unkB0 < -arg0->unk104) {
        arg0->unkB0 = -arg0->unk104;
    }
    if (D_8014A928[path] - D_80008F70 < arg0->unkB4) {
        arg0->unkB4 = D_8014A928[path] - D_80008F70;
    }
    if (arg0->unkB4 < 0.0f) {
        arg0->unkB4 = 0.0f;
    }
    return 0;
}

