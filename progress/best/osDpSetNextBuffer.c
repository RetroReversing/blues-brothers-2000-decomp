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

s32 func_800A8CD0();                                /* extern */
s32 osVirtualToPhysical(s32);                       /* extern */
extern s32 D_A4100000;

s32 osDpSetNextBuffer(s32 arg0, M2C_UNK arg2, s32 arg3) {
    s32 var_v0;

    var_v0 = -1;
    if (func_800A8CD0() == 0) {
        *(s32 *)0xA410000C = 1;
        do {

        } while (*(u8 *)(void *)0xA410000C & 1);
        D_A4100000 = osVirtualToPhysical(arg0);
        var_v0 = 0;
        *(s32 *)0xA4100004 = arg3 + osVirtualToPhysical(arg0);
    }
    return var_v0;
}
