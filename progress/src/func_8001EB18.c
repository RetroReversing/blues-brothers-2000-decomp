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

M2C_UNK func_800899DC(M2C_UNK *, s32, M2C_UNK, M2C_UNK *, s32); /* extern */
extern M2C_UNK D_80000DB0;
extern M2C_UNK D_80000DE4;
extern s32 D_800BD6C0;

s32 func_8001EB18(s32 arg0) {
    s32 temp_a1;

    temp_a1 = D_800BD6C0 + arg0;
    D_800BD6C0 = temp_a1;
    if (temp_a1 >= 0xFA1) {
        func_800899DC(&D_80000DB0, temp_a1, 0xFA0, &D_80000DE4, 0x51);
    }
    return D_800BD6C0;
}
