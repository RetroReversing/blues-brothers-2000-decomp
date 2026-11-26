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

s32 func_800221C0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800433A8(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_80081588(s32, M2C_UNK);                /* extern */
M2C_UNK func_800852CC(void *, s32);                 /* extern */
extern s32 D_800B7B0C;
extern s32 D_800B81D0;
extern M2C_UNK D_8014AA49;
extern M2C_UNK func_80056D80;
extern M2C_UNK func_80056E1C;
extern M2C_UNK func_8006DC44;
extern M2C_UNK func_80084000;

void *func_80056F04(s32 arg0) {
    s32 temp_a0;
    void *temp_v0;

    func_80050460(&func_80056D80, &D_8014AA49);
    temp_v0 = func_80042F00(0x1B, 0, 0, 0);
    func_800433A8(temp_v0, 0xA3, 0x100);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x1008;
    M2C_FIELD(temp_v0, s32 *, 0x58) = func_800221C0(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
    func_800852CC(temp_v0, arg0);
    if (D_800B81D0 != 0) {
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8006DC44;
        M2C_FIELD(temp_v0, s32 *, 0xBC) = 4;
        M2C_FIELD(temp_v0, s32 *, 0x6C) = 1;
        return temp_v0;
    }
    M2C_FIELD(temp_v0, s32 *, 0x74) = 0xA2;
    temp_a0 = M2C_FIELD(temp_v0, s32 *, 0x70);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80084000;
    if (temp_a0 != 0) {
        func_80081588(temp_a0, 1);
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80056E1C;
    }
    return temp_v0;
}
