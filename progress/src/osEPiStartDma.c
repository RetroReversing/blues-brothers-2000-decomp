/* identical to osEPiStartDma in Asteroids Hyper 64 (matched), with its names changed by decompdecomp */
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

s32 func_800A2360(s32, void *, M2C_UNK);                /* extern */
s32 osPiGetCmdQueue();                              /* extern */
s32 func_80097B20(s32, void *, M2C_UNK);               /* extern */
extern s32 D_800BC420;

s32 func_800A22C0(s32 arg0, void *arg1, s32 arg2) {
    s32 ret;

    if (D_800BC420 == 0) {
        return -1;
    }
    M2C_FIELD(arg1, s32 *, 0x14) = arg0;
    if (arg2 == 0) {
        M2C_FIELD(arg1, s16 *, 0) = 0xF;
    } else {
        M2C_FIELD(arg1, s16 *, 0) = 0x10;
    }
    if (M2C_FIELD(arg1, u8 *, 2) == 1) {
        ret = func_800A2360(osPiGetCmdQueue(), arg1, 0);
    } else {
        ret = func_80097B20(osPiGetCmdQueue(), arg1, 0);
    }
    return ret;
}
