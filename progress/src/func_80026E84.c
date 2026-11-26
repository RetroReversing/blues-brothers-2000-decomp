s32 func_8002D63C(s32, s32);
extern char D_800AE1F0[];

void func_80026E84(f64 val, char *out, s32 base, s32 prec) {
    char buf[16];
    s32 n;
    s32 i;
    s32 neg;

    neg = 0;
    n = val * func_8002D63C(10, prec);
    if (n == 0) {
        out[0] = '0';
        out[1] = 0;
        return;
    }
    if (n < 0) {
        n = -n;
        neg = 1;
    }
    for (i = 0; i < 12; i++) {
        if (i == prec) {
            buf[i] = '.';
        } else {
            buf[i] = D_800AE1F0[0];
        }
    }
    for (i = 0; i < 11; i++) {
        if (n == 0) {
            break;
        }
        if (i == prec) {
            buf[i] = '.';
        } else {
            buf[i] = D_800AE1F0[n % base];
            n /= base;
        }
    }
    if (neg) {
        *out++ = '-';
    }
    if (i < prec + 2) {
        i = prec + 2;
    }
    for (i--; i >= 0; i--) {
        *out++ = buf[i];
    }
    *out = 0;
}
