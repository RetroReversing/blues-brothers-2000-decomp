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

extern void *D_800B3960;
extern s32 func_80023078;
extern s32 func_800340B4;

void func_80074F74(void *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    M2C_FIELD(D_800B3960, s32 *, 0x9C) = (s32) &func_800340B4;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x8C);
    temp_v1 = temp_v0;
    temp_v0 = temp_v0 + 1;
    M2C_FIELD(arg0, s32 *, 0x8C) = temp_v0;
    if (temp_v1 >= 0xB) {
        M2C_FIELD(arg0, s32 *, 0x9C) = (s32) (&func_80023078 + 2);
    }
}
