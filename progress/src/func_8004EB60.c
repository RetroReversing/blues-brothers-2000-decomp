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

s32 func_800140D0();                                /* extern */
s32 func_80014234();                                /* extern */
s32 func_800151B8();                                /* extern */
s32 func_80015258();                                /* extern */
s32 func_800153B4();                                /* extern */
s32 func_80015428();                                /* extern */
s32 func_8001549C();                                /* extern */
s32 func_80076BF0();                                /* extern */

s32 func_8004EB60(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x6C);
    switch (temp_v0) {
    case 1:
        return func_80014234();
    case 2:
        return func_800151B8();
    case 3:
        return func_80015258();
    case 5:
        return func_800153B4();
    case 7:
        return func_80015428();
    case 6:
        return 0;
    case 4:
        return func_8001549C();
    case 13:
    case 14:
        return func_80076BF0();
    default:
        return func_800140D0();
    }
}
