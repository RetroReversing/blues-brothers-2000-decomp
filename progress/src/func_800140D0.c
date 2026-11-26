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

M2C_UNK func_80013F88(void *);                      /* extern */
s32 func_800221C0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8002D620(void *);                      /* extern */
void *func_8002E374(M2C_UNK);                       /* extern */
extern f32 D_80000820;

void *func_800140D0(void *arg0) {
    void *temp_v0;

    temp_v0 = func_8002E374(0x95);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x9C) = func_80013F88;
    M2C_FIELD(temp_v0, s32 *, 0x58) = func_800221C0(1, 1, 0, 3, 0, 0, 1, 0);
    if (arg0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
        M2C_FIELD(temp_v0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
        M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    }
    func_8002D620(temp_v0);
    M2C_FIELD(temp_v0, f32 *, 0x44) = (f32) (M2C_FIELD(temp_v0, f32 *, 0x44) + D_80000820);
    M2C_FIELD(temp_v0, s32 *, 0x74) = (s32) (func_80024394(0, 0x200) + 0x400);
    M2C_FIELD(temp_v0, s32 *, 0x78) = (s32) (func_80024394(0, 0x200) + 0x200);
    M2C_FIELD(temp_v0, s32 *, 0x64) = 0x3E8;
    M2C_FIELD(temp_v0, s32 *, 0x7C) = 0x64;
    func_80013F88(temp_v0);
    return temp_v0;
}
