/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

M2C_UNK func_8006E964();                            /* extern */
extern void *gCameraRig;
extern void *D_800B3964;
extern s32 D_800B82D8;
extern s32 D_800B82E4;

void func_8006EF70(void *arg0) {
    f32 var_fv0;
    s32 *var_v0;

    if ((M2C_FIELD(D_800B3964, s32 *, 0xBC) == 0) && (M2C_FIELD(gCameraRig, s32 *, 0x74) != 0)) {
        if (M2C_FIELD(D_800B3964, s32 *, 0x88) == 0) {
            var_fv0 = (f32) D_800B82D8;
            var_v0 = &D_800B82D8;
        } else {
            var_fv0 = (f32) D_800B82E4;
            var_v0 = &D_800B82E4;
        }
        M2C_FIELD(arg0, f32 *, 0x28) = var_fv0;
        M2C_FIELD(arg0, f32 *, 0x2C) = (f32) M2C_FIELD(var_v0, s32 *, 4);
        M2C_FIELD(arg0, f32 *, 0x30) = (f32) M2C_FIELD(var_v0, s32 *, 8);
    }
    func_8006E964();
}
