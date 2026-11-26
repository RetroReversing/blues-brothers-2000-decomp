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

M2C_UNK func_800242A8(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
void *func_8002E374(M2C_UNK);                       /* extern */
extern s32 D_800BD06C;
extern M2C_UNK func_8000C37C;

void func_80014740(void) {
    void *temp_v0;

    func_800242A8(0x88, 0x560, 0);
    temp_v0 = func_8002E374(0x88);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8000C37C;
    M2C_FIELD(temp_v0, s32 *, 0xA4) = (s32) D_800BD06C;
    M2C_FIELD(temp_v0, s32 *, 0x34) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x34) * 3);
    M2C_FIELD(temp_v0, s32 *, 0x38) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x38) * 3);
    M2C_FIELD(temp_v0, s32 *, 0x3C) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x3C) * 3);
}
