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

M2C_UNK coss(s32);                                  /* extern */
s32 func_80023E18(s32);                             /* extern */
M2C_UNK func_80025FF8();                            /* extern */
M2C_UNK func_800261D4(M2C_UNK);                     /* extern */
M2C_UNK func_80027038(M2C_UNK);                     /* extern */
M2C_UNK func_8002710C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80027158(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_800294D0(s32);                         /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8003CDA0(M2C_UNK);                     /* extern */
M2C_UNK func_80081E1C(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s32 D_800AE174;
extern s32 D_800AE178;
extern s32 D_800B9EA4;
extern s32 D_801070A0;

void func_80031CA8(void *arg0) {
    coss((D_800B9EA4 * 0x28F) & 0xFFFF);
    func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
    func_80027038(1);
    func_800294D0(func_80023E18(M2C_FIELD(arg0, s32 *, 0x84)));
    func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
    func_80081E1C(M2C_FIELD(arg0, s32 *, 0x60), 0xA0, 0x14, 2);
    func_80027038(1);
    func_80027158(0xA0, 0x3C);
    func_8003CDA0(0x43);
    func_8003CDA0(0x44);
    func_8003CDA0(0x25);
    func_8003CDA0(0x60);
    if (D_801070A0 & 0x1000) {
        M2C_FIELD(arg0, s32 *, 0x94) = 1;
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x9F);
        return;
    }
    D_800AE174 = 0;
    func_800261D4(0);
    D_800AE178 = 0;
    func_80025FF8();
}
