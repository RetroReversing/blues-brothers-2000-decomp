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

void *func_80013110(void *);                        /* extern */
M2C_UNK func_800768E8(void *);                      /* extern */
extern f32 D_80000844;
extern void *gCameraTarget;
extern M2C_UNK func_80014870;
extern M2C_UNK func_80023848;

void func_80014964(void) {
    void *temp_v0;

    M2C_FIELD(gCameraTarget, s32 *, 0) = 0x101;
    M2C_FIELD(gCameraTarget, M2C_UNK **, 0xD8) = &func_80014870;
    M2C_FIELD(gCameraTarget, M2C_UNK (**)(void *), 0x9C) = func_800768E8;
    M2C_FIELD(gCameraTarget, s32 *, 0x68) = -1;
    M2C_FIELD(gCameraTarget, s32 *, 0x64) = 0x32;
    temp_v0 = func_80013110(gCameraTarget);
    M2C_FIELD(temp_v0, f32 *, 8) = (f32) (M2C_FIELD(temp_v0, f32 *, 8) + 175.0f);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x9C)(temp_v0);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x9C) = func_800768E8;
    M2C_FIELD(temp_v0, M2C_UNK **, 0xD8) = &func_80023848;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 0x32;
}

