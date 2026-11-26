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

void func_80030C40(void *arg0, s32 arg1) {
    s32 old;
    s32 tbl;
    s32 temp_v0;

    old = *(s32 *)((s8 *)arg0 + 0x70);
    tbl = *(s32 *)((s8 *)arg0 + 0x74);
    temp_v0 = old + arg1;
    *(s32 *)((s8 *)arg0 + 0x70) = temp_v0;
    *(s32 *)((s8 *)arg0 + 0x9C) = *(s32 *)((temp_v0 * 4) + tbl);
    *(s32 *)((s8 *)arg0 + 0x7C) = 1;
}
