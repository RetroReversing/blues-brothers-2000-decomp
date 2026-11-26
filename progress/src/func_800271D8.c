extern void (*D_800B2B08)(u8);

void func_800271D8(s32 n) {
    u8 buf[20];
    s32 i;

    if (n < 0) {
        D_800B2B08('-');
        n = -n;
    }
    for (i = 0; i < 20; i++) {
        buf[i] = n % 10;
        n /= 10;
        if (n == 0) {
            break;
        }
    }
    for (n = i; n >= 0;) {
        D_800B2B08(buf[n--] + '0');
    }
}
