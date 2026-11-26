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
extern M2C_UNK D_8014AA7A;
extern M2C_UNK func_80075E4C;
extern M2C_UNK func_80075EBC;
extern M2C_UNK func_80075F00;

s32 func_80075FEC(s32 arg0) {
    void *temp_v0;

    func_80050460(&func_80075E4C, (char *)&D_8014AA7A + 1);
    temp_v0 = func_80042F00(0x7B, 0, 0, 0);
    func_800433A8(temp_v0, 0x1C3, 0x100);
    func_800852CC(temp_v0, arg0);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x101;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80075F00;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_80075EBC;
    return (s32) temp_v0;
}
