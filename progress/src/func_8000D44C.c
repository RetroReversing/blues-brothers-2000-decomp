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

void *spawnEffectObj(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK drawHud;

void func_8000D44C(void) {
    void *temp_v0;

    temp_v0 = spawnEffectObj(6, 0, 0, 0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &drawHud;
    M2C_FIELD(temp_v0, s32 *, 0x68) = 0xF;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 0x64;
}
