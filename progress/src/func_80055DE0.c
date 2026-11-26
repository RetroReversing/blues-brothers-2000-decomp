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

void func_80055DE0(void) {
    func_80023A74(0x1E, 0x64C);
    func_80023A98(0x8B, 0x647, 0);
    func_80023A98(0x8C, 0x64B, 0);
    func_80023A98(0x8D, 0x649, 0);
    func_80023A98(0x8E, 0x64A, 0);
    func_80023A98(0x8F, 0x645, 0);
    func_80023A98(0x90, 0x643, 1);
    func_80023A98(0x91, 0x648, 1);
}
