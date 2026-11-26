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

s32 func_8003C9AC(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800433A8(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK func_8005FBE4;
extern M2C_UNK func_8005FD4C;

s32 func_8005FD88(void *arg0, void *arg1) {
    M2C_UNK *temp_a0;
    M2C_UNK *temp_v1;

    if (func_8003C9AC(arg1, 1, 1, 1) == 0) {
    } else {
        temp_v1 = M2C_FIELD(arg0, M2C_UNK **, 0x9C);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8005FD4C;
        M2C_FIELD(arg0, M2C_UNK **, 0xD8) = temp_v1;
        func_800433A8(arg0, 0x19, 0x100);
        M2C_FIELD(arg0, s32 *, 0xC0) = 1;
        temp_a0 = M2C_FIELD(arg1, M2C_UNK **, 0x9C);
        M2C_FIELD(arg1, M2C_UNK **, 0x9C) = &func_8005FBE4;
        M2C_FIELD(arg1, void **, 0xA8) = arg0;
        M2C_FIELD(arg1, s32 *, 0x64) = 0x32;
        M2C_FIELD(arg1, M2C_UNK **, 0xD8) = temp_a0;
        return 1;
    }
    return 0;
}
