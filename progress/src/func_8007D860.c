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

s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
s32 func_8002D260(s32);                             /* extern */
M2C_UNK func_8002D3E4(void *, M2C_UNK);             /* extern */
s32 tickActorTimer(void *);                          /* extern */
M2C_UNK func_8002DA80(void *);                      /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK animStepKeys(void *);                      /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8007DB44();                            /* extern */
extern void *D_800B3960;
extern void *gCameraTarget;
extern void *D_801705EC;
extern void *D_801705F0;
extern s16 D_801705F4;
extern s16 D_801705F6;

s32 func_8007D860(void) {
    volatile u64 scratch[4];
    void *temp_s0;
    void *var_s0;

    if (D_801705F0 == NULL) {
        var_s0 = func_80042F00(1, 0, 0, 0);
        { M2C_FIELD(var_s0, f32 *, 4) = (f32) M2C_FIELD(gCameraTarget, const f32 *, 4); }
        M2C_FIELD(var_s0, f32 *, 8) = (f32) M2C_FIELD(gCameraTarget, const f32 *, 8);
        D_801705F0 = var_s0;
        M2C_FIELD(var_s0, f32 *, 0xC) = (f32) M2C_FIELD(gCameraTarget, const f32 *, 0xC);
        actorSetAnim(var_s0, 4, 0x100);
        M2C_FIELD(var_s0, s32 *, 0x8C) = randomRange(1, 4);
        M2C_FIELD(var_s0, s32 *, 0x10) = (s32) (M2C_FIELD(D_800B3960, const s32 *, 0x10) + 0x4000);
    } else {
        var_s0 = D_801705F0;
    }
    if (D_801705F6 != 0) {
        actorSetAnim(var_s0, 4, 0x100);
        M2C_FIELD(var_s0, s32 *, 0x90) = 8;
        M2C_FIELD(var_s0, s32 *, 0x10) = (s32) (M2C_FIELD(D_800B3960, const s32 *, 0x10) + 0x4000);
        func_8002D3E4(var_s0, 0x190);
        D_801705F4 = 0;
    }
    { animStepKeys(var_s0);
    do { func_8002DA80(var_s0); M2C_FIELD(var_s0, M2C_UNK (**)(void *), 0x98)(var_s0); } while (0);
    }
    if (!(M2C_FIELD(var_s0, const s32 *, 0xF8) & 4)) {
        if (tickActorTimer(var_s0) != 0) {
            M2C_FIELD(var_s0, s32 *, 0x64) = 0x8C;
            M2C_FIELD(var_s0, s32 *, 0x90) = (s32) -M2C_FIELD(var_s0, const s32 *, 0x90);
            M2C_FIELD(var_s0, s32 *, 0x10) = func_8002D260(M2C_FIELD(var_s0, const s32 *, 0x10) + 0x8000);
            func_8002D3E4(var_s0, 0x190);
            temp_s0 = D_801705EC;
            D_801705F4 = 1;
            if (temp_s0 != NULL) {
                M2C_FIELD(temp_s0, s32 *, 0x10) = func_8002D260(M2C_FIELD(temp_s0, const s32 *, 0x10) + 0x8000);
                func_8002D3E4(temp_s0, 0x190);
            }
        }
    }
    if (D_801705F4 != 0) {
        func_8007DB44();
    }
    return 0;
}
