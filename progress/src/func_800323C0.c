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

M2C_UNK sendCommand(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80030C40(void *, M2C_UNK);             /* extern */
M2C_UNK updateMenuScroll(void *, M2C_UNK);             /* extern */
extern s32 D_800BD1D8;
extern s32 gPadPressed;
extern M2C_UNK func_80023078;
extern M2C_UNK func_80032314;

void func_800323C0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_80032314;
        M2C_FIELD(arg0, s32 *, 0x78) = 0;
    }
    updateMenuScroll(arg0, 6);
    if (gPadPressed & 0x9000) {
        M2C_FIELD(arg0, M2C_UNK **, 0x98) = (M2C_UNK *) (&func_80023078 + 2);
        D_800BD1D8 = M2C_FIELD(arg0, s32 *, 0x78);
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x9F);
        func_80030C40(arg0, 1);
    }
}
