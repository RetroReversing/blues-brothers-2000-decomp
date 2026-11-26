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

void func_800784C4(void) {
    func_80023A74(0x4E, 0x78D);
    func_80023A74(0x79, 0x78E);
    func_80023A98(0x11D, 0x790, 0);
    func_80023A98(0x11E, 0x791, 1);
    func_80023A98(0x11F, 0x792, 1);
    func_80023A74(0x69, 0x793);
    func_80023A98(0x120, 0x794, 0);
    func_80023A98(0x121, 0x795, 1);
    func_80023A98(0x122, 0x796, 1);
}
