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

M2C_UNK sendCommand(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002D124();                            /* extern */

void func_800854C4(s32 *arg0) {
    M2C_UNK var_a1;
    s32 temp_a0;

    temp_a0 = *arg0;
    if (temp_a0 != 0x1006) {
        if (temp_a0 == 0x102B) {
            sendCommand(0xC, 0x80);
            var_a1 = 0xB6;
            sendCommand(8, var_a1);
            func_8002D124();
        }
    } else {
        sendCommand(0xC, 0x80);
        var_a1 = 0xD7;
        sendCommand(8, var_a1);
        func_8002D124();
    }
}
