s16 coss(s32);
s16 sins(s32);
s32 func_8000C43C(void);
void func_80034F1C(void *);
extern void *D_800B3960;
extern s32 D_800B4ABC[];
extern void *D_800BD06C;
extern s32 D_8013FFA4;
extern s32 D_8013FFA8;
extern s32 D_8014002C;
extern s32 D_80140030;

#define F(p, t, o) (*(t *)((char *)(p) + (o)))

void func_80033BDC(s32 arg0) {
    void *p;
    f32 t;
    s32 a1, a2;
    void *q;

    D_80140030 = 0;
    p = D_800B3960;
    D_8014002C = 0;
    F(p, s32, 0x6C) = arg0;
    F(p, s32, 0xC0) = 0;
    if (func_8000C43C() == 0x36 || func_8000C43C() == 0x23) {
        D_800B4ABC[0] = 800;
        D_800B4ABC[2] = 1000;
        D_800B4ABC[4] = 1200;
        D_800B4ABC[6] = 1000;
        D_800B4ABC[8] = 800;
    } else {
        D_800B4ABC[0] = 800;
        D_800B4ABC[2] = 1200;
        D_800B4ABC[4] = 1600;
        D_800B4ABC[6] = 1200;
        D_800B4ABC[8] = 800;
    }
    func_80034F1C(p);
    a1 = F(p, s32, 0x10);
    a2 = F(p, s32, 0x80);
    q = D_800BD06C;
    F(p, s32, 0x78) = F(p, s32, 0x7C);
    F(p, s32, 0x74) = a1;
    F(p, s32, 0x14) = a2;
    F(p, f32, 0x40) = F(q, f32, 4);
    F(p, f32, 0x44) = F(q, f32, 8);
    F(p, f32, 0x48) = F(q, f32, 0xC);
    F(p, f32, 4) = F(p, f32, 0x40) + (f32)((((-F(p, s32, 0x78) * sins(F(p, u16, 0x12))) >> 15) * coss(F(p, u16, 0x16))) >> 15);
    F(p, f32, 0xC) = F(p, f32, 0x48) + (f32)((((-F(p, s32, 0x78) * coss(F(p, u16, 0x12))) >> 15) * coss(F(p, u16, 0x16))) >> 15);
    t = F(p, f32, 0x44) + (f32)((-F(p, s32, 0x78) * sins(F(p, u16, 0x16))) >> 15) + 200.0f;
    D_8013FFA8 = 0;
    F(p, f32, 8) = t;
    D_8013FFA4 = 0;
}
