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

s32 func_800918E0(M2C_UNK, s32, u32);               /* extern */
M2C_UNK func_80092920(s32, s32, u32);               /* extern */

s32 func_80091694(void *arg0, s32 arg1, u32 arg2) {
    s32 temp_v1_2;
    
    u32 temp_s3;
    
    void *temp_a0;
    void *temp_v1;
    temp_s3 = arg2;
    if ((arg0 == NULL) || (temp_v1 = M2C_FIELD(arg0, void **, 0x1C), (temp_v1 == NULL)) || (M2C_FIELD(temp_v1, s32 *, 0) != 6)) {
        return -2;
    }
    if (func_800918E0(1, arg1, arg2) == M2C_FIELD(arg0, s32 *, 0x30)) {
        do { temp_a0 = M2C_FIELD(arg0, void **, 0x1C); } while (0);
        M2C_FIELD(arg0, s32 *, 0x30) = 1;
        do { do { do { temp_v1_2 = M2C_FIELD(temp_a0, s32 *, 0x10); } while (0); } while (0); } while (0);
        if ((arg2 >> temp_v1_2) != 0) {
            arg2 = (1 << temp_v1_2) - 1;
            do { arg1 += temp_s3 - arg2; } while (0);
        }
        func_80092920(M2C_FIELD(temp_a0, s32 *, 0x14), arg1, arg2);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s32 *, 0) = 7;
        return 0;
    }
    return -3;
}
