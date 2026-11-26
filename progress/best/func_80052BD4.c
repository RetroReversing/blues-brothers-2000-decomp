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

s32 func_8000C5E4();
void *spawnEffectObj();
void *findActor();
void *getImageAsset();
s32 func_800242A8();
s32 func_80026B50();
s32 func_80027030();
s32 func_80043328();
s32 func_80053EF0();
s32 debugPrintf();
extern char D_800080F0[];
extern char D_8000811C[];
extern s32 D_800AE010;
extern void *gCameraRig;
extern s32 D_800B5DD4;
extern void *gCameraTarget;
extern s32 D_80107040;
extern s32 gPadPressed;
extern s32 D_80140228;
extern s32 D_8014AA90;
extern void *D_8014AA94;
extern s32 D_8014AA98;
extern s32 D_8014AA9C;
extern s32 D_8014AAA0;
extern s32 animStepKeys;
extern s32 func_80052EC0;
extern s32 func_80053C94;
extern s32 func_80053CE0;

s32 func_80052BD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, s32 arg13, s32 arg14, s32 arg15) {
    s32 saved_reg_s1;
    s32 saved_reg_s3;
    s32 *temp_v0_3;
    char *var_a1;
    char *var_s1;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s6;
    void *temp_a3;
    void *temp_v0;
    void *temp_v0_2;

    temp_a2 = arg2 | 0x5678;
    temp_a1 = D_800AE010;
    D_8014AA9C = 0;
    D_8014AA94 = NULL;
    D_800B5DD4 = 0;
    gPadPressed = 0;
    D_80107040 = 0;
    D_800AE010 = temp_a2;
    D_8014AA90 = temp_a1;
    func_80027030(2, temp_a1, temp_a2);
    D_80140228 = 0;
    func_8000C5E4();
    M2C_FIELD(gCameraRig, s32 *, 0xC0) = 2;
    temp_v0 = getImageAsset(saved_reg_s1);
    if (temp_v0 == NULL) {
        debugPrintf(D_800080F0);
    }
    func_800242A8(0x88, 0x560, 0);
    if (D_8014AAA0 != 0) {
        func_800242A8(0x89, D_8014AAA0, 0);
    }
    if (findActor(0x801, 0) == NULL) {
        M2C_FIELD(spawnEffectObj(0x801, 0, 0, 0), s32 **, 0x9C) = &func_80053C94;
    }
    if (findActor(0x802, 0) == NULL) {
        M2C_FIELD(spawnEffectObj(0x802, 0, 0, 0), s32 **, 0x9C) = &func_80053CE0;
    }
    temp_v0_2 = findActor(0x803, 0);
    if (temp_v0_2 != NULL) {
        M2C_FIELD(temp_v0_2, s32 *, 0x7C) = 0;
    } else {
        M2C_FIELD(spawnEffectObj(0x803, 0, 0, 0), s32 **, 0x9C) = &func_80053CE0;
    }
    func_80053EF0(temp_v0);
    var_s1 = M2C_FIELD(temp_v0, s32 **, 8);
    if (arg15 != 0) {
        var_s0 = 0;
        if (M2C_FIELD(temp_v0, s16 *, 4) > 0) {
loop_17:
            if (func_80026B50(arg15, *(s32 *)var_s1) != 0) {
                var_s0 += 1;
                var_s1 += 0xC;
                if (var_s0 < M2C_FIELD(temp_v0, s16 *, 4)) {
                    goto loop_17;
                }
            } else {
                var_s6 = 1;
                temp_a3 = spawnEffectObj(0x800, 0, 0, 0);
                if (saved_reg_s3 != NULL) {
                    M2C_FIELD(temp_a3, f32 *, 4) = (f32) M2C_FIELD(saved_reg_s3, f32 *, 4);
                    M2C_FIELD(temp_a3, f32 *, 8) = (f32) M2C_FIELD(saved_reg_s3, f32 *, 8);
                    M2C_FIELD(temp_a3, s32 **, 0xA4) = (void *) saved_reg_s3;
                    M2C_FIELD(temp_a3, f32 *, 0xC) = (f32) M2C_FIELD(saved_reg_s3, f32 *, 0xC);
                }
                M2C_FIELD(gCameraRig, s32 *, 0xD8) = (s32) M2C_FIELD(gCameraRig, s32 *, 0x9C);
                M2C_FIELD(temp_a3, s32 **, 0x70) = temp_v0;
                M2C_FIELD(temp_a3, s32 **, 0x74) = var_s1;
                M2C_FIELD(temp_a3, s32 **, 0x9C) = &func_80052EC0;
                M2C_FIELD(temp_a3, s32 *, 0x64) = 0xC8;
                M2C_FIELD(temp_a3, s32 *, 0xD8) = 0;
                temp_v0_3 = M2C_FIELD(gCameraTarget, s32 **, 0x9C);
                M2C_FIELD(gCameraTarget, s32 **, 0x9C) = &animStepKeys;
                M2C_FIELD(gCameraTarget, s32 *, 0x4C) = 0;
                M2C_FIELD(gCameraTarget, s32 *, 0x50) = 0;
                M2C_FIELD(gCameraTarget, s32 *, 0x54) = 0;
                M2C_FIELD(gCameraTarget, s32 **, 0xD8) = temp_v0_3;
                func_80043328(gCameraTarget, 1, 0x100, temp_a3);
            }
        }
    }
    if (var_s6 == 0) {
        debugPrintf(D_8000811C, arg15);
    }
    var_a1 = M2C_FIELD(var_s1, s32 **, 4);
    if (*(s32 *)var_a1 != -1) {
loop_28:
        temp_v1 = *(s32 *)var_a1;
        if (temp_v1 != 0) {
            var_a1 += 8;
            if (temp_v1 != 1) {
                if (*(s32 *)var_a1 != -1) {
                    goto loop_28;
                }
            } else {
                D_8014AA98 = temp_v1;
            }
        } else {
            D_8014AA98 = 0;
        }
    }
    D_800AE010 = D_8014AA90;
    return 1;
}
