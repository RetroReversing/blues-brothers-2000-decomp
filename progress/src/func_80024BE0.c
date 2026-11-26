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

M2C_UNK func_80024D5C(s32, M2C_UNK, s32 *);         /* extern */
s32 func_80025014(M2C_UNK);                         /* extern */
s32 func_80025038(M2C_UNK);                         /* extern */

void func_80024BE0(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 sp10[9];
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = func_80025038(arg2);
    temp_v0 = func_80025014(arg2);
    sp10[0] = temp_s0;
    sp10[1] = -temp_v0;
    sp10[2] = 0;
    sp10[3] = temp_v0;
    sp10[4] = temp_s0;
    sp10[5] = 0;
    sp10[6] = 0;
    sp10[7] = 0;
    sp10[8] = 0x7FFF;
    func_80024D5C(arg0, arg1, sp10);
}
