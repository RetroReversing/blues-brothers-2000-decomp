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

void *func_80023874(M2C_UNK, M2C_UNK);              /* extern */
s32 func_80043248(void *);                          /* extern */
M2C_UNK func_80075614(void *);                      /* extern */
extern void *D_800BD06C;
extern M2C_UNK func_800393F4;
extern M2C_UNK func_8007563C;

void func_8007569C(void *arg0) {
    void *temp_v0;
    void *temp_v0_2;

    if (func_80043248(D_800BD06C) != 0) {
        M2C_FIELD(D_800BD06C, M2C_UNK **, 0x9C) = &func_800393F4;
        M2C_FIELD(arg0, s32 *, 0x64) = 0x78;
        temp_v0 = func_80023874(0x11E, 0);
        func_80075614(temp_v0);
        temp_v0_2 = func_80023874(0x11F, 0);
        func_80075614(temp_v0_2);
        if (M2C_FIELD(temp_v0, s32 *, 0x68) == M2C_FIELD(temp_v0_2, s32 *, 0x68)) {
            func_80075614(temp_v0_2);
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8007563C;
    }
}
