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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern s32 D_800FB810;

void func_80023D28(void) {
    char *var_v1;
    s32 var_a0;

    var_a0 = 0;
    var_v1 = &D_800FB810;
    loop_goto_1:
    {
        (*(s32 *)((s8 *)var_v1 + 0)) = 0;
        (*(s32 *)((s8 *)var_v1 + 8)) = 0;
        (*(s32 *)((s8 *)var_v1 + 4)) = 0;
        var_v1 += 0xC;
        var_a0 += 1;
    }
    if (var_a0 < 0xED8)
    {
        goto loop_goto_1;
    }
}
