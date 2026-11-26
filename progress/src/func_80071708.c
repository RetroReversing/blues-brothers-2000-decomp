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

s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
s32 func_8004303C(void *);                          /* extern */
M2C_UNK func_80043328(void *, s32, M2C_UNK);        /* extern */

void func_80071708(void *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = (s32) M2C_FIELD(arg0, s32 *, 0xD0);
        M2C_FIELD(arg0, s32 *, 0x8C) = func_80024394(1, 4);
    }
    temp_v0 = func_8004303C(arg0);
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v0;
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s32 *, 0x8C) = (s32) (M2C_FIELD(arg0, s32 *, 0x8C) - 1);
    }
    if (M2C_FIELD(arg0, s32 *, 0x8C) <= 0) {
        M2C_FIELD(arg0, s32 *, 0x8C) = func_80024394(1, 4);
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x7C) + 1;
        M2C_FIELD(arg0, s32 *, 0x7C) = temp_v1;
        if (temp_v1 >= 0x147) {
            M2C_FIELD(arg0, s32 *, 0x7C) = 0x144;
        }
        func_80043328(arg0, M2C_FIELD(arg0, s32 *, 0x7C), 0x100);
    }
}
