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
M2C_UNK func_80050460(void *, M2C_UNK *);           /* extern */
M2C_UNK func_800852CC(void *, s32);                 /* extern */
extern M2C_UNK D_8014AA5A;
extern M2C_UNK func_8005AE84;
extern M2C_UNK func_8005B0E8;

void *func_8005AF60(s32 arg0) {
    void *temp_v0;

    func_80050460((char *)&func_8005AE84 + 0xC, &D_8014AA5A);
    temp_v0 = func_800232B4(1, 0, 0, 0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8005B0E8;
    M2C_FIELD(temp_v0, s32 *, 0x68) = -1;
    func_800852CC(temp_v0, arg0);
    return temp_v0;
}
