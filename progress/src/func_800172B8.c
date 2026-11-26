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

M2C_UNK func_8002D9B0(void *);                      /* extern */
M2C_UNK func_8002D9F8();                            /* extern */
extern f32 D_80000A20;
extern s32 gCamSpeedScale;

void func_800172B8(void *arg0) {
    s32 temp_v1;
    s32 tB;

    M2C_FIELD(arg0, f32 *, 0xB0) = (f32) D_80000A20;
    M2C_FIELD(arg0, s32 *, 0xAC) = 0;
    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
    func_8002D9F8(arg0);
    do { func_8002D9B0(arg0); } while (0);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + 0x4B4);
    tB = M2C_FIELD(arg0, s32 *, 0x80);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + 0x1000);
    do { M2C_FIELD(arg0, s32 *, 0x80) = (s32) (tB + 0xA); } while (0);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x5C) - (gCamSpeedScale * 4);
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_v1;
    if (temp_v1 <= 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
