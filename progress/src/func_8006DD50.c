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

s32 func_8002ECB8();                                /* extern */
M2C_UNK func_8006DD34(M2C_UNK);                     /* extern */
extern void *D_800B3964;

void func_8006DD50(void *arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0xC0) == 0) {
        if (func_8002ECB8() != 0) {
            M2C_FIELD(D_800B3964, s32 *, 0x90) = (s32) M2C_FIELD(arg0, s32 *, 0x90);
            M2C_FIELD(arg0, s32 *, 0xC0) = (s32) (M2C_FIELD(arg0, s32 *, 0xC0) + 1);
        }
    } else {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x7C) + 1;
        M2C_FIELD(arg0, s32 *, 0x7C) = temp_v0;
        if (temp_v0 >= 3) {
            func_8006DD34(0);
            M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        }
    }
}
