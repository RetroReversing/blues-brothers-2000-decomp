/* identical to func_80234838 in BATMAN BEYOND RETURN (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8008713C in AIDYN_CHRONICLES (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80047108 in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
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

M2C_UNK func_80012C9C();                            /* extern */
M2C_UNK func_80012C6C();                            /* extern */
M2C_UNK func_80031724();                            /* extern */

void func_8002E348(void) {
    func_80031724();
    func_80012C6C();
    func_80012C9C();
}
