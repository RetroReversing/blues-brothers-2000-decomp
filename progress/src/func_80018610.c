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

s32 cameraGetMode();                                /* extern */
s32 func_80013784(void *);                          /* extern */
M2C_UNK func_80017CF0(void *); /* extern */
M2C_UNK func_80017F78(M2C_UNK);                     /* extern */
void *findActor(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK func_8002ADC8(M2C_UNK);                     /* extern */
M2C_UNK func_8002D604(void *);                      /* extern */
f32 getCameraTargetDist(void *, f32, M2C_UNK);            /* extern */
extern s32 gCamSpeedScale;
extern u8 D_800BCFB8[];
extern M2C_UNK animStepKeys;

void func_80018610(void *arg0_in) {
    u8 *__base_D_800BCFB8;
    f32 temp_fs0;
    s32 temp_lo;
    s32 temp_v0;
    void *temp_v0_2;

    __base_D_800BCFB8 = D_800BCFB8;
    if (*(cameraGetMode() + __base_D_800BCFB8) != 0) {
        M2C_FIELD(arg0_in, M2C_UNK (**)(void *), 0xA0)(arg0_in);
        return;
    }
    M2C_FIELD(arg0_in, s32 *, 0) = 0x12D;
    temp_v0 = M2C_FIELD(arg0_in, s32 *, 0x5C) + gCamSpeedScale;
    M2C_FIELD(arg0_in, s32 *, 0x5C) = temp_v0;
    if (temp_v0 >= 0x100) {
        M2C_FIELD(arg0_in, s32 *, 0x5C) = 0xFF;
    }
    temp_lo = (0xFF - M2C_FIELD(arg0_in, s32 *, 0x5C)) * gCamSpeedScale;
    M2C_FIELD(arg0_in, s32 *, 0x10) = (s32) (M2C_FIELD(arg0_in, s32 *, 0x10) + (temp_lo * 4));
    if (M2C_FIELD(arg0_in, s32 *, 0x5C) != 0xFF) {
        func_80017CF0(arg0_in);
    }
    if (M2C_FIELD(arg0_in, s32 *, 0x7C) == 2) {
        func_8002D604(arg0_in);
    }
    temp_fs0 = 200.0f;
    if ((getCameraTargetDist(arg0_in, temp_fs0, 0) != temp_fs0) && (func_80013784(arg0_in) != 0)) {
        temp_v0_2 = findActor(0x100E, 0);
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, s32 *, 0x6C) = 1;
            M2C_FIELD(arg0_in, M2C_UNK **, 0x9C) = &animStepKeys;
            M2C_FIELD(M2C_FIELD(arg0_in, void **, 0xA8), s32 *, 0x68) = 0xE;
            M2C_FIELD(M2C_FIELD(arg0_in, void **, 0xA8), M2C_UNK (**)(void *), 0x9C) = func_8002D604;
            M2C_FIELD(arg0_in, s32 *, 0x7C) = 2;
            func_80017F78(0xB);
            func_8002ADC8(1);
        }
    }
}
