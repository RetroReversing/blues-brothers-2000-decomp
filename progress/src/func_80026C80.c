u8 *func_80026C80(u8 *arg0, u8 *arg1) {
    u8 *var_v1;
    u8 temp_v0;

    var_v1 = arg0;
    do {
    } while (*var_v1++ != 0);
    var_v1 -= 1;
    do {
        temp_v0 = *arg1;
        arg1 += 1;
        *var_v1 = temp_v0;
        var_v1 += 1;
    } while (temp_v0 & 0xFF);
    return arg0;
}
