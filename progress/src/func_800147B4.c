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

extern s32 D_800BD0E0;

void func_800147B4(void) {
    s32 *__base_D_800BD0E0;
    s32 *temp_v1;

    __base_D_800BD0E0 = &D_800BD0E0;
    temp_v1 = (s32 *)((s8 *)__base_D_800BD0E0 + (*(s32 *)((s8 *)__base_D_800BD0E0 + 0x20)) * 4);
    temp_v1[1] = temp_v1[1] + 7;
}
