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

s32 func_80066280(s32 *, s32 *, s32, s32, s32);
extern void *gCameraRig;
extern s32 D_800BD278[3];
extern s32 D_800BD688[3];

void func_80066368(s32 arg0) {
    s32 a[3];
    s32 b[3];

    a[0] = D_800BD278[0] + 0x1F4;
    a[1] = D_800BD278[1];
    a[2] = D_800BD278[2] + 0x60E;
    b[0] = D_800BD688[0] - 0x1F4;
    b[1] = D_800BD688[1];
    b[2] = D_800BD688[2] - 0x60E;
    func_80066280(a, b, 0x7A, 0, arg0);
    func_80066280(a, b, 0x7A, 1, arg0);
    func_80066280(a, b, 0x78, 1, arg0);
    func_80066280(a, b, 0x78, 1, arg0);
    M2C_FIELD(gCameraRig, f32 *, 4) = (b[0] - a[0]) / 2;
    M2C_FIELD(gCameraRig, f32 *, 8) = a[1] + 0x44C;
    M2C_FIELD(gCameraRig, f32 *, 0xC) = (b[2] - a[2]) / 2;
}
