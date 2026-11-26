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

M2C_UNK func_800263F4();                            /* extern */
M2C_UNK func_8002642C(s32);                         /* extern */
s32 func_800269B8(M2C_UNK *);                       /* extern */
s32 osPfsFindFile(M2C_UNK *, M2C_UNK, M2C_UNK, s32, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK D_80001110;
extern M2C_UNK D_80001120;
extern s32 D_800AE174;
extern s32 D_800AE1A4;
extern s32 D_800AE1A8;
extern M2C_UNK D_80107210;

s32 func_80026780(void) {
    M2C_UNK sp18;
    s32 temp_v0;

    func_800263F4();
    temp_v0 = osPfsFindFile(&D_80107210, 0x3630, 0x4E425045, func_800269B8(&D_80001120), &D_80001110, &sp18);
    if (temp_v0 == 2) {
        D_800AE1A4 = 1;
    } else {
        D_800AE1A4 = 0;
    }
    if (temp_v0 == 5) {
        D_800AE1A8 = 1;
    } else {
        D_800AE1A8 = 0;
    }
    if (temp_v0 == 3) {
        D_800AE174 = 1;
    } else {
        D_800AE174 = 0;
    }
    func_8002642C(temp_v0);
    return 1;
}
