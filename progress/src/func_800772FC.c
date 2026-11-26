s32 randomRange(s32, s32);
f32 func_800247D0(f32, f32);
f32 sqrtf(f32);

s32 func_800772FC(void *arg0) {
    f32 dx;
    f32 dz;
    f32 r;
    f32 a;

    dx = *(f32 *)((s8 *)arg0 + 4) - *(f32 *)((s8 *)arg0 + 0x40);
    dz = *(f32 *)((s8 *)arg0 + 0xC) - *(f32 *)((s8 *)arg0 + 0x48);
    r = *(f32 *)((s8 *)arg0 + 0x104);
    if (r <= sqrtf(dx * dx + dz * dz)) {
        a = func_800247D0(dx, dz) + 3.1415926;
        a = a * 32768.0f / 3.1415926;
        *(s32 *)((s8 *)arg0 + 0x10) = a + randomRange(-5000, 5000);
        return 1;
    }
    return 0;
}
