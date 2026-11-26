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

s32 func_80024AC4(s32, M2C_UNK);                    /* extern */
s32 func_80025100(s32, s32);                        /* extern */
f32 func_8002DD60(f32);                    /* extern */
M2C_UNK func_8004303C(void *);                      /* extern */

void func_80050B3C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x84) = (s32) ((f32) M2C_FIELD(arg0, s32 *, 0x84) + M2C_FIELD(arg0, f32 *, 0x4C));
    M2C_FIELD(arg0, s32 *, 0x88) = (s32) ((f32) M2C_FIELD(arg0, s32 *, 0x88) + M2C_FIELD(arg0, f32 *, 0x50));
    M2C_FIELD(arg0, s32 *, 0x8C) = (s32) ((f32) M2C_FIELD(arg0, s32 *, 0x8C) + M2C_FIELD(arg0, f32 *, 0x54));
    if ((f32) M2C_FIELD(arg0, s32 *, 0x84) < (M2C_FIELD(arg0, f32 *, 0x40) - (f32) M2C_FIELD(arg0, s32 *, 0x70))) {
        M2C_FIELD(arg0, f32 *, 0x4C) = func_8002DD60(M2C_FIELD(arg0, f32 *, 0x4C));
    }
    if ((M2C_FIELD(arg0, f32 *, 0x40) + (f32) M2C_FIELD(arg0, s32 *, 0x70)) < (f32) M2C_FIELD(arg0, s32 *, 0x84)) {
        M2C_FIELD(arg0, f32 *, 0x4C) = (f32) -func_8002DD60(M2C_FIELD(arg0, f32 *, 0x4C));
    }
    if ((f32) M2C_FIELD(arg0, s32 *, 0x88) < (M2C_FIELD(arg0, f32 *, 0x44) - 0.0f)) {
        M2C_FIELD(arg0, f32 *, 0x50) = func_8002DD60(M2C_FIELD(arg0, f32 *, 0x50));
    }
    if ((M2C_FIELD(arg0, f32 *, 0x44) + (f32) M2C_FIELD(arg0, s32 *, 0x74)) < (f32) M2C_FIELD(arg0, s32 *, 0x88)) {
        M2C_FIELD(arg0, f32 *, 0x50) = (f32) -func_8002DD60(M2C_FIELD(arg0, f32 *, 0x50));
    }
    if ((f32) M2C_FIELD(arg0, s32 *, 0x8C) < (M2C_FIELD(arg0, f32 *, 0x48) - (f32) M2C_FIELD(arg0, s32 *, 0x70))) {
        M2C_FIELD(arg0, f32 *, 0x54) = func_8002DD60(M2C_FIELD(arg0, f32 *, 0x54));
    }
    if ((M2C_FIELD(arg0, f32 *, 0x48) + (f32) M2C_FIELD(arg0, s32 *, 0x70)) < (f32) M2C_FIELD(arg0, s32 *, 0x8C)) {
        M2C_FIELD(arg0, f32 *, 0x54) = (f32) -func_8002DD60(M2C_FIELD(arg0, f32 *, 0x54));
    }
    M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) + (f32) func_80024AC4(M2C_FIELD(arg0, s32 *, 0x84) - (s32) M2C_FIELD(arg0, f32 *, 4), 3));
    M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + (f32) func_80024AC4(M2C_FIELD(arg0, s32 *, 0x88) - (s32) M2C_FIELD(arg0, f32 *, 8), 3));
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) + (f32) func_80024AC4(M2C_FIELD(arg0, s32 *, 0x8C) - (s32) M2C_FIELD(arg0, f32 *, 0xC), 3));
    func_8004303C(arg0);
    M2C_FIELD(arg0, s32 *, 0x10) = func_80025100((s32) M2C_FIELD(arg0, f32 *, 0x4C), (s32) M2C_FIELD(arg0, f32 *, 0x54));
}
