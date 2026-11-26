/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

f32 func_8002DD60(f32);                             /* extern */
M2C_UNK func_8002DD8C(void *, M2C_UNK *, f32 *);    /* extern */
extern void *D_800B3960;
extern M2C_UNK D_800CD148;

s32 func_8001EF80(void *arg0, s32 arg1) {
    f32 sp10[3];

    sp10[0] = M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(D_800B3960, f32 *, 4);
    sp10[1] = M2C_FIELD(arg0, f32 *, 8) - M2C_FIELD(D_800B3960, f32 *, 8);
    sp10[2] = M2C_FIELD(arg0, f32 *, 0xC) - M2C_FIELD(D_800B3960, f32 *, 0xC);
    if (func_8002DD60(sp10[0]) > (f32) arg1) {
        return 0;
    }
    if (func_8002DD60(sp10[1]) > (f32) arg1) {
        return 0;
    }
    if (func_8002DD60(sp10[2]) > (f32) arg1) {
        return 0;
    }
    func_8002DD8C((s8 *) arg0 + 0x28, &D_800CD148, sp10);
    if (func_8002DD60(M2C_FIELD(arg0, f32 *, 0x28)) > (f32) arg1) {
        return 0;
    }
    if (func_8002DD60(M2C_FIELD(arg0, f32 *, 0x2C)) > (f32) arg1) {
        return 0;
    }
    if (func_8002DD60(M2C_FIELD(arg0, f32 *, 0x30)) > (f32) arg1) {
        return 0;
    }
    return 1;
}
