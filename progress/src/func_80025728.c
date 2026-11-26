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

M2C_UNK func_800899C4(M2C_UNK *, s32, void *, s32, s32); /* extern */
extern M2C_UNK D_800010A4;
extern void *D_80106A38;

s32 func_80025728(void) {
    s32 temp_s0;
    s32 var_s2;
    s32 var_v0;
    void *var_s1;
    void *temp;
    s32 shift_stage;

    var_s1 = D_80106A38;
    var_s2 = 0;
    for (;;) {
        temp_s0 = M2C_FIELD(var_s1, const s32 *, 0);
        func_800899C4(&D_800010A4, var_s2, var_s1, temp_s0, M2C_FIELD(var_s1, const s32 *, 4));
        if (temp_s0 < 0) {
            break;
        }
        temp_s0 = temp_s0 >> 2;
        var_s1 = var_s1 + (temp_s0 * 4) + 8;
        var_s2 += 1;
    }
    var_v0 = var_s2;
    if (temp_s0 == -2) {
        return var_v0;
    }
    return -1;
}
