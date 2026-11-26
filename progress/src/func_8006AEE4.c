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

void func_8006AEE4(void) {
    func_80023A74(0x2F, 0x2A8);
    func_80023A98(0xB3, 0x2AA, 0);
    func_80023A98(0xB4, 0x2AB, 0);
    func_80023A98(0xB5, 0x2A9, 0);
    func_80023A98(0xB6, 0x2AF, 0);
    func_80023A98(0xB7, 0x2B1, 0);
    func_80023A98(0xB8, 0x2AE, 0);
    func_80023A98(0xB9, 0x2B0, 0);
}
