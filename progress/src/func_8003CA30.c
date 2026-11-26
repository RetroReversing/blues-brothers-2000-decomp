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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80043328();
extern char D_80107040[];
extern char D_801070A0[];

s32 func_8003CA30(void *arg0) {

    if (!(((u32 *) &D_80107040)[M2C_FIELD(arg0, s32 *, 0xBC)] & 0x2000)) {
        if (((u32 *) &D_801070A0)[M2C_FIELD(arg0, s32 *, 0xBC)] & 0x10) {
            func_80043328(arg0, 0x25, 0x100);
            return 1;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
