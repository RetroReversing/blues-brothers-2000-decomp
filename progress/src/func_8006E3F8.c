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

s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
s32 func_8004303C(void *);                          /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_8006DA0C(void *);                          /* extern */

void func_8006E3F8(void *arg0) {

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x34) = 0x190;
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x38) = 0x190;
        M2C_FIELD(arg0, s32 *, 0x3C) = M2C_FIELD(arg0, s32 *, 0x34);
    }
    if ((func_8006DA0C(arg0) == 0) && (func_8004303C(arg0) != 0)) {
        if (func_80024394(0, 0x14) != 0) {
            func_80043328(arg0, 1, 0x100);
        } else if (func_80024394(0, 5) != 0) {
            func_80043328(arg0, 0x18, 0x100);
        } else if (func_80024394(0, 1) != 0) {
            func_80043328(arg0, 0x1A, 0x100);
        } else {
            func_80043328(arg0, 0x22, 0x100);
        }
    }
}
