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

void func_80076DF8(void) {
    func_80023A74(0x4B, 0x5C7);
    setSlotAsset(0x150, 0x5CA, 0);
    setSlotAsset(0x151, 0x5CE, 0);
    setSlotAsset(0x152, 0x5CC, 0);
    setSlotAsset(0x153, 0x5CD, 1);
    setSlotAsset(0x154, 0x5C8, 0);
    setSlotAsset(0x155, 0x5C9, 1);
    setSlotAsset(0x156, 0x5CB, 1);
}
