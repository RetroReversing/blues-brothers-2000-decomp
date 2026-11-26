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

s32 func_800252D8();                                /* extern */
M2C_UNK func_8002710C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002713C(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_800271D8(s32);                         /* extern */
extern void *D_800B3964;
extern s32 D_800B9ECC;

s32 func_8007001C(void) {
    volatile u64 scratch[2];
    s32 temp_v0;
    s32 var_a0;

    func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
    func_8002713C(0x14, 0x14);
    temp_v0 = func_800252D8();
    var_a0 = temp_v0 + 0x200;
    if (var_a0 < 0) {
        var_a0 = temp_v0 + 0x5FF;
    }
    func_800271D8(var_a0 >> 0xA);
    func_8002713C(0x14, 0x23);
    func_800271D8(0x3C / (s32) D_800B9ECC);
    func_8002713C(0x14, 0x32);
    func_800271D8(M2C_FIELD(D_800B3964, s32 *, 0x84));
    return 0;
}
