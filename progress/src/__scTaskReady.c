/* identical to __scTaskReady in BATMAN BEYOND RETURN (local match library) (matched), with its names changed by decompdecomp */
/* identical to __scTaskReady in ALL STAR TENNIS '99 (local match library) (matched), with its names changed by decompdecomp */
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

s32 func_8009CD60();                                /* extern */
s32 func_8009CEB0();                                /* extern */

s32 __scTaskReady(s32 arg0) {
    s32 temp_s0;

    if (arg0 != 0) {
        temp_s0 = func_8009CD60();
        return arg0 & -(temp_s0 == func_8009CEB0());
    }
    return 0;
}
