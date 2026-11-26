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

M2C_UNK func_8002D620(void *);                      /* extern */
s32 func_80050144(void *, s32);                     /* extern */
extern void *D_800B3964;
extern void *D_800BD06C;
extern M2C_UNK func_800393F4;

void func_80072310(void *arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x80) = 1;
        M2C_FIELD(D_800B3964, s32 *, 0x70) = (s32) M2C_FIELD(arg0, s32 *, 0x70);
    }
    func_80050144(arg0, M2C_FIELD(arg0, s32 *, 0x70));
    func_80050144(arg0, M2C_FIELD(arg0, s32 *, 0x70));
    func_80050144(arg0, M2C_FIELD(arg0, s32 *, 0x70));
    func_80050144(arg0, M2C_FIELD(arg0, s32 *, 0x70));
    temp_v0 = func_80050144(arg0, M2C_FIELD(arg0, s32 *, 0x70));
    if (temp_v0 != 0) {
        M2C_FIELD(D_800BD06C, M2C_UNK **, 0x9C) = &func_800393F4;
    }
    M2C_FIELD(D_800BD06C, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
    M2C_FIELD(D_800BD06C, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
    M2C_FIELD(D_800BD06C, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    func_8002D620(D_800BD06C);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
