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

typedef struct { u32 w0; u32 w1; } Gfx;
extern Gfx *D_80177E18;

void func_80027060(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Gfx *temp_t0;

    temp_t0 = D_80177E18++;
    temp_t0->w0 = 0xFA000000;
    temp_t0->w1 = (u32) ((arg0 << 0x18) | ((arg1 & 0xFF) << 0x10) | ((arg2 & 0xFF) << 8) | (arg3 & 0xFF));
}
