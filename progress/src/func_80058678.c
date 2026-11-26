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

s32 func_8000C43C();                                /* extern */
M2C_UNK func_80023A74(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80023A98(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_80058678(void) {

    if (func_8000C43C() == 0x3C) {
        func_80023A74(0x12, 0x3AA);
    } else {
        func_80023A74(0x12, 0x3AB);
    }
    func_80023A98(0x7E, 0x3A7, 0);
    func_80023A98(0x77, 0x3A6, 0);
    func_80023A98(0x78, 0x3A7, 0);
    func_80023A98(0x79, 0x3A7, 0);
    func_80023A98(0x7A, 0x3A9, 0);
    func_80023A98(0x7B, 0x3A4, 0);
    func_80023A98(0x7D, 0x3A8, 0);
    func_80023A98(0x7C, 0x3A5, 0);
}
