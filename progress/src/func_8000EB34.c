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

s32 tickActorTimer();                                /* extern */
M2C_UNK func_800393F4(void *);                      /* extern */
extern s32 D_80107040;
extern s32 gPadPressed;
extern s32 gStickX;
extern s32 gStickY;

void func_8000EB34(void *arg0) {
    if (tickActorTimer(arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x9C) = func_800393F4;
        return;
    }
    gStickY = 0;
    gStickX = 0;
    D_80107040 = 0;
    gPadPressed = 0;
    func_800393F4(arg0);
}
