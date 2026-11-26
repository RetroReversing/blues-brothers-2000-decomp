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

extern void *D_800B3960;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;

void func_80065BBC(void *arg0) {
    void *temp;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0xC0) = 1;
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        D_800B3974 = 0;
        D_800B3978 = 0;
        do { D_800B3970 = 0; } while (0);
        temp = D_800B3960;
        M2C_FIELD(arg0, s32 *, 0x70) = 0;
        M2C_FIELD(arg0, s32 *, 0x74) = 0;
        M2C_FIELD(arg0, s32 *, 0x78) = 0;
        M2C_FIELD(arg0, s32 *, 0x80) = 0;
        M2C_FIELD(arg0, s32 *, 0x84) = 0;
        M2C_FIELD(arg0, s32 *, 0x88) = 0;
        M2C_FIELD(arg0, s32 *, 0x8C) = 0;
        M2C_FIELD(arg0, s32 *, 0x90) = 0;
        M2C_FIELD(temp, s32 *, 0xC0) = 4;
    }
}
