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

s32 func_8000C43C();                                /* extern */
M2C_UNK func_80023A74(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80023A98(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
s32 func_80023D58(M2C_UNK);                         /* extern */
extern s32 D_8014AB14;

void func_8005E744(void) {
    func_80023A74(0x26, 0x46B);
    func_80023A98(0xDE, 0x473, 0);
    func_80023A98(0xDF, 0x476, 0);
    func_80023A98(0xE0, 0x471, 0);
    func_80023A98(0xE1, 0x474, 0);
    func_80023A98(0xE2, 0x46C, 0);
    func_80023A98(0xE3, 0x46D, 0);
    func_80023A98(0xE5, 0x472, 0);
    func_80023A98(0xE6, 0x475, 0);
    func_80023A98(0xE4, 0x470, 0);
    if (func_8000C43C() == 9) {
        func_80023A98(0xE7, 0x46E, 0);
        func_80023A98(0xE8, 0x46F, 0);
    }
    func_80023A74(0x64, 0x467);
    func_80023A98(0xE9, 0x46A, 0);
    func_80023A98(0xEA, 0x469, 0);
    D_8014AB14 = func_80023D58(0x197);
}
