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

M2C_UNK func_8001B990(M2C_UNK, s32);                /* extern */
extern s32 D_800A9540;
extern s32 D_800BD0F4;

void func_80014A34(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_8001B990(0x200, var_s0 + 0x32);
        var_s0 += 1;
    } while (var_s0 < 5);
    D_800A9540 = 8;
    D_800BD0F4 = 8;
}
