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
M2C_UNK func_80034FEC(void *, s32 *);               /* extern */
M2C_UNK func_80036FB8(void *, M2C_UNK);             /* extern */
extern f32 D_80001474;
extern f32 D_80001478;
extern void *gCameraTarget;
extern s32 gPadPressed;
extern s32 D_801073B0;
extern s32 gStickY;

void func_80036DB4(void *arg0) {
    s32 sp10[3];
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;

    if (M2C_FIELD(arg0, s32 *, 0xC0) == 1) {
        s32 temp_v0_2_a1;
        do { M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + (func_80024AE8(D_801073B0, 3) * 0x50)); } while (0);
        temp_v0_2_a1 = (func_80024AE8(gStickY, 3) * 0x50); temp_a0 = M2C_FIELD(arg0, s32 *, 0x14) - temp_v0_2_a1;
        M2C_FIELD(arg0, s32 *, 0x14) = temp_a0;
        temp_v0 = func_8002D260(temp_a0);
        M2C_FIELD(arg0, s32 *, 0x14) = temp_v0;
        if (temp_v0 < -0x1B58) {
            M2C_FIELD(arg0, s32 *, 0x14) = -0x1B58;
        }
        if (M2C_FIELD(arg0, s32 *, 0x14) >= 0x2329) {
            M2C_FIELD(arg0, s32 *, 0x14) = 0x2328;
        }
    } else {
        sp10[0] = (s32) M2C_FIELD(gCameraTarget, f32 *, 4);
        sp10[1] = (s32) (M2C_FIELD(gCameraTarget, f32 *, 8) + 200.0f);
        sp10[2] = (s32) M2C_FIELD(gCameraTarget, f32 *, 0xC);
        func_80034FEC(arg0, sp10);
    }
    if (gPadPressed & 8) {
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 0xC0) ^ 1;
        M2C_FIELD(arg0, s32 *, 0xC0) = temp_v0_2;
        if (temp_v0_2 == 1) {
            M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(gCameraTarget, f32 *, 4);
            M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(gCameraTarget, f32 *, 8) + 300.0f);
            M2C_FIELD(arg0, f32 *, 0xC) = (f32) M2C_FIELD(gCameraTarget, f32 *, 0xC);
            M2C_FIELD(arg0, s32 *, 0x14) = 0;
            M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(gCameraTarget, s32 *, 0x10);
        } else {
            M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 0x40);
            M2C_FIELD(arg0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x44);
            M2C_FIELD(arg0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0x48);
            M2C_FIELD(gCameraTarget, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        }
    }
    updateCameraView(arg0);
    func_80036FB8(arg0, 0xE);
}
