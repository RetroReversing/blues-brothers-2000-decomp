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

M2C_UNK func_800433A8(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80047824(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80047864(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80047898();                                /* extern */
extern void *D_800BD06C;
extern M2C_UNK func_80074880;
extern M2C_UNK func_80074A28;

void func_8007491C(void *arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(D_800BD06C, f32 *, 4);
        M2C_FIELD(arg0, f32 *, 0xC) = (f32) M2C_FIELD(D_800BD06C, f32 *, 0xC);
        if (M2C_FIELD(D_800BD06C, s32 *, 0x90) != 0) {
            temp_v0 = func_80047898();
            M2C_FIELD(D_800BD06C, s32 *, 0xE8) = temp_v0;
            func_80047824(temp_v0, 0, 0xFF, 0xFF, 0xFF);
            func_80047824(temp_v0, 0, 0xFF, 0xFF, 0xFF);
            func_80047864(temp_v0, 0, 0x14, 0x78, 0x14);
            func_80047864(temp_v0, 0, 0x14, 0x78, 0x14);
            func_800433A8(D_800BD06C, 0x22, 0x100);
            M2C_FIELD(D_800BD06C, M2C_UNK **, 0x9C) = &func_80074880;
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80074A28;
        }
    }
}
