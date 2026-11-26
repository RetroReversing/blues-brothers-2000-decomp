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

void func_80025280(void *arg0);                         /* extern */
extern void *D_800B3964;
extern s32 D_800B83B4;

s32 func_8006DA0C(void *arg0) {
    s32 temp_a0;

    if (M2C_FIELD(arg0, s32 *, 0xBC) == M2C_FIELD(D_800B3964, s32 *, 0xBC)) {
        if (M2C_FIELD(arg0, s32 *, 0x68) >= 0) {
            goto __shared_return_0;
        }
        M2C_FIELD(arg0, s32 *, 0x68) = 4;
        __shared_return_0:
    return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x68) == -1) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0xC4);
        if (temp_a0 != 0) {
            func_80025280(temp_a0);
            M2C_FIELD(arg0, s32 *, 0xC4) = 0;
        }
        D_800B83B4 += 1;
    }
    M2C_FIELD(arg0, s32 *, 0x68) = -1;
    return 1;
}
