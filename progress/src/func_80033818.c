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

s32 getImageAsset(s32);                             /* extern */
M2C_UNK func_80027038(M2C_UNK);                     /* extern */
M2C_UNK setTextColor(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80027158(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_800294D0(s32);                         /* extern */
M2C_UNK setSlotTextColor(void *, M2C_UNK);             /* extern */
M2C_UNK drawCenteredMessage(M2C_UNK);                     /* extern */
M2C_UNK func_80081E1C(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_80033818(void *arg0) {
    func_80027038(1);
    func_800294D0(getImageAsset(M2C_FIELD(arg0, s32 *, 0x84)));
    setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    func_80081E1C(M2C_FIELD(arg0, s32 *, 0x60), 0xA0, 0x14, 2);
    func_80027158(0xA0, 0x3C);
    drawCenteredMessage(0x50);
    drawCenteredMessage(0x82);
    drawCenteredMessage(0x83);
    drawCenteredMessage(0x84);
    drawCenteredMessage(0x85);
    drawCenteredMessage(0x86);
    setSlotTextColor(arg0, 0);
    drawCenteredMessage(0x28);
    setSlotTextColor(arg0, 1);
    drawCenteredMessage(0x2F);
    setSlotTextColor(arg0, 2);
    drawCenteredMessage(0x29);
}
