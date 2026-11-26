typedef struct { s32 a; s32 b; s32 c; } Rec12;
s32 func_800242A8();
s32 func_800253A0();
extern s32 D_800B8380;
extern s32 D_800B8384[];
extern s32 D_800B83B0;
extern Rec12 D_800F6188[];
extern s32 *D_801700B0;

void func_80072CA8(void) {
    s32 i;

    D_801700B0 = func_800253A0((D_800B8380 * 4) | 1);
    for (i = 0; i < D_800B8380; i++) {
        D_801700B0[i] = D_800B83B0++ + 0x1D6;
        func_800242A8(D_801700B0[i], D_800B8384[i], 0);
        D_800F6188[D_801700B0[i]].b += 0x32;
    }
}
