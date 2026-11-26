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

M2C_UNK func_800134F0(void *);                      /* extern */
M2C_UNK func_80013550(void *);                      /* extern */
f32 func_8002D340(f32, f32, f32);                   /* extern */
extern f32 D_800007D0;
extern s32 D_800B9ECC;

void func_80013594(void *arg0) {
    f32 var_fa0;

    if (M2C_FIELD(arg0, const s32 *, 0x90) != 0) {
        var_fa0 = M2C_FIELD(arg0, const f32 *, 0x44);
        do { M2C_FIELD(arg0, f32 *, 8) = func_8002D340(var_fa0, M2C_FIELD(arg0, const f32 *, 8), (f32) (D_800B9ECC * 0xA)); } while (0);
    } else {
        var_fa0 = 100.0f;
        do { M2C_FIELD(arg0, f32 *, 8) = func_8002D340(var_fa0, M2C_FIELD(arg0, const f32 *, 8), (f32) (D_800B9ECC * 0xA)); } while (0);
    }
    func_800134F0(arg0);
    func_80013550(arg0);
}
