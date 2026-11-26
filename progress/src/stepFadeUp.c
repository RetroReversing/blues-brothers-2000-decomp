/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
void stepFadeUp(s32 *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v1 = *arg0;
    temp_v0 = temp_v1 + 0x10;
    if ((temp_v1 >= 0xFF) || (*arg0 = (temp_v1 + 0x10), (((temp_v1 + 0x10) < 0x100) == 0))) {
        *arg0 = 0xFF;
    }
}
