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

M2C_UNK func_800242A8(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80074BAC();                            /* extern */
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 D_800B83B0;

void func_80074C14(void *arg0) {
    s32 temp_a0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        D_800B3970 = 0x96;
        D_800B3974 = 0xB6;
        D_800B3978 = 0xC6;
        func_80074BAC();
        temp_a0 = D_800B83B0 + 0x1D6;
        M2C_FIELD(arg0, s32 *, 0x94) = temp_a0;
        func_800242A8(temp_a0, 0xAD4, 0);
        D_800B83B0 += 1;
    }
}
