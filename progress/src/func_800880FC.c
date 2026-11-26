/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

M2C_UNK func_80023A98(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_800880FC(s32 arg0, s32 arg1) {
    if (arg0 == 0) {
        func_80023A98(arg1, 0xCF1, 0);
        func_80023A98(arg1 + 5, 0xCE5, 0);
        func_80023A98(arg1 + 6, 0xCE9, 0);
        func_80023A98(arg1 + 3, 0xCEA, 0);
        func_80023A98(arg1 + 2, 0xCEB, 0);
        func_80023A98(arg1 + 0xC, 0xCEC, 0);
        func_80023A98(arg1 + 4, 0xCED, 0);
        func_80023A98(arg1 + 9, 0xCEE, 0);
        func_80023A98(arg1 + 0xA, 0xCEF, 0);
        func_80023A98(arg1 + 1, 0xCF0, 0);
        func_80023A98(arg1 + 0xB, 0xCE6, 0);
        func_80023A98(arg1 + 7, 0xCE7, 0);
        func_80023A98(arg1 + 8, 0xCE8, 0);
        func_80023A98(arg1 + 0xD, 0xCF4, 0);
        func_80023A98(arg1 + 0xE, 0xCF2, 0);
        func_80023A98(arg1 + 0xF, 0xCF3, 0);
    }
    if (arg0 == 1) {
        func_80023A98(arg1, 0xD38, 0);
        func_80023A98(arg1 + 5, 0xD2C, 0);
        func_80023A98(arg1 + 6, 0xD30, 0);
        func_80023A98(arg1 + 3, 0xD31, 0);
        func_80023A98(arg1 + 2, 0xD32, 0);
        func_80023A98(arg1 + 0xC, 0xD33, 0);
        func_80023A98(arg1 + 4, 0xD34, 0);
        func_80023A98(arg1 + 9, 0xD35, 0);
        func_80023A98(arg1 + 0xA, 0xD36, 0);
        func_80023A98(arg1 + 1, 0xD37, 0);
        func_80023A98(arg1 + 0xB, 0xD2D, 0);
        func_80023A98(arg1 + 7, 0xD2E, 0);
        func_80023A98(arg1 + 8, 0xD2F, 0);
        func_80023A98(arg1 + 0xD, 0xD3B, 0);
        func_80023A98(arg1 + 0xE, 0xD39, 0);
        func_80023A98(arg1 + 0xF, 0xD3A, 0);
    }
    if (arg0 == 2) {
        func_80023A98(arg1, 0xD07, 0);
        func_80023A98(arg1 + 5, 0xCFB, 0);
        func_80023A98(arg1 + 6, 0xCFF, 0);
        func_80023A98(arg1 + 3, 0xD00, 0);
        func_80023A98(arg1 + 2, 0xD01, 0);
        func_80023A98(arg1 + 0xC, 0xD02, 0);
        func_80023A98(arg1 + 4, 0xD03, 0);
        func_80023A98(arg1 + 9, 0xD04, 0);
        func_80023A98(arg1 + 0xA, 0xD05, 0);
        func_80023A98(arg1 + 1, 0xD06, 0);
        func_80023A98(arg1 + 0xB, 0xCFC, 0);
        func_80023A98(arg1 + 7, 0xCFD, 0);
        func_80023A98(arg1 + 8, 0xCFE, 0);
        func_80023A98(arg1 + 0xD, 0xD0A, 0);
        func_80023A98(arg1 + 0xE, 0xD08, 0);
        func_80023A98(arg1 + 0xF, 0xD09, 0);
    }
    if (arg0 == 3) {
        func_80023A98(arg1, 0xD28, 0);
        func_80023A98(arg1 + 5, 0xD1C, 0);
        func_80023A98(arg1 + 6, 0xD20, 0);
        func_80023A98(arg1 + 3, 0xD21, 0);
        func_80023A98(arg1 + 2, 0xD22, 0);
        func_80023A98(arg1 + 0xC, 0xD23, 0);
        func_80023A98(arg1 + 4, 0xD24, 0);
        func_80023A98(arg1 + 9, 0xD25, 0);
        func_80023A98(arg1 + 0xA, 0xD26, 0);
        func_80023A98(arg1 + 1, 0xD27, 0);
        func_80023A98(arg1 + 0xB, 0xD1D, 0);
        func_80023A98(arg1 + 7, 0xD1E, 0);
        func_80023A98(arg1 + 8, 0xD1F, 0);
        func_80023A98(arg1 + 0xD, 0xD2B, 0);
        func_80023A98(arg1 + 0xE, 0xD29, 0);
        func_80023A98(arg1 + 0xF, 0xD2A, 0);
    }
    if (arg0 == 4) {
        func_80023A98(arg1, 0xD18, 0);
        func_80023A98(arg1 + 5, 0xD0F, 0);
        func_80023A98(arg1 + 6, 0xD10, 0);
        func_80023A98(arg1 + 3, 0xD11, 0);
        func_80023A98(arg1 + 2, 0xD12, 0);
        func_80023A98(arg1 + 0xC, 0xD13, 0);
        func_80023A98(arg1 + 4, 0xD14, 0);
        func_80023A98(arg1 + 9, 0xD15, 0);
        func_80023A98(arg1 + 0xA, 0xD16, 0);
        func_80023A98(arg1 + 1, 0xD17, 0);
        func_80023A98(arg1 + 0xB, 0xD0C, 0);
        func_80023A98(arg1 + 7, 0xD0D, 0);
        func_80023A98(arg1 + 8, 0xD0E, 0);
        func_80023A98(arg1 + 0xD, 0xD1A, 0);
        func_80023A98(arg1 + 0xE, 0xD19, 0);
        func_80023A98(arg1 + 0xF, 0xD1B, 0);
    }
}
