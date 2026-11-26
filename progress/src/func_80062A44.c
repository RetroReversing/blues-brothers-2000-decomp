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

M2C_UNK func_8000C458();                            /* extern */
M2C_UNK func_80023620(M2C_UNK);                     /* extern */
M2C_UNK func_8002369C(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80023C58(M2C_UNK);                     /* extern */
M2C_UNK func_80023C64(M2C_UNK);                     /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */

void func_80062A44(void) {
    func_80023620(1);
    func_8002369C(0x100, 0x1031);
    func_8000C458();
    func_80023C64(0x10F);
    func_80023C58(0);
    func_8002A360(0x1D, 0);
}
