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

s32 func_8002444C();                                /* extern */
M2C_UNK func_8003BF98(s32);                         /* extern */
s32 func_80043248(void *);                          /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80058F74(void *, M2C_UNK *);           /* extern */
M2C_UNK func_80059298(void *);                      /* extern */
extern s32 D_800BD06C;
extern M2C_UNK func_80059058;
extern M2C_UNK func_80059100;

void func_80058FA8(void *arg0) {
    M2C_UNK *var_a1_2;

    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        if (func_8002444C() & 1) {
            func_80043328(arg0, 0x42, 0x180);
        } else {
            func_80043328(arg0, 0x41, 0x180);
        }
        func_80059298(arg0);
        func_8003BF98(D_800BD06C);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0xC0) & ~1) {
        var_a1_2 = &func_80059058;
        func_80058F74(arg0, var_a1_2);
    } else if (func_80043248(arg0) != 0) {
        var_a1_2 = &func_80059100;
        func_80058F74(arg0, var_a1_2);
    }
}
