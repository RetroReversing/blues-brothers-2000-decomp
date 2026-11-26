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

s32 tickActorTimer();                                /* extern */
extern void *D_800B3964;
extern s32 gPadPressed;

void func_8006E994(void *arg0) {
    if (tickActorTimer() != 0) {
        if (M2C_FIELD(D_800B3964, s32 *, 0xBC) != M2C_FIELD(arg0, s32 *, 0xBC)) {
            M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        }
        if (gPadPressed & 0x8000) {
            M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        }
    }
}
