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

void func_80076E88(void) {
    func_80023A74(0x4C, 0x5CF);
    setSlotAsset(0x157, 0x5D2, 0);
    setSlotAsset(0x158, 0x5D6, 0);
    setSlotAsset(0x159, 0x5D4, 0);
    setSlotAsset(0x15A, 0x5D5, 1);
    setSlotAsset(0x15B, 0x5D0, 0);
    setSlotAsset(0x15C, 0x5D1, 1);
    setSlotAsset(0x15D, 0x5D3, 1);
}
