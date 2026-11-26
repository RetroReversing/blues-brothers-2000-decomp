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

M2C_UNK func_80027038(M2C_UNK);                     /* extern */
M2C_UNK setTextColor(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800271A8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80029360(s32, void *);                 /* extern */
M2C_UNK debugPrintf(M2C_UNK *);                   /* extern */
extern M2C_UNK D_80008160;
typedef struct { s32 w0; s32 w1; } CursorRec8;
extern CursorRec8 *D_80177E18;

void func_8005321C(void *arg0) {
    s32 temp_s1;
    CursorRec8 *temp_a0;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0x88);
    M2C_FIELD(arg0, s32 *, 0x68) = 0xB;
    func_80027038(0);
    setTextColor(0x20, 0x20, 0x20, 0xFF);
    func_800271A8(0x28, 1);
    if (temp_s1 != 0) {
        func_80029360(temp_s1, arg0);
    } else {
        debugPrintf(&D_80008160);
    }
    temp_a0 = D_80177E18++;
    temp_a0->w0 = 0xE7000000;
    temp_a0->w1 = 0;
}

