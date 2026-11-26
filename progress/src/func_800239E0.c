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

extern s32 D_800AB9B8;
extern M2C_UNK D_800DA738;

M2C_UNK *func_800239E0(void) {
    M2C_UNK *__base_D_800DA738;
    if (D_800AB9B8 >= 0x17F) {
        __base_D_800DA738 = &D_800DA738;
        return __base_D_800DA738;
    }
    return NULL;
}
