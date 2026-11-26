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

M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
extern s32 gCamSpeedScale;
extern M2C_UNK func_8007631C;

void func_80059058(void *arg0) {
    s32 temp_a1;

    temp_a1 = gCamSpeedScale * 8;
    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        func_80043328(arg0, 0x40, 0x100);
        M2C_FIELD(arg0, s32 *, 0xF0) = 0xFF;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) - temp_a1);
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) - temp_a1);
    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) - temp_a1);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + (gCamSpeedScale << 0xB));
    if (M2C_FIELD(arg0, s32 *, 0x34) < 9) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8007631C;
        M2C_FIELD(arg0, s32 *, 0xD8) = 0;
        M2C_FIELD(arg0, s32 *, 0) = 0x101;
    }
}
