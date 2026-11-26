s32 func_80026D28(u8 *arg0, u8 *arg1, s32 arg2) {
    for (; arg2 > 0; arg0++, arg1++, arg2--) {
        if (*arg0 != *arg1) {
            return *arg0 - *arg1;
        }
        if (*arg0 == 0) {
            return 0;
        }
    }
    return 0;
}
