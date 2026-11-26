typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PlayerPos;
f32 func_8002D858(void *, s32, s32);
void func_8003BF98(void *);
extern s32 gCamSpeedScale;
extern u8 *gCameraTarget;

void func_8007F898(u8 *obj) {
    f32 dist;
    f32 lim;
    f32 dy;

    *(s32 *) (obj + 0x68) = 0xD;
    *(s32 *) (obj + 0x10) += gCamSpeedScale << 8;
    *(s32 *) (obj + 0x34) += 8;
    *(s32 *) (obj + 0x3C) = *(s32 *) (obj + 0x34);
    *(s32 *) (obj + 0x38) = *(s32 *) (obj + 0x34);
    dist = func_8002D858(obj, 0, *(s32 *) (obj + 0x38));
    lim = 0.00390625f;
    lim = *(s32 *) (obj + 0x34) * lim;
    lim = lim * 1800.0f;
    dy = *(f32 *) (gCameraTarget + 8) - *(f32 *) (obj + 8);
    if (*(s32 *) (obj + 0x7C) == 0 && dist <= lim && dy < 250.0f) {
        func_8003BF98(obj);
        *(s32 *) (obj + 0x7C) += 1;
    }
    if (*(s32 *) (obj + 0x34) > 0x4B0) {
        (*(void (**)(void *)) (obj + 0xA0))(obj);
    }
}

