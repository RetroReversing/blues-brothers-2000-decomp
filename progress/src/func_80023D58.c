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

M2C_UNK func_80023B84(s32, M2C_UNK *);              /* extern */
s32 func_800259F8();                                /* extern */
extern M2C_UNK D_800FB810;

s32 func_80023D58(s32 arg0) {
    M2C_UNK sp10;
    s32 temp_v0;

    temp_v0 = func_800259F8();
    if ((&D_800FB810)[temp_v0 * 3] == 0) {
        func_80023B84(arg0, &sp10);
    }
    return temp_v0;
}
