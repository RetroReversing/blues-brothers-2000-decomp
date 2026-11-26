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

M2C_UNK func_80023C58(s32);                         /* extern */
M2C_UNK func_80023C64(M2C_UNK);                     /* extern */
M2C_UNK sendCommand(M2C_UNK, M2C_UNK);            /* extern */
s32 approachS32(M2C_UNK, s32, M2C_UNK);           /* extern */
s32 tickActorTimer(void *);                          /* extern */
M2C_UNK func_8002E79C();                            /* extern */
M2C_UNK func_80030C40(void *, M2C_UNK);             /* extern */
extern s32 D_800AE010;
extern s32 D_800B9C70;
extern s32 gPadPressed;
extern M2C_UNK func_80023078;
extern M2C_UNK func_8003186C;

void func_800329A8(void *arg0) {
    M2C_UNK var_a0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x94) = 1;
        M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_8003186C;
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, s32 *, 0x6C) = 0;
        gPadPressed = 0;
        M2C_FIELD(arg0, s32 *, 0x90) = (s32) D_800AE010;
        M2C_FIELD(arg0, s32 *, 0x64) = 0x2BC;
        func_80023C58(0xB9458F);
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x94) != 0)
    {
      M2C_FIELD(arg0, s32 *, 0x6C) = approachS32(0xFF, M2C_FIELD(arg0, s32 *, 0x6C), 5);
    }
    else
    {
      M2C_FIELD(arg0, s32 *, 0x6C) = approachS32(0, M2C_FIELD(arg0, s32 *, 0x6C), 5);
    }
    if (M2C_FIELD(arg0, s32 *, 0x94) != 0) {
        if ((tickActorTimer(arg0) != 0) || (gPadPressed & 0x9000)) {
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA0);
            M2C_FIELD(arg0, s32 *, 0x94) = 0;
        }
        if (M2C_FIELD(arg0, s32 *, 0x94) == 0) {
            goto block_9;
        }
    } else {
block_9:
        if (M2C_FIELD(arg0, s32 *, 0x6C) == 0) {
            func_8002E79C();
            M2C_FIELD(arg0, M2C_UNK **, 0x98) = (M2C_UNK *) (&func_80023078 + 2);
            func_80030C40(arg0, 1);
            func_80023C58(M2C_FIELD(arg0, s32 *, 0x90));
            func_80023C64(0xB9458F);
            D_800B9C70 = 1;
        }
    }
}
