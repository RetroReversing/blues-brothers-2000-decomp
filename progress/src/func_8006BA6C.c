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

f32 getCameraTargetDist(void *, f32, M2C_UNK);            /* extern */
M2C_UNK animStepKeys();                            /* extern */
M2C_UNK func_80081188(s32, s32, f32 *);             /* extern */
extern f32 D_80008F34;
extern s32 gCameraTarget;

s32 func_8006BA6C(void *arg0) {
    f32 sp10;
    f32 temp_fs0;
    f32 temp_fs1;
    s32 var_v0;
    s32 var_v1;

    animStepKeys();
    temp_fs1 = 1500.0f;
    temp_fs0 = getCameraTargetDist(arg0, temp_fs1, 0);
    func_80081188(M2C_FIELD(arg0, s32 *, 0x70), gCameraTarget + 4, &sp10);
    var_v1 = 0;
    if (sp10 <= M2C_FIELD(arg0, f32 *, 0x104)) {
        var_v1 = 1;
    }
    M2C_FIELD(arg0, s32 *, 0x64) = 0x12C;
    if ((var_v1 != 0) || (var_v0 = 0, (temp_fs0 < temp_fs1))) {
        M2C_FIELD(arg0, s32 *, 0x8C) = 0;
        var_v0 = 1;
    }
    return var_v0;
}
