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

s32 sendCommand(s32, s32);            /* extern */
s32 tickActorTimer(void *);                          /* extern */
s32 strlen(s32);                                    /* extern */
extern s32 gPadPressed;
extern s32 func_8005321C;

s32 func_8005358C(void *arg0, void *arg1) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s1 = (*(s32 *)((s8 *)arg1 + 4));
    temp_s2 = strlen(temp_s1);
    if ((*(s32 *)((s8 *)arg0 + 0x7C)) == 0) {
do {
        (*(s32 *)((s8 *)arg0 + 0x7C)) = 1;
        (*(s32 *)((s8 *)arg0 + 0x68)) = 0xE;
        (*(s32 *)((s8 *)arg0 + 0x64)) = (s32) (temp_s2 * 8);
        (*(s32 *)((s8 *)arg0 + 0x88)) = temp_s1;
        (*(s32 **)((s8 *)arg0 + 0x98)) = &func_8005321C;
} while (0);
}
    if ((*(s32 *)((s8 *)arg0 + 0x80)) != 0) {
        (*(s32 *)((s8 *)arg0 + 0x80)) = 0;
        goto block_10;
    }
    if (tickActorTimer(arg0) != 0) {
        (*(s32 *)((s8 *)arg0 + 0x64)) = -1;
        if (gPadPressed & 0x8000) {
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            return 0;
        }
    }
    if (((*(s32 *)((s8 *)arg0 + 0x64)) < ((temp_s2 * 0xE) - 0x32)) && (gPadPressed & 0x8000)) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xA3);
        (*(s32 *)((s8 *)arg0 + 0x64)) = -1;
        (*(s32 *)((s8 *)arg0 + 0x80)) = 1;
    }
block_10:
    return 1;
}
