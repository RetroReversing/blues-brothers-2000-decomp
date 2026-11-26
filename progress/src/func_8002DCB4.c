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

f32 func_8002DD60(f32);                       /* extern */
extern f64 D_80001210;

void func_8002DCB4(s32 arg0) {
    M2C_UNK32 *temp_s0;
    f64 temp_fs0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;

    temp_fs0 = D_80001210;
    var_s4 = 0;
    var_s3 = 0;
    do {
        var_s2 = 0;
        var_s1 = var_s3;
loop_2:
        temp_s0 = arg0 + var_s1;
        do { if ((f64) func_8002DD60(*(f32 *)temp_s0) < temp_fs0) {
            *temp_s0 = 0;
        } } while (0);
        var_s2 += 1;
        var_s1 += 4;
        if (var_s2 < 2) {
            goto loop_2;
        }
        var_s4 += 1;
        var_s3 += 0xC;
    } while (var_s4 < 2);
}

