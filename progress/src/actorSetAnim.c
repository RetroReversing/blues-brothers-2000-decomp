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

s32 func_80023B2C(s32);                             /* extern */
M2C_UNK func_8003EAB4(void *, s32);                 /* extern */

void actorSetAnim(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    void *temp_s0;

    temp_v0 = func_80023B2C(arg1);
    temp_s0 = M2C_FIELD(arg0, void **, 0xE0);
    M2C_FIELD(arg0, s32 *, 0xD0) = arg1;
    if (temp_s0 != NULL) {
        do { func_8003EAB4(temp_s0, temp_v0); } while (0);
        M2C_FIELD(arg0, s32 *, 0xD4) = arg2;
        M2C_FIELD(arg0, s32 *, 0xD0) = arg1;
        M2C_FIELD(arg0, f32 *, 0xDC) = (f32) M2C_FIELD(temp_s0, const f32 *, 0x1C);
    }
}
