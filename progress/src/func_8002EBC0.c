/* adapted from similar verified C in func_8002E838 in BLUES BROTHERS 2000 (matched), with its names changed by decompdecomp */
void func_800270DC(s32, s32, s32, s32);
extern s32 D_800B9C74;
extern s32 D_8013FB20;
extern s32 D_800B9C78;
typedef struct { u32 w0, w1; } GfxW;
extern GfxW *D_80177E18;

void func_8002EBC0(void) {
    GfxW *g;

    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE2001E01;
        _g->w1 = 0;
    }
    func_800270DC(0, 0, 0, D_8013FB20);
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
        _g->w0 = 0xF6000000 | (((D_800B9C74 - 1) & 0x3FF) << 14) | (((D_800B9C78 - 1) & 0x3FF) << 2);
        _g->w1 = 0;
    }
}

