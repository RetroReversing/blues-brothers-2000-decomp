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

extern s32 D_800BD100;

extern s32 D_800BD100;
extern u8 D_800BD1F0[];

s32 func_80011388(void) {
    s32 a1;
    u8 *p;
    s32 base;

    a1 = 0;
    p = D_800BD1F0;
    base = D_800BD100 * 0xA;
    for (a1 = 0; a1 < 0xA; a1++) {
        if (((u8 *)(base + a1) + 0)[(s32)p] == 0) {
            return 0;
        }
    }
    return 1;
}
