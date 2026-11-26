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

M2C_UNK animStepKeys();                            /* extern */
M2C_UNK func_80043328(void *, s32, M2C_UNK);        /* extern */
extern M2C_UNK func_8006B8CC;

s32 func_8006BA14(void *arg0) {
    animStepKeys(arg0);
    if (M2C_FIELD(arg0, s32 *, 0x6C) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0xD8) = &func_8006B8CC;
        M2C_FIELD(arg0, s32 *, 0x78) = 7;
        func_80043328(arg0, M2C_FIELD(arg0, s32 *, 0x74) + 7, 0x100);
    }
    return 0;
}
