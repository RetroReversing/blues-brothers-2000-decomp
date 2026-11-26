/* machine draft (m2c) for sn-n64-281 -G0 -mips2 -O2, tried by autopilot */
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

f32 func_80080DFC(void *arg0, f32 arg1) {
    f32 temp_ft2;

    temp_ft2 = arg1 * arg1;
    return (M2C_FIELD(arg0, f32 *, 0) * (arg1 * temp_ft2)) + (M2C_FIELD(arg0, f32 *, 4) * temp_ft2) + (M2C_FIELD(arg0, f32 *, 8) * arg1) + M2C_FIELD(arg0, f32 *, 0xC);
}
