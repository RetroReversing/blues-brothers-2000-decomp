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

M2C_UNK updateCameraView(void *);                      /* extern */
s32 tickActorTimer();                                /* extern */
extern void *gCameraRig;
extern M2C_UNK func_80023078;

void func_8001D2C0(void *arg0) {
    if (tickActorTimer() != 0) {
        M2C_FIELD(gCameraRig, s32 *, 0xC0) = 0;
        M2C_FIELD(gCameraRig, s32 *, 0x9C) = (s32) M2C_FIELD(gCameraRig, s32 *, 0xA4);
        updateCameraView(gCameraRig);
        M2C_FIELD(arg0, void **, 0x9C) = (void *) (&func_80023078 + 2);
    }
}
