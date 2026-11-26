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

extern s32 gCamSpeedScale;
extern M2C_UNK func_8001D048;
void func_8001CFF4(void *arg0) {
    f32 temp_fv0;
    f32 temp_fv1;
    temp_fv0 = M2C_FIELD(arg0, f32 *, 8) + (f32) (-gCamSpeedScale * 0x14);
    temp_fv1 = M2C_FIELD(arg0, f32 *, 0x44);
    M2C_FIELD(arg0, f32 *, 8) = temp_fv0;
    if (temp_fv0 < temp_fv1) {
        M2C_FIELD(arg0, f32 *, 8) = temp_fv1;
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8001D048;
    }
}
