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

void initBoundsToSegment(void *arg0, void *arg1, void *arg2, void *arg3) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;

    temp_fv0 = M2C_FIELD(arg2, f32 *, 0);
    M2C_FIELD(arg0, f32 *, 0) = temp_fv0;
    M2C_FIELD(arg1, f32 *, 0) = temp_fv0;
    temp_fv0_2 = M2C_FIELD(arg2, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 4) = temp_fv0_2;
    M2C_FIELD(arg1, f32 *, 4) = temp_fv0_2;
    temp_fv0_3 = M2C_FIELD(arg2, f32 *, 8);
    M2C_FIELD(arg0, f32 *, 8) = temp_fv0_3;
    M2C_FIELD(arg1, f32 *, 8) = temp_fv0_3;
    { f32 d = M2C_FIELD(arg0, f32 *, 0); f32 s = M2C_FIELD(arg3, f32 *, 0); if (s < d) { M2C_FIELD(arg0, f32 *, 0) = s; } }
    { f32 d = M2C_FIELD(arg0, f32 *, 4); f32 s = M2C_FIELD(arg3, f32 *, 4); if (s < d) { M2C_FIELD(arg0, f32 *, 4) = s; } }
    { f32 d = M2C_FIELD(arg0, f32 *, 8); f32 s = M2C_FIELD(arg3, f32 *, 8); if (s < d) { M2C_FIELD(arg0, f32 *, 8) = s; } }
    { f32 d = M2C_FIELD(arg1, f32 *, 0); f32 s = M2C_FIELD(arg3, f32 *, 0); if (d < s) { M2C_FIELD(arg1, f32 *, 0) = s; } }
    { f32 d = M2C_FIELD(arg1, f32 *, 4); f32 s = M2C_FIELD(arg3, f32 *, 4); if (d < s) { M2C_FIELD(arg1, f32 *, 4) = s; } }
    { f32 d = M2C_FIELD(arg1, f32 *, 8); f32 s = M2C_FIELD(arg3, f32 *, 8); if (d < s) { M2C_FIELD(arg1, f32 *, 8) = s; } }
}
