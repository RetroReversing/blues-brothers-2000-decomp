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

s32 func_800A1D10();                                /* extern */
M2C_UNK osInvalDCache(s32, s32);                    /* extern */
M2C_UNK osPiStartDma(M2C_UNK *, M2C_UNK, M2C_UNK, s32, s32, s32, M2C_UNK *); /* extern */
M2C_UNK osRecvMesg(M2C_UNK *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_801771C8;

void func_8002B410(s32 arg0, s32 arg1, s32 arg2) {
    char sp20[0x18];
    M2C_UNK sp38;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;

    var_s3 = arg0;
    var_s2 = arg1;
    var_s1 = arg2;
    if (var_s1 != 0) {
        do {
loop_2:
            if (func_800A1D10() == 1) {
                goto loop_2;
            }
            var_s0 = var_s1;
            if (var_s1 >= 0x4001) {
                var_s0 = 0x4000;
            }
            osInvalDCache(var_s2, var_s0);
            osPiStartDma(sp20, 0, 0, var_s3, var_s2, var_s0, &D_801771C8);
            osRecvMesg(&D_801771C8, &sp38, 1);
            var_s3 += var_s0;
            var_s1 -= var_s0;
            var_s2 += var_s0;
        } while (var_s1 != 0);
    }
}
