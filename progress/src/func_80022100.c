typedef struct { u32 w0, w1; } GfxW;
typedef struct {
    GfxW g[2];
    u32 f10;
    u32 f14;
} Arg;
extern s32 D_800AB8E8;
extern s32 D_800AB8EC;
extern s32 D_800AB8F0;
extern s32 D_800AB998;
extern GfxW *D_80177E18;

void func_80022100(Arg *arg0) {
    D_800AB8EC = -1;
    D_800AB8E8 = -1;
    D_800AB998 = -1;
    D_800AB8F0 = 0;
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xD940F9FA;
        _g->w1 = 0;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE3000A01;
        _g->w1 = arg0->f14;
    }
    *D_80177E18++ = arg0->g[0];
    *D_80177E18++ = arg0->g[1];
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xD9FFFFFF;
        _g->w1 = arg0->f10;
    }
}
