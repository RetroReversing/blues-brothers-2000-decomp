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

typedef struct E8D72C {
    u8 pad0[0x44];
    s32 f44;
    u8 pad48[0x56];
    s16 f9E;
    u8 padA0[0x13C - 0xA0];
} E8D72C;
extern s32 D_8017B204;
extern E8D72C *D_8017B20C;

s32 func_8008D72C(s32 arg0, s16 arg1) {
    E8D72C *p;
    s32 i;
    s32 n;

    if (arg0 == 0) {
        return 0;
    }
    i = 0;
    n = 0;
    p = D_8017B20C;
    for (; i < D_8017B204; i++, p++) {
        if (p->f44 == arg0) {
            p->f9E = arg1;
            n++;
        }
    }
    return n;
}
