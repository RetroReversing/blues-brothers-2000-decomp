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

void *func_80017DEC(s32);                           /* extern */
extern void *gCameraRig;
extern M2C_UNK func_80034F50;

s32 func_80018244(void *arg0) {
    void *temp_v0;
    void *temp_a0;
    s32 temp_a0_2;

    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x70);
    if (temp_a0_2 != 0) {
        temp_v0 = func_80017DEC(temp_a0_2);
        if (temp_v0 != NULL) {
            temp_a0 = gCameraRig;
            M2C_FIELD(temp_a0, f32 *, 4) = (f32) M2C_FIELD(temp_v0, f32 *, 4);
            M2C_FIELD(temp_a0, f32 *, 8) = (f32) (M2C_FIELD(temp_v0, f32 *, 8) + 1000.0f);
            M2C_FIELD(temp_a0, f32 *, 0xC) = (f32) (M2C_FIELD(temp_v0, f32 *, 0xC) - 1000.0f);
            M2C_FIELD(temp_a0, M2C_UNK **, 0x9C) = &func_80034F50;
            M2C_FIELD(arg0, s32 *, 0x70) = 0;
            return 1;
        }
        return 0;
    }
    return 0;
}
