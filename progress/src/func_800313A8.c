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

M2C_UNK func_8002A360(M2C_UNK, s32);                /* extern */
M2C_UNK func_80030C40();             /* extern */
M2C_UNK func_80062280();                            /* extern */
M2C_UNK func_80062A44();                            /* extern */
s32 func_80062A90();                                /* extern */
extern M2C_UNK gAudioVolume;
extern s32 D_80107040;
extern s32 gPadPressed;
extern s32 D_80171A48;
extern M2C_UNK func_80023078;

void func_800313A8(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        if (D_80171A48 == 0) {
            func_80030C40(arg0, 1);
            return;
        }
        func_8002A360(0, M2C_FIELD(&gAudioVolume, s32 *, 0) * 0x147);
        func_8002A360(1, M2C_FIELD(&gAudioVolume, s32 *, 4) * 0x147);
        func_80062280();
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, s32 *, 0x90) = 0;
        M2C_FIELD(arg0, void **, 0x98) = (void *) (&func_80023078 + 2);
        goto block_4;
    }
block_4:
    if (func_80062A90() != 0) {
        func_80062A44();
        func_8002A360(0x1D, 0);
        func_80030C40(arg0, 1);
        D_80107040 = 0;
        gPadPressed = 0;
    }
}
