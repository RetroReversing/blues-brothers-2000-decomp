/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s16 coss(s32);                                      /* extern */
s32 tickActorTimer(void *);                          /* extern */
extern f32 D_8000086C;
extern u8 gTextWaveTime[];

void func_80015F80(void *arg0) {
    M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + D_8000086C);
    loop_goto_1:
    {
 M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 0x40) + (f32) ((s32) (coss(((M2C_FIELD(arg0, s32 *, 0x8C) + *(s32 *) gTextWaveTime) * 0x320) & 0xFFE0) * 0x19) >> 0xE));
    }
    if (0)
    {
        { goto loop_goto_1; }
    }
    if (tickActorTimer(arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
