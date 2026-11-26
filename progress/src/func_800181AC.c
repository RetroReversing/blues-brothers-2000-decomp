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

s32 func_80023874(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_800433A8(void *, M2C_UNK, M2C_UNK);    /* extern */
extern void *D_800BD06C;
extern M2C_UNK func_8003930C;

s32 func_800181AC(void) {

    if (func_80023874(0x800, 0) == 0) {
        M2C_FIELD(D_800BD06C, s32 *, 0x10) = 0x4000;
        M2C_FIELD(D_800BD06C, M2C_UNK **, 0x9C) = &func_8003930C;
        M2C_FIELD(D_800BD06C, s32 *, 0x64) = 0xC8;
        func_800433A8(D_800BD06C, 2, 0x100);
        return 1;
    }
    return 0;
}
