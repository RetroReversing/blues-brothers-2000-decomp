typedef struct {
    s32 state;
    u8 pad_4[0x8C];
    s32 f90;
    u8 pad_94[8];
    void (*f9C)();
    u8 pad_A0[0x30];
    s32 fD0;
} Player3C9AC;

extern Player3C9AC *D_800BD06C;
void func_800393F4();

s32 func_8003C9AC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (D_800BD06C->state != 3) {
        return 0;
    }
    if (D_800BD06C->f9C != func_800393F4) {
        return 0;
    }
    if (arg1 != 0 && D_800BD06C->fD0 == 0xB) {
        return 0;
    }
    if (arg2 != 0 && D_800BD06C->f90 == 0) {
        return 0;
    }
    if (arg3 != 0 && D_800BD06C->fD0 == 0x1A) {
        return 0;
    }
    return 1;
}
