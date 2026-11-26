s32 atan2S16(s32, s32);
f32 func_8002DD60(f32);
extern f32 *gCameraTarget;

f32 func_8002D77C(f32 *pos, f32 range, s32 *angle) {
    f32 dx;
    f32 dz;

    dx = gCameraTarget[1] - pos[1];
    dz = gCameraTarget[3] - pos[3];
    if (range < func_8002DD60(dx)) {
        return range;
    }
    if (range < func_8002DD60(dz)) {
        return range;
    }
    if (angle != NULL) {
        *angle = atan2S16(dx, dz);
    }
    return sqrtf(dx * dx + dz * dz);
}
