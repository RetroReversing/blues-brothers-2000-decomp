/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_FIELD_PTR(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8002D3E4(void *, M2C_UNK);             /* extern */
s32 func_8002D5E8(void *);                          /* extern */
M2C_UNK func_8002DA80(void *);                      /* extern */
M2C_UNK animStepKeys(void *);                      /* extern */
s32 func_80085754(void *, s32, f32);            /* extern */
extern f32 D_80009AFC;
extern void *gCameraTarget;
extern void *D_8014AAB0;
extern f32 D_801700D0;
extern M2C_UNK func_80085998;

s32 func_80085A5C(void *arg0) {
    s32 var_v0;
    s32 var_v0_web;

    if (M2C_FIELD(arg0, s32 *, 0x64) <= 0) {
        return 1;
    }
    func_8002D3E4(arg0, 0x87);
    func_8002DA80(arg0);
    animStepKeys(arg0);
    if (func_8002D5E8(arg0) != 0) {
        if (func_80085754(arg0, M2C_FIELD(arg0, s32 *, 0xF4), 0.0f) == 0) {
            void *__repair_cached_pointer = D_8014AAB0;

            M2C_FIELD_PTR(arg0, s32 *, 0x90) = 0x32;
            M2C_FIELD(__repair_cached_pointer, s32 *, 0x88) = 1;
            M2C_FIELD(arg0, s32 *, 0x8C) = 0;
            M2C_FIELD(arg0, s32 *, 0x10) += randomRange(-0x1000, 0x1000);
            if (func_80085754(arg0, M2C_FIELD(arg0, s32 *, 0xF4), 100.0f) == 0) {
                M2C_FIELD(arg0, M2C_UNK **, 0xD8) = &func_80085998;
                M2C_FIELD(D_8014AAB0, s32 *, 0x88) = 0xA;
                return 0;
            }
            return 2;
        }
        M2C_FIELD(D_8014AAB0, s32 *, 0x88) = 2;
        M2C_FIELD(arg0, s32 *, 0x90) = 0;
        goto block_7;
    }
block_7:
    if (D_801700D0 < 250.0f) {
        return 3;
    }
    var_v0 = (func_80085754(gCameraTarget, M2C_FIELD(arg0, s32 *, 0xF4), 0.0f) != 0);
    var_v0_web = var_v0 * 4;
    return var_v0_web;
}

