typedef struct { u32 w0, w1; } GfxW;
typedef struct { u8 pad[0x70]; s32 f70; } Obj;
s32 func_8002710C(s32, s32, s32, s32);
extern GfxW *D_80177E18;

s32 func_80080A08(Obj *o) {
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
    func_8002710C(0, 0, 0, o->f70);
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xFCFFFFFF;
        _g->w1 = 0xFFFDF6FB;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xF65003C0;
        _g->w1 = 0;
    }
    return 0;
}
