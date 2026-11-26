s32 atan2S16(s32, s32);
f32 sqrtf(f32);
extern u8 *gCameraTarget;

f32 func_8002D858(u8 *arg0, s32 *arg1) {
    f32 dx;
    f32 dz;

    dx = *(f32 *)(gCameraTarget + 4) - *(f32 *)(arg0 + 4);
    dz = *(f32 *)(gCameraTarget + 0xC) - *(f32 *)(arg0 + 0xC);
    if (arg1 != NULL) {
        *arg1 = atan2S16(dx, dz);
    }
    return sqrtf(dx * dx + dz * dz);
}
