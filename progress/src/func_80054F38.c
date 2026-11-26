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

M2C_UNK func_800385AC();                            /* extern */
extern f32 D_800082D4;
extern void *D_800BD06C;

void func_80054F38(void *arg0) {
    func_800385AC();
    M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(D_800BD06C, const f32 *, 4);
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) M2C_FIELD(D_800BD06C, const f32 *, 0xC);
    M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(D_800BD06C, const f32 *, 8) + D_800082D4);
}
