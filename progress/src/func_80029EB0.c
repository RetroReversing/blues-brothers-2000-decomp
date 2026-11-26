typedef struct { u32 w0, w1; } GfxW;
void setRenderState(s32);
extern GfxW *D_80177E18;

void func_80029EB0(void) {
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE3001700;
        _g->w1 = 0;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE2001E01;
        _g->w1 = 0;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE3001201;
        _g->w1 = 0x2000;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE3000F00;
        _g->w1 = 0;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE3000C00;
        _g->w1 = 0x80000;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xD7000002;
        _g->w1 = 0x80008000;
    }
    setRenderState(-1);
}
