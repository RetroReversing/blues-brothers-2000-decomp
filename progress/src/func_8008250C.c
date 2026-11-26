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

s32 func_80023620();
void *findActor();
s32 tickActorTimer();
s32 func_8002E7B8();
extern void *D_800B3960;
extern void *gCameraTarget;
extern s32 D_80171994;
extern void *D_801719A8;
extern void *D_801719AC;
extern s32 D_801719B0;
extern s32 D_801719C8;
extern s32 D_80171A48;
extern s32 func_80082EF8;
extern s32 func_80083830;
extern s32 func_80088658;
extern s32 func_800886E8;

void func_8008250C(void *arg0) {
    s32 *var_v0;
    char *var_a0;
    char *var_a1;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;
    s32 var_s0;
    s32 var_s1;
    s32 temp_v0_2;

    temp_v0_2 = 0;
    var_s1 = temp_v0_2;
    var_s0 = temp_v0_2;
    if (tickActorTimer() != 0) {
        var_a2 = temp_v0_2;
        var_a1 = &D_801719C8;
        var_a0 = &D_801719B0;
        M2C_FIELD(arg0, s32 *, 0x80) += 1;
        do {
            temp_v1 = *(s32 *)var_a1;
            var_a1 += 4;
            temp_v0 = *(s32 *)var_a0;
            var_a0 += 4;
            var_a2 += 1;
            var_s1 += temp_v0;
            var_s0 += temp_v1;
        } while (var_a2 < 5);
        if ((var_s1 < 3)) {
            if ((var_s0 < 3)) {
                M2C_FIELD(arg0, s32 **, 0x9C) = &func_80082EF8;
                M2C_FIELD(D_800B3960, s32 **, 0x9C) = &func_80083830;
                M2C_FIELD(D_800B3960, s32 *, 0x70) = 1;
                return;
            }
        }
        if (D_80171994 != 0) {
            D_80171A48 = 0;
            temp_v0_2 = (s32)findActor(0x13C, temp_v0_2);
            if (temp_v0_2 != 0) {
                M2C_FIELD(gCameraTarget, f32 *, 4) = (f32) M2C_FIELD(temp_v0_2, f32 *, 4);
                M2C_FIELD(gCameraTarget, f32 *, 8) = (f32) M2C_FIELD(temp_v0_2, f32 *, 8);
                M2C_FIELD(gCameraTarget, f32 *, 0xC) = (f32) M2C_FIELD(temp_v0_2, f32 *, 0xC);
            }
        } else {
            func_8002E7B8(1, 0);
            if (var_s1 >= var_s0) {
              s32 *var_v0_1;
                D_80171A48 = 1;
                var_v0_1 = &func_80088658;
              M2C_FIELD(arg0, s32 **, 0x9C) = var_v0_1;
            } else {
              s32 *var_v0_2;
                D_80171A48 = 0;
                var_v0_2 = &func_800886E8;
              M2C_FIELD(arg0, s32 **, 0x9C) = var_v0_2;
            }
            
            M2C_FIELD(D_801719A8, s32 *, 0x68) = -1;
            M2C_FIELD(D_801719AC, s32 *, 0x68) = -1;
            func_80023620(0x141);
        }
    }
}

