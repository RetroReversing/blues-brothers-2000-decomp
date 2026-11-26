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
M2C_UNK func_80050460(M2C_UNK *, void *);           /* extern */
M2C_UNK func_800852CC(void *, s32);                 /* extern */
extern M2C_UNK D_8014AA5C;
extern M2C_UNK func_800689B4;
extern M2C_UNK func_80068E0C;

s32 func_80068A34(s32 arg0) {
    void *temp_v0;

    func_80050460(&func_800689B4, (char *)&D_8014AA5C + 1);
    temp_v0 = func_80042F00(0x37, 0, 0, 0);
    func_800433A8(temp_v0, 0x112, 0x100);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x1012;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80068E0C;
    M2C_FIELD(temp_v0, s32 *, 0x34) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x34) * 2);
    M2C_FIELD(temp_v0, s32 *, 0x38) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x38) * 2);
    M2C_FIELD(temp_v0, s32 *, 0x3C) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x3C) * 2);
    func_800852CC(temp_v0, arg0);
    M2C_FIELD(temp_v0, s32 *, 0xFC) = 4;
    return (s32) temp_v0;
}
