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

M2C_UNK func_80090E50(void *);                      /* extern */
M2C_UNK func_80090EB4(void *);                      /* extern */
s32 func_80091BA0(void *, M2C_UNK *, s32);          /* extern */
extern M2C_UNK func_800918E0;
extern M2C_UNK func_800942C8;
extern M2C_UNK func_80094324;

s32 func_80090F2C(void *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    M2C_UNK *var_a1;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_v0;
    void *temp_v0;

    var_s1 = arg1;
    if ((arg2 == NULL) || (((*arg2 != 0x31) | (arg3 != 0x38)) != 0)) {
        return -6;
    }
    var_v0 = -2;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x18) = 0;
        if (M2C_FIELD(arg0, void *(**)(s32, M2C_UNK, M2C_UNK), 0x20) == NULL) {
            M2C_FIELD(arg0, void *(**)(s32, M2C_UNK, M2C_UNK), 0x20) = (void *(*)(s32, M2C_UNK, M2C_UNK)) (&func_800942C8 + 0xe);
            M2C_FIELD(arg0, s32 *, 0x28) = 0;
        }
        if (M2C_FIELD(arg0, M2C_UNK **, 0x24) == NULL) {
            M2C_FIELD(arg0, M2C_UNK **, 0x24) = &func_80094324;
        }
        temp_v0 = M2C_FIELD(arg0, void *(**)(s32, M2C_UNK, M2C_UNK), 0x20)(M2C_FIELD(arg0, s32 *, 0x28), 1, 0x18);
        M2C_FIELD(arg0, void **, 0x1C) = temp_v0;
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s32 *, 0x14) = 0;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s32 *, 0xC) = 0;
            if (var_s1 < 0) {
                var_s1 = -var_s1;
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s32 *, 0xC) = 1;
            }
            if ((u32) (var_s1 - 8) >= 8U) {
                func_80090EB4(arg0);
                return -2;
            }
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s32 *, 0x10) = var_s1;
            var_a1 = NULL;
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s32 *, 0xC) == 0) {
                var_a1 = &func_800918E0;
            }
            temp_v0_2 = func_80091BA0(arg0, var_a1, 1 << var_s1);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s32 *, 0x14) = temp_v0_2;
            if (temp_v0_2 != 0) {
                func_80090E50(arg0);
                return 0;
            }
            func_80090EB4(arg0);
            goto block_18;
        }
block_18:
        var_v0 = -4;
        /* Duplicate return node #19. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
