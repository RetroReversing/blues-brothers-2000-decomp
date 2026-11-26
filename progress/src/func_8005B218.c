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

void *func_80023874(M2C_UNK, void *);               /* extern */
f32 func_8002DD60(f32);                    /* extern */
extern f32 D_8000859C;
extern f32 D_800085A0;

s32 func_8005B218(void *arg0) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fv0;
    void *var_s0;

    var_s0 = func_80023874(0x129, NULL);
    if (var_s0 != NULL) {
        temp_fs2 = D_8000859C;
        temp_fs1 = D_800085A0;
        do {
            if (M2C_FIELD(var_s0, f32 *, 0xC) == M2C_FIELD(arg0, f32 *, 0xC)) {
                temp_fs0 = func_8002DD60(M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(var_s0, f32 *, 4));
                temp_fv0 = func_8002DD60(M2C_FIELD(arg0, f32 *, 8) - M2C_FIELD(var_s0, f32 *, 8));
                if (temp_fs0 < temp_fs2) {
                    if (temp_fv0 < temp_fs1) {
                        M2C_FIELD(var_s0, s32 *, 0xC0) = 0xFF;
                    }
                }
            }
            var_s0 = func_80023874(0x129, var_s0);
        } while (var_s0 != NULL);
    }
    return 0;
}
