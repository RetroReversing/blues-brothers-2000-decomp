/* machine draft */
extern s32 *D_80106A38;
s32 func_800252D8(void) {
    s32 *var_a0;
    s32 var_a1;
    s32 var_v0;
    s32 var_v1;

    var_a0 = D_80106A38;
    var_v1 = *var_a0;
    var_a1 = 0;
    if (var_v1 > 0) {
        do {
            if (var_v1 & 1) {
                var_a1 += var_v1 & ~1;
            }
            var_v1 = var_v1 & ~1;
            var_a0 = &var_a0[(s32) (var_v1 + 8) >> 2];
            var_v1 = *var_a0;
        } while (var_v1 > 0);
    }
    return var_a1;
}
