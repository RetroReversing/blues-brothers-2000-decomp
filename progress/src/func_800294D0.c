typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_8002220C(s32);
void func_8002710C(s32, s32, s32, s32);
void func_80029F8C(s32);
extern s32 D_800B9C74;
extern s32 D_800B9C78;
extern s32 D_800B9ECC;
extern s32 D_80107658;
extern s32 D_8010765C;
extern Gfx *D_80177E18;

void func_800294D0(s32 arg0) {
    s32 x = D_800B9C74;
    s32 y = D_800B9C78;

    func_8002220C(func_800221C0(0, 0, 0, 2, 0, 0, 1, 1));
    func_80029F8C(0x5B);
    func_8002710C(0, 0, 0xB0, 0xFF);
    { Gfx *_g = D_80177E18++; _g->w0 = 0xFC30FE61; _g->w1 = 0xFFFFF7FB; }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xE200001C; _g->w1 = 0x0F0A4000; }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xE3000A01; _g->w1 = 0; }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xFD900000; _g->w1 = arg0; }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xF5900000; _g->w1 = 0x07018060; }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xE6000000; _g->w1 = 0; }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xF3000000; _g->w1 = 0x077FF100; }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xE7000000; _g->w1 = 0; }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xF5881000; _g->w1 = 0x00018060; }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xF2000000; _g->w1 = 0x000FC0FC; }
    { Gfx *_g = D_80177E18++;
      _g->w0 = 0xF2000000 | ((D_80107658 & 0xFFF) << 12) | (D_8010765C & 0xFFF);
      _g->w1 = (((D_80107658 + 0x40) & 0xFFF) << 12) | ((D_8010765C + 0x40) & 0xFFF); }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xE4000000 | (((x << 2) & 0xFFF) << 12) | ((y << 2) & 0xFFF); _g->w1 = 0; }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xE1000000; _g->w1 = 0; }
    { Gfx *_g = D_80177E18++; _g->w0 = 0xF1000000; _g->w1 = 0x04000400; }
    D_80107658 += D_800B9ECC * 3;
    D_8010765C -= D_800B9ECC * 2;
}
