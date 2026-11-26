/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
extern s32 D_80107030;
extern s32 D_80107040;
extern s32 D_80107070;
extern s32 D_80107080;
extern s32 D_80107090;
extern s32 gPadPressed;
extern u8 D_801071F0;
extern s32 D_801073B0;
extern s32 gStickY;
extern s32 D_80107600;
extern s32 D_80107610;

void func_80025D34(void) {
    s32 var_a2;

    var_a2 = 0;
    do {
        if (((s32) D_801071F0 >> var_a2) & 1) {
            *(&D_80107040 + var_a2) = *(&D_80107080 + var_a2);
            *(&D_801073B0 + var_a2) = *(&D_80107600 + var_a2);
            *(&gStickY + var_a2) = *(&D_80107610 + var_a2);
            *(&gPadPressed + var_a2) = *(&D_80107030 + var_a2);
            *(&D_80107090 + var_a2) = *(&D_80107040 + var_a2);
            *(&D_80107080 + var_a2) = *(&D_80107070 + var_a2);
            *(&D_80107030 + var_a2) = 0;
        }
        var_a2 += 1;
    } while (var_a2 < 4);
}
