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

void *func_8002E374(s32);                           /* extern */
M2C_UNK func_80050488(M2C_UNK *, M2C_UNK *, void *); /* extern */
M2C_UNK func_800852CC(void *, void *);              /* extern */
extern M2C_UNK D_8014AA70;
extern M2C_UNK func_800763F8;
extern M2C_UNK func_800764B8;

void *func_800767E4(void *arg0) {
    void *temp_v0;

    func_80050488(&func_800763F8, &D_8014AA70, arg0);
    temp_v0 = func_8002E374(M2C_FIELD(arg0, s32 *, 0xBC) + 0x1D6);
    func_800852CC(temp_v0, arg0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_800764B8;
    M2C_FIELD(temp_v0, s32 *, 0x6C) = 1;
    M2C_FIELD(temp_v0, s32 *, 0xBC) = (s32) M2C_FIELD(arg0, s32 *, 0xBC);
    M2C_FIELD(temp_v0, s32 *, 0x64) = 0x64;
    return temp_v0;
}

