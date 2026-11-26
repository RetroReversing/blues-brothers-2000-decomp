/* identical to func_80077E80 in BATTLETANXGA (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80076240 in BATTLETANX (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80078D70 in ARMYMEN SARGE 2 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8000C0E0 in ARMYMENAIRCOMBAT (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80300A40 in All Star Baseball 99 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8006F450 in Army Men Sarge (local match library) (matched), with its names changed by decompdecomp */
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

void func_8000ADC0(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a2;

    temp_a2 = (~arg0 & 3) * 8;
    temp_a0 = arg0 & ~3;
    *(s32 *)temp_a0 = (s32) ((*(s32 *)temp_a0 & ~(0xFF << temp_a2)) | ((arg1 & 0xFF) << temp_a2));
}
