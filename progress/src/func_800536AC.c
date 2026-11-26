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

s32 tickActorTimer(void *);                         /* extern */
extern s32 D_8014AA9C;

s32 func_800536AC(void *arg0, void *arg1) {
    s32 temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        temp_v1 = M2C_FIELD(arg1, s32 *, 0);
        if (temp_v1 == 2) {
            goto ec;
        }
        if (temp_v1 != 3) {
            goto b;
        }
        M2C_FIELD(arg0, s32 *, 0x64) = (s32) M2C_FIELD(arg1, s32 *, 4);
        goto fc;
ec:
        D_8014AA9C = 1;
        return 0;
b:
        M2C_FIELD(arg0, s32 *, 0x64) = 0x32;
    }
fc:
    return tickActorTimer(arg0) == 0;
}
