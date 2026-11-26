/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
extern s32 gPadPressed;
extern s32 D_80140028;

void func_80036FB8(s32 arg0, s32 arg1) {
    if ((arg1 & 1) && (gPadPressed & 8)) {
        D_80140028 = 8;
    }
    if ((arg1 & 2) && (gPadPressed & 4)) {
        D_80140028 = 8;
    }
    if ((arg1 & 4) && (gPadPressed & 2)) {
        D_80140028 = 8;
    }
    if ((arg1 & 8) && (gPadPressed & 1)) {
        D_80140028 = 8;
    }
}
