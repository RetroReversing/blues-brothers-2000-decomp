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

M2C_UNK func_800899DC(M2C_UNK *);                   /* extern */
extern M2C_UNK D_80000D80;
extern s32 D_800BD6C0;
extern s32 D_800CD0E0;

s32 func_8001EAD0(void) {
    s32 ret;
    if ((D_800BD6C0 - D_800CD0E0) < 0x515) {
        ret = D_800BD6C0;
    } else {
        func_800899DC(&D_80000D80);
        ret = -1;
    }
    return ret;
}
