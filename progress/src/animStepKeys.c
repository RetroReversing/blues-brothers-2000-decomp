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


extern f64 D_80007950;
extern f64 D_80007958;
extern f32 D_800B9EC4;
extern s32 D_801402F8;
M2C_UNK animSampleKeys(void *, f32);

typedef struct { unsigned char pad_0[220]; float field_DC; void * field_E0; } __repair_record_arg0;
s32 animStepKeys(void *arg0_in) {
    f32 temp_fs0;
    f32 temp_fv0;
    f32 scale;
    s32 var_v0;
    void *temp_s0;

    do { temp_s0 = ((__repair_record_arg0*)arg0_in)->field_E0; } while (0);
    scale = (f32) M2C_FIELD(arg0_in, const s32 *, 0xD4);
    if ((temp_s0 == NULL) || (temp_fs0 = M2C_FIELD(temp_s0, const f32 *, 0x1C), D_801402F8 += 1, animSampleKeys(temp_s0, M2C_FIELD(temp_s0, const f32 *, 0x1C) + (f32) ((f64) ((f32) ((f64) scale * D_80007950) * D_800B9EC4) / D_80007958)), temp_fv0 = M2C_FIELD(temp_s0, const f32 *, 0x1C), var_v0 = 1, ((__repair_record_arg0*)arg0_in)->field_DC = temp_fv0, !(temp_fv0 < temp_fs0))) {
        var_v0 = 0;
    }
    return var_v0;
}
