s16 coss(u16);
s32 randomRange(s32, s32);
void func_800393C8(void *);
extern s32 gTextWaveTime;

#define F(p, t, o) (*(t *)((char *)(p) + (o)))

void func_80013B9C(void *arg0) {
    void *q;
    s32 m;
    s32 c;

    if (F(arg0, s32, 0xC0) == 0) {
        F(arg0, s32, 0x78) = randomRange(0x28, 0x3C);
        F(arg0, s32, 0x8C) = randomRange(0, 0x8000);
        F(arg0, s32, 0xC0) = 1;
        F(arg0, s32, 0) = 0x142;
    }
    m = gTextWaveTime * F(arg0, s32, 0x78);
    F(arg0, f32, 0x4C) = -F(arg0, f32, 4);
    F(arg0, f32, 0x54) = -F(arg0, f32, 0xC);
    c = coss(F(arg0, u16, 0x8E) + m);
    {
        s32 m2 = gTextWaveTime * F(arg0, s32, 0x78);
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
    F(arg0, f32, 8) = F(arg0, f32, 0x44) + ((coss(F(arg0, u16, 0x8E) + gTextWaveTime * 20) * 25) >> 14);
}
