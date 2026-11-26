/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_BITS_F32(expr) (m2c_bits = (u32)(expr), *(f32 *)&m2c_bits)
extern u32 m2c_bits;
#define M2C_PTR_FROM_F32(type, expr) ((type)(m2c_fbits = (expr), *(u32 *)&m2c_fbits))
extern f32 m2c_fbits;
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

/* a branch below leaves the function (its target is before or after what the project filed as this function): it is drafted as a return, so check where this function really starts and ends */
s32 func_80043248();
extern s32 D_800B9ECC;

s32 func_8005CAB0(void *arg0) {
    s32 temp_v1;
    s32 var_v0;
    void *temp_s1;

    var_v0 = M2C_FIELD(arg0, s32 *, 0x70);
    temp_s1 = M2C_FIELD(arg0, s32 **, 0xA4);
    if (var_v0 == 0) {
        var_v0 = 1;
        if (temp_s1 != NULL) {
            var_v0 = M2C_FIELD(temp_s1, s32 *, 0x90) < 2;
            if (var_v0 == 0) {
                var_v0 = 1;
                if (M2C_FIELD(temp_s1, s32 *, 0x8C) >= 2) {
                    M2C_FIELD(arg0, s32 *, 0x70) = 1;
                    var_v0 = M2C_FIELD(arg0, s32 *, 0x70);
                    if (var_v0 != 0) {
                        var_v0 = 1;
                        if (func_80043248(arg0) != 0) {
                            M2C_FIELD(arg0, s32 *, 0x74) = 1;
                            var_v0 = (s32) &D_800B9ECC;
                            if (M2C_FIELD(arg0, s32 *, 0x74) != 0) {
                                var_v0 = *(s32 *)(s32) &D_800B9ECC * 0xC;
                                temp_v1 = M2C_FIELD(arg0, s32 *, 0x5C) - var_v0;
                                M2C_FIELD(arg0, s32 *, 0x5C) = temp_v1;
                                if (temp_v1 < 0xA) {
                                    if (temp_s1 != NULL) {
                                        M2C_FIELD(temp_s1, s32 *, 0xA8) = 0;
                                        return var_v0;
                                    }
                                    return M2C_FIELD(arg0, s32 (**)(void *), 0xA0)(arg0);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return var_v0;
}
