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

s32 func_80070EE0(s32, s32 *, s32);
s32 func_80070F38(s32, s32 *);
s32 func_8009CD60();                                /* extern */
s32 func_8009CEB0(void);                             /* extern */
s32 osRecvMesg(s32, s32 *, s32);            /* extern */

void func_80071220(s32 arg0, void *arg1) {
    s32 sp10[2];
    s32 sp18;
    s32 temp_s0;
    s32 temp_s1;

    do {
    temp_s1 = *(s32 *)((s8 *)arg1 + 0xC);
    temp_s0 = arg0 + 0x11C;
    sp18 = 0;
    } while (0);
loop_1:
    if (func_8009CD60() != temp_s1) {
        if (func_8009CEB0() != temp_s1) {
            return;
        }
    }
    func_80070EE0(arg0, sp10, temp_s0);
    osRecvMesg(temp_s0, &sp18, 1);
    func_80070F38(arg0, sp10);
    goto loop_1;
}

