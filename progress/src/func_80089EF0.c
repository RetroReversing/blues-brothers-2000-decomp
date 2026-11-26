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
M2C_UNK func_800162E4();                            /* extern */
M2C_UNK func_800230D8();                            /* extern */
M2C_UNK func_800237D8();                            /* extern */
M2C_UNK func_80023CD4();                            /* extern */
M2C_UNK func_800256A4(s32);                         /* extern */
M2C_UNK func_80089130(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_80089EF0(void) {
    s32 var_s0;

    func_800237D8();
    var_s0 = 0x100;
    func_8000C458();
    func_800230D8();
    func_800162E4();
    func_80023CD4();
    func_800256A4(0x10C);
    do {
        func_800256A4(var_s0);
        var_s0 += 1;
    } while (var_s0 < 0x136);
    func_80089130(0, 0, 0);
}
