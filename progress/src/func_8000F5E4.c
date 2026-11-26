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
u32 func_80023088(s32);
u32 func_800230B0(s32);
extern void *D_800B3960;
extern void *gCameraTarget;
extern s32 updateCameraView;
extern s32 func_80023078;
extern s32 animStepKeys;
void func_8000F5E4(void) {
    u32 var_s0;

    M2C_FIELD(gCameraTarget, s32 **, 0x9C) = &func_80023078 + 2;
    M2C_FIELD(D_800B3960, s32 **, 0x9C) = &updateCameraView;
    for (var_s0 = func_80023088(0); var_s0 < func_800230B0(0); var_s0 += 0x108) {
        if (M2C_FIELD(var_s0, s32 *, 0) & 0x1000) {
            M2C_FIELD(var_s0, s32 **, 0x9C) = &animStepKeys;
        }
    }
}
