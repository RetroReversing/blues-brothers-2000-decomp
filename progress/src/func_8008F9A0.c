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

M2C_UNK func_8008F9FC(s32, M2C_UNK);                /* extern */
M2C_UNK func_80090198(M2C_UNK);                     /* extern */
extern s32 D_800BB530;
extern s32 D_8017B260;

void func_8008F9A0(s32 arg0, M2C_UNK arg1) {
    if (D_800BB530 == 0) {
        D_800BB530 = arg0;
        func_80090198(arg1);
        D_8017B260 = D_800BB530;
        func_8008F9FC(D_800BB530, arg1);
    }
}
