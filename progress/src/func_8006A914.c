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

s32 func_8002D5CC();                                /* extern */
M2C_UNK func_8002D858(void *, M2C_UNK *);           /* extern */
M2C_UNK func_8004303C(void *);                      /* extern */
M2C_UNK func_80043328(void *, s32, M2C_UNK);        /* extern */
s32 func_80084CCC(void *);                          /* extern */

s32 func_8006A914(void *arg0) {
    s32 ret;
    M2C_UNK sp10;

    if (func_8002D5CC() != 0) {
        M2C_FIELD(arg0, s32 *, 0x64) = 0;
        ret = func_80084CCC(arg0);
    } else {
        func_8002D858(arg0, &sp10);
        do { func_80043328(arg0, M2C_FIELD(arg0, s32 *, 0x74), 0x100); } while (0);
        func_8004303C(arg0);
        ret = 0;
    }
    return ret;
}
