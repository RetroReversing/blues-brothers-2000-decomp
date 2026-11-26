
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

s32 func_80034F50();
s32 func_80081990(void *, s32, f32);            /* extern */
s32 func_80081AC0(s32 *, s32, f32);         /* extern */
extern f64 D_80009980;
extern f32 D_80009988;
extern char D_8014A928[];

void func_80083870(void *arg0) {
    char sp10[0x10];
    f32 temp_ft0;
    f32 temp_fv0;

    temp_ft0 = (f32) ((f64) M2C_FIELD(arg0, f32 *, 0xB4) + D_80009980);
    M2C_FIELD(arg0, f32 *, 0xB4) = temp_ft0;
    temp_fv0 = (f32) *(s32 *)((M2C_FIELD(arg0, s32 *, 0x70) * 4) + D_8014A928) - 1.0f;
    if (temp_fv0 <= temp_ft0) {
        M2C_FIELD(arg0, f32 *, 0xB4) = (f32) (temp_ft0 - temp_fv0);
    }
    func_80081990(arg0 + 4, M2C_FIELD(arg0, s32 *, 0x70), M2C_FIELD(arg0, f32 *, 0xB4));
    func_80081AC0(sp10, M2C_FIELD(arg0, s32 *, 0x70), M2C_FIELD(arg0, f32 *, 0xB4));
    func_80034F50(arg0);
}

