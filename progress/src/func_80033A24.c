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

s32 func_80023E18(s32);                             /* extern */
M2C_UNK func_80027038(M2C_UNK);                     /* extern */
M2C_UNK func_8002710C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800294D0(s32);                         /* extern */

void func_80033A24(void *arg0) {
    func_80027038(1);
    func_800294D0(func_80023E18(M2C_FIELD(arg0, s32 *, 0x84)));
    func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
}
