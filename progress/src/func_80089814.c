typedef struct { u32 w0, w1; } GfxW;
typedef struct { s32 m[4][4]; } Mtx;
typedef struct {
    Mtx proj[2];
    Mtx view[2];
} Cam;
void guPerspective(Mtx *, u16 *, f32, f32, f32, f32, f32);
extern f32 D_800B9C80;
extern s32 D_800B9E88;
extern s32 D_800B9EC0;
extern u16 D_801771C4;
extern GfxW *D_80177E18;

void func_80089814(Cam *c) {
    s32 unused[10];

    guPerspective(&c->proj[D_800B9EC0], &D_801771C4, D_800B9C80, -4.0f / 3.0f, D_800B9E88, 25000.0f, 1.0f);
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xDB0E0000;
        _g->w1 = D_801771C4;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xDA380007;
        _g->w1 = (u32)&c->proj[D_800B9EC0] - 0x80000000;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xDA380005;
        _g->w1 = (u32)&c->view[D_800B9EC0] - 0x80000000;
    }
}
