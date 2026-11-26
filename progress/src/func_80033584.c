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
s32 func_80030C40();
s32 func_80031B54();
extern s32 gPadPressed;
extern s32 func_800336A4;
void func_80033584(void *arg0) {
    M2C_FIELD(arg0, s32 **, 0x98) = &func_800336A4;
    func_80031B54(arg0, 2);
    if (gPadPressed & 0x9000) {
switch (M2C_FIELD(arg0, s32 *, 0x78)) { case 0: func_80030C40(arg0, -1); break; case 1: func_80030C40(arg0, 7); break; } M2C_FIELD(arg0, s32 *, 0x78) = 0;
    }
}
