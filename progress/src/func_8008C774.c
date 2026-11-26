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

typedef struct L8C774 { u8 pad0[0x30]; f32 f30; u8 pad34[0x5C]; f32 f90; } L8C774;
extern f64 D_80009CD8;

u8 *func_8008C774(L8C774 *arg0, u8 *arg1) {
    s32 v;
    f32 d;

    v = *arg1++;
    if (v & 0x80) {
        v |= ~0xFF;
    }
    d = (f32)v / D_80009CD8;
    arg0->f30 = arg0->f30 - arg0->f90 + d;
    arg0->f90 = d;
    return arg1;
}
