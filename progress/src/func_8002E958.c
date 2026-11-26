typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

void setTextColor(s32, s32, s32, s32);
void func_8002EBC0(void);
void func_8002EB98(void);
extern Gfx *D_80177E18;
extern s32 D_800B4988;
extern s32 D_800B4980;
extern s32 D_8013FB24;
extern s32 D_8013FB20;
extern s32 gScreenWidth;
extern s32 gScreenHeight;
extern s32 gCamSpeedScale;

void func_8002E958(void) {
    Gfx *g0;
    Gfx *g1;
    Gfx *g2;
    Gfx *g3;
    Gfx *g4;
    s32 v;

    D_8013FB24 = D_800B4988;
    if (D_800B4988 != 0) {
        setTextColor(0, 0, 0, 0xFF);
        g0 = D_80177E18++;
        g0->w0 = 0xFCFFFFFF;
        g0->w1 = 0xFFFDF6FB;
        g1 = D_80177E18++;
        g1->w0 = 0xE200001C;
        g1->w1 = 0x00552230;
        g2 = D_80177E18++;
        g2->w0 = 0xF7000000;
        g2->w1 = 0xFF;
        g3 = D_80177E18++;
        g3->w0 = 0xF6000000 | (((gScreenWidth - 1) & 0x3FF) << 14) | ((D_8013FB24 & 0x3FF) << 2);
        g3->w1 = 0;
        g4 = D_80177E18++;
        g4->w0 = 0xF6000000 | (((gScreenWidth - 1) & 0x3FF) << 14) | (((gScreenHeight - 1) & 0x3FF) << 2);
        g4->w1 = ((gScreenHeight - D_8013FB24) & 0x3FF) << 2;
    }
    D_800B4988 -= gCamSpeedScale * 2;
    if (D_800B4988 < 0) {
        D_800B4988 = 0;
    }
    D_8013FB24 = D_800B4988;
    if (D_800B4980 != 0) {
        if (D_800B4980 == 1) {
            D_8013FB20 += gCamSpeedScale * 4;
            if (D_8013FB20 >= 0xFF) {
                D_8013FB20 = 0xFF;
                D_800B4980 = 2;
            }
        }
        if (D_800B4980 == 2) {
            D_8013FB20 = 0xFF;
        }
        if (D_800B4980 == 3) {
            D_8013FB20 -= gCamSpeedScale * 4;
            if (D_8013FB20 < 0) {
                D_8013FB20 = 0;
                D_800B4980 = 0;
            }
        }
        v = D_8013FB20;
        if (v == 0xFF || v < 10) {
            func_8002EBC0();
        } else if (v >= 0xF6) {
            D_8013FB20 = 0xFF;
            func_8002EBC0();
            D_8013FB20 = v;
        } else {
            func_8002EB98();
        }
    } else {
        D_8013FB20 = 0;
    }
}
