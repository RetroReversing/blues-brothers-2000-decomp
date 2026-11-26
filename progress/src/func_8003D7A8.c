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

M2C_UNK func_8001AFD4();                            /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002E7B8(M2C_UNK, M2C_UNK);            /* extern */
extern s32 D_800B5DD4;
extern s32 D_800B81D4;
extern s32 gPadPressed;
extern M2C_UNK func_8003D558;
extern M2C_UNK func_8003D854;
extern M2C_UNK func_8003DEF0;

void func_8003D7A8(void *arg0) {
    if (gPadPressed & 0x8000) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8003D558;
        func_8002E7B8(1, 0);
        D_800B5DD4 = 1;
        M2C_FIELD(arg0, s32 *, 0x70) = 0;
        D_800B81D4 = 0;
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x9D);
        func_8001AFD4();
    }
    if (gPadPressed & 0x4000) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8003D854;
        M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_8003DEF0;
    }
}
