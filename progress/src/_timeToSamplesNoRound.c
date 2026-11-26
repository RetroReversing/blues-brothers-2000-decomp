/* identical to func_800451B4 in BATTLEZONE (local match library) (matched), with its names changed by decompdecomp */
/* identical to _timeToSamplesNoRound in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
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

extern f64 D_8000A8A0;
extern f64 D_8000A8A8;

s32 _timeToSamplesNoRound(void *arg0, s32 arg1) {
    return (s32) (f32) (((f64) ((f32) arg1 * (f32) M2C_FIELD(arg0, s32 *, 0x44)) / D_8000A8A0) + D_8000A8A8);
}
