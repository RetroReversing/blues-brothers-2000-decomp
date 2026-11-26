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
extern void *D_800B3960;
extern M2C_UNK func_8001FF64;

void func_80012C9C(void) {
    void *temp_v0;

    temp_v0 = func_800232B4(0x8001, 0, 0, 0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8001FF64;
    D_800B3960 = temp_v0;
}
