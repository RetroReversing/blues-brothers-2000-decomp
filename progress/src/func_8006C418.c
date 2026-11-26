/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

f32 func_8002D858();
s32 func_8004303C();
s32 func_80043248();
s32 func_80043328();
s32 func_8006C264();
s32 func_8006C378();

void func_8006C418(void *arg0) {
    s32 (*temp_v0)(void *);
    s32 temp_a0;

    M2C_FIELD(arg0, s32 *, 0x90) = (s32) func_8002D858(arg0, arg0 + 0x8C);
    if (M2C_FIELD(arg0, s32 *, 0x88) != 0) {
        M2C_FIELD(arg0, s32 *, 0x84) = func_80043248(arg0);
    } else {
        M2C_FIELD(arg0, s32 *, 0x84) = func_8004303C(arg0);
    }
    if (M2C_FIELD(arg0, s32 *, 0xD0) == 0xF1) {
        if (M2C_FIELD(arg0, s32 *, 0x84) != 0) {
            M2C_FIELD(arg0, s32 *, 0x7C) = 0;
            M2C_FIELD(arg0, s32 (**)(void *), 0xD8) = func_8006C264;
            goto block_6;
        }
    } else {
block_6:
        temp_a0 = M2C_FIELD(arg0, s32 *, 0xD0);
        if ((temp_a0 != 0xF0) && (M2C_FIELD(arg0, s32 *, 0xC0) & ~1) && (temp_a0 != 0xF1)) {
            M2C_FIELD(arg0, s32 *, 0xFC) -= 1;
            func_80043328(arg0, 0xF1, 0xF0);
            M2C_FIELD(arg0, s32 *, 0xF0) = 0x80;
            M2C_FIELD(arg0, s32 *, 0x88) = 1;
            M2C_FIELD(arg0, s32 *, 0x84) = 0;
            if (M2C_FIELD(arg0, s32 *, 0xFC) <= 0) {
                M2C_FIELD(arg0, s32 *, 0xF0) = 0xFF;
                M2C_FIELD(arg0, s32 *, 0x7C) = 0;
                M2C_FIELD(arg0, s32 (**)(void *), 0xD8) = func_8006C378;
            }
            M2C_FIELD(arg0, s32 *, 0xC0) = 0;
        }
        temp_v0 = M2C_FIELD(arg0, s32 (**)(void *), 0xD8);
        if (temp_v0 != NULL) {
            temp_v0(arg0);
        }
    }
}
