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

s16 coss(s32);                                      /* extern */
f32 func_8002DD60(f32);                             /* extern */
M2C_UNK func_8003C140(void *);                      /* extern */
s16 sins(s32);                                      /* extern */
extern s32 D_800B9EA4;
extern void *D_800BD06C;

void func_8000E294(void *arg0) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 lim;
    f32 y;
    void *p;
    f32 px;
    s32 t;
    s32 a;
    s32 b;

    a = (coss(((D_800B9EA4 + M2C_FIELD(arg0, s32 *, 0x8C)) * 300) & 0xFFFC) * 625) >> 11;
    b = (a + 0x4000) & 0xFFFF;
    M2C_FIELD(arg0, s32 *, 0x18) = a;
    M2C_FIELD(arg0, f32 *, 4) = M2C_FIELD(arg0, f32 *, 0x40) + ((coss(b) * 125) >> 13);
    t = (sins(b) * 275) >> 14;
    y = M2C_FIELD(arg0, f32 *, 0x44) - t;
    p = D_800BD06C;
    M2C_FIELD(arg0, f32 *, 8) = y;
    dx = M2C_FIELD(p, f32 *, 4) - M2C_FIELD(arg0, f32 *, 4);
    dz = M2C_FIELD(p, f32 *, 0xC) - M2C_FIELD(arg0, f32 *, 0xC);
    lim = 19000.0f;
    dy = M2C_FIELD(p, f32 *, 8) - y;
    if (!(lim < func_8002DD60(dx)) && !(lim < func_8002DD60(dz)) && !(lim < func_8002DD60(dy)) && ((dx * dx) + (dz * dz) + (dy * dy)) < 250000.0f) {
        func_8003C140(D_800BD06C);
    }
}
