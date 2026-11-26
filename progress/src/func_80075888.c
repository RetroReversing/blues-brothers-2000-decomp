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

s32 func_80023874(M2C_UNK, M2C_UNK);                /* extern */
s32 func_8002D5CC();                                /* extern */
M2C_UNK func_80075614(s32);                         /* extern */
extern void *D_800B3964;
extern M2C_UNK func_80075748;

void func_80075888(void *arg0) {
    if (func_8002D5CC() != 0) {
        func_80075614(func_80023874(0x11E, 0));
        do { func_80075614(func_80023874(0x11F, 0)); } while (0);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80075748;
        M2C_FIELD(D_800B3964, s32 *, 0x8C) = 0;
    }
}
