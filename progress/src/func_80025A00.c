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

M2C_UNK func_80023BE0(s32, M2C_UNK, s32);           /* extern */
M2C_UNK func_80025280(s32);                         /* extern */
s32 func_800253A0(s32);                             /* extern */
M2C_UNK func_800258E4();                            /* extern */
s32 func_800259F8(s32);                             /* extern */
M2C_UNK func_8002B410(s32, s32, s32);               /* extern */
M2C_UNK func_80090DA0(M2C_UNK, s32 *, s32, s32);    /* extern */
extern s32 D_80106A44;

s32 func_80025A00(s32 arg0, M2C_UNK arg1) {
    s32 sp60;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_3;
    void *temp_v0_2;
    s32 pad[20];

    func_800258E4();
    temp_v0 = func_800259F8(arg0);
    temp_v0_2 = (temp_v0 * 8) + D_80106A44;
    temp_s1 = M2C_FIELD(temp_v0_2, s32 *, 0);
    temp_s2 = M2C_FIELD(temp_v0_2, s32 *, 4);
    temp_s0 = M2C_FIELD(temp_v0_2, s32 *, 8) - temp_s1;
    sp60 = temp_s2;
    temp_v0_3 = func_800253A0(temp_s0);
    func_8002B410(temp_s1, temp_v0_3, temp_s0);
    func_80090DA0(arg1, &sp60, temp_v0_3, temp_s0);
    func_80023BE0(temp_v0, arg1, temp_s2);
    func_80025280(temp_v0_3);
    return temp_s2;
}
