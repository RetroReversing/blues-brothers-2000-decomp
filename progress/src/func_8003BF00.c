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

M2C_UNK func_8001AFD4();                            /* extern */
M2C_UNK func_80089130(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern s32 D_800B4A84;
extern s32 D_800B9EBC;
extern s32 D_8013FB20;

void func_8003BF00(void) {
    if (D_8013FB20 == 0xFF) {
        func_80089130(0, 0, 0);
        D_800B9EBC = 1;
        D_800B4A84 = 1;
        func_8001AFD4();
    }
}
