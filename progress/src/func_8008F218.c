/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
extern f32 D_80009D88;
extern s32 D_8017B224;

s32 func_8008F218(s32 arg0) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;

    var_a2 = 0;
    do {
        temp_a1 = D_8017B224 * 2;
        temp_v0 = D_8017B224 & 0x48000000;
        temp_v1 = (temp_v0 == 0x48000000) | (temp_v0 == 0x08000000);
        D_8017B224 = temp_a1;
        var_a2 += 1;
        if (temp_v1 != 0) {
            D_8017B224 = temp_a1 | 1;
        }
    } while (var_a2 < 8);
    return (s32) ((f32) arg0 * (((f32) D_8017B224 / D_80009D88) / D_80009D88));
}
