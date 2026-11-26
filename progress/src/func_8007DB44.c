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

M2C_UNK func_8002D3E4(void *, M2C_UNK);             /* extern */
s32 tickActorTimer(void *);                          /* extern */
M2C_UNK func_8002DA80(void *);                      /* extern */
M2C_UNK animStepKeys(void *);                      /* extern */
void *func_8007DA68();                              /* extern */
extern void *D_801705EC;
extern void *D_801705F0;

s32 func_8007DB44(void) {
    volatile u64 scratch[4];
    void *temp_s1;
    void *var_s0;

    if (D_801705EC == NULL) {
        temp_s1 = D_801705F0;
        var_s0 = func_8007DA68();
        if (var_s0 == NULL) {
            return 0;
        }
        M2C_FIELD(var_s0, f32 *, 4) = (f32) M2C_FIELD(temp_s1, f32 *, 4);
        M2C_FIELD(var_s0, f32 *, 8) = (f32) M2C_FIELD(temp_s1, f32 *, 8);
        M2C_FIELD(var_s0, f32 *, 0xC) = (f32) M2C_FIELD(temp_s1, f32 *, 0xC);
        D_801705EC = var_s0;
        M2C_FIELD(var_s0, s32 *, 0x10) = (s32) M2C_FIELD(temp_s1, s32 *, 0x10);
        func_8002D3E4(var_s0, 0x190);
        M2C_FIELD(var_s0, s32 *, 0x64) = 0x46;
        M2C_FIELD(var_s0, s32 *, 0x90) = (s32) (M2C_FIELD(temp_s1, s32 *, 0x90) + 2);
    } else {
        var_s0 = D_801705EC;
    }
    if (tickActorTimer(var_s0) != 0) {
        M2C_FIELD(var_s0, s32 *, 0x64) = 0;
        func_8002DA80(var_s0);
        animStepKeys(var_s0);
        M2C_FIELD(var_s0, M2C_UNK (**)(void *), 0x98)(var_s0);
    }
    return 0;
}
