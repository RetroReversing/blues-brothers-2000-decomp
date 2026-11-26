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
void *func_800232B4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800242A8(M2C_UNK, s32, M2C_UNK);       /* extern */
void *func_8002E374(M2C_UNK);                       /* extern */
extern M2C_UNK func_80015980;

void *func_80015A90(s32 arg0) {
    void *temp_v0;

    if (arg0 == 0) {
        return func_800232B4(1, 0, 0, 0);
    }
    func_800242A8(0x9A, arg0, 0);
    temp_v0 = func_8002E374(0x9A);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_80015980;
    M2C_FIELD(temp_v0, s32 *, 0x34) = 0x140;
    M2C_FIELD(temp_v0, s32 *, 0x38) = 0x140;
    M2C_FIELD(temp_v0, s32 *, 0x3C) = 0x140;
    M2C_FIELD(temp_v0, s32 *, 0x68) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x58) = func_800221C0(0, 1, 0, 3, 0, 0, 1, 0);
    return temp_v0;
}
