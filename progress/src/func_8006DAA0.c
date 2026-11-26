/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;



#define M2C_CARRY 0

#endif

extern char D_800B81F4[];
extern char D_800BCFB8[];

s32 func_8006DAA0(s32 arg0) {
    char *__base_D_800B81F4;
    s32 temp_v1;
    s32 var_a0;
    s8 *temp;

    __base_D_800B81F4 = D_800B81F4;
    temp = (s8 *)(((arg0 * 0xC) + __base_D_800B81F4));
    temp_v1 = (*(s32 *)(temp + (8)));
    var_a0 = 0;
    if ((temp_v1 == 0) || (*(temp_v1 + D_800BCFB8) != 0)) {
        var_a0 = 1;
    }
    return var_a0;
}
