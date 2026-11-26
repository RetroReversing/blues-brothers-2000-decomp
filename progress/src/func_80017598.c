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

s32 func_80024380(s32);                             /* extern */
s32 func_8002A360(s32, s32);            /* extern */
f32 approachF32(f32, f32, f32);                   /* extern */
s32 func_80035238();                            /* extern */
extern s32 gCamSpeedScale;
extern void *gCameraTarget;
extern s32 func_80023078;

void func_80017598(void *arg0) {
    s32 temp_ft0;

    temp_ft0 = (s32) (M2C_FIELD(gCameraTarget, f32 *, 4) - M2C_FIELD(arg0, f32 *, 4));
    if (M2C_FIELD(arg0, s32 *, 0x74) < 0) {
        if (temp_ft0 < 0x65) {

        } else {
            goto block_4;
        }
    } else if (temp_ft0 < -0x64) {
block_4:
        if (M2C_FIELD(arg0, s32 *, 0xC0) == 1) {
            M2C_FIELD(arg0, s32 *, 0xC0) = 2;
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0xC0) == 0) {
        M2C_FIELD(arg0, s32 *, 0x74) = func_80024380(temp_ft0);
        M2C_FIELD(arg0, s32 *, 0xC0) = 1;
        M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 0x44) + 500.0f);
    }
    if (M2C_FIELD(arg0, s32 *, 0xC0) == 2) {
        M2C_FIELD(arg0, f32 *, 8) = approachF32(M2C_FIELD(arg0, f32 *, 0x44), M2C_FIELD(arg0, f32 *, 8), (f32) gCamSpeedScale * 6.0f);
        if (M2C_FIELD(arg0, s32 *, 0x90) == 0) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x45);
            M2C_FIELD(arg0, s32 *, 0x90) = 1;
        }
    }
    if (M2C_FIELD(arg0, f32 *, 8) == M2C_FIELD(arg0, f32 *, 0x44)) {
        M2C_FIELD(arg0, void **, 0x9C) = (void *) ((&func_80023078) + 0x2);
        func_80035238();
        M2C_FIELD(arg0, s32 *, 0x90) = 0;
    }
}

