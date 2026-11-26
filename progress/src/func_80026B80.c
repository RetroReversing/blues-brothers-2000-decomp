void *func_80026B80(void *dst, void *src, s32 n) {
    u8 *d;
    u8 *s;
    s32 i;

    d = dst;
    s = src;
    if (d == s) {
        return dst;
    }
    if (s < d) {
        d += n;
        s += n;
        for (i = 0; i < n; i++) {
            *--d = *--s;
        }
    } else {
        for (i = 0; i < n; i++) {
            *d++ = *s++;
        }
    }
    return dst;
}
