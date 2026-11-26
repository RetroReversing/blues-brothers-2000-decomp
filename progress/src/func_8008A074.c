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

s32 cameraGetMode();                                /* extern */
M2C_UNK func_8000C458();                            /* extern */
extern s32 D_800B9F50;
extern s32 D_800B9F54;

void func_8008A074(void) {
    s32 *__base_D_800B9F54;
    s32 pad[32];
    do { func_8000C458(); } while (0);
    __base_D_800B9F54 = &D_800B9F54;
    if (cameraGetMode() < (*__base_D_800B9F54)) {
        D_800B9F50 += 1;
    }
    (*__base_D_800B9F54) = cameraGetMode();
}
