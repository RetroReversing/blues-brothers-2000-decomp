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

s32 func_80026C04();
extern char D_800AE1B0[];
extern u8 D_801070B0;

u8 *func_80026A6C(u8 *arg0, s32 arg1) {
    char *__base_D_800AE1B0;
    s32 temp_a0;
    s32 var_a1;
    char *var_s0;
    s32 temp_v0;
    u8 var_v1;

    func_80026C04(&D_801070B0, 0, 0x100);
    var_s0 = &D_801070B0;
    var_a1 = 0;
    for (;;) {
        if (var_a1 < arg1) {
            temp_v0 = *(u8 *)arg0;
            temp_a0 = temp_v0 & 0xFF;
            arg0 += 1;
            if (temp_a0 != 0) {
                do { var_v1 = 0; } while (0);
                if ((u32) (temp_v0 - 0xF) < 0x33U) {
                    __base_D_800AE1B0 = D_800AE1B0;
                    var_v1 = M2C_FIELD((temp_a0 + __base_D_800AE1B0), u8 *, -0xF);
                }
                *(u8 *)var_s0 = var_v1;
                var_s0 += 1;
                var_a1 += 1;
                *(u8 *)var_s0 = 0;
                continue;
            }
        }
        break;
    }
    return &D_801070B0;
}

