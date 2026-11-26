/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

extern void *D_800BD06C;
extern M2C_UNK func_8004303C;

void func_80052A30(void) {
    M2C_FIELD(D_800BD06C, M2C_UNK **, 0x9C) = &func_8004303C;
    M2C_FIELD(D_800BD06C, s32 *, 0) = 3;
    M2C_FIELD(D_800BD06C, s32 *, 0x50) = 0;
    M2C_FIELD(D_800BD06C, s32 *, 0x90) = 1;
}
