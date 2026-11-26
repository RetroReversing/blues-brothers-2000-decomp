/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

s32 func_80023D58(M2C_UNK);                         /* extern */
extern f64 D_800090F8;
extern void *gCameraRig;
extern void *D_800B3964;
extern void *gCameraTarget;
extern s32 D_8014002C;
extern M2C_UNK func_80023078;
extern M2C_UNK func_80073328;

void func_80073394(void *arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
        M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_80073328;
        M2C_FIELD(arg0, s32 *, 0x60) = func_80023D58(0x211);
    }
    if ((M2C_FIELD(gCameraRig, s32 *, 0xC0) != 0) && (D_800090F8 < (f64) M2C_FIELD(gCameraTarget, f32 *, 8))) {
        if (M2C_FIELD(D_800B3964, s32 *, 0x90) == 0) {
            M2C_FIELD(arg0, s32 *, 0x68) = -1;
        } else {
            M2C_FIELD(arg0, s32 *, 0x68) = 0xD;
        }
        D_8014002C = 1;
    } else {
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
    }
    if (M2C_FIELD(D_800B3964, s32 *, 0x9C) == (&func_80023078 + 2)) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
