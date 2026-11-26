/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

s32 func_80025100(s32, s32);
extern void *D_800BD06C;

f32 func_8002D8F4(void *arg0, s32 *arg1) {
    f32 dx;
    f32 dy;
    f32 dz;

    dx = M2C_FIELD(D_800BD06C, f32 *, 4) - M2C_FIELD(arg0, f32 *, 4);
    dy = M2C_FIELD(D_800BD06C, f32 *, 8) - M2C_FIELD(arg0, f32 *, 8);
    dz = M2C_FIELD(D_800BD06C, f32 *, 0xC) - M2C_FIELD(arg0, f32 *, 0xC);
    if (arg1 != NULL) {
        *arg1 = func_80025100((s32) dx, (s32) dz);
    }
    return sqrtf(dx * dx + dy * dy + dz * dz);
}
