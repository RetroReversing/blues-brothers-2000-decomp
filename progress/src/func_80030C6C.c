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

s32 func_80030C40();

void func_80030C6C(void *arg0, s32 arg1) {
    char *var_v1;
    s32 temp_v0;
    s32 var_a2;

    var_a2 = 0;
    var_v1 = M2C_FIELD(arg0, s32 **, 0x74);
    M2C_FIELD(arg0, s32 *, 0x7C) = 1;
loop_1:
    temp_v0 = *(s32 *)var_v1;
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, s32 *, 0x70) = 0;
    } else {
        var_v1 += 4;
        if (arg1 != temp_v0) {
            var_a2 += 1;
            goto loop_1;
        }
        M2C_FIELD(arg0, s32 *, 0x70) = var_a2;
    }
    func_80030C40(arg0, 0, var_a2);
}
