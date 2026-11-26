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

M2C_UNK func_80023A74(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80023A98(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern s32 D_800B81D0;

void func_8005C7CC(void) {
    M2C_UNK var_a0;
    M2C_UNK var_a1;

    func_80023A74(0xD, 0xB25);
    var_a0 = 0x32;
    if (D_800B81D0 == 0) {
        func_80023A98(0x32, 0xB29, 0);
        func_80023A98(0x33, 0xB26, 1);
        func_80023A98(0x34, 0xB27, 1);
        func_80023A98(0x35, 0xB28, 1);
        func_80023A98(0x36, 0xB2B, 0);
        var_a0 = 0x37;
        var_a1 = 0xB2A;
    } else {
        var_a1 = 0xB29;
    }
    func_80023A98(var_a0, var_a1, 0);
}
