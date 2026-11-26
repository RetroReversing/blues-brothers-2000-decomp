void func_8002A360(s32, s32);
s32 func_80082400(void);
extern s32 D_800B2FD0[];
extern u8 **D_800B37F8[];
extern s32 D_800B3838;
extern s32 D_800BD0E0[];
extern s32 D_80140148;

void func_8002ABCC(void) {
    s32 cur;
    s32 want;

    if (D_800B3838 != 0) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x2A);
        return;
    }
    cur = func_80082400();
    if (cur != -1) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x2B);
        return;
    }
    want = D_800B2FD0[(*(u8 **)((u8 *)D_800B37F8[D_800BD0E0[8]] + (D_800BD0E0[7] << 2)))[D_80140148]];
    if (want != cur) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, want);
    }
}
