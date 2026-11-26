/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
s32 debugPrintf();
extern char D_80007CA0[];
extern s32 D_800B7690;
extern s32 D_801407C8;

s32 func_800487A4(s32 arg0, s32 arg1) {
    char *var_v1;
    s32 var_a1;
    s32 var_s0;
    s32 var_v0;

    var_a1 = arg1;
    var_s0 = 0;
    if (D_800B7690 > 0) {
        var_a1 = D_800B7690;
        var_v1 = &D_801407C8;
loop_2:
        if (arg0 != *(s32 *)var_v1) {
            var_s0 += 1;
            var_v1 += 8;
            if (var_s0 >= var_a1) {

            } else {
                goto loop_2;
            }
        }
        var_v0 = var_s0;
        if (var_s0 >= D_800B7690) {
            goto block_6;
        }
    } else {
block_6:
        debugPrintf(D_80007CA0, var_a1);
        var_v0 = var_s0;
    }
    return var_s0;
}
