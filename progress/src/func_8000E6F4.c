int abs(int);
extern void *gCameraTarget;
extern void func_8000E570();
void func_8000E6F4(void *arg0) {
    s32 dx, dz, t;
    f32 fx, fz;

    fx = ((f32 *)gCameraTarget)[1] - ((f32 *)arg0)[1];
    fz = ((f32 *)gCameraTarget)[3] - ((f32 *)arg0)[3];
    dx = fx;
    dz = fz;
    if (abs(dx) < 0x4A39) {
        t = abs(dz);

        if (t < 0x4A39 && dx * dx + dz * dz <= 0x270FFF) {
            *(void **)((s8 *)arg0 + 0x9C) = func_8000E570;
            *(s32 *)((s8 *)arg0 + 0x64) = 0x190;
            *(s32 *)((s8 *)arg0 + 0x7C) = 0x400;
        }
    }
}
