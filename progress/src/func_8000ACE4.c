u32 func_8000AC20(u32);
u8 func_8000ACA4(u32);

void func_8000ACE4(u32 src, u8 *dst, u32 len) {
    u32 w;

    while (len != 0 && (src & 3)) {
        *dst++ = func_8000ACA4(src++);
        len--;
    }
    while (len >= 4) {
        w = func_8000AC20(src);
        *dst++ = w >> 24;
        *dst++ = w >> 16;
        *dst++ = w >> 8;
        *dst++ = w;
        src += 4;
        len -= 4;
    }
    while (len != 0) {
        *dst++ = func_8000ACA4(src++);
        len--;
    }
}
