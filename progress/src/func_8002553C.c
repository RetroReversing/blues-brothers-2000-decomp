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
s32 func_800255DC();
extern s32 D_800B9C74;
extern s32 D_800B9C78;
extern s32 D_80106A30;
extern s32 D_80106A34;
extern s32 D_80106A38;

void func_8002553C(s32 arg0, s32 arg1) {
    s32 *__base_D_800B9C74;
    s32 temp_a0;
    s32 temp_lo;
    u32 temp_a1_3;
    s32 temp2;

    s32 *p34 = &D_80106A34;
    s32 *p38 = &D_80106A38;
    temp_a0 = (arg0 + 7) & ~7;
    *p38 = temp_a0;
    D_80106A30 = arg1 & ~7;
    temp_lo = (arg1 & ~7) - temp_a0;
    *p34 = temp_lo;
    temp_a1_3 = ((temp_lo - 0x10) & ~7) | 1;
    *(u32 *)temp_a0 = temp_a1_3;
    *(s32 *)((s8 *)(((temp_a1_3 >> 2) * 4) + temp_a0) + 8) = -2;
    __base_D_800B9C74 = &D_800B9C74;
    if ((*__base_D_800B9C74) == 0x140) {
        s32 temp;
        temp = D_800B9C78 * 2;
        temp2 = temp * D_800B9C74;
        temp_lo = temp2;
        func_800255DC(0x80200000 - (temp_lo * 2), temp_lo * 6);
    }
}
