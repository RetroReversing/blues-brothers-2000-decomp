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

extern s32 D_800AE134;
extern s32 D_80106A34;
extern s32 *D_80106A38;

void func_800255DC(void *arg0, s32 arg1) {
    s32 temp_a3;
    s32 temp_v1;
    s32 temp;
    s32 temp2;
    s32 temp3;

    do {
    temp = D_800AE134 + 0x10;
    D_800AE134 = temp + arg1;
    temp2 = D_80106A34 - 0x10;
    D_80106A34 = temp2 - arg1;
    temp_a3 = (s32)arg0 - (s32)D_80106A38;
    temp_v1 = *D_80106A38;
    *D_80106A38 = (temp_a3 - 0x10) | 1;
    M2C_FIELD(arg0, s32 *, -8) = arg1;
    temp3 = (((temp_v1 & ~1) - arg1) - temp_a3) | 1;
    *(s32 *)(arg0 + arg1) = temp3;
    } while (0);
}

