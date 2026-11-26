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

s32 func_8002D5CC();                                /* extern */
M2C_UNK func_800899DC(M2C_UNK *);                   /* extern */
extern M2C_UNK D_80009284;

void func_800768E8(void *arg0) {
    s32 temp_v0;

    if (func_8002D5CC() != 0) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0xD8);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, s32 *, 0x9C) = temp_v0;
            M2C_FIELD(arg0, s32 *, 0xD8) = 0;
            return;
        }
        func_800899DC(&D_80009284);
    }
}
