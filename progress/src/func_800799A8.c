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

M2C_UNK func_80043248();                            /* extern */
extern f32 D_800093C0;
void func_800462A0(void *);

void func_800799A8(void *arg0) {
    s32 temp_v0;

    func_80043248();
    M2C_FIELD(arg0, s32 *, 0) = 0x101;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x5C) - 6;
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_v0;
    if (temp_v0 < 6) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_800462A0;
        M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + D_800093C0);
    }
}
