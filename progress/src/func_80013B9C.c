s16 coss(u16);
s32 func_80024394(s32, s32);
void func_800393C8(void *);
extern s32 D_800B9EA4;

#define F(p, t, o) (*(t *)((char *)(p) + (o)))

void func_80013B9C(void *arg0) {
    void *q;
    s32 m;
    s32 c;

    if (F(arg0, s32, 0xC0) == 0) {
        F(arg0, s32, 0x78) = func_80024394(0x28, 0x3C);
        F(arg0, s32, 0x8C) = func_80024394(0, 0x8000);
        F(arg0, s32, 0xC0) = 1;
        F(arg0, s32, 0) = 0x142;
    }
    m = D_800B9EA4 * F(arg0, s32, 0x78);
    F(arg0, f32, 0x4C) = -F(arg0, f32, 4);
    F(arg0, f32, 0x54) = -F(arg0, f32, 0xC);
    c = coss(F(arg0, u16, 0x8E) + m);
    {
        s32 m2 = D_800B9EA4 * F(arg0, s32, 0x78);
        F(arg0, f32, 4) = F(arg0, f32, 0x40) + ((c * 125) >> 13);
        F(arg0, f32, 0xC) = F(arg0, f32, 0x48) - ((coss(F(arg0, u16, 0x8E) + m2) * 125) >> 13);
    }
    F(arg0, f32, 0x4C) += F(arg0, f32, 4);
    F(arg0, f32, 0x54) += F(arg0, f32, 0xC);
    q = F(arg0, void *, 0xA8);
    if (q != 0) {
        F(q, f32, 4) += F(arg0, f32, 0x4C);
        F(q, f32, 0xC) += F(arg0, f32, 0x54);
        func_800393C8((char *)arg0 + 0x4C);
    }
    F(arg0, f32, 8) = F(arg0, f32, 0x44) + ((coss(F(arg0, u16, 0x8E) + D_800B9EA4 * 20) * 25) >> 14);
}
