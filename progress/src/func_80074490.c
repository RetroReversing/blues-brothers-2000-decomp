/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 tickActorTimer();                                /* extern */
extern void *gCameraRig;
extern void *D_800B3964;
extern s32 D_800B5DD4;
extern void *gCameraTarget;
extern M2C_UNK func_80023078;
extern M2C_UNK func_800340B4;
extern M2C_UNK func_800393F4;

void func_80074490(void *arg0) {
    if (tickActorTimer() != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        if (M2C_FIELD(D_800B3964, s32 *, 0x9C) != (&func_80023078 + 2)) {
            D_800B5DD4 = 1;
            if (M2C_FIELD(gCameraRig, M2C_UNK **, 0x9C) != &func_800340B4) {
                M2C_FIELD(gCameraRig, M2C_UNK **, 0x9C) = &func_800340B4;
                M2C_FIELD(gCameraRig, s32 *, 0xA8) = 0;
                M2C_FIELD(gCameraTarget, M2C_UNK **, 0x9C) = &func_800393F4;
                M2C_FIELD(D_800B3964, s32 *, 0x8C) = (s32) (M2C_FIELD(D_800B3964, s32 *, 0x8C) + 1);
            }
        }
    }
}
