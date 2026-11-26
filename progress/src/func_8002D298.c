s32 func_80024380(s32);
int abs(int);
s32 func_8002D298(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = arg0 - arg1;
    temp_v0 = func_80024380(var_s0);
    var_s0 = abs(var_s0);
    if (arg2 < var_s0) {
        var_s0 = arg2;
    }
    return arg1 + (temp_v0 * var_s0);
}
