s32 func_80026B50(u8 *arg0, u8 *arg1) {
    if (*arg0 != *arg1) {
        return *arg0 - *arg1;
    }
    if (*arg0 == 0) {
        return 0;
    }
    return func_80026B50(arg0 + 1, arg1 + 1);
}
