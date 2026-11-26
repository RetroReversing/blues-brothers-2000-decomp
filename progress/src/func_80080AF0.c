/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_FIELD_PTR(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 approachS32(M2C_UNK, s32, s32);               /* extern */
extern s32 gCamSpeedScale;
extern M2C_UNK func_80080A08;

void func_80080AF0(void *arg0) {
    s32 temp_v0_2;

    if (M2C_FIELD_PTR(arg0, const s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x70) = 0xFF;
        M2C_FIELD(arg0, s32 *, 0x68) = 0xF;
        M2C_FIELD(arg0, s32 *, 0xC0) = 1;
        M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_80080A08;
        return;
    }
    if (M2C_FIELD(arg0, const s32 *, 0xC0) == 0) {
      s32 temp_v0;
        temp_v0 = approachS32(0xFF, M2C_FIELD(arg0, const s32 *, 0x70), gCamSpeedScale * 8);
        M2C_FIELD(arg0, s32 *, 0x70) = temp_v0;
        if (temp_v0 == 0xFF) {
            M2C_FIELD(arg0, s32 *, 0xC0) = (s32) (M2C_FIELD(arg0, const s32 *, 0xC0) + 1);
        }
    } else {
        temp_v0_2 = approachS32(0, M2C_FIELD(arg0, const s32 *, 0x70), gCamSpeedScale * 8);
        M2C_FIELD(arg0, s32 *, 0x70) = temp_v0_2;
        if (temp_v0_2 == 0) {
            M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        }
    }
}
