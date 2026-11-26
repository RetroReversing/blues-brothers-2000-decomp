/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
s32 func_80027010(u8);                              /* extern */

s32 func_80026CB4(u8 *arg0, u8 *arg1) {
    s32 temp_s0;
    u8 temp_v0;
    u8 *var_s1;
    u8 *var_s2;

    var_s1 = arg0;
    var_s2 = arg1;
loop_1:
    if (*var_s1 == 0) {
        return 0;
    }
    temp_s0 = func_80027010(*var_s1);
    temp_v0 = func_80027010(*var_s2) & 0xFF;
    if ((temp_s0 & 0xFF) != temp_v0) {
        return (temp_s0 & 0xFF) - temp_v0;
    }
    var_s1 += 1;
    var_s2 += 1;
    goto loop_1;
}
