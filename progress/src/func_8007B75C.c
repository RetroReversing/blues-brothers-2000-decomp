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

M2C_UNK func_8003BB90(void *);
s32 func_8003BF98(void *);
extern s32 D_800B396C;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern void *D_800BD06C;

void func_8007B75C(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        D_800B3970 = 0;
        D_800B3974 = 0;
        D_800B3978 = 0x40;
        D_800B396C = 0x3DE;
    }
    if (M2C_FIELD(D_800BD06C, f32 *, 8) < -1150.0f) {
        if (func_8003BF98(D_800BD06C) != 0) {
            func_8003BB90(D_800BD06C);
        }
    }
}
