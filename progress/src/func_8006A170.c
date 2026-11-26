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

s32 cameraGetMode();                                /* extern */
void *func_800232B4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern void *gCameraTarget;
extern M2C_UNK D_8014AB90;
extern M2C_UNK func_80074A28;

void func_8006A170(void *arg0) {
    void *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
      s32 var_s1;
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        D_800B3978 = 0;
        D_800B3974 = 0;
        D_800B3970 = 0;
        if (cameraGetMode() == 8) {
            var_s1 = 1;
            do {
                temp_v0 = func_800232B4(1, 0, 0, 0);
                M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80074A28;
                M2C_FIELD(temp_v0, s32 *, 0x70) = var_s1;
                M2C_FIELD(temp_v0, s32 *, 0x90) = (s32) (randomRange(0, 0x1F) + 0x20);
                var_s1 += 1;
                M2C_FIELD(temp_v0, s32 *, 0x8C) = 0xC;
            } while (var_s1 < 0x1E);
            M2C_FIELD(&D_8014AB90, f32 *, 0) = (f32) M2C_FIELD(gCameraTarget, f32 *, 4);
            M2C_FIELD(&D_8014AB90, f32 *, 4) = (f32) M2C_FIELD(gCameraTarget, f32 *, 8);
            M2C_FIELD(&D_8014AB90, f32 *, 8) = (f32) M2C_FIELD(gCameraTarget, f32 *, 0xC);
        }
    }
}
