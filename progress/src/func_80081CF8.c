/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

s32 getImageAsset(s32);                             /* extern */
M2C_UNK setTextColor(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80027D7C(s32, s32, M2C_UNK, M2C_UNK);  /* extern */
extern s32 D_800AB9B4;
extern s32 D_800BD07C;
extern s32 D_800BD1E4;
extern s32 gComboWinFlagsA;
extern s32 gComboWinFlagsB;

void func_80081CF8(void *arg0) {
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;

    M2C_FIELD(arg0, s32 *, 0x68) = 0xE;
    setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    var_s1 = 0;
    if (D_800AB9B4 == 0) {
        for (; var_s1 < 5; var_s1++) {
            if (*(&gComboWinFlagsA + var_s1) != 0) {
                func_80027D7C(getImageAsset(D_800BD1E4), ((0x1E) + var_s1 * 15), 0xF, 0);
            } else {
                func_80027D7C(getImageAsset(D_800BD07C), ((0x1E) + var_s1 * 15), 0xF, 0);
            }
        }
        var_s1 = 0;
        for (; var_s1 < 5; var_s1++) {
            if (*(&gComboWinFlagsB + var_s1) != 0) {
                func_80027D7C(getImageAsset(D_800BD1E4), ((0xBE) + var_s1 * 15), 0xF, 0);
            } else {
                func_80027D7C(getImageAsset(D_800BD07C), ((0xBE) + var_s1 * 15), 0xF, 0);
            }
        }
    }
}
