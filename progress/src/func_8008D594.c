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

typedef struct E8D594 {
    s32 flags;
    s32 f4;
    u8 pad8[0x70];
    s32 f78;
    u8 pad7C[0x13C - 0x7C];
} E8D594;
extern s32 D_8017B204;
extern E8D594 *D_8017B20C;

s32 func_8008D594(s32 arg0) {
    E8D594 *p;
    s32 i;
    s32 n;

    n = 0;
    i = 0;
    p = D_8017B20C;
    for (; i < D_8017B204; i++, p++) {
        if (p->f4 == 0) {
            continue;
        }
        if (p->f78 != 0 ? (arg0 & 1) : (arg0 & 2)) {
            n++;
        }
    }
    return n;
}
