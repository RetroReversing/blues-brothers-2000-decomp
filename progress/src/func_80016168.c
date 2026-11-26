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

s32 func_8002D5CC(void *);                          /* extern */
M2C_UNK func_8002DA80();                            /* extern */
extern M2C_UNK D_800BD090;

void func_80016168(void *arg0) {
    s32 temp_v0;
    s32 var_a0;

    M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + M2C_FIELD(arg0, s32 *, 0x74));
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) ((M2C_FIELD(arg0, f32 *, 0x4C) * 69.0f) / 100.0f);
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) ((M2C_FIELD(arg0, f32 *, 0x54) * 69.0f) / 100.0f);
    func_8002DA80();
    var_a0 = M2C_FIELD(arg0, s32 *, 0x80);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x84) - 1;
    M2C_FIELD(arg0, s32 *, 0x84) = temp_v0;
    if (temp_v0 <= 0) {
        M2C_FIELD(arg0, s32 *, 0x84) = 2;
        M2C_FIELD(arg0, s32 *, 0x80) = (s32) (M2C_FIELD(arg0, s32 *, 0x80) + 1);
    }
    if (var_a0 < 0) {
        var_a0 = 0;
    }
    if (var_a0 >= 9) {
        var_a0 = 8;
    }
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) (&D_800BD090)[var_a0];
    if (func_8002D5CC(arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}

