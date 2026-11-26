s16 coss(u16);
s16 sins(u16);
s32 isqrtS32(s32);

typedef struct ObjM {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s16 f10;
    u16 yaw;
    u8 pad14[0xC0 - 0x14];
    s32 fC0;
    u8 padC4[0xD0 - 0xC4];
    s32 fD0;
} ObjM;

extern ObjM *gCameraTarget;

s32 func_8005ACA4(ObjM *arg0) {
    s32 dx;
    s32 dz;
    s32 d;
    f32 k;

    arg0->fC0 = 0;
    if (arg0->fD0 == 0x71) {
        dx = (arg0->x + (f32)(-(sins(arg0->yaw) * 150) >> 15)) - gCameraTarget->x;
        dz = (arg0->z + (f32)(-(coss(arg0->yaw) * 150) >> 15)) - gCameraTarget->z;
    } else {
        dx = arg0->x - gCameraTarget->x;
        dz = arg0->z - gCameraTarget->z;
    }
    d = isqrtS32(dx * dx + dz * dz);
    if (d < 175 && !((arg0->y + 150.0f) - 50.0f < gCameraTarget->y)) {
        k = 175 - d;
        gCameraTarget->x -= (dx * k) / d;
        gCameraTarget->z -= (dz * k) / d;
        arg0->fC0 |= 1;
        return 1;
    }
    return 0;
}
