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

f32 func_8002D858(void *, M2C_UNK);                 /* extern */
M2C_UNK func_8003BF98(void *);                      /* extern */
s32 func_80073DC8(void *, M2C_UNK);                 /* extern */
extern f32 D_80009188;
extern s32 D_800B5DD4;

void func_80073FC8(void *arg0) {
    if (D_800B5DD4 == 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0xA0)();
        return;
    }
    if ((func_80073DC8(arg0, 1) == 0) && (func_8002D858(arg0, 0) < D_80009188)) {
        func_8003BF98(arg0);
        M2C_FIELD(arg0, s32 *, 0x64) = 0;
    }
}
