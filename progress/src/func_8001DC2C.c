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

s32 func_8000C43C();                                /* extern */
s32 func_8001B990(M2C_UNK, s32);                    /* extern */
f32 func_8002D858(void *, M2C_UNK);                 /* extern */
extern f32 D_80000D3C;
extern M2C_UNK func_8001DAD4;

void func_8001DC2C(void *arg0) {
    if (func_8000C43C() == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8001DAD4;
        M2C_FIELD(arg0, s32 *, 0xC0) = 0;
        return;
    }
    if ((func_8002D858(arg0, 0) < D_80000D3C) && (func_8001B990(0x100, M2C_FIELD(arg0, s32 *, 0x70)) != 0)) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
