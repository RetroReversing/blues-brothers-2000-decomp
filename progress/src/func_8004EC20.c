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

extern s32 D_8014A928;
extern s32 D_8014A9A8;
extern s32 D_801718C0;

void func_8004EC20(void) {
    char *var_a0;
    char *var_a1;
    char *var_v1;
    s32 var_a2;

    var_a2 = 0;
    var_a1 = &D_801718C0;
    var_a0 = &D_8014A9A8;
    var_v1 = &D_8014A928;
    do {
        *(s32 *)var_v1 = 0;
        *(s32 *)var_a0 = 0;
        *(s32 *)var_a1 = 0;
        var_a1 += 4;
        var_a0 += 4;
        var_a2 += 1;
        var_v1 += 4;
    } while (var_a2 < 0x1E);
}
