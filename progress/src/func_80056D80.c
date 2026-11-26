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
extern s32 D_800B81D0;

void func_80056D80(void) {
    func_80023A74(0x1B, 0x3C1);
    setSlotAsset(0xA3, 0x3BE, 0);
    if (D_800B81D0 == 0) {
        setSlotAsset(0xA2, 0x3BE, 0);
        setSlotAsset(0xA4, 0x3BF, 0);
        setSlotAsset(0xA6, 0x3BC, 0);
        setSlotAsset(0xA5, 0x3C3, 0);
        setSlotAsset(0xA7, 0x3BD, 0);
        setSlotAsset(0xA8, 0x3C2, 0);
    }
}
