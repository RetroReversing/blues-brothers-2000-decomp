void func_8002A360(s32, s32);
s32 func_800141B8(s32);

s32 func_80014234(s32 arg0) {
    s32 i;
    s32 r;
    s32 n = 5;

    func_8002A360(0xC, 0x80);
    func_8002A360(8, 0xA7);
    for (i = 0; i < n; i++) {
        r = func_800141B8(arg0);
    }
    return r;
}
