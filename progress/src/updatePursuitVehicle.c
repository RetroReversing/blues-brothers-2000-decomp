typedef struct Obj47E8 {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 ang;
    u8 pad14[0x50];
    s32 c64;
    u8 pad68[4];
    struct Obj47E8 *who;
    s32 track;
    s32 c74;
    s32 c78;
    u8 pad7C[0x30];
    f32 cAC;
    f32 speed;
    f32 dist;
    u8 padB8[4];
    s32 cBC;
    u8 padC0[0x10];
    s32 cD0;
    u8 padD4[0x2C];
    f32 c100;
    f32 c104;
} Obj47E8;

extern s32 coss(u16);
extern s32 sins(u16);
extern s32 func_8002492C(f32, f32);
extern s32 approachAngle(s32, s32, s32);
extern s32 approachS32(s32, s32, s32);
extern f32 func_8002D858(Obj47E8 *, s32 *);
extern f32 func_8002DD60(f32);
extern void func_8002E100(f32 *, f32 *);
extern s32 animStepKeys(Obj47E8 *);
extern void func_80043328(Obj47E8 *, s32, s32);
extern s32 func_80081188(s32, f32 *, f32 *);
extern void func_80081990(f32 *, s32, f32);
extern void func_80081AC0(f32 *, s32, f32);
extern const f32 D_80009A2C;
extern const f32 D_80009A30;
extern const f64 D_80009A38;
extern const f32 D_80009A40;
extern const f32 D_80009A44;
extern const f32 D_80009A48;
extern const f32 D_80009A4C;
extern const f32 D_80009A50;
extern u8 gCamSpeedScale[];
extern u8 gCameraTarget[];
extern s32 gSplinePointCount[];
extern u8 D_8014AAB0[];

#define P47 (*(Obj47E8 **) D_8014AAB0)
#define CAM47 (*(Obj47E8 **) gCameraTarget)
#define ECC47 (*(s32 *) gCamSpeedScale)

/* Advances a pursuit vehicle along its track, steers it toward the camera and updates the chase state. Returns 0 while chasing, 1 when it gives up, 2 when it catches the player. */
s32 updatePursuitVehicle(Obj47E8 *veh) {
    f32 dir[4];
    s32 heading;
    f32 camHeight;
    s32 track;
    s32 settled;
    s32 sgn;
    f32 turn;
    f32 accel;
    f32 targetDist;
    f32 maxDist;
    f32 err;
    s16 cosA;
    s16 sinA;
    f32 distToTarget;

    track = veh->track;
    func_80081990(&veh->x, track, veh->dist);
    func_80081AC0(dir, track, veh->dist);
    func_8002E100(dir, dir);
    veh->x += veh->speed * dir[2];
    veh->z -= veh->speed * dir[0];
    settled = animStepKeys(veh);
    turn = 0.0f;
    if (P47->who == veh) {
        P47->dist = veh->dist;
    }
    distToTarget = func_8002D858(veh, &heading);
    veh->ang = approachAngle(heading, veh->ang, ECC47 * 448);
    if (distToTarget < D_80009A2C) {
        P47->who = veh;
        P47->c78 = 1;
        return 2;
    }
    if (distToTarget < D_80009A30) {
        P47->who = veh;
        P47->c78 = 2;
        heading = func_8002492C(dir[2], dir[0]);
        func_80043328(veh, veh->c74 + 1, 0x100);
        targetDist = CAM47->x;
        accel = CAM47->z;
        targetDist -= veh->x;
        accel -= veh->z;
        cosA = coss(heading);
        sinA = sins(heading);
        turn = cosA * targetDist + sinA * accel;
        sinA = sins(heading);
        cosA = coss(heading);
        accel = sinA * targetDist + cosA * accel;
        turn /= D_80009A38;
        targetDist = veh->cAC * D_80009A40;
        accel /= D_80009A44;
        veh->ang = approachS32(heading, veh->ang, ECC47 << 9);
    } else {
        func_80043328(veh, veh->c74 + 2, 0x100);
        targetDist = func_80081188(track, &CAM47->x, &camHeight);
        if (P47->who == veh) {
            P47->c100 = targetDist;
            P47->c104 = camHeight;
            P47->c74 = veh->c104;
            P47->speed = func_8002DD60(targetDist - veh->dist);
            P47->c78 = 3;
        }
        if (camHeight > veh->c104) {
            s32 nearCam = 0;
            if (func_8002DD60(targetDist - veh->dist) < D_80009A48) {
                nearCam = 1;
                if (P47->who == veh) {
                    P47->c78 = 0x29;
                }
            }
            if (veh->c104 * D_80009A4C < camHeight) {
                nearCam = 1;
                if (P47->who == veh) {
                    P47->c78 = 0x2A;
                }
            }
            if (nearCam) {
                if (veh->cD0 != veh->c74) {
                    func_80043328(veh, veh->c74, 0x100);
                } else if (settled) {
                    veh->c64 = 0;
                }
                return 1;
            }
        }
        err = targetDist - veh->dist;
        dir[0] = err;
        if (0.0f < err) {
            veh->cAC = func_8002DD60(veh->cAC);
            veh->cBC = 1;
        } else {
            veh->cAC = -func_8002DD60(veh->cAC);
            veh->cBC = -1;
        }
        targetDist = veh->cAC + veh->cAC;
        accel = -veh->speed / D_80009A50;
    }
    if (targetDist < turn) {
        turn = targetDist;
    }
    if (turn < targetDist) {
        turn = targetDist;
    }
    veh->dist += turn;
    veh->speed += accel;
    maxDist = gSplinePointCount[track];
    if (veh->c104 < veh->speed) {
        veh->speed = veh->c104;
    }
    if (veh->speed < -veh->c104) {
        veh->speed = -veh->c104;
    }
    if (maxDist < veh->dist) {
        veh->dist = maxDist;
    }
    if (veh->dist < 0.0f) {
        veh->dist = 0.0f;
    }
    return 0;
}
