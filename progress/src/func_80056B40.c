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

f32 getCameraTargetDist();
s32 animStepKeys();
extern f32 D_800083FC;
extern s32 func_8000F310;

void func_80056B40(void *arg0) {
    f32 temp_fs0;

    temp_fs0 = getCameraTargetDist(arg0, 0x43C80000, arg0 + 0x10);
    animStepKeys(arg0);
    if (temp_fs0 < D_800083FC) {
        M2C_FIELD(arg0, s32 *, 0) = 0x101;
        M2C_FIELD(arg0, s32 **, 0x9C) = &func_8000F310;
        M2C_FIELD(arg0, s32 *, 0x78) = 9;
    }
}
