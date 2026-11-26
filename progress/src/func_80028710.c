void func_8002854C(u8, s32);
u8 *func_8002856C(u8 *, s32);
s32 func_80028610(u8 *);
extern s32 D_8010788C;
extern s32 D_80107890;
extern s32 D_8010789C;

void func_80028710(u8 *s) {
    s32 first;
    s32 cx;
    s32 tall;
    s32 w;
    u8 *brk;
    u8 c;

    first = 1;
    tall = 0;
    D_8010788C = cx = 160;
    D_80107890 = D_8010789C;
    w = func_80028610(s);
    if (w > 280) {
        brk = func_8002856C(s, 280);
        *brk = 0;
        D_8010788C = cx - func_80028610(s) / 2;
        for (;;) {
            u8 *q;

            c = *s++;

            if (c == 0) {
                break;
            }
            func_8002854C(c, first);
            first = 0;
        }
        *brk = ' ';
        s = brk + 1;
        w = func_80028610(s);
        D_8010788C = cx;
        D_8010789C += 14;
    }
    D_80107890 = D_8010789C;
    D_8010788C -= w / 2;
    for (;;) {
        u8 *q;

            c = *s++;

        if (c == 0) {
            break;
        }
        if (c == '.') {
            tall = 1;
        }
        if (c == '?') {
            tall = 1;
        }
        if (c == '!') {
            tall = 1;
        }
        func_8002854C(c, first);
        first = 0;
    }
    D_8010789C += 14;
    if (tall) {
        D_8010789C += 10;
    }
}
