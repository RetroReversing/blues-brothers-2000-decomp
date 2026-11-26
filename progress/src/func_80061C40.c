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

void func_80061C40(void) {
    M2C_UNK var_a0;
    M2C_UNK var_a1;
    M2C_UNK var_a2;

    func_80023A74(0x14, 0x2C5);
    var_a0 = 0x98;
    if (D_800B81D0 == 0) {
        setSlotAsset(0x97, 0x2C4, 0);
        setSlotAsset(0x98, 0x2C7, 0);
        setSlotAsset(0x99, 0x2C2, 0);
        setSlotAsset(0x9B, 0x2C6, 1);
        var_a0 = 0x9A;
        var_a1 = 0x2C3;
        var_a2 = 1;
    } else {
        var_a1 = 0x2C7;
        var_a2 = 0;
    }
    setSlotAsset(var_a0, var_a1, var_a2);
}
