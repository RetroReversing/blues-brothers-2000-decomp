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

s16 *func_800851D8(void *);                         /* extern */
extern M2C_UNK func_80080460;

void func_80080518(void *arg0, void *arg1) {
    s16 *temp_v0;
    f32 temp_f;

    temp_v0 = func_800851D8(arg1);
    M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(arg1, f32 *, 4);
    do { M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg1, f32 *, 8) + (f32) *temp_v0); } while (0);
    temp_f = (f32) M2C_FIELD(arg1, f32 *, 0xC);
    M2C_FIELD(arg0, s32 *, 0x64) = 0x19;
    M2C_FIELD(arg0, s32 *, 0x80) = 0x14;
    M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80080460;
    M2C_FIELD(arg0, void **, 0xA4) = arg1;
    M2C_FIELD(arg0, f32 *, 0xC) = temp_f;
}
