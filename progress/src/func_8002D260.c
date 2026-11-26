/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
s32 func_8002D260(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0 & 0xFFFF;
    if (var_a0 > 0x7FFF) {
        var_a0 += 0xFFFF0000;
    }
    return var_a0;
}
