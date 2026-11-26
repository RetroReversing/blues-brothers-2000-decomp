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

M2C_UNK func_8002D9B0(void *);                      /* extern */
M2C_UNK func_8002D9F8();                            /* extern */
extern f32 D_80000D44;
extern s32 gFrameScale;

void func_8001E0E0(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    M2C_FIELD(arg0, f32 *, 0xB0) = (f32) (-1600.0f);
    M2C_FIELD(arg0, s32 *, 0xAC) = 0;
    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
    func_8002D9F8(arg0);
    func_8002D9B0(arg0);
    if (M2C_FIELD(arg0, f32 *, 0x54) > 0.0f) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x14) + (gFrameScale << 8);
        M2C_FIELD(arg0, s32 *, 0x14) = temp_v0;
        if (temp_v0 < 0x3FFD) {
            return;
        }
        goto block_4;
    }
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x14) - (gFrameScale << 8);
    M2C_FIELD(arg0, s32 *, 0x14) = temp_v0_2;
    if (temp_v0_2 < -0x3FFC) {
block_4:
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
