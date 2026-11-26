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

M2C_UNK func_80033DC4(void *);                      /* extern */
extern void *gCameraRig;
extern void *gCameraTarget;
extern M2C_UNK func_800340B4;
extern M2C_UNK func_800393F4;

s32 func_800182CC(void) {
    if ((M2C_FIELD(gCameraTarget, s32 *, 0x9C) == &func_800393F4) && (M2C_FIELD(gCameraTarget, f32 *, 8) < -997.0f) && (M2C_FIELD(gCameraTarget, f32 *, 0xC) < 3100.0f)) {
        func_80033DC4(gCameraRig);
        M2C_FIELD(gCameraRig, M2C_UNK **, 0x9C) = &func_800340B4;
        return 1;
    }
    return 0;
}
