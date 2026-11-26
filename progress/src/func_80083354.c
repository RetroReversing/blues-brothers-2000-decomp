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

s32 func_800833D0();
extern char D_801719E0[];

void func_80083354(s32 arg0) {
    char *__base_D_801719E0;
    s32 temp_a1;
    void *temp_s0;

    __base_D_801719E0 = D_801719E0;
    temp_a1 = arg0 * 0x28;
    temp_s0 = temp_a1 + __base_D_801719E0;
    if (M2C_FIELD(temp_s0, s32 *, 0xC) == 0) {
        M2C_FIELD((M2C_FIELD(temp_s0, s32 *, 8) + temp_a1 + __base_D_801719E0), s8 *, 0x10) = 1;
        M2C_FIELD(((M2C_FIELD(temp_s0, s32 *, 8) * 2) + temp_a1 + __base_D_801719E0), s16 *, 0x18) = 0xFF;
        M2C_FIELD(temp_s0, s32 *, 8) += 1;
        M2C_FIELD(temp_s0, s32 *, 0xC) = func_800833D0(arg0, temp_a1, __base_D_801719E0);
    }
}
