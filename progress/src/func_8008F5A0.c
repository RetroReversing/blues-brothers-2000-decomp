/* identical to func_800FD7D0 in BATTLETANXGA (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80188AC4 in BATMAN BEYOND RETURN (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800896E0 in ARMYMEN SARGE 2 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8007F440 in Army Men Sarge (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80097EA0 in ARMYMENAIRCOMBAT (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8006772C in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
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

void func_8008F5A0(s32 *arg0, s32 arg1, s32 arg2) {
    u8 __repair_frame[8];
    char *var_a0;
    s32 temp_v0;
    s32 var_v1;

    var_a0 = arg0;
    var_v1 = 0;
    if (arg2 > 0) {
        do {
            temp_v0 = *(s32 *)var_a0;
            var_v1 += 1;
            if (temp_v0 != 0) {
                *(s32 *)var_a0 = temp_v0 + arg1;
            }
            var_a0 += 4;
        } while (var_v1 < arg2);
    }
}
