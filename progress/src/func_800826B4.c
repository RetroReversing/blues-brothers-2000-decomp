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
extern s32 D_801719A8;
extern s32 D_801719AC;
extern volatile s32 D_801719B0[];
extern volatile s32 D_801719C8[];
extern volatile s32 D_80171988;
extern volatile s32 D_8017198C;
extern Unk800826B4 *D_800B3960;

s32 tickActorTimer(void *arg0);
s32 func_80082688(s32, s32);
void func_800836CC(void);
s32 randomRange(s32 arg0, s32 arg1);
void func_8002A360(s32, s32);
void actorSetAnim(s32 arg0, s32 arg1, s32 arg2);
void func_80087160(s32);
void func_80082990(void);
void func_8008250C(void);
void func_80083870(void);

void func_800826B4(Unk800826B4 *arg0) {
    s32 phase;

    gComboBeat += gCamSpeedScale;
    phase = gComboBeat % 144;
    if (tickActorTimer(arg0) == 0) {
        return;
    }
    if (func_80082688(phase, 36) == 0) {
        return;
    }
    func_800836CC();
    arg0->unk9C = func_80082990;
    if (gComboSlots[1].unk4 == gComboSlots[0].unk4) {
        if (randomRange(0, 100) >= 51) {
            gComboSlots[1].unk4++;
        } else {
            gComboSlots[0].unk4++;
        }
    }
    if (gComboSlots[0].unk4 > gComboSlots[1].unk4) {
        arg0->unk64 = 400;
        arg0->unk9C = func_8008250C;
        func_8002A360(12, 0x80);
        func_8002A360(8, 0x78);
        actorSetAnim(D_801719A8, 0x188, 0x100);
        actorSetAnim(D_801719AC, 0x199, 0x100);
        D_801719B0[arg0->unk80] = 1;
        func_80087160(D_80171988);
        D_800B3960->unk9C = func_80083870;
        D_800B3960->unkB4 = 0;
        if (randomRange(0, 100) >= 51) {
            D_800B3960->unk70 = 2;
        } else {
            D_800B3960->unk70 = 4;
        }
    } else if (gComboSlots[0].unk4 < gComboSlots[1].unk4) {
        arg0->unk64 = 400;
        arg0->unk9C = func_8008250C;
        actorSetAnim(D_801719A8, 0x189, 0x100);
        actorSetAnim(D_801719AC, 0x198, 0x100);
        D_801719C8[arg0->unk80] = 1;
        func_80087160(D_8017198C);
        if (randomRange(0, 100) >= 51) {
            D_800B3960->unk70 = 3;
        } else {
            D_800B3960->unk70 = 5;
        }
        D_800B3960->unk9C = func_80083870;
        D_800B3960->unkB4 = 0;
    } else {
        arg0->unk64 = 400;
        arg0->unk9C = func_8008250C;
        actorSetAnim(D_801719A8, 0x189, 0x100);
        actorSetAnim(D_801719AC, 0x198, 0x100);
        D_801719C8[arg0->unk80] = 1;
    }
}
