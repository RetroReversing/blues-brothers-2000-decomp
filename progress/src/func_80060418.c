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

s32 func_8002492C(f32, f32);                        /* extern */
M2C_UNK func_8002DA80(void *);                      /* extern */
f32 func_8002DD60(f32);                             /* extern */
M2C_UNK func_8005FE74(void *);                      /* extern */
M2C_UNK func_80060214(void *);                      /* extern */
s32 func_80076080();                                /* extern */
extern f32 D_800088F0;
extern f32 D_800088F4;

void func_80060418(void *arg0) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_ft0;
    f32 temp_fv1;
    s32 var_v0;

    { temp_fv1 = M2C_FIELD(arg0, f32 *, 0x40); }
    { { { temp_fs0 = temp_fv1 - D_800088F0; } } }
    temp_ft0 = M2C_FIELD(arg0, f32 *, 0x48);
    temp_fs1 = temp_fv1 + D_800088F0;
    { temp_fs2 = temp_ft0 - D_800088F4; }
    temp_fs3 = temp_ft0 + D_800088F4;
    if (func_80076080() == 0) {
        func_80060214(arg0);
        if (M2C_FIELD(arg0, s32 *, 0x80) == 0) {
            func_8002DA80(arg0);
            var_v0 = 0;
            if (M2C_FIELD(arg0, f32 *, 4) < temp_fs0) {
                M2C_FIELD(arg0, f32 *, 0x4C) = func_8002DD60(M2C_FIELD(arg0, f32 *, 0x4C));
                var_v0 = 1;
            }
            if (temp_fs1 < M2C_FIELD(arg0, f32 *, 4)) {
                M2C_FIELD(arg0, f32 *, 0x4C) = (f32) -func_8002DD60(M2C_FIELD(arg0, f32 *, 0x4C));
                var_v0 = 1;
            }
            if (M2C_FIELD(arg0, f32 *, 0xC) < temp_fs2) {
                M2C_FIELD(arg0, f32 *, 0x54) = func_8002DD60(M2C_FIELD(arg0, f32 *, 0x54));
                var_v0 = 1;
            }
            if (temp_fs3 < M2C_FIELD(arg0, f32 *, 0xC)) {
                M2C_FIELD(arg0, f32 *, 0x54) = (f32) -func_8002DD60(M2C_FIELD(arg0, f32 *, 0x54));
                var_v0 = 1;
            }
            if (var_v0 != 0) {
                M2C_FIELD(arg0, s32 *, 0x10) = func_8002492C(M2C_FIELD(arg0, f32 *, 0x4C), M2C_FIELD(arg0, f32 *, 0x54));
            }
            func_8005FE74(arg0);
        }
    }
}
