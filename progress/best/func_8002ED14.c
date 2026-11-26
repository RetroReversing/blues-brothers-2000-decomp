/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
/* Warning: missing "jr $ra" in last block of func_8002ED14 (initial). */

s32 func_8002ED14(void) {
    s32 saved_reg_s0;
    s32 saved_reg_s2;
    *(s32 *)saved_reg_s0 = 0;
    return (saved_reg_s2 + 1) < 2;
}
