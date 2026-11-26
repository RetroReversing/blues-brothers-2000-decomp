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

void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800433A8(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK D_8014AA62;
extern M2C_UNK func_800712B0;
extern M2C_UNK func_8007148C;

void *func_800717A8(void *arg0) {
    void *temp_v0;

    func_80050460(&func_800712B0, &D_8014AA62);
    temp_v0 = func_80042F00(0x44, 0, 0, 0);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x135;
    func_800433A8(temp_v0, 0x144, 0x100);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8007148C;
    M2C_FIELD(temp_v0, s32 *, 0x90) = 1;
    if (arg0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
        M2C_FIELD(temp_v0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
        M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    }
    return temp_v0;
}
