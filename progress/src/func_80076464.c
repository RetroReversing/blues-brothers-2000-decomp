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

void func_80076464(void *arg0) {
    void *temp_v1;

    if (func_80043248() != 0) {
        temp_v1 = M2C_FIELD(arg0, void **, 0xA4);
        if (temp_v1 != NULL) {
            M2C_FIELD(temp_v1, s32 *, 0x68) = 5;
            M2C_FIELD(temp_v1, s32 *, 0xA8) = 0;
            M2C_FIELD(temp_v1, s32 *, 0) = 0x102;
        }
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
