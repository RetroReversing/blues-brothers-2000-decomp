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

s32 func_800340B4();
s32 func_80036FB8();
extern s32 D_800B4ABC;
extern s32 D_80107040;
extern s32 D_801070A0;

void func_800351D4(void *arg0) {
    s32 *__base_D_801070A0;

    M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    M2C_FIELD(arg0, s32 *, 0x7C) = (s32) D_800B4ABC;
    func_80036FB8(arg0, 0xF);
    D_80107040 &= ~0x40F;
    __base_D_801070A0 = &D_801070A0;
    (*__base_D_801070A0) &= ~0x40F;
    func_800340B4(arg0);
}
