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
s32 func_8002D5CC(void *);                          /* extern */
M2C_UNK func_8002D620(void *);                      /* extern */
void *func_8002E374(s32);                           /* extern */
M2C_UNK func_800852CC(void *, void *);              /* extern */
extern M2C_UNK func_8001AA2C;

void func_8001AB70(void *arg0) {
    void *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
        M2C_FIELD(arg0, s32 *, 0) = 0x101;
        if (func_8000C43C() != 0x31) {
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8001AA2C;
        }
    }
    if (func_8002D5CC(arg0) != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x7C) < 5) {
            temp_v0 = func_8002E374(M2C_FIELD(arg0, s32 *, 0xB8));
            func_800852CC(temp_v0, arg0);
            M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8001AA2C;
            func_8002D620(temp_v0);
            M2C_FIELD(arg0, s32 *, 0x64) = 0x3E8;
            M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
            return;
        }
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
