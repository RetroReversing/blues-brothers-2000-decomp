typedef struct Cam47 {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    u8 pad10[0x80];
    s32 x90;
} Cam47;
typedef struct Obj47 {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    s32 x14;
    s32 x18;
} Obj47;
extern Cam47 *gCameraTarget;
extern s32 D_80140214;
extern s32 gCamSpeedScale;
extern s32 D_800B764C;
extern f32 D_800B7660[];
s32 approachAngle(s32, s32, s32);
f32 approachF32(f32, f32, f32);
s32 func_8002492C(f32, f32);
void updateCameraView(Obj47 *);
void func_80036FB8(Obj47 *, s32);

void func_80047560(Obj47 *o) {
    s32 i;
    s32 idx;
    f32 t;

    o->x4 = gCameraTarget->x4;
    if (D_80140214 == 0) {
        o->x10 = approachAngle(0, o->x10, gCamSpeedScale << 7);
        o->xC = approachF32(gCameraTarget->xC - 1100.0f, o->xC, 100.0f);
        o->x8 = approachF32(gCameraTarget->x8 + 270.0f, o->x8, 100.0f);
        o->x14 = approachAngle(-func_8002492C(100.0f, 1600.0f), o->x14, gCamSpeedScale << 7);
        if (D_800B764C != 0) {
            o->xC = gCameraTarget->xC - 1100.0f;
            o->x8 = gCameraTarget->x8 + 270.0f;
            D_800B764C = 0;
        }
    } else {
        idx = 0;
        for (i = 0; i < 4; i++) {
            if (D_800B7660[i] - 50.0f <= gCameraTarget->x8) {
                idx = i;
            }
        }
        if (gCameraTarget->x90 == 1) {
            D_800B7660[idx] = gCameraTarget->x8;
        }
        o->x14 = approachAngle(-func_8002492C(300.0f, 1500.0f), o->x14, gCamSpeedScale << 7);
        if (D_800B764C != 0) {
            o->xC = gCameraTarget->xC - 1500.0f;
            o->x8 = D_800B7660[idx] + 300.0f + 300.0f;
            D_800B764C = 0;
        }
        o->xC = approachF32(gCameraTarget->xC - 1500.0f, o->xC, 100.0f);
        t = approachF32(D_800B7660[idx] + 300.0f + 300.0f, o->x8, 100.0f);
        o->x8 = t;
        if (2600.0f < t) {
            o->x8 = 2600.0f;
        }
    }
    o->x18 = 0;
    updateCameraView(o);
    func_80036FB8(o, 15);
}
