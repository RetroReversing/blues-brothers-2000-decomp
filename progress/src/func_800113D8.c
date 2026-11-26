extern u8 D_800BD1F0[];

s32 func_800113D8(s32 arg0)
{
    s32 i;
    s32 p;
    s32 base;

    i = 0;
    p = (s32)D_800BD1F0;
    base = arg0 * 0xA;
    for (; i < 0xA; i++)
    {
        if (*(u8 *)(base + i + p) == 0)
        {
            return 0;
        }
    }
    return 1;
}
