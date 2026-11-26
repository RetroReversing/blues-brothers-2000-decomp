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

void *spawnEffectObj(M2C_UNK, s32, s32, s32);        /* extern */
M2C_UNK func_8004E538(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK func_8004E654;

void *func_8004E080(const void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    void *temp_v0;

    if (arg0 != NULL) {
      s32 var_a1_1;
      s32 var_a2_1;
      s32 var_a3_1;
        var_a1_1 = (s32) M2C_FIELD(arg0, const f32 *, 4);
        var_a2_1 = (s32) M2C_FIELD(arg0, const f32 *, 8);
        var_a3_1 = (s32) M2C_FIELD(arg0, const f32 *, 0xC);
      temp_v0 = spawnEffectObj(1, var_a1_1, var_a2_1, var_a3_1);
    } else {
      s32 var_a1_2;
      s32 var_a2_2;
      s32 var_a3_2;
        var_a1_2 = 0;
        var_a2_2 = 0;
        var_a3_2 = 0;
      temp_v0 = spawnEffectObj(1, var_a1_2, var_a2_2, var_a3_2);
    }
    
    M2C_FIELD(temp_v0, M2C_UNK **, 0xA0) = &func_8004E654;
    func_8004E538(temp_v0, arg1, arg2, arg3);
    return temp_v0;
}
