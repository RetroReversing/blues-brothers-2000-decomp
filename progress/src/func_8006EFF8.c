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

s32 func_8002D5CC(void *);                          /* extern */
M2C_UNK func_8006D8E0(s32);                         /* extern */
M2C_UNK func_8006DDD4(void *);                      /* extern */
M2C_UNK func_8006F944();                            /* extern */
extern void *D_800B3960;
extern s32 D_80107040;
extern M2C_UNK func_80023848;
extern M2C_UNK func_800768E8;

void func_8006EFF8(void *arg0) {
    if (M2C_FIELD(D_800B3960, s32 *, 0x74) == 0) {
        M2C_FIELD(D_800B3960, s32 *, 0x74) = 1;
        return;
    }
    func_8006D8E0(arg0 + 0x70);
    M2C_FIELD(arg0, s32 *, 0x68) = 5;
    if (func_8002D5CC(arg0) != 0) {
        if (D_80107040 & 0x4000) {
            M2C_FIELD(D_800B3960, s32 *, 0x74) = 0;
            func_8006F944();
            M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
            return;
        }
        if (D_80107040 & 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x90) = 0x1010;
            func_8006DDD4(arg0);
            M2C_FIELD(arg0, s32 *, 0x64) = 0x64;
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_800768E8;
            M2C_FIELD(arg0, M2C_UNK **, 0xD8) = &func_80023848;
        }
    }
}
