extern s32 D_80171A38;
extern s32 D_80171A3C;
extern s32 D_80171A4C;
extern s32 D_801719A0;
extern s32 D_8017199C;
extern s32 D_801719DC;

s32 func_80081FA4(s32 arg0) {
    if (arg0 == 0x8000) {
        return D_80171A38;
    }
    if (arg0 == 0x4000) {
        return D_80171A3C;
    }
    if (arg0 == 0x800) {
        return D_80171A4C;
    }
    if (arg0 == 0x400) {
        return D_801719A0;
    }
    if (arg0 == 0x200) {
        return D_8017199C;
    }
    if (arg0 == 0x100) {
        return D_801719DC;
    }
    return -1;
}
