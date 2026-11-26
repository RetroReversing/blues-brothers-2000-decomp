/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
extern s32 D_800B7DE0;
s32 func_8004F984(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_a2;
    s32 var_a3;
    s32 bit;

    var_a0 = arg0;
    var_a3 = 1;
    var_a2 = 0;
    do {
        bit = arg1 & var_a3;
        var_a3 *= 2;
        if (bit != 0) {
            var_a0 += *(&D_800B7DE0 + var_a2) * 4;
        }
        var_a2 += 1;
    } while (var_a2 < 0x20);
    return var_a0;
}
