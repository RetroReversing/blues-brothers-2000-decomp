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

void func_8007DEA0(void) {
    func_80023A74(0x2A, 0xCCE);
    func_80023A98(0x1A7, 0xCD0, 0);
    func_80023A98(0x1A8, 0xCD4, 0);
    func_80023A98(0x1A9, 0xCCF, 0);
    func_80023A98(0x1AA, 0xCD5, 1);
    func_80023A98(0x1AB, 0xCD2, 0);
    func_80023A98(0x1AC, 0xCD3, 0);
    func_80023A98(0x1AD, 0xCD1, 1);
    func_80023A74(0x77, 0xCC6);
    func_80023A98(0x1AE, 0xCC8, 0);
    func_80023A98(0x1AF, 0xCCC, 0);
    func_80023A98(0x1B0, 0xCC7, 0);
    func_80023A98(0x1B1, 0xCCD, 1);
    func_80023A98(0x1B2, 0xCCA, 0);
    func_80023A98(0x1B3, 0xCCB, 0);
    func_80023A98(0x1B4, 0xCC9, 1);
}
