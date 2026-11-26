extern u8 D_800B2904[];
extern u8 D_800B2A04[];

s32 func_80028694(u8 *s) {
    s32 i;
    s32 w;

    i = 0;
    w = 0;
    for (;;) {
        u8 c = s[i];

        if (c == 0) {
            return w;
        }
        if (c == '~') {
            s[i] = ' ';
            return w;
        }
        if (c == ' ') {
            return w;
        }
        i++;
        c = D_800B2904[c];
        w += 13 - D_800B2A04[c - 0x20];
    }
}
