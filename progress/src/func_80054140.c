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

s32 findActor(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80023C64(M2C_UNK);                     /* extern */
s32 tickActorTimer(void *);                          /* extern */

void func_80054140(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x64) = 0x3E8;
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
    }
    if (findActor(0x800, 0) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
    if (tickActorTimer(arg0) != 0) {
        func_80023C64(0x12345678);
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
