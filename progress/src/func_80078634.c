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

f32 func_8002DD60(f32);                             /* extern */
M2C_UNK func_8003BF98(void *);                      /* extern */
s32 func_8003C9AC(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK animStepKeys(void *);                      /* extern */
s32 func_80081990(void *, s32, f32);                /* extern */
extern f32 D_80009320;
extern void *gCameraTarget;

s32 func_80078634(void *arg0) {
    volatile u64 scratch[2];
    s32 ret;
    f32 temp_fv0;
    s32 temp_s1;
    s32 temp_v0;

    temp_fv0 = M2C_FIELD(arg0, f32 *, 0xB4) + M2C_FIELD(arg0, f32 *, 0xAC);
    M2C_FIELD(arg0, f32 *, 0xB4) = temp_fv0;
    temp_s1 = func_80081990(arg0 + 4, M2C_FIELD(arg0, s32 *, 0x70), temp_fv0);
    if (func_8002DD60(M2C_FIELD(gCameraTarget, f32 *, 0xC) - M2C_FIELD(arg0, f32 *, 0xC)) < D_80009320) {
        animStepKeys(arg0);
    }
    if ((M2C_FIELD(arg0, s32 *, 0xC0) & 1) && (M2C_FIELD(arg0, s32 *, 0x8C) == 0)) {
        if (func_8003C9AC(arg0, 0, 0, 0) != 0) {
            func_8003BF98(arg0);
        }
        M2C_FIELD(arg0, s32 *, 0xC0) = 0;
        M2C_FIELD(arg0, s32 *, 0x8C) = (s32) (M2C_FIELD(arg0, s32 *, 0x8C) + 1);
    }
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x88);
    if (temp_v0 == 0) {
        ret = temp_s1;
    } else {
        M2C_FIELD(arg0, s32 *, 0x88) = (s32) (temp_v0 + 1);
        ret = 0;
    }
    return ret;
}
