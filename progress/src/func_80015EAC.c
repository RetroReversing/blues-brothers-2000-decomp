/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_FIELD_PTR(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
void *func_800232B4(M2C_UNK, s32, s32, s32);        /* extern */
extern s32 D_800BD1D4;
extern M2C_UNK func_80015E24;
extern M2C_UNK func_8002F8D0;

void *func_80015EAC(void *arg0) {
    void *temp_v0;

    temp_v0 = func_800232B4(0x101, (s32) M2C_FIELD(arg0, f32 *, 4), (s32) M2C_FIELD(arg0, f32 *, 8), (s32) M2C_FIELD(arg0, f32 *, 0xC));
    M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_8002F8D0;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80015E24;
    M2C_FIELD(temp_v0, s32 *, 0x70) = 0x1E;
    M2C_FIELD_PTR(temp_v0, s32 *, 0x78) = 0xFFFFFF;
    M2C_FIELD(temp_v0, s32 *, 0x7C) = 1;
    M2C_FIELD(temp_v0, s32 *, 0x74) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = (s32) D_800BD1D4;
    M2C_FIELD(temp_v0, s32 *, 0x58) = packDrawFlags(0, 1, 1, 3, 0, 0, 2, 0);
    M2C_FIELD(temp_v0, s32 *, 0x68) = 0xC;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 0xFF;
    return temp_v0;
}
