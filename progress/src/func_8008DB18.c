/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
s32 func_8008DAE4(s32);                             /* extern */
extern s32 D_8017B230;
extern s32 D_8017B234;

void func_8008DB18(s32 arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (arg0 == 0) {
        var_v0 = func_8008DAE4(D_8017B234);
    }
    if (var_v0 != 0) {
        D_8017B230 = arg0;
    }
}
