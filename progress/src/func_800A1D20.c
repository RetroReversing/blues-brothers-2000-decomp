extern u32 D_80000308;

s32 func_800A1D20(u32 devAddr, u32 *data) {
    register u32 stat;

    while (stat = *(volatile u32 *)0xA4600010, stat & 3) {
    }
    *data = *(volatile u32 *)((D_80000308 | devAddr) | 0xA0000000);
    return 0;
}
