int abs(int);
extern void *D_800BD06C;
extern void func_8000E468();
extern void func_8002ADFC();
void func_8000E4AC(void *arg0) {
    s32 dx, dz, t;
    f32 fx, fz;

    fx = ((f32 *)D_800BD06C)[1] - ((f32 *)arg0)[1];
    fz = ((f32 *)D_800BD06C)[3] - ((f32 *)arg0)[3];
    dx = fx;
    dz = fz;
    if (abs(dx) < 0x4A39) {
        t = abs(dz);

        if (t < 0x4A39 && dx * dx + dz * dz <= 0x270FFF) {
            *(void **)((s8 *)arg0 + 0x9C) = func_8000E468;
            *(s32 *)((s8 *)arg0 + 0x64) = 0x64;
            func_8002ADFC(0x23, 0xFA0, arg0);
        }
    }
}

