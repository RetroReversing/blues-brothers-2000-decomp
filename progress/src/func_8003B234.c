/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
s32 func_80023A74();
s32 func_80023A98();
extern char D_800B4D10[];

void func_8003B234(s32 arg0) {
    char *__base_D_800B4D10;
    char *var_s1;
    s32 var_s0;
    s32 var_s2;

    var_s2 = 2;
    var_s0 = 1;
    __base_D_800B4D10 = D_800B4D10;
    var_s1 = __base_D_800B4D10 + 4;
    do {
        if (arg0 & var_s2) {
            func_80023A74(var_s0 + 2, *(s32 *)var_s1);
        }
        var_s2 *= 2;
        var_s0 += 1;
        var_s1 += 4;
    } while (var_s0 < 7);
    if (arg0 & 4) {
        func_80023A98(0x2E, 0x67F, 0);
        func_80023A98(0x2F, 0x680, 0);
    }
    if (arg0 & 0x40) {
        func_80023A98(0x19B, 0x67A, 0);
    }
    if (arg0 == 0x100) {
        func_80023A98(0x16B, 0xCF1, 0);
        func_80023A98(0x16C, 0xCF0, 0);
        func_80023A98(0x16D, 0xCEB, 0);
        func_80023A98(0x16E, 0xCEA, 0);
        func_80023A98(0x16F, 0xCED, 0);
        func_80023A98(0x170, 0xCE5, 0);
        func_80023A98(0x172, 0xCE7, 0);
        func_80023A98(0x176, 0xCE6, 0);
        func_80023A98(0x173, 0xCE8, 0);
        func_80023A98(0x174, 0xCEE, 0);
        func_80023A98(0x175, 0xCEF, 0);
        func_80023A98(0x171, 0xCE9, 0);
        func_80023A98(0x177, 0xCEC, 0);
        func_80023A98(0x178, 0xCF4, 0);
        func_80023A98(0x179, 0xCF2, 0);
        func_80023A98(0x17A, 0xCF3, 0);
    }
}
