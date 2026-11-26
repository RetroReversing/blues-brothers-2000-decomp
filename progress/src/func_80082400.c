/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
s32 cameraGetMode();                                /* extern */

s32 func_80082400(void) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = -1;
    temp_v0 = cameraGetMode();
    switch (temp_v0) {
    case 0xA:
        var_s0 = 0;
        break;
    case 0xB:
        var_s0 = 1;
        break;
    case 0x1A:
        var_s0 = 2;
        break;
    case 0x1B:
        var_s0 = 3;
        break;
    case 0x26:
        var_s0 = 4;
        break;
    case 0x27:
        var_s0 = 5;
        break;
    case 0x35:
        var_s0 = 6;
        break;
    case 0x39:
        var_s0 = 7;
        break;
    case 0x3A:
        var_s0 = 8;
        break;
    }
    return var_s0;
}
