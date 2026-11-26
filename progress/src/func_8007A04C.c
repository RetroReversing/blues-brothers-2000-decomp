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

s32 func_8001B990();
void *func_80023874();
s32 func_8002ADFC();
f32 func_800385AC();
s32 func_8004303C();
s32 func_800433A8();
s32 func_8004F9D0();
extern f32 D_800093FC;
extern s32 func_80079EF0;

void func_8007A04C(void *arg0) {
    f32 temp_fv0;
    f32 temp_fv1;
    void *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0xD0) != 0x101) {
        func_800433A8(arg0, (void *)0x101, 0xC0);
    }
    func_8004303C(arg0);
    func_8004F9D0(arg0, 6);
    func_8004F9D0(arg0, 6);
    func_8004F9D0(arg0, 6);
    func_8004F9D0(arg0, 6);
    M2C_FIELD(arg0, f32 *, 8) = func_800385AC(arg0);
    temp_v0 = func_80023874(0x137, 0);
    temp_fv1 = M2C_FIELD(temp_v0, f32 *, 4) - M2C_FIELD(arg0, f32 *, 4);
    temp_fv0 = M2C_FIELD(temp_v0, f32 *, 0xC) - M2C_FIELD(arg0, f32 *, 0xC);
    if (((temp_fv1 * temp_fv1) + (temp_fv0 * temp_fv0)) < D_800093FC) {
        func_8002ADFC(0x6C, 0x7D0, arg0);
        M2C_FIELD(arg0, s32 **, 0x9C) = &func_80079EF0;
        func_8001B990(0x200, 0x1E);
        func_800433A8(arg0, 0x102, 0x100);
    }
}
