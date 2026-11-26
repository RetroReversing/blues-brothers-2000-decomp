extern char D_800AE1F0[];

void func_80026D6C(s32 arg0, char *buf, s32 base) {
    char tmp[16];
    s32 i;
    s32 neg = 0;
    s32 val = arg0;
    u32 u;
    char c;
    char *p;

    if (val == 0) {
        buf[0] = '0';
        buf[1] = 0;
        return;
    }
    if (base == 16) {
        u = val;
        i = 0;
        for (;;) { if (u != 0) { tmp[i] = D_800AE1F0[u & 0xF]; u >>= 4; i++; if (i >= 10) goto out; continue; } goto out; } out:
    } else {
        i = 0;
        if ((s32)val < 0) {
            val = abs(val);
            neg = 1;
        }
        for (;;) { if (val != 0) { tmp[i++] = D_800AE1F0[(s32)val % base]; val = (s32)val / base; if (i < 10) continue; } break; }
        if (neg) {
            *buf++ = '-';
        }
    }
    for (i--; i >= 0; i--) {
        *buf++ = tmp[i];
    }
    *buf = 0;
}
