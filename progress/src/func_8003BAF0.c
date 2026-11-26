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

M2C_UNK func_80024394(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8003BF98(void *);                      /* extern */
s32 func_8004303C();                                /* extern */
extern s32 D_800B4CE0;
extern void *D_800BD06C;
extern M2C_UNK func_800393F4;

void func_8003BAF0(void *arg0) {
    s32 temp_s0;

    temp_s0 = func_8004303C();
    func_80024394(5, 0x32);
    if (temp_s0 != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        M2C_FIELD(D_800BD06C, M2C_UNK **, 0x9C) = &func_800393F4;
        M2C_FIELD(D_800BD06C, s32 *, 0x68) = 3;
        { M2C_FIELD(D_800BD06C, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4); }
        M2C_FIELD(D_800BD06C, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(D_800BD06C, s32 *, 0xF0) = 0xFF;
        M2C_FIELD(D_800BD06C, s32 *, 0) = 3;
        func_8003BF98(D_800BD06C);
        D_800B4CE0 = 0;
        M2C_FIELD(D_800BD06C, s32 *, 0) = 0x101;
    }
}
