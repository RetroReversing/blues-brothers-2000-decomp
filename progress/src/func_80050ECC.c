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

void func_80050ECC(void) {
    func_80023A74(0x20, 0xA9A);
    setSlotAsset(0xAB, 0xA95, 0);
    setSlotAsset(0xAC, 0xA9B, 0);
    setSlotAsset(0xAD, 0xA97, 0);
    setSlotAsset(0xAE, 0xA99, 1);
    setSlotAsset(0xAF, 0xA93, 0);
    setSlotAsset(0xB0, 0xA94, 1);
    setSlotAsset(0xB1, 0xA96, 1);
}
