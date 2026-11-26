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

M2C_UNK func_80026C04(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern s32 D_800A9548;
extern M2C_UNK D_800BCFB8;
extern M2C_UNK D_800BD0B8;
extern s32 D_800BD0E0;
extern M2C_UNK D_800BD120;
extern M2C_UNK D_800BD1F0;

void func_8001AFD4(void) {
    func_80026C04(&D_800BD0B8, 0, 0x20);
    func_80026C04(&D_800BD1F0, 0, 0x28);
    func_80026C04(&D_800BCFB8, 0, 0x40);
    func_80026C04(&D_800BD120, 0, 0x40);
    D_800A9548 = 0;
    D_800BD0E0 = 3;
}
