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

s32 func_800221C0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
extern M2C_UNK func_8002ED14;

void func_80065630(void *arg0) {
    M2C_FIELD(arg0, void **, 0x98) = (void *) ((char *)&func_8002ED14 + 0xC);
    M2C_FIELD(arg0, s32 *, 0x70) = 0x50;
    M2C_FIELD(arg0, s32 *, 0x74) = 0;
    M2C_FIELD(arg0, s32 *, 0x78) = 0xFFFFFF;
    M2C_FIELD(arg0, s32 *, 0x7C) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = func_800221C0(0, 1, 1, 3, 0, 0, 1, 0);
    M2C_FIELD(arg0, s32 *, 0x68) = 0xC;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0xD0;
}
