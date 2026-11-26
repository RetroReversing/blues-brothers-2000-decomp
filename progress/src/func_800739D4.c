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

s32 func_80023E18(s32);                             /* extern */
M2C_UNK func_8002710C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800272E0(s32, s32, M2C_UNK, M2C_UNK);  /* extern */

void func_800739D4(void *arg0) {
    s32 var_s0;
    s32 var_s1;

    func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
    /*__repair_loop_weight*/do {do {do { var_s0 = 0; } while (0);} while (0);} while (0);
    if (M2C_FIELD(arg0, s32 *, 0x90) > 0) {
        var_s1 = 0x32;
        do {
            var_s0 += 1;
            func_800272E0(func_80023E18(M2C_FIELD(arg0, s32 *, 0x60)), var_s1, 0xB4, 0);
            var_s1 += 0x11;
        } while (var_s0 < M2C_FIELD(arg0, s32 *, 0x90));
    }
}
