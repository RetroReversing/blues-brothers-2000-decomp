/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
s32 func_800263F4();
s32 func_8002642C();
s32 func_80026780();
s32 func_80026848();
s32 osPfsChecker();
extern s32 gPakInitWarn;
extern char D_80107210[];

s32 func_80026370(s32 arg0) {
    func_800263F4();
    osPfsChecker((arg0 * 0x68) + D_80107210);
    func_8002642C();
    func_800263F4();
    func_80026848(1);
    func_8002642C();
    if (gPakInitWarn != 0) {
        return 1;
    }
    func_80026780();
    return gPakInitWarn != 0;
}
