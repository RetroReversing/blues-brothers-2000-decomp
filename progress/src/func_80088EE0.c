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

M2C_UNK func_800233C8();                            /* extern */
M2C_UNK func_800234F4();                            /* extern */
M2C_UNK func_80025D34();                            /* extern */
M2C_UNK func_8002CE84(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80088F60();                            /* extern */
M2C_UNK func_8008A064();                            /* extern */
extern s32 D_800B9C7C;

void func_80088EE0(void) {
    func_80025D34();
loop_1:
    func_800234F4();
    if (D_800B9C7C != 0) {
        D_800B9C7C = 0;
        goto loop_1;
    }
    func_800233C8();
    func_80088F60();
    func_8008A064();
    func_8002CE84(6, 0);
}
