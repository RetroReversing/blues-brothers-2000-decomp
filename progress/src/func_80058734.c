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

s32 func_8000C43C();                                /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800433A8(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, void *);           /* extern */
void *func_800851D8(void *);                        /* extern */
M2C_UNK func_80085244(void *, s32);                 /* extern */
M2C_UNK func_800852CC(void *, s32);                 /* extern */
extern M2C_UNK D_8014AA42;
extern M2C_UNK func_80058104;
extern M2C_UNK func_80058678;
extern M2C_UNK func_800589C4;

void *func_80058734(s32 arg0) {
    s16 var_v0;
    void *temp_s1;
    void *temp_v0;

    func_80050460(&func_80058678, (char *)&D_8014AA42 + 1);
    temp_v0 = func_80042F00(0x12, 0, 0, 0);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x100B;
    func_800433A8(temp_v0, 0x77, 0x100);
    func_800852CC(temp_v0, arg0);
    temp_s1 = func_800851D8(temp_v0);
    if (func_8000C43C() == 0x3C) {
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = (M2C_UNK *) ((char *)&func_80058104 + 0xC);
        M2C_FIELD(temp_v0, s32 *, 0x34) = 0x200;
        M2C_FIELD(temp_v0, s32 *, 0x38) = 0x200;
        M2C_FIELD(temp_v0, s32 *, 0x3C) = 0x200;
        do { var_v0 = 0x13E; } while (0);
    } else {
        func_80085244(temp_v0, arg0);
        M2C_FIELD(temp_v0, s32 *, 0x74) = 0x77;
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_800589C4;
        do { do { do { var_v0 = 0x9F; } while (0); } while (0); } while (0);
        M2C_FIELD(temp_v0, s32 *, 0x78) = 0;
    }
    do { M2C_FIELD(temp_s1, s16 *, 2) = var_v0; } while (0);
    return temp_v0;
}
