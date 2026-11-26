u64 osGetTime(void);

u32 func_8008990C(u64 *arg0) {
    u64 prev;
    u64 now;
    u32 ret;

    if (arg0 == NULL) {
        ret = osGetTime() / 46875;
    } else {
        prev = *arg0;
        now = osGetTime() * 64 / 3;
        *arg0 = now;
        ret = (now - prev) / 1000000;
    }
    return ret;
}
