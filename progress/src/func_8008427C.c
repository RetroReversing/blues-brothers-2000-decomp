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

s32 func_8002D260(s32);                             /* extern */
M2C_UNK func_8002D858(void *, s32 *);               /* extern */
s32 func_8004303C();                                /* extern */
M2C_UNK func_800433A8(void *, s32, M2C_UNK);        /* extern */
extern M2C_UNK func_80083EDC;
extern M2C_UNK func_80084000;

void func_8008427C(void *arg0) {
    s32 sp10;

    if (func_8004303C() != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80084000;
        M2C_FIELD(arg0, M2C_UNK **, 0xD8) = &func_80083EDC;
        M2C_FIELD(arg0, s32 *, 0x78) = 2;
        M2C_FIELD(arg0, s32 *, 0x10) = func_8002D260(M2C_FIELD(arg0, s32 *, 0x10) + 0x8000);
        func_800433A8(arg0, M2C_FIELD(arg0, s32 *, 0x74) + M2C_FIELD(arg0, s32 *, 0x78), 0x100);
        return;
    }
    func_8002D858(arg0, &sp10);
    M2C_FIELD(arg0, s32 *, 0x10) = func_8002D260(sp10 + 0x8000);
}
