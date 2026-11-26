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

M2C_UNK func_80012718(void *);                      /* extern */
M2C_UNK func_8002CE84(M2C_UNK, M2C_UNK);            /* extern */
extern void *gCameraTarget;
extern M2C_UNK func_800393F4;
extern M2C_UNK func_8005AA58;

void func_8005A9CC(void) {
    if (M2C_FIELD(gCameraTarget, M2C_UNK **, 0x9C) == &func_800393F4) {
        M2C_FIELD(gCameraTarget, M2C_UNK **, 0x9C) = &func_8005AA58;
        func_80012718(gCameraTarget);
        func_80012718(gCameraTarget);
        func_80012718(gCameraTarget);
        func_80012718(gCameraTarget);
        func_8002CE84(3, 0);
        func_8002CE84(2, 5);
        func_8002CE84(4, 0);
    }
}
