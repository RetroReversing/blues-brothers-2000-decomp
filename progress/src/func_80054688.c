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

s32 func_80023A04();                                /* extern */
extern s32 gFrameScale;
extern f32 D_800B9EC4;
extern s32 gCamSpeedScale;
extern s32 D_8010704C;
extern s32 D_8014AAB0;

void func_80054688(void *arg0) {
    if (D_8010704C != 0) {
        s32 *p = &D_8014AAB0;
        do { *p = func_80023A04(); } while (0);
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
    M2C_FIELD(arg0, f32 *, 0x100) = D_800B9EC4;
    M2C_FIELD(arg0, s32 *, 0x94) = gFrameScale;
    M2C_FIELD(arg0, s32 *, 0x90) = gCamSpeedScale;
}
