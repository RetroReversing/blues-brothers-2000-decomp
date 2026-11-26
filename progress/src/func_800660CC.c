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

s32 func_80025100(s32, s32);                        /* extern */
s32 func_8002D204(s32, s32, s32);                   /* extern */
extern s32 D_800B4C28;
extern s32 D_800B9ECC;
extern s32 D_800BD278;
extern s32 D_800BD280;
extern s32 D_800BD68C;
extern s32 D_800BD690;

s32 func_800660CC(void *arg0, s32 arg1, s32 arg2) {
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;
    s32 var_s0;

    temp_fv1 = (f32) (D_800BD278 + arg1);
    var_s0 = 0;
    if (M2C_FIELD(arg0, f32 *, 4) < temp_fv1) {
        var_s0 = 1;
        if (arg2 != 0) {
            M2C_FIELD(arg0, f32 *, 4) = temp_fv1;
        }
    }
    temp_fv1_2 = (f32) (D_800BD280 + arg1);
    if (M2C_FIELD(arg0, f32 *, 0xC) < temp_fv1_2) {
        var_s0 += 1;
        if (arg2 != 0) {
            M2C_FIELD(arg0, f32 *, 0xC) = temp_fv1_2;
        }
    }
    temp_fv1_3 = (f32) (0x1E14 - arg1);
    if (temp_fv1_3 < M2C_FIELD(arg0, f32 *, 4)) {
        var_s0 += 1;
        if (arg2 != 0) {
            M2C_FIELD(arg0, f32 *, 4) = temp_fv1_3;
        }
    }
    temp_fv1_4 = (f32) (D_800BD690 - arg1);
    if (temp_fv1_4 < M2C_FIELD(arg0, f32 *, 0xC)) {
        var_s0 += 1;
        if (arg2 != 0) {
            M2C_FIELD(arg0, f32 *, 0xC) = temp_fv1_4;
        }
    }
    temp_fv1_5 = (f32) (D_800BD68C - arg1);
    if (temp_fv1_5 < M2C_FIELD(arg0, f32 *, 8)) {
        var_s0 += 1;
        if (arg2 != 0) {
            M2C_FIELD(arg0, f32 *, 8) = temp_fv1_5;
        }
    }
    temp_fv1_6 = (f32) D_800B4C28;
    if (M2C_FIELD(arg0, f32 *, 8) < temp_fv1_6) {
        var_s0 += 1;
        M2C_FIELD(arg0, f32 *, 8) = temp_fv1_6;
        M2C_FIELD(arg0, s32 *, 0x50) = 0;
    }
    if ((var_s0 != 0) && (arg2 == 0)) {
        M2C_FIELD(arg0, s32 *, 0x10) = func_8002D204(func_80025100((s32) (M2C_FIELD(arg0, f32 *, 0x40) - M2C_FIELD(arg0, f32 *, 4)), (s32) (M2C_FIELD(arg0, f32 *, 0x48) - M2C_FIELD(arg0, f32 *, 0xC))), M2C_FIELD(arg0, s32 *, 0x10), D_800B9ECC << 0xA);
    }
    return var_s0;
}
