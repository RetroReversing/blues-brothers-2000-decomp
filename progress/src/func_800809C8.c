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

extern s32 func_80023078;

void func_800809C8(void *arg0) {
    s32 *__base_func_80023078;
    (*(s32 *)((s8 *)arg0 + 0x68)) = -1;
    (*(s32 *)((s8 *)arg0 + 0)) = 0x901;
    __base_func_80023078 = &func_80023078;
    (*(void **)((s8 *)arg0 + 0x9C)) = (void *) (__base_func_80023078 + 0x2);
}
