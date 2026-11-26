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

s32 func_8002D5CC();
s32 func_80043328();
extern f32 D_80008F7C;
extern s32 func_8006C264;

void func_8006C1D4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x8C);
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        func_80043328(arg0, 0xEB, 0x100);
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x64) = 0x32;
        return;
    }
    if (((f32) M2C_FIELD(arg0, s32 *, 0x90) < D_80008F7C) && (func_8002D5CC(arg0) != 0)) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, s32 **, 0xD8) = &func_8006C264;
    }
}
