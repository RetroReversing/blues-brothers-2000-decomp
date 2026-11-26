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

M2C_UNK animSampleKeys(void *, f32);                 /* extern */
extern s32 gCamSpeedScale;
extern s32 D_801402F8;

s32 func_8004318C(void *arg0) {
    void *temp_s0;
    s32 var_v0;
    s32 temp_v0;
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_s0 = M2C_FIELD(arg0, void **, 0xE0);
    if (temp_s0 == NULL) {
        return 0;
    }
    temp_v0 = D_801402F8;
    temp_fv1 = M2C_FIELD(temp_s0, f32 *, 0x1C);
    D_801402F8 = temp_v0 + 1;
    temp_fv1 = temp_fv1 + (f32) gCamSpeedScale;
    temp_fs0 = M2C_FIELD(temp_s0, f32 *, 0x1C);
    animSampleKeys(temp_s0, temp_fv1);
    temp_fv0 = M2C_FIELD(temp_s0, f32 *, 0x1C);
    var_v0 = 1;
    M2C_FIELD(arg0, f32 *, 0xDC) = temp_fv0;
    if (!(temp_fv0 < temp_fs0)) {
        var_v0 = 0;
    }
    return var_v0;
}
