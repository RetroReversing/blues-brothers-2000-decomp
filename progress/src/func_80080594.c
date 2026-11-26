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

s32 func_800239E0();                                /* extern */
s32 func_8002E374(s32);                             /* extern */
s32 func_80076BF0(M2C_UNK);                         /* extern */
M2C_UNK func_80080518(s32, s32);                    /* extern */

s32 func_80080594(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s1;
    
s32 __repair_phase_var_v0;

    var_s1 = arg1;
    temp_v0 = func_800239E0();
    if (temp_v0) return temp_v0;
        if (arg0 == 0) {
            return func_80076BF0(0);
        }
        if (var_s1 < 0) {
            var_s1 = 0;
        }
        if (var_s1 >= 4) {
            var_s1 = 3;
        }
        temp_v0 = func_8002E374(var_s1 + 0xA4);
        func_80080518(temp_v0, arg0);
        __repair_phase_var_v0 = temp_v0;
        /* Duplicate return node #8. Try simplifying control flow for better match */
        return __repair_phase_var_v0;
    
    return temp_v0;
}
