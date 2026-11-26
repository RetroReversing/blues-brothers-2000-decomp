void func_80090D28(u8 *arg0, u8 *arg1, s32 arg2) {
    if (arg1 < arg0) {
        arg0 += arg2;
        arg1 += arg2;
        while (--arg2 != -1) {
            *--arg0 = *--arg1;
        }
    } else {
        while (--arg2 != -1) {
            *arg0++ = *arg1++;
        }
    }
}

