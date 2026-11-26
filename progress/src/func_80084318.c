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

s32 func_80081188(s32, s32, f32 *);                 /* extern */
extern s32 D_800BD06C;

s32 func_80084318(const void *arg0) {
    f32 sp10;
    s32 var_v0;

    var_v0 = func_80081188(M2C_FIELD(arg0, const s32 *, 0x70), D_800BD06C + 4, &sp10);
    if (!(sp10 <= M2C_FIELD(arg0, const f32 *, 0x104))) {
        var_v0 = 0;
    }
    return var_v0;
}
