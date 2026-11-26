extern s32 gTextPenX;
extern s32 D_80107654;
extern s32 gTextPenY;
s32 strlen(const char *s);
void setTextColor(s32 a, s32 b, s32 c, s32 d);
s32 func_80028694(u8 *p);
void drawFontChar(s32 c, s32 flag);

void func_80029360(u8 *str, u8 *arg1)
{
    s32 skip;
    s32 saved;
    s32 i;
    s32 first;
    u8 *next;
    s32 w;
    s32 n;

    n = strlen((char *)str);
    first = 1;
    skip = *(s32 *)(arg1 + 0x64) / 8;
    skip = n - skip;
    saved = gTextPenX;
    i = 0;
    while (*str != 0) {
        i++;
        if (i <= skip) {
            setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
            D_80107654 = 0;
        } else {
            setTextColor(0xFF, 0xFF, 0xFF, 0);
            D_80107654 = 1;
        }
        if (*str == '~') {
            *str = ' ';
        }
        if (*str == ' ') {
            if (gTextPenX == saved) {
                str++;
                continue;
            }
            next = str + 1;
            w = 0x118;
            if (w < gTextPenX + func_80028694(next)) {
                str = next;
                gTextPenX = saved;
                gTextPenY += 15;
                continue;
            }
        }
        drawFontChar(*str, first);
        if (first) {
            first = 0;
        }
        str++;
    }
}
