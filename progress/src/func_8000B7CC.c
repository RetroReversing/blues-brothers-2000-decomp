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

s32 func_8000AB80();                                /* extern */
M2C_UNK func_8000ABB8(s32);                         /* extern */
M2C_UNK func_8000AF88(M2C_UNK, s32, s32);           /* extern */
s32 func_8000B5FC(M2C_UNK, s32, M2C_UNK, M2C_UNK);  /* extern */
s32 func_8000B6D0(s32);                             /* extern */

s32 func_8000B7CC(s32 arg0, M2C_UNK arg1) {
    s32 temp_s2;
    s32 temp_v0;
    s32 var_s0;

    temp_s2 = func_8000AB80();
    temp_v0 = func_8000B6D0(arg0);
    func_8000AF88(0xB1FF0000, arg0, temp_v0);
    var_s0 = func_8000B5FC(0x303, temp_v0, arg1, 0);
    if (var_s0 & 0x8000) {
        var_s0 |= 0xFFFF0000;
    }
    func_8000ABB8(temp_s2);
    return var_s0;
}
