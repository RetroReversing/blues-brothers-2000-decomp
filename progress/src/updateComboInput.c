typedef struct ComboSlot {
    s32 type;
    s32 acc;
    s32 step;
    s32 done;
    u8 hit[8];
    s16 flash[8];
} ComboSlot;

typedef struct ComboDef {
    s32 startStep;
    s32 sound;
    s32 meterGain;
} ComboDef;

s32 *getComboSequence(s32, s32, s32);
s32 checkComboWindow(s32);

extern ComboDef gComboDefs[];
extern s32 gPadPressed[];
extern s32 gStickX[];
extern s32 gStickY[];
extern s32 gPrevStickX[];
extern s32 gPrevStickY[];
extern s32 gComboBeat;
extern ComboSlot gComboSlots[];
extern s32 D_80171A54;
extern s32 D_80171A70[];

/* Reads one player's stick and buttons and advances or resets their combo sequence. */
void updateComboInput(s32 player) {
    s32 phase;
    s32 *seq;
    s32 stickX;
    s32 stickY;
    s32 buttons;
    s32 i;

    phase = gComboBeat % 144;
    seq = getComboSequence(gComboSlots[player].type, D_80171A70[player], D_80171A54);
    stickX = gStickX[player];
    stickY = gStickY[player];
    if (abs(stickX) * 2 > abs(stickY)) {
        stickY = 0;
    }
    if (abs(stickX) < abs(stickY) * 2) {
        stickX = 0;
    }
    if (abs(stickX) < 10) {
        stickX = 0;
    }
    if (abs(stickY) < 10) {
        stickY = 0;
    }
    if (stickX > 20 && gPrevStickX[player] <= 20) {
        gPadPressed[player] |= 0x100;
    }
    if (stickX < -20 && gPrevStickX[player] >= -20) {
        gPadPressed[player] |= 0x200;
    }
    if (stickY > 20 && gPrevStickY[player] <= 20) {
        gPadPressed[player] |= 0x800;
    }
    if (stickY < -20 && gPrevStickY[player] >= -20) {
        gPadPressed[player] |= 0x400;
    }
    gPrevStickX[player] = stickX;
    gPrevStickY[player] = stickY;
    buttons = gPadPressed[player];
    if (buttons != 0) {
        if (buttons == seq[gComboSlots[player].step]) {
            gComboSlots[player].hit[gComboSlots[player].step] = 1;
            gComboSlots[player].flash[gComboSlots[player].step] = 0xFF;
            gComboSlots[player].step++;
            gComboSlots[player].done = checkComboWindow(player);
        } else {
            for (i = gComboSlots[player].step; i > 0; i--) {
                gComboSlots[player].hit[i] = 0;
                gComboSlots[player].flash[i] = 0x76;
            }
            gComboSlots[player].step = gComboDefs[gComboSlots[player].type].startStep;
        }
    }
    if (gComboSlots[player].done == 0 && phase >= 31 && phase < 36) {
        for (i = gComboSlots[player].step; i > 0; i--) {
            gComboSlots[player].hit[i] = 0;
            gComboSlots[player].flash[i] = 0x76;
        }
        gComboSlots[player].step = gComboDefs[gComboSlots[player].type].startStep;
    }
}
