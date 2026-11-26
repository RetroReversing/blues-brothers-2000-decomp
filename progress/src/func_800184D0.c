/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

M2C_UNK func_80015C30(void *);                      /* extern */
s32 func_8002D204(s32, s32, M2C_UNK);               /* extern */
s32 func_8002D260(M2C_UNK);                         /* extern */
s32 func_8002D5CC(void *);                          /* extern */
M2C_UNK func_8002D604(void *);                      /* extern */
M2C_UNK func_8004EB60(void *);                      /* extern */
extern f32 D_80000A7C;
extern f64 D_80000A80;

void func_800184D0(void *arg0) {
    M2C_UNK var_a0;
    s32 temp_ft0;
    s32 temp_v0;
    s32 var_s0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + D_80000A7C);
        M2C_FIELD(arg0, s32 *, 0x84) = func_8002D260(0x1FFF);
    }
    temp_v0 = func_8002D204(M2C_FIELD(arg0, s32 *, 0x84), M2C_FIELD(arg0, s32 *, 0x18), 0x578);
    M2C_FIELD(arg0, s32 *, 0x18) = temp_v0;
    if (temp_v0 == M2C_FIELD(arg0, s32 *, 0x84)) {
        if (M2C_FIELD(arg0, s32 *, 0x84) == func_8002D260(0x1FFF))
        {
          M2C_FIELD(arg0, s32 *, 0x84) = func_8002D260(-0x1FFF);
        }
        else
        {
          M2C_FIELD(arg0, s32 *, 0x84) = func_8002D260(0x1FFF);
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x64) < 0x12C) {
        M2C_FIELD(arg0, s32 *, 0) = 0x101;
    }
    func_8002D604(arg0);
    func_8002D604(arg0);
    func_8002D604(arg0);
    func_8002D604(arg0);
    func_8002D604(arg0);
    temp_ft0 = (s32) (f32) ((f64) M2C_FIELD(arg0, s32 *, 0x64) * D_80000A80);
    M2C_FIELD(arg0, s32 *, 0x34) = temp_ft0;
    M2C_FIELD(arg0, s32 *, 0x38) = temp_ft0;
    M2C_FIELD(arg0, s32 *, 0x3C) = temp_ft0;
    if (func_8002D5CC(arg0) != 0) {
        func_8004EB60(arg0);
        var_s0 = 0;
        do {
            func_80015C30(arg0);
            var_s0 += 1;
        } while (var_s0 < 4);
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
