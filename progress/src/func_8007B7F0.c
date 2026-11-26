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
M2C_UNK setSlotAsset(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_8007B7F0(void) {
    func_80023A74(0xF, 0x3AD);
    setSlotAsset(0x5B, 0x3B2, 0);
    setSlotAsset(0x5C, 0x3B2, 0);
    setSlotAsset(0x5D, 0x3B1, 0);
    setSlotAsset(0x5E, 0x3B3, 0);
    setSlotAsset(0x5F, 0x3AC, 0);
    setSlotAsset(0x60, 0x3AE, 0);
    setSlotAsset(0x61, 0x3B0, 0);
}
