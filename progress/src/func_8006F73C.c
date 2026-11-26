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

s32 tickActorTimer(void *);                          /* extern */
M2C_UNK stepFadeUp(void *);                      /* extern */
s32 pollMenuInput(M2C_UNK);                         /* extern */
extern void *gCameraRig;
extern void *D_800B3964;
extern s32 D_80107040;

void func_8006F73C(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x68) == -1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0xA0)();
        return;
    }
    stepFadeUp(arg0 + 0x6C);
    if (M2C_FIELD(D_800B3964, s32 *, 0xBC) != M2C_FIELD(arg0, s32 *, 0xBC)) {
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
    }
    if (M2C_FIELD(gCameraRig, s32 *, 0x74) != M2C_FIELD(arg0, s32 *, 0x74)) {
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
    }
    if ((M2C_FIELD(arg0, s32 *, 0x68) != -1) && (tickActorTimer(arg0) != 0)) {
        if (pollMenuInput(0x14) != 0) {
            M2C_FIELD(gCameraRig, s32 *, 0x74) = (s32) (M2C_FIELD(gCameraRig, s32 *, 0x74) + 1);
        }
        if (D_80107040 & 0x9000) {
            M2C_FIELD(D_800B3964, s32 *, 0x90) = 0x2000;
        }
    }
}
