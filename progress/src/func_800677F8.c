/* machine draft (m2c) for sn-n64-281 -G8 -mips2 -O2, tried by autopilot */
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

s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8002DA80();                            /* extern */
extern f32 D_80008D24;

void func_800677F8(void *arg0) {
    f32 temp_fv1;

    func_8002DA80();
    M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + D_80008D24);
    temp_fv1 = M2C_FIELD(arg0, f32 *, 4) + (f32) func_80024394(-5, 5);
    M2C_FIELD(arg0, s32 *, 0x5C) = (s32) (M2C_FIELD(arg0, s32 *, 0x5C) - 8);
    M2C_FIELD(arg0, f32 *, 4) = temp_fv1;
    if (M2C_FIELD(arg0, s32 *, 0x90) != 0) {
        M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) + 5);
    }
    if (M2C_FIELD(arg0, s32 *, 0x5C) < 4) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
