/* Partial candidate from function #137438953492 in project #32; rechecked locally. */
/* adapted from similar verified C in osScAddClient in ARMYMEN SARGE 2 (matched), with its names changed by decompdecomp */
/* identical to func_80070EE0 in ARMYMENAIRCOMBAT (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80070EE0 in ALL STAR TENNIS '99 (local match library) (matched), with its names changed by decompdecomp */
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

s32 func_80096100(s32);                             /* extern */

void func_80070EE0(void *arg0, void *arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_80096100(1);
    M2C_FIELD(arg1, s32 *, 4) = arg2;
    M2C_FIELD(arg1, void **, 0) = (void *) M2C_FIELD(arg0, void **, 1640);
    M2C_FIELD(arg0, void **, 1640) = arg1;
    func_80096100(temp_v0);
}
