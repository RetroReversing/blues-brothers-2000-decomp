s32 func_8000B6D0(u8 *arg0)
{
    u8 *p;

    p = arg0 + 1;
    if (*arg0 != 0) {
        do {
        } while (*p++ != 0);
    }
    return p - arg0;
}
