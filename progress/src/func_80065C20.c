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

M2C_UNK func_80023A74(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80023A98(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
s32 func_80023D58(M2C_UNK);                         /* extern */
extern s32 D_8014AB30;
extern s32 D_8014AB3C;
extern s32 D_8014AB44;

void func_80065C20(void) {
    func_80023A74(0x34, 0x2CE);
    func_80023A98(0xF4, 0x2D1, 0);
    func_80023A98(0xF5, 0x2D6, 0);
    func_80023A98(0xF6, 0x2D9, 0);
    func_80023A98(0xF7, 0x2D2, 0);
    func_80023A98(0xF8, 0x2D5, 0);
    func_80023A98(0xF9, 0x2CF, 0);
    func_80023A98(0xFA, 0x2D4, 0);
    func_80023A98(0xFD, 0x2D8, 0);
    func_80023A98(0xFE, 0x2D7, 0);
    func_80023A98(0x22, 0x69E, 1);
    func_80023A74(0x65, 0x3F0);
    func_80023A98(0xFF, 0x3EF, 0);
    D_8014AB3C = func_80023D58(0x198);
    D_8014AB44 = func_80023D58(0x199);
    D_8014AB30 = func_80023D58(0x1DF);
}
