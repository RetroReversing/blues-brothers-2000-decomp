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

s32 func_8001B990();
s32 func_80043328();
s32 func_800761FC();
extern s32 func_8000F670;

void func_8006C378(void *arg0_in) {
      s32 temp_v0;
    void *temp_a0;

    if (M2C_FIELD(arg0_in, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0_in, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0_in, s32 *, 0x88) = 1;
        func_80043328(arg0_in, 0xF0, 0xC0);
        func_8001B990(0x200, 0x1A);
        func_800761FC(arg0_in);
        temp_a0 = M2C_FIELD(arg0_in, void **, 0xA8);
        if (temp_a0 != NULL) {
            M2C_FIELD(temp_a0, s32 **, 0x9C) = &func_8000F670;
        }
    } else if (M2C_FIELD(arg0_in, s32 *, 0x84) != 0) {
        temp_v0 = M2C_FIELD(arg0_in, s32 *, 0x5C) - 5;
        M2C_FIELD(arg0_in, s32 *, 0x5C) = temp_v0;
        if (temp_v0 < 5) {
            M2C_FIELD(arg0_in, void (**)(void *), 0xA0)(arg0_in);
        }
    }
}
