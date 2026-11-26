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

s32 initControllerPaks();                                /* extern */
s32 func_80026164(M2C_UNK);                         /* extern */
M2C_UNK refreshControllerPak(M2C_UNK);                     /* extern */
M2C_UNK func_800263F4();                            /* extern */
M2C_UNK func_8002642C();                            /* extern */
M2C_UNK func_80026C04(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80030C40(void *, M2C_UNK);             /* extern */
M2C_UNK func_80032830();                   /* extern */
extern s32 gPakInitWarn;
extern s32 gPakInitError;
extern s32 D_800AE1A0;
extern s32 D_800B499C;
extern s32 D_800B49A0;
extern s32 D_800B49A4;
extern s32 D_800B49A8;
extern M2C_UNK D_8014ABC0;
extern M2C_UNK func_80023078;

typedef struct { unsigned char pad_0[152]; void * field_98; unsigned char pad_9C[96]; int field_FC; } __repair_record_arg0;
void func_800333D0(void *arg0) {
    s32 flag;

    flag = 0;
    M2C_FIELD(arg0, void **, 0x98) = (void *) (&func_80023078 + 2);
    gPakInitWarn = 0;
    refreshControllerPak(flag);
    gPakInitError = 0;
    D_800B49A4 = initControllerPaks();
    switch (D_800B49A4) {
    case 0:
    case 2:
        func_80030C40(arg0, 1);
        return;
    case 1:
    case 3:
        func_800263F4();
        D_800B499C = func_80026164(0);
        func_8002642C();
        if (D_800B499C != 0) {
            func_80032830();
        } else {
            func_80026C04(&D_8014ABC0, 0, 0x21C);
        }
        if ((D_800B49A0 == 0) && ((D_800B499C == 0x10) || ((D_800AE1A0 / 256) < 3))) {
            flag = 1;
        }
        if (gPakInitWarn != 0) {
            M2C_FIELD(arg0, s32 *, 0xFC) = 0;
            func_80026C04(&D_8014ABC0, 0, 0x21C);
            func_80030C40(arg0, 2);
        } else if (flag != 0) {
            func_80030C40(arg0, 6);
        } else if (D_800B49A8 != 0) {
            s32 t = M2C_FIELD(arg0, s32 *, 0xFC);
            D_800B49A8 = 0;
            if (t != 0) {
                M2C_FIELD(arg0, s32 *, 0xFC) = 0;
                func_80030C40(arg0, 7);
            } else {
                func_80030C40(arg0, 8);
            }
        } else {
            func_80030C40(arg0, 8);
        }
        return;
    }
}
