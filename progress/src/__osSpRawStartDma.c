/* identical to func_80051590 in BATTLEZONE (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80194340 in BATMAN BEYOND RETURN (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800595B0 in BASSMASTERS2000 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800C3280 in AIDYN_CHRONICLES (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800634C0 in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800A92C0 in TWINE (local match library) (matched), with its names changed by decompdecomp */
s32 func_8009CBF0(void);
s32 osVirtualToPhysical(s32);

s32 __osSpRawStartDma(s32 direction, u32 spAddress, s32 dramAddress, u32 size) {
    volatile u32 *length;
    if (func_8009CBF0())
        return -1;
    *(volatile u32 *)0xA4040000 = spAddress;
    *(volatile u32 *)0xA4040004 = osVirtualToPhysical(dramAddress);
    switch (direction) {
        case 1: length = (volatile u32 *)0xA4040008; break;
        case 0: length = (volatile u32 *)0xA404000C; break;
    default: length = (volatile u32 *)0xA4040008; break;
        }
    *length = size - 1;
    return 0;
}
