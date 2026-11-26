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
extern f32 D_80000A28;
extern void *D_800BD06C;

void func_800174F0(void *arg0) {
    f32 temp_fs0;
    f32 temp_fs1;

    temp_fs1 = 100.0f;
    temp_fs0 = M2C_FIELD(arg0, f32 *, 0xC) - M2C_FIELD(D_800BD06C, f32 *, 0xC);
    if ((func_8002DD60(M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(D_800BD06C, f32 *, 4)) < temp_fs1) && (func_8002DD60(temp_fs0) < temp_fs1)) {
        M2C_FIELD(D_800BD06C, f32 *, 4) = (f32) M2C_FIELD(D_800BD06C, f32 *, 0x40);
        M2C_FIELD(D_800BD06C, f32 *, 0xC) = (f32) M2C_FIELD(D_800BD06C, f32 *, 0x48);
    }
    M2C_FIELD(arg0, s32 *, 0x68) = -1;
}
