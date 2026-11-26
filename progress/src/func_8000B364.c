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

s32 func_8000AB80();
s32 func_8000ABB8();
s32 func_8000ABE8();
s32 func_8000BB30();
extern s8 D_800BC910;
extern s8 D_800BC912;

void func_8000B364(void) {
    s32 temp_s0;

    temp_s0 = func_8000AB80();
    func_8000BB30();
    func_8000ABE8(0xB1FFFFF0, 0);
    func_8000ABE8(0xB1FFFFFC, 0);
    D_800BC910 = 1;
    *(u8 *)&D_800BC912 = 0xFF;
    func_8000ABB8(temp_s0);
}
