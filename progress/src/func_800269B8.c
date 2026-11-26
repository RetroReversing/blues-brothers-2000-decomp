void func_80026C04(void *, s32, s32);
char *strchr(char *, s32);
extern char D_800AE1B0[];
extern char D_801070B0[];

char *func_800269B8(u8 *s) {
    char *p;
    char *r; char v;
    p = D_801070B0;
    func_80026C04(p, 0, 0x100);
    for (;;) {
        u8 t = *s++; u8 c;
        if (t == 0) { *p = 0; break; }
        c = t;
        if ((u8)(c - 'a') < 26) c -= 0x20;
        r = strchr(D_800AE1B0, c);
        if (r != 0) {
            v = (r - D_800AE1B0) + 0xF;
        } else {
            v = 0x30;
        }
        *p = v;
        p++;
        *p = 0;
    }
    return D_801070B0;
}
