void debugPrintf();
extern s32 D_80007880;
extern s32 D_80007898;
extern s32 D_800078B0;

void func_800413C0(s32 arg0) {
    if (arg0 >= 0) {
        debugPrintf(&D_80007880, arg0, &D_80007898);
    }
    if ((u32) arg0 > 0x80400000U) {
        debugPrintf(&D_800078B0, arg0);
    }
}
