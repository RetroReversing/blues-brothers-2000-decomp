typedef struct Slot {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    u8 x10[8];
    s16 x18[8];
} Slot;

typedef struct Pair {
    s32 x0;
    s32 x4;
    s32 x8;
} Pair;

s32 *getComboSequence(s32, s32, s32);
s32 checkComboWindow(s32);

extern Pair gComboDefs[];
extern s32 gPadPressed[];
extern s32 D_801073B0[];
extern s32 gStickY[];
extern s32 gPrevStickX[];
extern s32 gPrevStickY[];
extern s32 gComboBeat;
extern Slot gComboSlots[];
extern s32 D_80171A54;
extern s32 D_80171A70[];

void updateComboInput(s32 p) {
    s32 phase;
    s32 *seq;
    s32 sx;
    s32 sy;
    s32 btn;
    s32 i;

    phase = gComboBeat % 144;
    seq = getComboSequence(gComboSlots[p].x0, D_80171A70[p], D_80171A54);
    sx = D_801073B0[p];
    sy = gStickY[p];
    if (abs(sx) * 2 > abs(sy)) {
        sy = 0;
    }
    if (abs(sx) < abs(sy) * 2) {
        sx = 0;
    }
    if (abs(sx) < 10) {
        sx = 0;
    }
    if (abs(sy) < 10) {
        sy = 0;
    }
    if (sx > 20 && gPrevStickX[p] <= 20) {
        gPadPressed[p] |= 0x100;
    }
    if (sx < -20 && gPrevStickX[p] >= -20) {
        gPadPressed[p] |= 0x200;
    }
    if (sy > 20 && gPrevStickY[p] <= 20) {
        gPadPressed[p] |= 0x800;
    }
    if (sy < -20 && gPrevStickY[p] >= -20) {
        gPadPressed[p] |= 0x400;
    }
    gPrevStickX[p] = sx;
    gPrevStickY[p] = sy;
    btn = gPadPressed[p];
    if (btn != 0) {
        if (btn == seq[gComboSlots[p].x8]) {
            gComboSlots[p].x10[gComboSlots[p].x8] = 1;
            gComboSlots[p].x18[gComboSlots[p].x8] = 0xFF;
            gComboSlots[p].x8++;
            gComboSlots[p].xC = checkComboWindow(p);
        } else {
            for (i = gComboSlots[p].x8; i > 0; i--) {
                gComboSlots[p].x10[i] = 0;
                gComboSlots[p].x18[i] = 0x76;
            }
            gComboSlots[p].x8 = gComboDefs[gComboSlots[p].x0].x0;
        }
    }
    if (gComboSlots[p].xC == 0 && phase >= 31 && phase < 36) {
        for (i = gComboSlots[p].x8; i > 0; i--) {
            gComboSlots[p].x10[i] = 0;
            gComboSlots[p].x18[i] = 0x76;
        }
        gComboSlots[p].x8 = gComboDefs[gComboSlots[p].x0].x0;
    }
}
