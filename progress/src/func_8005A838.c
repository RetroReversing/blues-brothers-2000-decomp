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

void func_8005A838(void) {
    M2C_UNK var_a0;
    M2C_UNK var_a1;

    func_80023A74(0x2D, 0x30E);
    var_a0 = 0x6C;
    if (D_800B81D0 == 0) {
        func_80023A74(0x3B, 0x307);
        func_80023A98(0x6B, 0x30C, 0);
        func_80023A98(0x6C, 0x30D, 0);
        func_80023A98(0x6D, 0x311, 0);
        func_80023A98(0x6E, 0x308, 0);
        func_80023A98(0x6F, 0x30B, 0);
        func_80023A98(0x70, 0x309, 0);
        func_80023A98(0x71, 0x30A, 0);
        func_80023A98(0x72, 0x30F, 0);
        var_a0 = 0x73;
        var_a1 = 0x310;
    } else {
        var_a1 = 0x30D;
    }
    func_80023A98(var_a0, var_a1, 0);
}
