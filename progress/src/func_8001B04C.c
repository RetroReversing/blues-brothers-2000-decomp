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

s32 animStepKeys();                                /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK func_8001B098;

void func_8001B04C(void *arg0) {
    if (animStepKeys(arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8001B098;
        M2C_FIELD(arg0, s32 *, 0x64) = 0x64;
        actorSetAnim(arg0, 4, 0x100);
    }
}
