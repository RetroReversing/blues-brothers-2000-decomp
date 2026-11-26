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

void func_8005141C(void) {
    func_80023A74(0x3A, 0x2F0);
    setSlotAsset(0x129, 0x2F7, 0);
    setSlotAsset(0x126, 0x2F6, 0);
    setSlotAsset(0x127, 0x2F4, 0);
    setSlotAsset(0x128, 0x2F5, 0);
    setSlotAsset(0x12A, 0x2FB, 0);
    setSlotAsset(0x12B, 0x2F9, 0);
    setSlotAsset(0x12C, 0x2FA, 0);
    setSlotAsset(0x12D, 0x2F1, 0);
    setSlotAsset(0x12E, 0x2F2, 0);
    setSlotAsset(0x12F, 0x2F8, 0);
    setSlotAsset(0x130, 0x2F3, 0);
}
