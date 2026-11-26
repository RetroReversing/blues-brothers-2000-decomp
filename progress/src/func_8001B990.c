s32 func_800899DC(char *);
extern char D_80000C44[];
extern s32 D_800BD0B8[];

s32 func_8001B990(s32 arg0, u32 arg1) {
    s32 mask;
    u32 idx;
    s32 ret;

    if (arg1 >= 0x44) {
        return func_800899DC(D_80000C44);
    }
    mask = 1 << (arg1 & 0x1F);
    idx = arg1 >> 5;
    if (arg0 == 0x100) {
        return (D_800BD0B8[idx] & mask) != 0;
    }
    if (arg0 == 0x200) {
        D_800BD0B8[idx] |= mask;
        return 1;
    }
    if (arg0 == 0x300) {
        D_800BD0B8[idx] &= ~mask;
        return 1;
    }
}
