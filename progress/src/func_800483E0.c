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

f32 sinApprox(f32);                             /* extern */
s32 guRandom();                                     /* extern */
extern f32 D_80007BF8;
extern f64 D_80007C00;
extern f64 D_80007C08;
extern f64 D_80007C10;
extern f64 D_80007C18;
extern f64 D_80007C20;
extern f64 D_80007C28;
extern f64 D_80007C30;
extern f32 D_800B9EC4;

void func_800483E0(void *arg0) {
    f32 temp_fa0;
    f64 var_fv0;
    s32 temp_v1;
    void *temp_s0;

    do { temp_s0 = M2C_FIELD(arg0, void **, 0xE8); } while (0);
    M2C_FIELD(temp_s0, f32 *, 4) = 1.0f;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x84);
    switch (temp_v1) {                              /* irregular */
    case 1:
        temp_fa0 = (f32) ((f64) M2C_FIELD(temp_s0, f32 *, 0) + ((D_80007C08 / (D_80007C00 / (f64) D_800B9EC4)) * D_80007C10));
        M2C_FIELD(temp_s0, f32 *, 0) = temp_fa0;
        var_fv0 = ((f64) sinApprox(temp_fa0) * D_80007C18) + D_80007C18;

        M2C_FIELD(temp_s0, f32 *, 4) = (f32) var_fv0;
        return;
    case 2:
        var_fv0 = ((((f64) (f32) (guRandom() % 100)) / D_80007C20) * D_80007C28) + D_80007C30;
        {
M2C_FIELD(temp_s0, f32 *, 4) = (f32) var_fv0;
return;
}
    }
}

