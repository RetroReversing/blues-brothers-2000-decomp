/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
f32 func_8002D280(f32, M2C_UNK);                    /* extern */
M2C_UNK func_8002D9B0(void *);                      /* extern */
M2C_UNK func_8002D9F8(void *);                      /* extern */
extern f32 D_80009AA0;
extern f32 D_80009AA4;
extern f64 D_80009AA8;
extern f32 D_8014022C;

void func_80085528(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0x5C) < 5) || (M2C_FIELD(arg0, s32 *, 0x70) <= 0)) {
        M2C_FIELD(arg0, void (**)(void *), 0xA0)(arg0);
    }
    M2C_FIELD(arg0, s32 *, 0x5C) -= 3;
    M2C_FIELD(arg0, s32 *, 0x70) -= 2;
    M2C_FIELD(arg0, f32 *, 0xB0) = -1250.0f;
    M2C_FIELD(arg0, f32 *, 0xAC) = randomRange(0x32, 0x190);
    M2C_FIELD(arg0, f32 *, 0xB4) = randomRange(0x32, 0x190);
    func_8002D9F8(arg0);
    func_8002D9B0(arg0);
    if (M2C_FIELD(arg0, f32 *, 8) < D_8014022C + 25.0f) {
        M2C_FIELD(arg0, f32 *, 0x50) = M2C_FIELD(arg0, f32 *, 0x50) * D_80009AA8;
        M2C_FIELD(arg0, f32 *, 0x4C) = func_8002D280(M2C_FIELD(arg0, f32 *, 0x4C), 1);
        M2C_FIELD(arg0, f32 *, 0x54) = func_8002D280(M2C_FIELD(arg0, f32 *, 0x54), 1);
        M2C_FIELD(arg0, f32 *, 8) = D_8014022C + 25.0f;
    }
}
