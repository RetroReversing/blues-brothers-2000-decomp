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

s16 coss(u16);                                      /* extern */
M2C_UNK updateCameraView(void *);                      /* extern */
s32 func_80024AC4(s32, M2C_UNK);                    /* extern */
s32 func_8002D1C4(s32, s32, M2C_UNK);               /* extern */
s16 sins(u16);                                      /* extern */
extern void *gCameraTarget;
extern M2C_UNK func_800340B4;

void func_8003B670(void *arg0) {
    s16 temp_s0;
    s16 temp_s0_2;

    if (M2C_FIELD(arg0, s32 *, 0xD8) == &func_800340B4) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 0x1F4;
        M2C_FIELD(arg0, s32 *, 0x80) = -0x2000;
        M2C_FIELD(arg0, s32 *, 0x74) = (s32) (M2C_FIELD(gCameraTarget, s32 *, 0x10) + 0x8000);
        M2C_FIELD(arg0, s32 *, 0x78) = (s32) (M2C_FIELD(arg0, s32 *, 0x78) + func_80024AC4(M2C_FIELD(arg0, s32 *, 0x7C) - M2C_FIELD(arg0, s32 *, 0x78), 4));
        M2C_FIELD(arg0, s32 *, 0x10) = func_8002D1C4(M2C_FIELD(arg0, s32 *, 0x74), M2C_FIELD(arg0, s32 *, 0x10), 4);
        M2C_FIELD(arg0, s32 *, 0x14) = func_8002D1C4(M2C_FIELD(arg0, s32 *, 0x80), M2C_FIELD(arg0, s32 *, 0x14), 2);
        temp_s0 = sins(M2C_FIELD(arg0, u16 *, 0x12));
        M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(gCameraTarget, f32 *, 4) + (f32) ((s32) (((s32) (-M2C_FIELD(arg0, s32 *, 0x78) * temp_s0) >> 0xF) * coss(M2C_FIELD(arg0, u16 *, 0x16))) >> 0xF));
        temp_s0_2 = coss(M2C_FIELD(arg0, u16 *, 0x12));
        M2C_FIELD(arg0, f32 *, 0xC) = (f32) (M2C_FIELD(gCameraTarget, f32 *, 0xC) + (f32) ((s32) (((s32) (-M2C_FIELD(arg0, s32 *, 0x78) * temp_s0_2) >> 0xF) * coss(M2C_FIELD(arg0, u16 *, 0x16))) >> 0xF));
        M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(gCameraTarget, f32 *, 8) + (f32) ((s32) (-M2C_FIELD(arg0, s32 *, 0x78) * sins(M2C_FIELD(arg0, u16 *, 0x16))) >> 0xF) + 100.0f);
        updateCameraView(arg0);
    }
}

