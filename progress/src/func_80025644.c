extern s32 *D_80106A38;
extern s32 D_80106A3C;

s32 func_80025644(void) {
    s32 *p;
    s32 n;
    s32 count;

    count = 0;
    p = D_80106A38;
    D_80106A3C = 0;
for (;;)
{
    n = *p;
    if (n >= 0) {
        if (D_80106A3C < n) {
            D_80106A3C = n;
        }
        n >>= 2;
        p = (s32 *)((u8 *)(p + n) + 8);
        count++;
        continue;
    }
break;
}
    if (n == -2) {
        return count;
    }
    return -1;
}
