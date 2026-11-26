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

void func_8003B3F4(void) {
    func_80023A74(2, 0x683);
    func_80023A74(1, 0x675);
    func_80023A98(5, 0x693, 0);
    func_80023A98(2, 0x6B0, 0);
    func_80023A98(4, 0x6A2, 0);
    func_80023A98(1, 0x691, 0);
    func_80023A98(6, 0x6AA, 0);
    func_80023A98(0xB, 0x669, 0);
    func_80023A98(0xC, 0x6A4, 1);
    func_80023A98(0xD, 0x697, 0);
    func_80023A98(0x13, 0x697, 0);
    func_80023A98(0xE, 0x698, 0);
    func_80023A98(0xF, 0x699, 0);
    func_80023A98(3, 0x692, 0);
    func_80023A98(0x10, 0x688, 0);
    func_80023A98(0x11, 0x6A1, 1);
    func_80023A98(0x12, 0x6A9, 0);
    func_80023A98(0x14, 0x6A8, 1);
    func_80023A98(0x15, 0x68E, 1);
    func_80023A98(0x16, 0x66B, 1);
    func_80023A98(0x17, 0x6AF, 1);
    func_80023A98(0x18, 0x66A, 1);
    func_80023A98(0x1A, 0x667, 1);
    func_80023A98(0x1B, 0x69F, 1);
    func_80023A98(0x1C, 0x690, 1);
    func_80023A98(0x1D, 0x6A6, 0);
    func_80023A98(0x1F, 0x69B, 1);
    func_80023A98(0x22, 0x69E, 0);
    func_80023A98(0x2A, 0x68B, 0);
    func_80023A98(0x2B, 0x68C, 0);
    func_80023A98(0x2C, 0x68D, 0);
    func_80023A98(0x1E, 0x6A0, 1);
    func_80023A98(0x2D, 0x6AD, 0);
    func_80023A98(0x23, 0x695, 0);
    func_80023A98(0x28, 0x67C, 0);
    func_80023A98(0x29, 0x67B, 0);
    func_80023A98(0x24, 0x671, 0);
    func_80023A98(0x25, 0x672, 0);
    func_80023A98(0x26, 0x673, 0);
}
