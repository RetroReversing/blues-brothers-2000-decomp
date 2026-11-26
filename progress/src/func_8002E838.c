void func_800270DC(s32, s32, s32, s32);
extern s32 gScreenWidth;
extern s32 gScreenHeight;
typedef struct { u32 w0, w1; } GfxW;
extern GfxW *D_80177E18;

void func_8002E838(s32 arg0) {
    GfxW *g;

    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE3001801;
        _g->w1 = 0;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE2001E01;
        _g->w1 = 0;
    }
    func_800270DC(0, 0, 0, arg0);
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xFCFFFFFF;
        _g->w1 = 0xFFFDF6FB;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE200001C;
        _g->w1 = 0x504340;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xF6000000 | (((gScreenWidth - 1) & 0x3FF) << 14) | (((gScreenHeight - 1) & 0x3FF) << 2);
        _g->w1 = 0;
    }
}
