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

M2C_UNK debugPrintf(M2C_UNK *, M2C_UNK (*)(void *)); /* extern */
extern M2C_UNK D_80008000;

void func_80050488(M2C_UNK (*arg0)(void *), u8 *arg1, void *arg2) {
    u8 temp_v0;

    if (arg2 == NULL) {
        debugPrintf(&D_80008000, arg0);
    }
    do { temp_v0 = *arg1; } while (0);
    if (temp_v0 == 0) {
        arg0(arg2);
        *arg1 = M2C_FIELD(arg2, u8 *, 0xBF) + 1;
        return;
    }
    M2C_FIELD(arg2, s32 *, 0xBC) = (s32) (temp_v0 - 1);
}
