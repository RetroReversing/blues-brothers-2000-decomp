extern s32 D_8010788C;
extern s32 D_80107654;
extern s32 D_80107890;
extern s32 D_8014AA98;
extern u8 D_800B2A04;
s32 strlen(const char *s);
s32 func_8000C43C(void);
void func_8002710C(s32 a, s32 b, s32 c, s32 d);
s32 func_80028694(u8 *p);
void func_800289BC(s32 c, s32 flag);

void func_80028FF4(u8 *str, u8 *arg1)
{
    s32 skip;
    s32 saved;
    s32 i;
    s32 first;
    u8 *next;
    s32 w;
    s32 n;

    first = 1;
    w = 0x118;
    if (D_8014AA98 == 1) {
        w = 0xF0;
    }
    if (func_8000C43C() == 0x17) {
        D_8010788C += 0x12;
    }
    n = strlen((char *)str);
    skip = *(s32 *)(arg1 + 0x64) / 8;
    skip = n - skip;
    saved = D_8010788C;
    i = 0;
    while (*str != 0) {
        i++;
        if (i <= skip) {
            func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
            D_80107654 = 0;
        } else {
            func_8002710C(0xFF, 0xFF, 0xFF, 0);
            D_80107654 = 1;
        }
        if (*str == '~') {
            *str = ' ';
        }
        if (*str == ' ') {
            if (D_8010788C == saved) {
                str++;
                continue;
            }
            next = str + 1;
            if (w < D_8010788C + func_80028694(next) - D_800B2A04 + 0xD) {
                str = next;
                D_8010788C = saved;
                D_80107890 += 15;
                continue;
            }
        }
        func_800289BC(*str, first);
        if (first) {
            first = 0;
        }
        str++;
    }
}
