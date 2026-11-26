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

typedef struct Y91894B { u8 pad0[0x14]; s32 f14; } Y91894B;
typedef struct Y91894A { u8 pad0[0x1C]; Y91894B *f1C; } Y91894A;
s32 func_80092968(s32);

s32 func_80091894(Y91894A *arg0) {
    if (arg0 == NULL || arg0->f1C == NULL || arg0->f1C->f14 == 0) {
        return -2;
    }
    return func_80092968(arg0->f1C->f14);
}
