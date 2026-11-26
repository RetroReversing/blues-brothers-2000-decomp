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

void func_80017ECC(s32, f32, f32, f32, s32, s32, s32);

void func_8007DD1C(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        func_80017ECC(0xA, 3115.0f, 2538.0f, 655.0f, 0xFFFF6380, -0x19C0, 0);
        func_80017ECC(0xB, 2381.0f, 1134.0f, 5249.0f, 0x1180, -0x40, 0);
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
    }
}
