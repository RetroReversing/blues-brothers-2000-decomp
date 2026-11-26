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

extern f32 D_800008E0;
extern s32 D_800B9ECC[];

void func_80016F64(void *arg0) {
    f32 temp_fv1;

    temp_fv1 = M2C_FIELD(arg0, f32 *, 8) - (f32) (D_800B9ECC[0] * 0xA);
    M2C_FIELD(arg0, f32 *, 8) = temp_fv1;
    if (temp_fv1 < (M2C_FIELD(arg0, f32 *, 0x44) - D_800008E0)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0xA0)();
    }
}
