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

void func_80057FC0(void) {
    func_80023A74(0x33, 0x3B7);
    func_80023A98(0xC0, 0x3B6, 0);
    func_80023A98(0xC1, 0x3BB, 0);
    func_80023A98(0xC2, 0x3B4, 0);
    func_80023A98(0xC3, 0x3B5, 0);
    func_80023A98(0xC4, 0x3B8, 0);
    func_80023A98(0xC5, 0x3B9, 0);
}
