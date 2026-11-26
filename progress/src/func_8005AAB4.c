s16 coss(s32);
s16 sins(s32);
s32 isqrtS32(s32);
void func_8002A360(s32, s32);
void actorSetAnim(void *, s32, s32);
extern s32 D_80140240;

#define F(p, t, o) (*(t *)((char *)(p) + (o)))

s32 func_8005AAB4(void *arg0, void *arg1) {
    s32 dy;
    s32 x;
    s32 z;
    s32 dx;
    s32 dz;

    dy = F(arg0, f32, 8) - F(arg1, f32, 8);
    if (dy <= 0 || (u32)(F(arg1, s32, 0xD0) - 0x70) >= 2) {
        return 0;
    }
    x = F(arg1, f32, 4) + (f32)((-(sins(F(arg1, u16, 0x12)) * 150)) >> 15);
    z = F(arg1, f32, 0xC) + (f32)((-(coss(F(arg1, u16, 0x12)) * 150)) >> 15);
    dx = F(arg0, f32, 4) - (f32)x;
    dz = F(arg0, f32, 0xC) - (f32)z;
    if (isqrtS32(dx * dx + dz * dz) < 175) {
        if (F(arg0, s32, 0xD0) != 5) {
            return 0;
        }
        if (F(arg0, f32, 0x50) < 0.0f && dy < 150) {
            F(arg0, f32, 0x50) = (D_80140240 * 3) / 2;
            F(arg0, f32, 8) += 1.0f;
            actorSetAnim(arg0, 5, 0x100);
            actorSetAnim(arg1, 0x71, 0x100);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 2);
        }
    }
    return 0;
}
