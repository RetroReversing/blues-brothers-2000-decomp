typedef struct { u32 w0; u32 w1; } GfxW;
extern GfxW *D_80177E18;

void func_800226E4(void) {
    GfxW *g1;
    GfxW *g2;

    g1 = D_80177E18++;
    g1->w0 = 0xE7000000;
    g1->w1 = 0;
    g2 = D_80177E18++;
    g2->w0 = 0xE2001D00;
    g2->w1 = 0;
}
