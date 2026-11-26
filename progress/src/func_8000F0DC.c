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

M2C_UNK func_8000C5B4();                            /* extern */
M2C_UNK func_8000F044(void *);                      /* extern */
s32 tickActorTimer(void *);                          /* extern */
s32 animStepKeys();                                /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
extern s32 gFrameScale;
extern s32 D_800BD23C;
extern M2C_UNK func_8001BBB4;

void func_8000F0DC(void *arg0) {
    s32 temp_a0;
    s32 temp_s1;

    temp_s1 = animStepKeys();
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x7C) - gFrameScale;
    M2C_FIELD(arg0, s32 *, 0x7C) = temp_a0;
    if (temp_a0 < 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 0x19;
        func_8000F044(arg0);
    }
    if (temp_s1 != 0) {
        func_80043328(arg0, 0x89, 0x100);
    }
    D_800BD23C = M2C_FIELD(arg0, s32 *, 0x64);
    if (tickActorTimer(arg0) != 0) {
        D_800BD23C = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8001BBB4;
    }
    func_8000C5B4();
}
