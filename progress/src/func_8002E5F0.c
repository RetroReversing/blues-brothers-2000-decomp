typedef struct { u32 w0, w1; } GfxW;
void func_800270DC(s32, s32, s32, s32);
void setRenderState(s32);
extern GfxW *D_80177E18;

void func_8002E5F0(s32 x, s32 y, s32 w, s32 h) {
    func_800270DC(0, 0, 0, 0x80);
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xFCFFFFFF;
        _g->w1 = 0xFFFDF6FB;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE200001C;
        _g->w1 = 0x504240;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xF6000000 | (((x + w) & 0x3FF) << 14) | (((y + h) & 0x3FF) << 2);
        _g->w1 = ((x & 0x3FF) << 14) | ((y & 0x3FF) << 2);
    }
    setRenderState(-1);
}
