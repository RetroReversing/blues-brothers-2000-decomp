/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_8000C43C();                                /* extern */
M2C_UNK func_8000C874(s16);                         /* extern */
s32 func_8002D5CC(void *);                          /* extern */
f32 func_8002D66C(void *, f32, s32 *);            /* extern */
extern u8 D_800BCFB8[];
extern s32 *D_800BD06C;
typedef struct { s16 x0; u16 x2; u16 x4; u16 x6; u16 x8; s16 xA; } Snd;
extern Snd D_801700B8;
extern M2C_UNK func_80023078;

void func_800729C4(void *arg0) {
    f32 r;
    f32 f;
    s16 v;

    if (M2C_FIELD(arg0, s32 *, 0x90) == 0) {
        M2C_FIELD(arg0, s32 *, 0x90) = 1;
        M2C_FIELD(arg0, s32 *, 0) = 0x816;
        M2C_FIELD(arg0, s32 *, 0xC0) = 0;
        if (M2C_FIELD(arg0, s32 *, 0x84) != 0) {
            M2C_FIELD(arg0, s32 *, 0x68) = -1;
        }
        M2C_FIELD(arg0, s32 *, 0x64) = 0x190;
        if ((M2C_FIELD(arg0, s32 *, 0x74) + M2C_FIELD(arg0, s32 *, 0x78) + M2C_FIELD(arg0, s32 *, 0x7C)) == 0) {
            M2C_FIELD(arg0, void **, 0x9C) = (void *) (&func_80023078 + 2);
            M2C_FIELD(arg0, s32 *, 0x68) = -1;
            return;
        }
    }
    if ((M2C_FIELD(arg0, s32 *, 0x88) == 0) && (func_8002D5CC(arg0) != 0)) {
        if (*D_800BD06C != 3) {
            M2C_FIELD(arg0, s32 *, 0xC0) = 0;
            return;
        }
        r = 200.0f;
        f = func_8002D66C(arg0, r, 0);
        M2C_FIELD(arg0, s32 *, 0x64) = 0;
        if (r <= f) {
            M2C_FIELD(arg0, s32 *, 0xC0) = 1;
            return;
        }
        if (M2C_FIELD(arg0, s32 *, 0xC0) != 0) {
            D_801700B8.x0 = 1;
            D_801700B8.x4 = M2C_FIELD(arg0, u16 *, 0x76);
            D_801700B8.x6 = M2C_FIELD(arg0, u16 *, 0x7A);
            D_801700B8.x8 = M2C_FIELD(arg0, u16 *, 0x7E);
            D_801700B8.x2 = M2C_FIELD(arg0, u16 *, 0x82);
            D_800BCFB8[func_8000C43C()] = 1;
            v = ((D_801700B8.x4 & 7) << 9) | ((D_801700B8.x6 & 0xF) << 5) | ((M2C_FIELD(arg0, u16 *, 0x72) & 0xF) * 2);
            if (D_801700B8.x2 != 0) {
                v |= 1;
            }
            D_801700B8.xA = v;
            func_8000C874(v);
        }
    }
}
