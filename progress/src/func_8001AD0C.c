/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

s32 func_8001B990(M2C_UNK, M2C_UNK);                /* extern */
f32 func_800385AC();                                /* extern */

extern M2C_UNK func_8001AC3C;
extern M2C_UNK func_80023078;

void func_8001AD0C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x137;
    if (M2C_FIELD(arg0, s32 *, 0x84) == 0) {
        M2C_FIELD(arg0, s32 *, 0x84) = 1;
        M2C_FIELD(arg0, s32 *, 0x78) = (s32) (func_800385AC() + 54.0f);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x9C) = (M2C_UNK *) (&func_80023078 + 2);
    if (func_8001B990(0x100, 0x1E) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8001AC3C;
    }
}
