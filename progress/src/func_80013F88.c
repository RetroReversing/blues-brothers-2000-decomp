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

s32 cameraGetMode();                                /* extern */
s32 func_8000F7A0(void *);                      /* extern */
s32 func_80017740(void *);                      /* extern */
s32 func_8002D1C4(s32, s32, s32);           /* extern */
f32 func_8002D280(f32, s32);                    /* extern */
s32 tickActorTimer(void *);                          /* extern */
s32 func_8002D9B0(void *);                      /* extern */
s32 func_8002D9F8(void *);                      /* extern */
extern s32 gFrameScale;

void func_80013F88(void *arg0) {
    s32 temp_a0_1;
    s32 temp_a0_2;

    temp_a0_1 = M2C_FIELD(arg0, s32 *, 0x78);
    M2C_FIELD(arg0, s32 *, 0x10) = M2C_FIELD(arg0, s32 *, 0x10) + M2C_FIELD(arg0, s32 *, 0x74);
    if (temp_a0_1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x14) = M2C_FIELD(arg0, s32 *, 0x14) + temp_a0_1;
    } else {
        M2C_FIELD(arg0, s32 *, 0x14) = func_8002D1C4(0, M2C_FIELD(arg0, s32 *, 0x14), 3);
    }
    M2C_FIELD(arg0, s32 *, 0xAC) = 0;
    M2C_FIELD(arg0, f32 *, 0xB0) = -1600.0f;
    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
    func_8002D9F8(arg0);
    func_8002D9B0(arg0);
    if (cameraGetMode() == 1) {
        M2C_FIELD(arg0, f32 *, 0xC) = 180.0f;
    } else {
        func_8000F7A0(arg0);
    }
    if (M2C_FIELD(arg0, f32 *, 0x8) < M2C_FIELD(arg0, f32 *, 0x44)) {
        M2C_FIELD(arg0, f32 *, 0x50) = -func_8002D280(M2C_FIELD(arg0, f32 *, 0x50), 1);
        M2C_FIELD(arg0, f32 *, 0x4C) = func_8002D280(M2C_FIELD(arg0, f32 *, 0x4C), 1);
        M2C_FIELD(arg0, f32 *, 0x54) = func_8002D280(M2C_FIELD(arg0, f32 *, 0x54), 1);
        M2C_FIELD(arg0, f32 *, 0x8) = M2C_FIELD(arg0, f32 *, 0x44);
        M2C_FIELD(arg0, s32 *, 0x78) = M2C_FIELD(arg0, s32 *, 0x78) >> 1;
    }
    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x7C) - gFrameScale;
    M2C_FIELD(arg0, s32 *, 0x7C) = temp_a0_2;
    if (0 >= temp_a0_2) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        func_80017740(arg0);
    }
    if (tickActorTimer(arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
