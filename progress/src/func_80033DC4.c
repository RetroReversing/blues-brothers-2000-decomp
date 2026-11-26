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

s16 coss();                                 /* extern */
M2C_UNK func_80034F1C(void *);                      /* extern */
s16 sins();                                 /* extern */
extern f32 D_800012B4;
extern void *gCameraRig;
extern s32 gCameraOffsetZ;
extern s32 gCameraOffsetX;
extern s32 D_8014002C;
extern s32 D_80140030;

void func_80033DC4(void *arg0) {
    f32 temp_fv1;
    s16 temp_s0;
    s16 temp_s0_2;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_v1;
    void *temp_s1;

    D_80140030 = 0;
    temp_s1 = gCameraRig;
    D_8014002C = 0;
    M2C_FIELD(temp_s1, s32 *, 0x6C) = 2;
    M2C_FIELD(temp_s1, s32 *, 0xC0) = 0;
    func_80034F1C(temp_s1);
    M2C_FIELD(temp_s1, s32 *, 0x78) = (s32) M2C_FIELD(temp_s1, s32 *, 0x7C);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x10);
    M2C_FIELD(temp_s1, s32 *, 0x10) = temp_v1;
    M2C_FIELD(temp_s1, s32 *, 0x14) = (s32) M2C_FIELD(temp_s1, s32 *, 0x80);
    M2C_FIELD(temp_s1, s32 *, 0x74) = temp_v1;
    M2C_FIELD(temp_s1, f32 *, 0x40) = (f32) M2C_FIELD(arg0, f32 *, 4);
    M2C_FIELD(temp_s1, f32 *, 0x44) = (f32) M2C_FIELD(arg0, f32 *, 8);
    M2C_FIELD(temp_s1, f32 *, 0x48) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    temp_s0 = sins(M2C_FIELD(temp_s1, u16 *, 0x12));
    temp_lo = ((s32) (-M2C_FIELD(temp_s1, s32 *, 0x78) * temp_s0) >> 0xF) * coss(M2C_FIELD(temp_s1, u16 *, 0x16));
    M2C_FIELD(temp_s1, f32 *, 4) = (f32) (M2C_FIELD(temp_s1, f32 *, 0x40) + (f32) (temp_lo >> 0xF));
    temp_s0_2 = coss(M2C_FIELD(temp_s1, u16 *, 0x12));
    temp_lo_2 = ((s32) (-M2C_FIELD(temp_s1, s32 *, 0x78) * temp_s0_2) >> 0xF) * coss(M2C_FIELD(temp_s1, u16 *, 0x16));
    M2C_FIELD(temp_s1, f32 *, 0xC) = (f32) (M2C_FIELD(temp_s1, f32 *, 0x48) + (f32) (temp_lo_2 >> 0xF));
    temp_fv1 = M2C_FIELD(temp_s1, f32 *, 0x44) + (f32) ((s32) (-M2C_FIELD(temp_s1, s32 *, 0x78) * sins(M2C_FIELD(temp_s1, u16 *, 0x16))) >> 0xF) + 200.0f;
    gCameraOffsetX = 0;
    M2C_FIELD(temp_s1, f32 *, 8) = temp_fv1;
    gCameraOffsetZ = 0;
}


