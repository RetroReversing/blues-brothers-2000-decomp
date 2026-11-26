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

M2C_UNK __rmonStopUserThreads(M2C_UNK);             /* extern */
M2C_UNK osInvalICache(s32 *, M2C_UNK);              /* extern */
M2C_UNK osWritebackDCache(s32 *, M2C_UNK);          /* extern */
M2C_UNK rmonFindFaultedThreads();                   /* extern */
extern s32 *D_80180FB0;
extern s32 D_80180FB4;
extern s32 *D_80181030;
extern s32 D_80181034;

void __rmonHitBreak(void) {
    u32 inst;

    if (D_80180FB0 != NULL) {
        inst = *D_80180FB0;
        if ((inst & 0xFC00003F) == 0xD) {
            *D_80180FB0 = D_80180FB4;
            osWritebackDCache(D_80180FB0, 4);
            osInvalICache(D_80180FB0, 4);
        }
        D_80180FB0 = NULL;
    }
    if (D_80181030 != NULL) {
        inst = *D_80181030;
        if ((inst & 0xFC00003F) == 0xD) {
            *D_80181030 = D_80181034;
            osWritebackDCache(D_80181030, 4);
            osInvalICache(D_80181030, 4);
        }
        D_80181030 = NULL;
    }
    __rmonStopUserThreads(0);
    rmonFindFaultedThreads();
}
