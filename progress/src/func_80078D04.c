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

void func_80078D04(void) {
    func_80023A74(0x36, 0x3D1);
    setSlotAsset(0x103, 0x3D4, 0);
    setSlotAsset(0x104, 0x3D9, 0);
    setSlotAsset(0x106, 0x3D8, 0);
    setSlotAsset(0x107, 0x3D7, 0);
    setSlotAsset(0x108, 0x3D2, 0);
    setSlotAsset(0x109, 0x3D5, 0);
    setSlotAsset(0x105, 0x3D6, 0);
}
