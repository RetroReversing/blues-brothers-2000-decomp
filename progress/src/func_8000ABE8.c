void func_8000ABE8(u32 *arg0, u32 arg1) {
    register u32 stat;

    stat = *(volatile u32 *)0xA4600010;
    while (stat & 3) {
        stat = *(volatile u32 *)0xA4600010;
    }
    *arg0 = arg1;
}
