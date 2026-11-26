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

M2C_UNK func_8001B990(M2C_UNK, M2C_UNK);            /* extern */
s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
M2C_UNK func_8002ADFC(M2C_UNK, M2C_UNK, void *);    /* extern */
M2C_UNK func_8002D604(void *);                      /* extern */
f32 getCameraTargetDist(void *, M2C_UNK, M2C_UNK);        /* extern */

void func_8001C124(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x58) = packDrawFlags(1, 1, 0, 3, 0, 1, 1, 0);
    func_8002D604(arg0);
    if ((s32) getCameraTargetDist(arg0, 0x42C80000, 0) < 0x64) {
        func_8002ADFC(0xB, 0x3E8, arg0);
        func_8001B990(0x200, 0x1C);
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
