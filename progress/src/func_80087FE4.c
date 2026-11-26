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

s32 func_8000C3C4();                                /* extern */
s32 func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_80052018(M2C_UNK);                         /* extern */

s32 func_80087FE4(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0 == 0) {
        var_v1 = func_8000C3C4();
    }
    if (arg0 == 1) {
        var_v1 = func_80042F00(0x19, 0, 0, 0);
    }
    if (arg0 == 2) {
        var_v1 = func_80042F00(0x30, 0, 0, 0);
    }
    if (arg0 == 3) {
        var_v1 = func_80042F00(0x2F, 0, 0, 0);
    }
    if (arg0 == 4) {
        var_v1 = func_80052018(0);
    }
    if (var_v1 == 0) {
        var_v1 = func_8000C3C4();
    }
    return var_v1;
}
