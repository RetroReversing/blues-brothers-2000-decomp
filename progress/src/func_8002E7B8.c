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

s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
extern s32 D_800B4980;
extern s32 D_800B4984;

void func_8002E7B8(s32 arg0) {
    D_800B4984 = func_80024394(0, 3);
    if (arg0 != 0) {
        if (D_800B4980 != 2) {
            D_800B4980 = 1;
        }
    } else if (D_800B4980 < 3) {
        if (D_800B4980 > 0) {
            D_800B4980 = 3;
        }
    } else if (D_800B4980 == 3) {
        D_800B4980 = D_800B4980;
    }
}
