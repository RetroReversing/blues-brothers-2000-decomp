typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern s32 gScreenWidth;
extern s32 gScreenHeight;
extern Gfx *D_8016D090;

void func_80070B08(void) {
    {
        Gfx *_g = D_8016D090++;
        _g->w0 = 0xFE000000;
        _g->w1 = 0x200000 - gScreenWidth * gScreenHeight * 2;
    }
    {
        Gfx *_g = D_8016D090++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_8016D090++;
        _g->w0 = 0xE3000A01;
        _g->w1 = 0x300000;
    }
    {
        Gfx *_g = D_8016D090++;
        _g->w0 = 0xFF100000 | ((gScreenWidth - 1) & 0xFFF);
        _g->w1 = 0x200000 - gScreenWidth * gScreenHeight * 2;
    }
    {
        Gfx *_g = D_8016D090++;
        _g->w0 = 0xF7000000;
        _g->w1 = 0xFFFCFFFC;
    }
    {
        Gfx *_g = D_8016D090++;
        _g->w0 = 0xF6000000 | (((gScreenWidth - 1) & 0x3FF) << 14) | (((gScreenHeight - 1) & 0x3FF) << 2);
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_8016D090++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_8016D090++;
        _g->w0 = 0xF7000000;
        _g->w1 = 0x10001;
    }
    {
        Gfx *_g = D_8016D090++;
        _g->w0 = 0xF6000000 | (((gScreenWidth - 1) & 0x3FF) << 14) | (((gScreenHeight - 1) & 0x3FF) << 2);
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_8016D090++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
}
