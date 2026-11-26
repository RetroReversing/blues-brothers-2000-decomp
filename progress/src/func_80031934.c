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

s32 func_80023D58(M2C_UNK);                         /* extern */
s32 getImageAsset(s32);                             /* extern */
M2C_UNK setTextColor(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800271A8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK drawImage(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK drawCenteredMessage(M2C_UNK);                     /* extern */

void func_80031934(void *arg0) {
    setTextColor(0xFF, 0xFF, 0xFF, M2C_FIELD(arg0, s32 *, 0x6C));
    drawImage(getImageAsset(func_80023D58(0x1F0)), 0x60, 0x14, 0);
    func_800271A8(0xA0, 0xB);
    drawCenteredMessage(0x3D);
    func_800271A8(0xA0, 0xC);
    drawCenteredMessage(0x3E);
    func_800271A8(0xA0, 0xD);
    drawCenteredMessage(0x3F);
    func_800271A8(0xA0, 0xF);
    drawCenteredMessage(0x40);
}
