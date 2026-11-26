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

void *findActor();
s32 func_8002A360();
s32 func_8002D3E4();
s32 syncActorPrevPos();
s32 func_8002DA80();
s32 animStepKeys();
s32 func_80043328();
s32 actorSetAnim();
f32 func_80094350(f32);                             /* extern */
extern f32 D_80008608;
extern f32 D_8000860C;
extern f32 D_80008610;
extern f32 D_80008614;
extern f32 D_80008618;
extern void *D_800B3964;
extern s32 gCamSpeedScale;
extern char gPlatformMaxOffsets[];
extern char gPlatformMinOffsets[];
extern s32 func_8005BB3C;

void func_8005BD8C(void *arg0) {
    f32 temp_fa0;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 var_fv1;
    s32 temp_v0;
    s32 temp_v1;
    void *temp_s0;
    void *var_s0;

    syncActorPrevPos();
    animStepKeys(arg0);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x5C);
    if (temp_v1 != 0xFF) {
        temp_v0 = temp_v1 + (gCamSpeedScale * 2);
        M2C_FIELD(arg0, s32 *, 0x5C) = temp_v0;
        if (temp_v0 >= 0x100) {
            M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF;
            return;
        }
        return;
    }
    temp_s0 = findActor(0x101F, NULL);
    M2C_FIELD(D_800B3964, s32 *, 0x70) = 0;
    if (temp_s0 != NULL) {
        temp_fv1 = M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(temp_s0, f32 *, 4);
        temp_fv1_2 = M2C_FIELD(arg0, f32 *, 0xC) - M2C_FIELD(temp_s0, f32 *, 0xC);
        temp_fa0 = (temp_fv1 * temp_fv1) + (temp_fv1_2 * temp_fv1_2);
        var_fv1 = sqrtf(temp_fa0);
        if (var_fv1 != var_fv1) {
            var_fv1 = func_80094350(temp_fa0);
        }
        if (var_fv1 < D_80008608) {
            actorSetAnim(arg0, 0xCF, 0x100);
            M2C_FIELD(arg0, s32 **, 0x9C) = &func_8005BB3C;
            M2C_FIELD(arg0, s32 *, 0) = 0x101;
            M2C_FIELD(arg0, s32 *, 0x7C) = 0;
            M2C_FIELD(temp_s0, s32 *, 0x8C) = 1;
            actorSetAnim(temp_s0, 0x128, 0x100);
            return;
        }
        goto block_10;
    }
block_10:
    if (M2C_FIELD(D_800B3964, s32 *, 0x74) != 0) {
        func_8002D3E4(arg0, 0x258);
        if (M2C_FIELD(D_800B3964, s32 *, 0xFC) == 0) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x55);
            M2C_FIELD(D_800B3964, s32 *, 0xFC) = 1;
        }
        func_80043328(arg0, 0xC7, 0x100);
    } else {
        func_8002D3E4(arg0, 0);
        func_80043328(arg0, 0xC6, 0x100);
        M2C_FIELD(D_800B3964, s32 *, 0xFC) = 0;
    }
    func_8002DA80(arg0);
    var_s0 = NULL;
loop_17:
    var_s0 = findActor(0x105, var_s0);
    if (var_s0 != NULL) {
        temp_fv1_3 = M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(var_s0, f32 *, 4);
        if ((!(temp_fv1_3 > 0.0f) || !(*(f32 *)((M2C_FIELD(var_s0, s32 *, 0xB8) * 0xC) + gPlatformMaxOffsets) < temp_fv1_3)) && (!(temp_fv1_3 <= 0.0f) || !(temp_fv1_3 < *(f32 *)((M2C_FIELD(var_s0, s32 *, 0xB8) * 0xC) + gPlatformMinOffsets))) && ((temp_fv1_4 = M2C_FIELD(arg0, f32 *, 0xC) - M2C_FIELD(var_s0, f32 *, 0xC), !(temp_fv1_4 > 0.0f)) || !((f32) M2C_FIELD(((M2C_FIELD(var_s0, s32 *, 0xB8) * 0xC) + gPlatformMaxOffsets), s32 *, 8) < temp_fv1_4)) && (!(temp_fv1_4 <= 0.0f) || !(temp_fv1_4 < (f32) M2C_FIELD(((M2C_FIELD(var_s0, s32 *, 0xB8) * 0xC) + gPlatformMinOffsets), s32 *, 8)))) {
            M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 0x40);
            M2C_FIELD(arg0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0x48);
        }
        goto loop_17;
    }
    if (M2C_FIELD(arg0, f32 *, 4) < D_8000860C) {
        M2C_FIELD(arg0, f32 *, 4) = (f32) D_8000860C;
    }
    if (D_80008610 < M2C_FIELD(arg0, f32 *, 4)) {
        M2C_FIELD(arg0, f32 *, 4) = (f32) D_80008610;
    }
    if (M2C_FIELD(arg0, f32 *, 0xC) < D_80008614) {
        M2C_FIELD(arg0, f32 *, 0xC) = (f32) D_80008614;
    }
    if (D_80008618 < M2C_FIELD(arg0, f32 *, 0xC)) {
        M2C_FIELD(arg0, f32 *, 0xC) = (f32) D_80008618;
    }
}
