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

s16 coss(s32);                                      /* extern */
s32 func_8000C43C();                                /* extern */
s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8002D620();                            /* extern */
extern s32 D_800B9EA4;

void func_800139D8(void *arg0) {
    s32 var_v1;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        func_8002D620();
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x64) = 0xC8;
        M2C_FIELD(arg0, s32 *, 0x8C) = func_80024394(-0x7D0, 0x7D0);
        M2C_FIELD(arg0, s32 *, 0) = 0x10E;
    }
    if (func_8000C43C() == 0x3C) {
        var_v1 = (s32) (coss(((D_800B9EA4 + M2C_FIELD(arg0, s32 *, 0x8C)) * 0x64) & 0xFFFC) * 0x19) >> 0xD;
    } else {
        var_v1 = (s32) (coss(((D_800B9EA4 + M2C_FIELD(arg0, s32 *, 0x8C)) * 0x64) & 0xFFFC) * 0x7D) >> 0xC;
    }
    M2C_FIELD(arg0, s32 *, 0x14) = var_v1;
}
