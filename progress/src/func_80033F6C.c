/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

M2C_UNK updateCameraView(void *);                      /* extern */
s32 func_80024AE8(s32, M2C_UNK);                    /* extern */
s32 func_8002D260(s32);                             /* extern */
extern void *gCameraTarget;
extern s32 gPadPressed;
extern s32 gStickX;
extern s32 gStickY;
extern s32 D_8013FFA0;
extern s32 D_8013FFCC;
extern s32 D_80140228;
extern M2C_UNK func_800340B4;
extern M2C_UNK func_800393F4;

void func_80033F6C(void *arg0) {
    s32 temp_a0;
    s32 temp_v0;

    if (gPadPressed != 0) {
        M2C_FIELD(arg0, s32 *, 0xC0) = 0;
        M2C_FIELD(gCameraTarget, s32 *, 0x14) = 0;
        if (M2C_FIELD(gCameraTarget, s32 *, 0x9C) == &func_800393F4) {
            M2C_FIELD(gCameraTarget, s32 *, 0x68) = 3;
        }
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) D_8013FFCC;
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) D_8013FFA0;
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_800340B4;
        return;
    }
    do { M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + (func_80024AE8(gStickX, 3) * 0x50)); } while (0);
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x14) - (func_80024AE8(gStickY, 3) * 0x50);
    M2C_FIELD(arg0, s32 *, 0x14) = temp_a0;
    temp_v0 = func_8002D260(temp_a0);
    M2C_FIELD(arg0, s32 *, 0x14) = temp_v0;
    if (temp_v0 < -0x1B58) {
        M2C_FIELD(arg0, s32 *, 0x14) = -0x1B58;
    }
    if (M2C_FIELD(arg0, s32 *, 0x14) >= 0x2329) {
        M2C_FIELD(arg0, s32 *, 0x14) = 0x2328;
    }
    M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(gCameraTarget, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(gCameraTarget, f32 *, 8) + 300.0f);
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) M2C_FIELD(gCameraTarget, f32 *, 0xC);
    updateCameraView(arg0);
    D_80140228 = 0;
    M2C_FIELD(gCameraTarget, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
}

