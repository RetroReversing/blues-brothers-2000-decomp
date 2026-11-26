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

M2C_UNK func_8004C78C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *); /* extern */
extern f64 D_80007E38;

void func_8004DE9C(void *arg0, M2C_UNK arg1) {
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    f64 a;
    f64 b;
    f64 c;

    func_8004C78C(arg1, 0, 0, 0, &sp28, &sp2C, &sp30, &sp34, &sp38, &sp3C);
    a = (f64) sp2C * D_80007E38;
    b = (f64) sp28 * D_80007E38;
    M2C_FIELD(arg0, f32 *, 4) = (f32) (s32) sp34;
    c = (f64) sp30 * D_80007E38;
    M2C_FIELD(arg0, f32 *, 8) = (f32) (s32) sp38;
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) (s32) sp3C;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) a;
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) -b;
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) -c;
}
