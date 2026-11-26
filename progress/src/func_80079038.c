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

s32 func_80043248();                                /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80078D94(void *);                      /* extern */

void func_80079038(void *arg0) {
    if (func_80043248() != 0) {
        if (M2C_FIELD(arg0, s32 *, 0xD0) != 0x109) {
            M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + 0x8000);
        }
        if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
            func_80043328(arg0, 0x103, 0x100);
            M2C_FIELD(arg0, s32 *, 0x7C) = 1;
            return;
        }
        func_80078D94(arg0);
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x9C) = func_80078D94;
    }
}
