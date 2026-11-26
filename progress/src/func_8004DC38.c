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

f32 func_8004BC74();
s32 func_8004D54C();
s32 func_800899DC();
extern char D_80007E00[];

void func_8004DC38(s32 arg0, void *arg1) {
    f32 temp_fv0;

    func_8004D54C();
    temp_fv0 = func_8004BC74(arg1);
    if ((f64) temp_fv0 == 0.0) {
        func_800899DC(D_80007E00);
    }
    M2C_FIELD(arg1, f32 *, 0) = (f32) (M2C_FIELD(arg1, f32 *, 0) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 4) = (f32) (M2C_FIELD(arg1, f32 *, 4) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 8) = (f32) (M2C_FIELD(arg1, f32 *, 8) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0xC) = (f32) (M2C_FIELD(arg1, f32 *, 0xC) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x10) = (f32) (M2C_FIELD(arg1, f32 *, 0x10) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x14) = (f32) (M2C_FIELD(arg1, f32 *, 0x14) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x18) = (f32) (M2C_FIELD(arg1, f32 *, 0x18) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x1C) = (f32) (M2C_FIELD(arg1, f32 *, 0x1C) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x20) = (f32) (M2C_FIELD(arg1, f32 *, 0x20) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x24) = (f32) (M2C_FIELD(arg1, f32 *, 0x24) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x28) = (f32) (M2C_FIELD(arg1, f32 *, 0x28) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x2C) = (f32) (M2C_FIELD(arg1, f32 *, 0x2C) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x30) = (f32) (M2C_FIELD(arg1, f32 *, 0x30) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x34) = (f32) (M2C_FIELD(arg1, f32 *, 0x34) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x38) = (f32) (M2C_FIELD(arg1, f32 *, 0x38) / temp_fv0);
    M2C_FIELD(arg1, f32 *, 0x3C) = (f32) (M2C_FIELD(arg1, f32 *, 0x3C) / temp_fv0);
}
