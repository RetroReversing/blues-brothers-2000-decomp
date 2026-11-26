extern s32 D_800AE024[];
s32 func_8002505C(s32 x) {
    s32 sign;
    u32 step;
    s32 i; s32 v;
    sign = 0x80;
    if (x < 0) {
        x = -x;
        sign = -0x80;
    }
    if (x < D_800AE024[1]) return 0;
    step = 0x10;
    if (D_800AE024[63] < x) return sign << 6;
    i = 0x20;
loop:
    
    if (x < D_800AE024[i]) {
        i -= step;
        step >>= 1;
        goto loop;
    }
    do { v = D_800AE024[i + 1]; } while (0);
    if (v < x) {
        i += step;
        step >>= 1;
        goto loop;
    }
    return i * sign;
}
