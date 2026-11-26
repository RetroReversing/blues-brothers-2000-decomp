s16 coss(u16);
s16 sins(u16);
f32 getCameraTargetDist(void *, f32, s32);
s32 animStepKeys(void);
extern f32 D_800008B4;
extern f32 D_800008B8;
extern u8 *gCameraTarget;

void func_800169B0(u8 *arg0) {
    f32 scale;
    f32 dist;
    f32 y;
    s32 ret;

    ret = animStepKeys();
    scale = 5000.0f;
    if (ret == 1) {
        *(s32 *)(arg0 + 0xC0) = 0;
    }
    dist = 200.0f;
    if (getCameraTargetDist(arg0, dist, 0) < dist) {
        *(f32 *)(gCameraTarget + 0x4C) = (((s32)(sins(*(u16 *)(gCameraTarget + 0x12)) * scale) >> 15) * coss(0x2000)) >> 15;
        *(f32 *)(gCameraTarget + 0x54) = (((s32)(coss(*(u16 *)(gCameraTarget + 0x12)) * scale) >> 15) * coss(0x2000)) >> 15;
        y = sins(0x2000) * scale;
        *(s32 *)(gCameraTarget + 0xAC) = 0;
        *(s32 *)(gCameraTarget + 0xB0) = 0;
        *(s32 *)(gCameraTarget + 0xB4) = 0;
        *(f32 *)(gCameraTarget + 0x50) = (s32)y >> 15;
        *(s32 *)(arg0 + 0xC0) = 1;
    }
}
