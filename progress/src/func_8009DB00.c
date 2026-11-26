s32 func_8009D8B0(void);
void osWritebackDCache(void *, s32);
void osInvalDCache(void *, s32);
u32 osVirtualToPhysical(void *);

s32 func_8009DB00(s32 direction, void *dramAddr)
{
    if (func_8009D8B0()) {
        return -1;
    }
    if (direction == 1) {
        osWritebackDCache(dramAddr, 64);
    }
    *(volatile u32 *)0xA4800000 = osVirtualToPhysical(dramAddr);
    if (direction == 0) {
        *(volatile u32 *)0xA4800004 = 0x1FC007C0;
    } else {
        *(volatile u32 *)0xA4800010 = 0x1FC007C0;
    }
    if (direction == 0) {
        osInvalDCache(dramAddr, 64);
    }
    return 0;
}
