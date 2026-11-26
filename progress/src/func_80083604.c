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

extern s32 D_800B9094;
extern s32 D_800B87E4;
extern s32 D_801719E0[];
extern void *D_800B3960;

void func_80083604(void) {
    s32 counter;
    s32 lo;
    s32 hi;

    counter = D_800B9094 + 1;
    D_800B9094 = counter;
    if (counter == 2) {
        lo = D_801719E0[1];
        hi = D_801719E0[11];
        if (hi < lo) {
            D_800B87E4 += 0x1F4;
            M2C_FIELD(D_800B3960, s32 *, 0x94) = 1;
        } else if (lo < hi) {
            D_800B87E4 -= 0x1F4;
            M2C_FIELD(D_800B3960, s32 *, 0x94) = counter;
        }
        D_800B9094 = 0;
    }
    if (D_800B87E4 < -0xBB8) {
        D_800B87E4 = -0xBB8;
    }
    if (D_800B87E4 >= 0xBB9) {
        D_800B87E4 = 0xBB8;
    }
    M2C_FIELD(D_800B3960, s32 *, 0x74) = D_800B87E4;
}
