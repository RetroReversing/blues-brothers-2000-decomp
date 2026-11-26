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

s32 func_8008F68C(void *, s32, M2C_UNK, M2C_UNK, s32); /* extern */
extern s32 D_8017B228;
extern void *D_8017B238;
extern void *D_8017B23C;

s32 func_8008D320(s32 arg0) {
    s32 temp_v0;
    void *var_a0;

    var_a0 = D_8017B23C;
    if (var_a0 == NULL) {
        var_a0 = D_8017B238;
        if (var_a0 == NULL) {
            D_8017B228 = 0;
            return 0;
        }
        goto block_4;
    }
    D_8017B23C = NULL;
block_4:
    if (D_8017B228 == 0) {
        D_8017B228 = M2C_FIELD(var_a0, s32 *, 0x10);
    }
    temp_v0 = func_8008F68C(var_a0, arg0, 0x80, 0x80, -1);
    D_8017B228 = 0;
    return temp_v0;
}
