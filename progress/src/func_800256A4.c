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

M2C_UNK func_80025280(void *, s32);                 /* extern */
extern void *D_80106A38;

s32 func_800256A4(s32 arg0) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 var_s0;
    s32 var_v0;
    void *var_a0;
    s32 temp;

    var_s0 = 0;
loop_1:
    var_a0 = D_80106A38;
loop_2:
    temp_a1 = M2C_FIELD(var_a0, s32 *, 0);
    if (temp_a1 >= 0) {
        temp = temp_a1 & 1;
        temp_a1_2 = temp_a1 >> 2;
        if (!temp) {
            if (M2C_FIELD(var_a0, s32 *, 4) == arg0) {
                func_80025280(var_a0 + 8, temp_a1_2);
                var_s0 += 1;
                goto loop_1;
            }
            goto block_7;
        }
block_7:
        var_a0 = var_a0 + (temp_a1_2 * 4) + 8;
        goto loop_2;
    }
    var_v0 = var_s0;
    if (temp_a1 == -2) {
        return var_v0;
    }
    return -1;
}
