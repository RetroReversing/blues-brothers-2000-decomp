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

M2C_UNK func_8002710C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002713C(M2C_UNK, s32);                /* extern */
M2C_UNK func_80028410(M2C_UNK, s32, s32, M2C_UNK);  /* extern */
M2C_UNK func_80028FF4(s32, void *);                 /* extern */
s32 func_800291AC(s32);                             /* extern */
s32 func_8002D5CC(void *);                            /* extern */
extern s32 D_800B4D30[];
extern s32 D_800B9C74;
extern s32 D_800BD1D8;
extern s32 D_8014AA98;
typedef struct { s32 w0; s32 w1; } CursorRec8;
extern CursorRec8 *D_80177E18;

void func_80088778(void *arg0) {
    s32 h = 0xC8;
    s32 y; s32 t; CursorRec8 *q; s32 e; s32 i;
    s32 saved;
    s32 w;
    CursorRec8 *p;

    h = 0xC8; w = D_800B9C74 - 0x1E;
    func_8002D5CC(arg0);
    if (M2C_FIELD(arg0, s32 *, 0x64) < -0xC8) {
        (*(M2C_UNK (**)(void *))((s8 *)(arg0) + 0xA0))(arg0);
        return;
    }
        func_8002713C(0x22, 0);
    t = func_800291AC(D_800B4D30[(D_800BD1D8 * 0xB1) + M2C_FIELD(arg0, s32 *, 0x70)]) + 0xA; y = h - t;
    D_8014AA98 = 0;
    func_80028410(0x1E, y, w, h);
    func_8002713C(0x22, y + 5);
    func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
    saved = M2C_FIELD(arg0, s32 *, 0x64);
    i = (D_800BD1D8 * 0xB1) + M2C_FIELD(arg0, s32 *, 0x70);
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    func_80028FF4(D_800B4D30[i], arg0);
    q = D_80177E18;
    M2C_FIELD(arg0, s32 *, 0x64) = saved;
    p = q++;
    D_80177E18 = q;
    p->w0 = 0xE7000000;
    p->w1 = 0;
}
