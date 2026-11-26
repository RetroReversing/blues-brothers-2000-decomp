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

s32 cameraGetMode();                                /* extern */
extern s32 D_800B4C28;
extern M2C_UNK D_800BD278;
extern M2C_UNK D_800BD688;

s32 func_8000F7A0(void *arg0) {
    s32 margin;
    s32 changed;
    f32 t;

    margin = 0xA;
    changed = 0;
    if (cameraGetMode() == 3) {
        margin = 0x1F4;
    }
    t = (f32) (M2C_FIELD(&D_800BD278, s32 *, 0) + margin);
    if (M2C_FIELD(arg0, f32 *, 4) < t) {
        changed = 1;
        M2C_FIELD(arg0, f32 *, 4) = t;
    }
    t = (f32) (M2C_FIELD(&D_800BD278, s32 *, 8) + margin);
    if (M2C_FIELD(arg0, f32 *, 0xC) < t) {
        changed = 1;
        M2C_FIELD(arg0, f32 *, 0xC) = t;
    }
    t = (f32) (M2C_FIELD(&D_800BD688, s32 *, 0) - margin);
    if (t < M2C_FIELD(arg0, f32 *, 4)) {
        changed = 1;
        M2C_FIELD(arg0, f32 *, 4) = t;
    }
    t = (f32) (M2C_FIELD(&D_800BD688, s32 *, 8) - margin);
    if (t < M2C_FIELD(arg0, f32 *, 0xC)) {
        changed = 1;
        M2C_FIELD(arg0, f32 *, 0xC) = t;
    }
    t = (f32) (M2C_FIELD(&D_800BD688, s32 *, 4) - margin);
    if (t < M2C_FIELD(arg0, f32 *, 8)) {
        changed = 1;
        M2C_FIELD(arg0, f32 *, 8) = t;
    }
    t = (f32) D_800B4C28;
    if (M2C_FIELD(arg0, f32 *, 8) < t) {
        M2C_FIELD(arg0, f32 *, 8) = t;
        M2C_FIELD(arg0, s32 *, 0x50) = 0;
        changed = 1;
    }
    return changed;
}
