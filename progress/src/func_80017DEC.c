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

void *findActor(M2C_UNK, void *);               /* extern */

void *func_80017DEC(s32 arg0) {
    void *var_a1;

    var_a1 = NULL;
loop_1:
    var_a1 = findActor(0x131, var_a1);
    if (var_a1 != NULL) {
        if (M2C_FIELD(var_a1, s32 *, 0x70) != arg0) {
            goto loop_1;
        }
    }
    return var_a1;
}
