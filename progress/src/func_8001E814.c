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

s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
extern M2C_UNK func_8001E750;
extern M2C_UNK func_80023078;

void func_8001E814(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x70);
    if (temp_v1 == 1) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8001E750;
        M2C_FIELD(arg0, s32 *, 0x58) = packDrawFlags(0, 1, 1, 3, 0, 0, temp_v1, 0);
    } else {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = (M2C_UNK *) (&func_80023078 + 2);
    }
    M2C_FIELD(arg0, s32 *, 0) = 0x101;
}
