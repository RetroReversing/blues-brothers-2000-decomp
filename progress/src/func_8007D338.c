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

extern s32 D_801704E0;

s32 func_8007D338(void) {
    void *base;
    f32 r;

    base = &D_801704E0;
    if (M2C_FIELD(base, s32 *, 0x7C) == 0) {
        M2C_FIELD(base, f32 *, 4) = 160.0f;
        M2C_FIELD(base, f32 *, 8) = 120.0f;
        if (M2C_FIELD(base, f32 *, 0x4C) == 0.0f) {
            do {
                r = (f32) func_80024394(-5, 5);
                M2C_FIELD(base, f32 *, 0x4C) = r;
            } while (r == 0.0f);
        }
        if (M2C_FIELD(base, f32 *, 0x50) == 0.0f) {
            do {
                r = (f32) func_80024394(-5, 5);
                M2C_FIELD(base, f32 *, 0x50) = r;
            } while (r == 0.0f);
        }
        M2C_FIELD(base, s32 *, 0x7C) = 1;
        M2C_FIELD(base, s32 *, 0x64) = 0x5DC0;
    }
    func_8007D860();
    return func_8002D5CC(base) != 0;
}
