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

s32 func_8001B990(M2C_UNK, M2C_UNK);                /* extern */
f32 getCameraTargetDist(void *, f32, M2C_UNK);        /* extern */
extern f32 D_80000C80;
extern f32 D_80000C84;

void func_8001C800(void *arg0) {
    f32 temp_fv1;

    M2C_FIELD(arg0, s32 *, 0) = 0x128;
    if (func_8001B990(0x100, 3) != 0) {
        M2C_FIELD(arg0, s32 *, 0) = 0x101;
        if ((s32) getCameraTargetDist(arg0, 200.0f, 0) < 0xC8) {
            temp_fv1 = M2C_FIELD(arg0, f32 *, 8);
            if (temp_fv1 < (M2C_FIELD(arg0, f32 *, 0x44) + D_80000C80)) {
                M2C_FIELD(arg0, f32 *, 8) = (f32) (temp_fv1 + D_80000C84);
            }
        }
    }
}
