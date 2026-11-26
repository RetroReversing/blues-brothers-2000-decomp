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

M2C_UNK func_8002ADFC(M2C_UNK, M2C_UNK, void *);    /* extern */
extern s32 D_800B9ECC;

void func_8000DA34(void *arg0) {
    s32 temp_a0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x5C) - (D_800B9ECC * 5);
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_v1;
    if (temp_v1 <= 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        func_8002ADFC(7, 0x1F4, arg0);
        return;
    }
    temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x34);
    var_v0 = temp_v1_2;
    if (temp_v1_2 < 0) {
        var_v0 = temp_v1_2 + 0x1F;
    }
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x3C);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (temp_v1_2 + (var_v0 >> 5));
    var_v0_2 = temp_a0;
    if (temp_a0 < 0) {
        var_v0_2 = temp_a0 + 0x1F;
    }
    temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x38);
    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (temp_a0 + (var_v0_2 >> 5));
    var_v0_3 = temp_v1_3;
    if (temp_v1_3 < 0) {
        var_v0_3 = temp_v1_3 + 0x1F;
    }
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (temp_v1_3 - (var_v0_3 >> 5));
}
