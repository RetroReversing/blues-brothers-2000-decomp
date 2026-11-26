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

s32 func_80043248();                                /* extern */
extern f32 D_800099A8;
extern f32 D_801700D0[];s32 func_80083E98(void) {
    s32 temp_v1;
    s32 var_v0;
    f32 f;

    temp_v1 = func_80043248();
    f = D_801700D0[0];
    do { var_v0 = 2; } while (0);
    if (!(f < D_800099A8)) {
        var_v0 = temp_v1;
    }
    return var_v0;
}
