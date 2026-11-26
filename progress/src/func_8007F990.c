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

M2C_UNK func_8001FF64(void *);                      /* extern */
s32 func_80024AE8(s32, M2C_UNK);                    /* extern */
s32 func_8002D260(s32);                             /* extern */
extern void *D_800BD06C;
extern s32 D_801070A0;
extern s32 D_801073B0;
extern s32 D_801073C0;
extern M2C_UNK func_8007FACC;

void func_8007F990(void *arg0) {
    s32 temp_a0;
    s32 temp_v0;

    M2C_FIELD(arg0, s32 *, 0xC0) = 1;
    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0x64) {
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + (func_80024AE8(D_801073B0, 3) * 0x50));
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x14) - (func_80024AE8(D_801073C0, 3) * 0x50);
        M2C_FIELD(arg0, s32 *, 0x14) = temp_a0;
        temp_v0 = func_8002D260(temp_a0);
        M2C_FIELD(arg0, s32 *, 0x14) = temp_v0;
        if (temp_v0 < -0x1B58) {
            M2C_FIELD(arg0, s32 *, 0x14) = -0x1B58;
        }
        if (M2C_FIELD(arg0, s32 *, 0x14) >= 0x2329) {
            M2C_FIELD(arg0, s32 *, 0x14) = 0x2328;
        }
        M2C_FIELD(D_800BD06C, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        if (((D_801070A0 & 0xC00F) | M2C_FIELD(D_800BD06C, s32 *, 0xF0)) != 0) {
            M2C_FIELD(arg0, s32 *, 0xC0) = 0;
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8007FACC;
        }
    } else {
        M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(D_800BD06C, f32 *, 4);
        M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(D_800BD06C, f32 *, 8) + 300.0f);
        M2C_FIELD(arg0, f32 *, 0xC) = (f32) M2C_FIELD(D_800BD06C, f32 *, 0xC);
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(D_800BD06C, s32 *, 0x10);
        M2C_FIELD(arg0, s32 *, 0x14) = 0;
        M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
    }
    func_8001FF64(arg0);
}
