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

void *spawnEffectObj(s32, s32, s32, s32);
extern void *gCameraRig;
extern void *D_800B3964;
extern s32 func_8006F644;

void func_8006F828(void)
{
    void *temp_v0;
    s32 var_a0;

    temp_v0 = spawnEffectObj(1, 0, 0, 0);
    M2C_FIELD(temp_v0, s32 *, 0x68) = 0xA;
    M2C_FIELD(temp_v0, s32 *, 0xBC) = M2C_FIELD(D_800B3964, s32 *, 0xBC);
    var_a0 = M2C_FIELD(gCameraRig, s32 *, 0x74);
    M2C_FIELD(temp_v0, s32 *, 0x64) = 0x32;
    M2C_FIELD(temp_v0, s32 **, 0x9C) = &func_8006F644;
    M2C_FIELD(temp_v0, s32 *, 0x74) = var_a0;
}
