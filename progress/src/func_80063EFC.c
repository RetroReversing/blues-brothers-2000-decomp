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

M2C_UNK func_8002D3E4(void *, M2C_UNK);             /* extern */
s32 tickActorTimer();                                /* extern */
M2C_UNK func_8002DA80(void *);                      /* extern */
f32 func_800385AC(void *);                          /* extern */
M2C_UNK animStepKeys(void *);                      /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80063E50();                            /* extern */
M2C_UNK fireActorEvents(void *);                      /* extern */
extern f32 D_80008B48;

void func_80063EFC(void *arg0) {
    if (tickActorTimer() != 0) {
        func_80063E50();
    }
    func_80043328(arg0, 0xDF, 0x100);
    M2C_FIELD(arg0, f32 *, 8) = func_800385AC(arg0);
    animStepKeys(arg0);
    fireActorEvents(arg0);
    func_8002D3E4(arg0, 0xA0);
    func_8002DA80(arg0);
    if (M2C_FIELD(arg0, f32 *, 0xC) < D_80008B48) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
