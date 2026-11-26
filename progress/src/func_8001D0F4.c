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
M2C_UNK debugPrintf(M2C_UNK *);                   /* extern */
extern M2C_UNK D_80000CD4;
extern M2C_UNK func_8001D048;
extern M2C_UNK func_8007AAE0;

void func_8001D0F4(void *arg0) {
    if (cameraGetMode() == 0x20) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8001D048;
    }
    if (cameraGetMode() == 0x30) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8007AAE0;
    }
    if (M2C_FIELD(arg0, M2C_UNK **, 0x9C) == func_8001D0F4) {
        debugPrintf(&D_80000CD4);
    }
}
