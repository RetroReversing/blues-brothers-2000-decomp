s32 func_80024AE8(s32 arg0, s32 arg1) {
    s32 r;

    r = arg0;
    if (r < 0) {
        r = -r;
        r = r >> arg1;
        r = -r;
    } else {
        r = r >> arg1;
    }
    return r;
}
