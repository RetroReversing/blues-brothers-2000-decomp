typedef struct {
    s32 unk0;
    u8 pad4[0xC];
    u8 unk10[8];
    s16 unk18[8];
} Unk801719E0;

typedef struct {
    s32 unk0[6];
} Unk800820E8_fp;

typedef struct {
    u8 pad0[4];
    f32 unk4;
    f32 unk8;
    u8 padC[0x70 - 0xC];
    s32 unk70;
} Unk800820E8;

extern Unk801719E0 gComboSlots[];
extern s32 gBrotherActorTypes[];
extern s32 D_80171A54;
extern s32 D_800AB9B4;
extern s32 gComboBeat;
typedef struct { u32 w0, w1; } GfxW;
extern GfxW *D_80177E18;

Unk800820E8_fp *getComboSequence(s32, s32, s32);
void setTextColor(s32, s32, s32, s32);
s32 func_80023D58(s32);
void func_80081E1C(s32, s32, s32, s32);
void func_8008203C(s32, s32);
s32 func_80081FA4(s32);
s32 func_80081F0C(s32);
void func_80081E78(s32, s32, s32, s32);

/* Draws the combo meter for one player: a pulsing title and the six-slot combo row,
   with each slot's icon and fade state taken from the combo sequence. */
void drawComboMeter(Unk800820E8 *meter) {
    Unk800820E8_fp *seq;
    s32 baseX;
    s32 baseY;
    s32 alphaFull;
    s32 alphaFade;
    s32 slot;
    s32 scale;
    s32 slotSpacing;
    s32 colorR;
    s32 colorG;
    s32 colorB;
    s32 beat144;
    s32 beat36;

    scale = 1;
    seq = getComboSequence(gComboSlots[meter->unk70].unk0, gBrotherActorTypes[meter->unk70], D_80171A54);
    baseX = meter->unk4;
    baseY = meter->unk8;
    slotSpacing = 24;
    if (D_800AB9B4 != 0) {
        return;
    }
    beat144 = gComboBeat % 144;
    beat36 = gComboBeat % 36;
    alphaFade = 0xFF - beat36 * 6;
    if ((alphaFull = 0xFF - beat144 * 4) < 0x50) {
        alphaFull = 0x50;
    }
    colorR = 0x80;
    if (alphaFull >= 0x70) {
        if (seq->unk0[5] == 0x8000) {
            colorR = 0x70;
            colorG = 0x70;
            colorB = 0xFA;
        } else {
            colorR = 0x64;
            colorG = 0xF0;
            colorB = 0x64;
        }
    } else {
        colorG = 0x60;
        colorB = 0x60;
    }
    setTextColor(colorR, colorG, colorB, alphaFade);
    func_80081E1C(func_80023D58(0x20A), scale * (slotSpacing + baseX - 15), scale * (baseY - 6), 0);
    {
        GfxW *gp = D_80177E18++;
        gp->w0 = 0xE7000000;
        gp->w1 = 0;
    }
    setTextColor(0xFF, 0xFF, 0xFF, alphaFade);
    for (slot = 0; slot < 5; slot++) {
        func_8008203C(meter->unk70, slot);
        if (gComboSlots[meter->unk70].unk10[slot] != 0) {
            func_80081E78(func_80081FA4(seq->unk0[slot]), baseX + slot * slotSpacing, baseY - 8, gComboSlots[meter->unk70].unk18[slot]);
        } else {
            func_80081E78(func_80081F0C(seq->unk0[slot]), baseX + slot * slotSpacing, baseY - 8, gComboSlots[meter->unk70].unk18[slot]);
        }
    }
    func_8008203C(meter->unk70, 5);
    setTextColor(0xFF, 0xFF, 0xFF, alphaFull);
    func_80081E78(func_80081F0C(seq->unk0[5]), baseX + slotSpacing * 5, baseY - 7, gComboSlots[meter->unk70].unk18[5]);
}
