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

s32 func_8000C43C();
s32 func_80028694();
s32 strlen();
extern s32 D_800B28C0;
extern char D_800B2904[];
extern u8 D_800B2A04;
extern s32 D_8010788C;
extern s32 D_80107890;
extern s32 D_8014AA98;

s32 func_800291AC(u8 *arg0) {
    u8 *__base_D_800B2A04;
    s32 temp_s4;
    s32 var_s5;
    s32 var_s6;
    u8 var_v0;
    u8 *temp_s1;
    char *var_s2;
    u8 var_v1;

    var_s2 = arg0;
    var_s5 = 1;
    var_s6 = 0x118;
    if (D_8014AA98 == 1) {
        var_s6 = 0xF0;
    }
    if (func_8000C43C() == 0x17) {
        D_8010788C += 0x12;
    }
    D_80107890 = 0xF;
    strlen(var_s2);
    var_v1 = *(u8 *)var_s2;
    temp_s4 = D_8010788C;
    if (var_v1 != 0) {
        do {
            if (var_v1 == 0x20) {
                if (D_8010788C != temp_s4) {
                    do { var_v0 = var_v1 & 0xFF; } while (0);
                    temp_s1 = var_s2 + 1;
                    if (var_s6 < (((D_8010788C + func_80028694(temp_s1)) - (*(u8 *)&D_800B2A04)) + 0xD)) {
                        var_s2 = temp_s1;
                        D_8010788C = temp_s4;
                        D_80107890 += 0xF;
                    } else {
                        goto block_11;
                    }
                } else {
                    goto block_13;
                }
            } else {
                do { var_v0 = var_v1 & 0xFF; } while (0);
    block_11:
            __base_D_800B2A04 = &D_800B2A04;
                D_8010788C = ((D_8010788C)) + ((2 + ((s32) (0xB - (*(u8 *)((s8 *)((s32) (*(var_v0 + D_800B2904)) + (s32) __base_D_800B2A04) + (-0x20)))) / (s32) D_800B28C0)));
                if (var_s5 != 0) {
                    var_s5 = 0;
                }
block_13:
                var_s2 += 1;
            }
            var_v1 = *(u8 *)var_s2;
        } while (var_v1 != 0);
    }
    return D_80107890 + 0xF;
}
