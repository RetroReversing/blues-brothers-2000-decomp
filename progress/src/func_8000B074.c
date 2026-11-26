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
void func_8000ABE8(u8 *, u32);
void func_8000AF10(u8 *, u8);

void func_8000B074(u8 *p, u8 c, u32 n) {
    u32 w;

    while (n != 0 && ((u32) p & 3) != 0) {
        func_8000AF10(p++, c & 0xFF);
        n--;
    }
    if (n >= 4) {
        {u32 t = c & 0xFF;
        w = (t << 24) | (t << 16) | (t << 8) | t;}
        do {
            func_8000ABE8(p, w);
            n -= 4;
            p += 4;
        } while (n >= 4);
    }
    while (n != 0) {
        func_8000AF10(p++, c & 0xFF);
        n--;
    }
}
