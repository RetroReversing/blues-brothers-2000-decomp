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

M2C_UNK func_80023A74(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80023A98(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8002E7B8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_800526E0(M2C_UNK);                     /* extern */
extern s32 D_800B4988;
extern s32 D_8013FB20;
extern M2C_UNK func_8008896C;

void func_80088658(void *arg0) {
    if (D_8013FB20 == 0xFF) {
        func_80023A74(0x76, 0xCF7);
        func_80023A98(0x1C0, 0xCF8, 0);
        func_800526E0(0);
        func_8002E7B8(0, 0);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8008896C;
        M2C_FIELD(arg0, s32 *, 0x64) = 0x3E8;
        D_800B4988 = 0x1E;
        M2C_FIELD(arg0, s32 *, 0x70) = 0x64;
        M2C_FIELD(arg0, s32 *, 0x74) = 0x2BC;
    }
}
