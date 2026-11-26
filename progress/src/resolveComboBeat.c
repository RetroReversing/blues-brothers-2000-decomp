typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x28 - 0x8];
} Unk801719E0_b;

typedef struct {
    u8 pad0[0x64];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    u8 pad74[0x80 - 0x74];
    s32 unk80;
    u8 pad84[0x9C - 0x84];
    void *unk9C;
    u8 padA0[0xB4 - 0xA0];
    s32 unkB4;
} Unk800826B4;

extern s32 gComboBeat;
extern s32 gCamSpeedScale;
extern Unk801719E0_b gComboSlots[];
extern s32 gComboActorA;
extern s32 gComboActorB;
extern volatile s32 gComboWinFlagsA[];
extern volatile s32 gComboWinFlagsB[];
extern volatile s32 D_80171988;
extern volatile s32 D_8017198C;
extern Unk800826B4 *gCameraRig;

s32 tickActorTimer(void *arg0);
s32 func_80082688(s32, s32);
void func_800836CC(void);
s32 randomRange(s32 arg0, s32 arg1);
void sendCommand(s32, s32);
void actorSetAnim(s32 arg0, s32 arg1, s32 arg2);
void func_80087160(s32);
void func_80082990(void);
void func_8008250C(void);
void func_80083870(void);

/* Resolves one combo beat: when the beat window hits, the side with more combo hits wins (or a coin flip breaks a tie), and the winner's animation and camera play. */
void resolveComboBeat(Unk800826B4 *comboActor) {
    s32 phase;

    gComboBeat += gCamSpeedScale;
    phase = gComboBeat % 144;
    if (tickActorTimer(comboActor) == 0) {
        return;
    }
    if (func_80082688(phase, 36) == 0) {
        return;
    }
    func_800836CC();
    comboActor->unk9C = func_80082990;
    if (gComboSlots[1].unk4 == gComboSlots[0].unk4) {
        if (randomRange(0, 100) >= 51) {
            gComboSlots[1].unk4++;
        } else {
            gComboSlots[0].unk4++;
        }
    }
    if (gComboSlots[0].unk4 > gComboSlots[1].unk4) {
        comboActor->unk64 = 400;
        comboActor->unk9C = func_8008250C;
        sendCommand(12, 0x80);
        sendCommand(8, 0x78);
        actorSetAnim(gComboActorA, 0x188, 0x100);
        actorSetAnim(gComboActorB, 0x199, 0x100);
        gComboWinFlagsA[comboActor->unk80] = 1;
        func_80087160(D_80171988);
        gCameraRig->unk9C = func_80083870;
        gCameraRig->unkB4 = 0;
        if (randomRange(0, 100) >= 51) {
            gCameraRig->unk70 = 2;
        } else {
            gCameraRig->unk70 = 4;
        }
    } else if (gComboSlots[0].unk4 < gComboSlots[1].unk4) {
        comboActor->unk64 = 400;
        comboActor->unk9C = func_8008250C;
        actorSetAnim(gComboActorA, 0x189, 0x100);
        actorSetAnim(gComboActorB, 0x198, 0x100);
        gComboWinFlagsB[comboActor->unk80] = 1;
        func_80087160(D_8017198C);
        if (randomRange(0, 100) >= 51) {
            gCameraRig->unk70 = 3;
        } else {
            gCameraRig->unk70 = 5;
        }
        gCameraRig->unk9C = func_80083870;
        gCameraRig->unkB4 = 0;
    } else {
        comboActor->unk64 = 400;
        comboActor->unk9C = func_8008250C;
        actorSetAnim(gComboActorA, 0x189, 0x100);
        actorSetAnim(gComboActorB, 0x198, 0x100);
        gComboWinFlagsB[comboActor->unk80] = 1;
    }
}
