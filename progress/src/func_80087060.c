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

M2C_UNK func_8002710C(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8003BD74(s32, f32, f32, f32);  /* extern */
extern f64 D_80009BB8;
extern f64 D_80009BC0;
extern f64 D_80009BC8;
extern s32 D_800AB9B4;
extern f32 D_800B9EC4;
extern s32 D_800B9ECC;

void func_80087060(void *arg0) {
    f32 temp_ft0_2;
    f32 temp_ft1;
    f64 temp_ft0;
    s32 temp_v1;
    s32 var_a3;

    var_a3 = M2C_FIELD(arg0, s32 *, 0x5C);
    if (var_a3 >= 0x100) {
        var_a3 = 0xFF;
    }
    if (D_800AB9B4 == 0) {
        func_8002710C(0xFF, 0xFF, 0xFF, var_a3);
        func_8003BD74(M2C_FIELD(arg0, s32 *, 0x60), 160.0f, 120.0f, M2C_FIELD(arg0, f32 *, 0x40));
        temp_ft0 = (f64) M2C_FIELD(arg0, f32 *, 0x44);
        temp_ft1 = (f32) (((f64) M2C_FIELD(arg0, f32 *, 0x40) - D_80009BB8) * D_80009BC0);
        temp_ft0_2 = (f32) (temp_ft0 + ((f64) D_800B9EC4 * ((f64) temp_ft1 - (temp_ft0 * D_80009BC8))));
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x5C) - (D_800B9ECC * 4);
        M2C_FIELD(arg0, s32 *, 0x5C) = temp_v1;
        M2C_FIELD(arg0, f32 *, 0x48) = temp_ft1;
        M2C_FIELD(arg0, f32 *, 0x44) = temp_ft0_2;
        M2C_FIELD(arg0, f32 *, 0x40) = (f32) (M2C_FIELD(arg0, f32 *, 0x40) + (D_800B9EC4 * temp_ft0_2));
        if (temp_v1 < 0) {
            M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        }
    }
}
