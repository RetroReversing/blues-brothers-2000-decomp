typedef struct { u32 w0, w1; } GfxW;
void func_8002710C(s32, s32, s32, s32);
extern GfxW *D_80177E18;

s32 func_80028410(s32 ulx, s32 uly, s32 lrx, s32 lry) {
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE200001C;
        _g->w1 = 0x504240;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xF7000000;
        _g->w1 = 0xFF;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE2001E01;
        _g->w1 = 0;
    }
    func_8002710C(0, 0, 0, 0xD0);
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xFCFFFFFF;
        _g->w1 = 0xFFFDF6FB;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xF6000000 | ((lrx & 0x3FF) << 14) | ((lry & 0x3FF) << 2);
        _g->w1 = ((ulx & 0x3FF) << 14) | ((uly & 0x3FF) << 2);
    }
    return 0;
}
