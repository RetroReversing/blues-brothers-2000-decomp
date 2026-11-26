/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
u8 *func_80026C4C(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 var_a2;
    u8 *var_a1;
    u8 *var_v1;
    u8 temp_v0;

    var_a1 = arg1;
    var_a2 = arg2;
    var_v1 = arg0;
loop_1:
    temp_v0 = *var_a1;
    var_a1 += 1;
    *var_v1 = temp_v0;
    var_v1 += 1;
    if (temp_v0 & 0xFF) {
        var_a2 -= 1;
        if (var_a2 == 0) {
            *var_v1 = 0;
        } else {
            goto loop_1;
        }
    }
    return arg0;
}
