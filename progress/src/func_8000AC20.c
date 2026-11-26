s32 func_8000AC20(s32 *arg0)
{
    volatile s32 *reg;

    if (*((volatile s32 *) 0xA4600010) & 3) {
        reg = (volatile s32 *) 0xA4600010;
        do {
        } while (*reg & 3);
    }
    return *arg0;
}
