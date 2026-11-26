typedef struct { u32 w0, w1; } Gfx_;

void func_800270DC(s32, s32, s32, s32);
void setRenderState(s32);
extern s32 gScreenWidth;
extern s32 gScreenHeight;
extern Gfx_ *D_80177E18;

void func_8002E6E4(void) {
    Gfx_ *g;

    func_800270DC(0, 0, 0, 0xFF);
    g = D_80177E18++;
    g->w0 = 0xFCFFFFFF;
    g->w1 = 0xFFFDF6FB;
    g = D_80177E18++;
    g->w0 = 0xE200001C;
    g->w1 = 0x0F0A4000;
    g = D_80177E18++;
    g->w0 = 0xF6000000 | ((gScreenWidth & 0x3FF) << 14) | ((gScreenHeight & 0x3FF) << 2);
    g->w1 = 0;
    setRenderState(-1);
}
