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

s32 func_8002D5CC();                                /* extern */
extern f64 D_80008218;
extern f64 D_80008220;
extern f32 D_800B9EC4;

void func_800538D4(void *arg0_in) {
    void *arg0 = arg0_in;
    f64 temp_ft0;
    f64 temp_ft1d;
    f32 temp_ft1;
    f32 temp_ft0_2;
    f32 temp_fv0;

    temp_ft1d = ((f64) (*(f32 *)((s8 *)arg0 + 0x40)) - D_80008218) * D_80008220;
    temp_ft0 = (f64) (*(f32 *)((s8 *)arg0 + 0x44));
    temp_ft1 = (f32) temp_ft1d;
    temp_ft0_2 = (f32) (temp_ft0 + ((f64) D_800B9EC4 * ((f64) temp_ft1 - temp_ft0)));
    temp_fv0 = (*(volatile f32 *)((s8 *)arg0 + 0x40)) + (D_800B9EC4 * temp_ft0_2);
    (*(s32 *)((s8 *)arg0 + 0x34)) = (s32) temp_fv0;
    (*(s32 *)((s8 *)arg0 + 0x10)) = 0;
    (*(s32 *)((s8 *)arg0 + 0x18)) = 0;
    (*(f32 *)((s8 *)arg0 + 0x48)) = temp_ft1;
    (*(f32 *)((s8 *)arg0 + 0x44)) = temp_ft0_2;
    (*(f32 *)((s8 *)arg0 + 0x40)) = temp_fv0;
    (*(s32 *)((s8 *)arg0 + 0x38)) = ((*(s32 *)((s8 *)arg0 + 0x34)));
    (*(s32 *)((s8 *)arg0 + 0x3C)) = ((*(s32 *)((s8 *)arg0 + 0x34)));
    if (func_8002D5CC() != 0) {
        (*(s32 (**)(void *))((s8 *)arg0 + 0xA0))(arg0);
    }
}
