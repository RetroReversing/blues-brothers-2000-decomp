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

void *func_800232B4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_8002D5CC();                                /* extern */
extern void *D_800B3960;
extern s32 D_80107040;
extern M2C_UNK func_8006E938;
extern M2C_UNK func_800700DC;

s32 func_8006F284(s32 arg0) {
    void *temp_v0;

    if ((func_8002D5CC(arg0) != 0) && (D_80107040 & 0x9000)) {
        M2C_FIELD(D_800B3960, s32 *, 0x74) = 1;
        M2C_FIELD(D_800B3960, s32 *, 0x7C) = 0;
        temp_v0 = func_800232B4(1, 0, 0, 0);
        M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_8006E938;
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_800700DC;
        M2C_FIELD(temp_v0, s32 *, 0x68) = 9;
    }
    return 0;
}
