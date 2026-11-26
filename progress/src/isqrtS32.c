s32 isqrtS32(s32 arg0) {
    if (arg0 < 0) {
        arg0 = 0x7FFFFFFF;
    }
    return sqrtf(arg0);
}
