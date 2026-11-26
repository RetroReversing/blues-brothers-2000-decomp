extern u8 D_800BD0E0[];
s32 func_8000C43C(void) {
    u8 *p = D_800BD0E0;
    return (*(s32 *)(p + 0x20) * 0x10) | *(s32 *)(p + 0x1C);
}
