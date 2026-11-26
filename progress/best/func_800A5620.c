/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
extern s32 D_A4040010;

s32 func_800A5620(void) {
    s32 var_v0;

    var_v0 = 0;
    if (!(D_A4040010 & 3)) {
        var_v0 = 1;
    }
    return var_v0;
}
