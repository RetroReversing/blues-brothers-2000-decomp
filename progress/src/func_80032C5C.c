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

M2C_UNK func_8000C458();                            /* extern */
M2C_UNK func_80023C10(s32);                         /* extern */
M2C_UNK func_80023C58(M2C_UNK);                     /* extern */
s32 func_80023D58(s32);                             /* extern */
M2C_UNK func_8002E7B8(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK D_800B4A00;
extern s32 gPadPressed;
extern M2C_UNK func_80032BF0;

void func_80032C5C(void *arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_80032BF0;
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, s32 *, 0x84) = 0;
        gPadPressed = 0;
        M2C_FIELD(arg0, s32 *, 0x64) = 0x2BC;
        func_80023C58(0xB9458F);
        M2C_FIELD(arg0, s32 *, 0x60) = func_80023D58((&D_800B4A00)[M2C_FIELD(arg0, s32 *, 0x70)]);
        func_8002E7B8(0, 0);
    }
    if (gPadPressed & 0x9000) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x84) + 1;
        M2C_FIELD(arg0, s32 *, 0x84) = temp_v0;
        if ((&D_800B4A00)[temp_v0] == 0) {
            M2C_FIELD(arg0, s32 *, 0x84) = 0;
        }
        func_80023C10(M2C_FIELD(arg0, s32 *, 0x60));
        func_8000C458();
        M2C_FIELD(arg0, s32 *, 0x60) = func_80023D58((&D_800B4A00)[M2C_FIELD(arg0, s32 *, 0x84)]);
        M2C_FIELD(arg0, s32 *, 0x94) = 0xA;
    }
}

