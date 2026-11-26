extern s32 D_80171A38;
extern s32 D_80171A3C;
extern s32 D_80171A40;
extern s32 D_80171998;
extern s32 D_80171990;
extern s32 D_801719A4;

s32 func_80081F0C(s32 arg0) {
    if (arg0 == 0x8000) {
        return D_80171A38;
    }
    if (arg0 == 0x4000) {
        return D_80171A3C;
    }
    if (arg0 == 0x800) {
        return D_80171A40;
    }
    if (arg0 == 0x400) {
        return D_80171998;
    }
    if (arg0 == 0x200) {
        return D_80171990;
    }
    if (arg0 == 0x100) {
        return D_801719A4;
    }
    return -1;
}
