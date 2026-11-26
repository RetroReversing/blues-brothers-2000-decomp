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

void *func_80017C54(s32, s32, s32, s32, s32, s32, s32); /* extern */
void *func_800239E0();                              /* extern */
s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
extern s32 D_800BD0D8;
extern s32 D_800BD168;

void *func_80017CF0(s32 arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    void *var_s0;

    var_s0 = func_800239E0();
    if (var_s0 != NULL) {
        return var_s0;
    }
    if (func_80024394(0, 0x64) >= 0x33) {
        temp_s0 = func_80024394(0, 0xFFFF);
        var_s0 = func_80017C54(arg0, D_800BD0D8, temp_s0, func_80024394(-0x7D0, 0x7D0) + 0x2AF8, 0x3E8, 0, 0x1F4);
    } else {
        temp_s0_2 = func_80024394(0, 0xFFFF);
        var_s0 = func_80017C54(arg0, D_800BD168, temp_s0_2, func_80024394(-0x1F4, -0x7D0) + 0x4000, 0x4B0, 0, 0);
        M2C_FIELD(var_s0, s32 *, 0x18) = 0x4000;
    }
    M2C_FIELD(var_s0, s32 *, 0x78) = func_80024394(0, 0x7EFF81);
    return var_s0;
}
