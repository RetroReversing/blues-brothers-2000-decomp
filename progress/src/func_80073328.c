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
M2C_UNK setTextColor(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK drawImage(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s32 D_800AB9B4;

s32 func_80073328(void *arg0) {
    if (D_800AB9B4 != 0) {
        return 0;
    }
    setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    drawImage(getImageAsset(M2C_FIELD(arg0, s32 *, 0x60)), 0x90, 0x68, 0);
    return 1;
}
