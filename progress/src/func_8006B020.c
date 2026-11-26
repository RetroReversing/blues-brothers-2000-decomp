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

s32 func_8000C43C();                                /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
void *func_80076BF0(s32);                           /* extern */
M2C_UNK func_800852CC(void *, s32);                 /* extern */
extern M2C_UNK D_8014AA4D;
extern M2C_UNK func_8006AEE4;
extern M2C_UNK func_8006AF74;

void *func_8006B020(s32 arg0) {
    void *temp_v0;

    if (func_8000C43C() != 5) {
        return func_80076BF0(arg0);
    }
    func_80050460(&func_8006AEE4, &D_8014AA4D);
    temp_v0 = func_80042F00(0x2F, 0, 0, 0);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x1004;
    func_800852CC(temp_v0, arg0);
    if (arg0 != 0) {
        func_80043328(temp_v0, 0xB3, 0x100);
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8006AF74;
    }
    return temp_v0;
}
