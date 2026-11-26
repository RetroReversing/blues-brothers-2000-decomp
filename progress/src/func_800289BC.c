typedef struct { u32 w0, w1; } Gfx;

s32 coss(u16);
s32 sins(u16);
s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_8002220C(s32);
void func_800272E0(void *, s32, s32, s32);
void func_80029F8C(s32);
extern u8 D_800AE210[];
extern u8 D_800B1C90[];
extern u8 D_800B20A0[];
extern u8 D_800B24B0[];
extern s32 D_800B28C0;
extern u8 D_800B28C4[];
extern u8 D_800B2904[];
extern u8 D_800B2A04[];
extern union { s32 w; u16 h[2]; } D_800B2B18;
extern s32 D_800B9EA4;
extern s32 D_80107650;
extern s32 D_8010788C;
extern s32 D_80107890;
extern Gfx *D_80177E18;

#define GFX(a, b) { Gfx *_g = D_80177E18++; _g->w0 = (a); _g->w1 = (b); }

void func_800289BC(s32 c, s32 first)
{
    u8 ch;
    s32 special;
    s32 idx;
    
    s32 x4;
    s32 y;
    s32 step;
    s32 temp;
    u32 tex;

    special = 0;
    D_800B2B18.w += 8000;
    if (c == '{') {
        func_800272E0(D_800B1C90, D_8010788C, D_80107890 - 2, 0);
        special = 1;
    }
    if (c == '~') {
        func_800272E0(D_800B24B0, D_8010788C, D_80107890 - 2, 0);
        special = 1;
    }
    if (c == '}') {
        func_800272E0(D_800B20A0, D_8010788C, D_80107890 - 2, 0);
        special = 1;
    }
    if (special) {
        func_8002220C(func_800221C0(0, 0, 1, 2, 0, 0, 1, 1));
        GFX(0xE200001C, 0x504A50);
        func_80029F8C(0x5B);
        GFX(0xFCFFB3FF, 0xFF65FEFF);
        D_8010788C += 16;
        return;
    }
    ch = c;
    c = D_800B2904[c];
    D_80107650 = idx;
    idx = c - 0x20;
    GFX(0xE7000000, 0);
    tex = (u32)D_800AE210;
    tex += idx * 0xD0;
    tex &= ~7;
    GFX(0xFD900000, tex);
    GFX(0xF5900000, 0x07080200);
    GFX(0xE6000000, 0);
    GFX(0xF3000000, 0x07067400);
    GFX(0xE7000000, 0);
    GFX(0xF5880400, 0x00080200);
    GFX(0xF2000000, 0x0003C030);
    if (first) {
        D_800B2B18.w = 0;
        func_8002220C(func_800221C0(0, 0, 1, 2, 0, 0, 1, 1));
        GFX(0xE200001C, 0x504A50);
        func_80029F8C(0x5B);
        GFX(0xFCFFB3FF, 0xFF65FEFF);
    }
    coss(D_800B2B18.h[1] + D_800B9EA4 * 200);
    sins(D_800B2B18.h[1] + D_800B9EA4 * 200);
    step = 64 / D_800B28C0;
    x4 = D_8010788C * 4;
    y = D_80107890;
    c = x4 + step;
    temp = (y * 4 + 0x34) & 0xFFF;
    GFX(0xE4000000 | ((c & 0xFFF) << 12) | temp, ((x4 & 0xFFF) << 12) | ((y * 4) & 0xFFF));
    GFX(0xE1000000, 0);
    GFX(0xF1000000, (D_800B28C0 << 26) | 0x400);
    if (ch >= 0xC0) {
        tex = (u32)D_800AE210;
        c = x4 + 64;
        tex += (D_800B28C4[ch - 0xC0] - 0x20) * 0xD0;
        tex &= ~7;
    GFX(0xFD900000, tex);
        GFX(0xF5900000, 0x07080200);
        GFX(0xE6000000, 0);
        GFX(0xF3000000, 0x07067400);
        GFX(0xE7000000, 0);
        GFX(0xF5880400, 0x00080200);
        GFX(0xF2000000, 0x0003C030);
        GFX(0xE4000000 | ((c & 0xFFF) << 12) | ((y * 4 + 0x34) & 0xFFF), ((x4 & 0xFFF) << 12) | (((y - 3) * 4) & 0xFFF));
        GFX(0xE1000000, 0);
        GFX(0xF1000000, 0x04000400);
    }
    D_8010788C = ((D_8010788C)) + ((2 + (11 - D_800B2A04[idx]) / D_800B28C0));
}


