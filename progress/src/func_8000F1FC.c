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

M2C_UNK func_80027038(M2C_UNK);                     /* extern */
M2C_UNK func_800270DC(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK setTextPos(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002E6E4();                            /* extern */
M2C_UNK drawCenteredMessage(M2C_UNK);                     /* extern */

void func_8000F1FC(void *arg0) {
    func_8002E6E4();
    M2C_FIELD(arg0, s32 *, 0x68) = 0xF;
    func_80027038(0);
    func_800270DC(0xFF, 0xFF, 0xFF, 0xFF);
    setTextPos(0xA0, 0x3C);
    drawCenteredMessage(0x35);
    setTextPos(0xA0, 0x4B);
    drawCenteredMessage(0x36);
    setTextPos(0xA0, 0x5F);
    drawCenteredMessage(0xD);
    setTextPos(0xA0, 0x73);
    drawCenteredMessage(0xE);
}
