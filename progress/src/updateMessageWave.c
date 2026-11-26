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

s16 sins(s32);                                      /* extern */
extern f64 D_80008228;
extern f64 D_80008230;
extern s32 gTextWaveTime;
extern f32 D_800B9EC4;
extern s32 D_80107654;
extern s32 D_8014AA9C;

void updateMessageWave(void *arg0) {
    s32 *__base_D_800B9EA4;
    f32 temp_ft1;
    f32 temp_fv0;
    f32 temp_fv1_2;
    f64 temp_fv1;
    s32 temp_v1;
    void *temp_v1_2;
    f32 temp;
    f64 temp2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x90);
    if (temp_v1 == 1) {
        if (D_80107654 != 0) {
            M2C_FIELD(arg0, s32 *, 0x34) = 0;
            M2C_FIELD(arg0, s32 *, 0x8C) = 0;
        } else {
            if (M2C_FIELD(arg0, s32 *, 0x8C) == 0) {
                M2C_FIELD(arg0, f32 *, 0x40) = 0.0f;
                M2C_FIELD(arg0, f32 *, 0x44) = 0.0f;
                M2C_FIELD(arg0, f32 *, 0x48) = 0.0f;
                M2C_FIELD(arg0, s32 *, 0x8C) = temp_v1;
            }
            if (M2C_FIELD(arg0, s32 *, 0x8C) == temp_v1) {
                temp_fv1 = (f64) M2C_FIELD(arg0, f32 *, 0x44);
                temp_ft1 = (f32) (((f64) M2C_FIELD(arg0, f32 *, 0x40) - D_80008228) * D_80008230);
                temp = (f32) (temp_fv1 + ((f64) D_800B9EC4 * (temp2 = (f64) temp_ft1 - temp_fv1)));
                temp_fv1_2 = temp;
                M2C_FIELD(arg0, f32 *, 0x48) = temp_ft1;
                M2C_FIELD(arg0, f32 *, 0x44) = temp_fv1_2;
                temp_fv0 = M2C_FIELD(arg0, f32 *, 0x40) + (D_800B9EC4 * temp_fv1_2);
                M2C_FIELD(arg0, s32 *, 0x34) = (s32) temp_fv0;
                M2C_FIELD(arg0, f32 *, 0x40) = temp_fv0;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x38) = (M2C_FIELD(arg0, s32 *, 0x34));
        M2C_FIELD(arg0, s32 *, 0x3C) = (M2C_FIELD(arg0, s32 *, 0x34));
        __base_D_800B9EA4 = &gTextWaveTime;
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) ((s32) (sins(((*__base_D_800B9EA4) * 0x64) & 0xFFFC) * 0x1F) >> 7);
        M2C_FIELD(arg0, s32 *, 0x18) = (s32) ((s32) (sins(((*__base_D_800B9EA4) * 0xC8) & 0xFFF8) * 0x1FC1) >> 0xF);
    }
    temp_v1_2 = M2C_FIELD(arg0, void **, 0xA4);
    if ((temp_v1_2 == NULL) || (D_8014AA9C != 0) || (M2C_FIELD(temp_v1_2, s32 *, 0x78) != M2C_FIELD(arg0, s32 *, 0x78))) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}

