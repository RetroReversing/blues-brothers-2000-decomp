typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

void func_80027038();
void func_80029EB0(void);
void func_80089130(s32, s32, s32);
extern Gfx D_800ABA00[];
extern s32 D_800B396C;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern Gfx *D_80177E18;

void func_8002E46C(void) {
    func_80027038(2);
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE3000A01;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xD9D0F9FA;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xF8000000;
        _g->w1 = (D_800B3970 << 24) | ((D_800B3974 & 0xFF) << 16) | ((D_800B3978 & 0xFF) << 8);
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xDB080000;
        _g->w1 = ((128000 / (1000 - D_800B396C)) << 16) | (((500 - D_800B396C) * 256 / (1000 - D_800B396C)) & 0xFFFF);
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xDE000000;
        _g->w1 = (u32)D_800ABA00;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE3001801;
        _g->w1 = 0xC0;
    }
    func_80089130(D_800B3970, D_800B3974, D_800B3978);
    func_80029EB0();
}
