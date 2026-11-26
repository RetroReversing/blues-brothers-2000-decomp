/* identical to initViManagerContexts in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8003F210 in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
typedef struct { s32 unk0; s32 unk4; } R8;
typedef struct { s16 unk0; s16 pad2; s32 pad4; R8 *unk8; s32 unkC; } V;
extern s32 D_80000300;
extern u8 D_800BB550[];
extern s16 D_800BB552;
extern s32 D_800BB554;
extern s16 D_800BB582;
extern s32 D_800BB584;
extern V *D_800BB588;
extern u8 *D_800BB5B0;
extern V *D_800BB5B4;
extern u8 D_800BC380[];
extern u8 D_800BC3D0[];
extern u8 D_800BC330[];
extern s32 __osViSwapContext(void);
extern void bzero(void *, s32);

/* Zeroes the VI context buffer, picks the per-TV-type context table, and resets the VI controller. */ void initViManagerContexts(void) {
    bzero(D_800BB550, 0x60);
    D_800BB5B0 = D_800BB550;
    D_800BB5B4 = (V *)(D_800BB550 + 0x30);
    D_800BB582 = 1;
    D_800BB552 = 1;
    D_800BB584 = 0x80000000;
    D_800BB554 = 0x80000000;
    if (D_80000300 == 0) {
        D_800BB588 = (V *)D_800BC380;
    } else if (D_80000300 == 2) {
        D_800BB588 = (V *)D_800BC3D0;
    } else {
        D_800BB588 = (V *)D_800BC330;
    }
    D_800BB5B4->unk0 = 0x20;
    D_800BB5B4->unkC = D_800BB5B4->unk8->unk4;
    while (*(volatile u32 *)0xA4400010 >= 0xB) {}
    *(volatile u32 *)0xA4400000 = 0;
    __osViSwapContext();
}
