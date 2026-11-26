typedef struct { u32 w0; u32 w1; } GfxW;
typedef struct { u8 col[8]; } Ambient;
typedef struct { u8 col[8]; s8 dir[8]; } Light;
typedef struct { Ambient a; Light l[7]; } Lights7;
typedef struct {
    s16 count;
    s16 pad2;
    s16 off;
    s16 pad6;
    Lights7 bufs[2];
} LightState;
extern GfxW *D_80177E18;
extern s32 D_80177E20;
extern s32 D_800B9EB8;
extern u8 D_800B7680[];

void func_800479B0(LightState *ls) {
    s32 n;
    s32 i;
    GfxW *g1;
    GfxW *g2;
    GfxW *g3;
    GfxW *g4;

    if (ls == NULL) {
        return;
    }
    if (ls->off != 0) {
        if (D_80177E20 == 0) {
            return;
        }
        D_80177E20 = 0;
    } else {
        D_80177E20 = 1;
    }
    n = 1;
    if (ls->count > 0) {
        n = ls->count;
    }
    g1 = D_80177E18++;
    g1->w0 = 0xDB020000;
    g1->w1 = n * 24;
    if (ls->count > 0) {
        for (i = 0; i < ls->count; i++) {
            g2 = D_80177E18++;
            g2->w0 = 0xDC08000A | ((((i + 1) * 3 + 3) & 0xFF) << 8);
            g2->w1 = (u32) &ls->bufs[D_800B9EB8].l[i];
        }
    } else {
        g3 = D_80177E18++;
        g3->w0 = 0xDC08060A;
        g3->w1 = (u32) D_800B7680;
    }
    g4 = D_80177E18++;
    g4->w0 = 0xDC08000A | ((((n + 1) * 3 + 3) & 0xFF) << 8);
    g4->w1 = (u32) &ls->bufs[D_800B9EB8].a;
}
