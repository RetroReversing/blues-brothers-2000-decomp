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

s32 func_8000AB80(void);
void func_8000ABB8(s32);
void func_8000ACE4(s32, s32, s32);
s32 func_8000B5FC(s32, s32, u32, s32);

s32 func_8000B8C4(s32 arg0, s32 arg1, u32 arg2) {
    s32 saved;
    s32 n;
    s32 total;
    u32 len;

    saved = func_8000AB80();
    total = 0;
    while (arg2 != 0) {
        len = arg2;
        if (arg2 > 0x8000U) {
            len = 0x8000;
        }
        do { n = func_8000B5FC(0x505, arg0, len, 0); } while (0);
        if (n == 0) {
            return total;
        }
        func_8000ACE4(0xB1FF0000, arg1, n);
        arg1 += n;
        arg2 -= n;
        total += n;
    }
    func_8000ABB8(saved);
    return total;
}
