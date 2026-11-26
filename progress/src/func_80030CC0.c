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

s32 func_80026188(M2C_UNK);                         /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80030C40(void *, M2C_UNK);             /* extern */
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 D_80107040;
extern M2C_UNK func_800317B8;

void func_80030CC0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        D_800B3978 = 0;
        D_800B3974 = 0;
        M2C_FIELD(arg0, s32 *, 0xFC) = 0;
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        D_800B3970 = 0;
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x98);
    }
    if (func_80026188(0) != 0) {
        M2C_FIELD(arg0, s32 *, 0x64) = 0x64;
        if (D_80107040 & 0x1000) {
            M2C_FIELD(arg0, s32 *, 0xFC) = 1;
        }
        func_80030C40(arg0, 1);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_800317B8;
}
