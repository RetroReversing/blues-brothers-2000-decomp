/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

M2C_UNK loadSlotAssetSet(s32, M2C_UNK);                /* extern */
extern s32 D_80171994;
extern M2C_UNK D_80171A70;
extern M2C_UNK func_800877C8;

void func_8008776C(void *arg0) {
    M2C_FIELD(&D_80171A70, s32 *, 0) = 0;
    M2C_FIELD(&D_80171A70, s32 *, 4) = 4;
    M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_800877C8;
    D_80171994 = 0;
    loadSlotAssetSet(M2C_FIELD(&D_80171A70, s32 *, 0), 0x17B);
    loadSlotAssetSet(M2C_FIELD(&D_80171A70, s32 *, 4), 0x18B);
}
