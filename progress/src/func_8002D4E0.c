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

s16 coss(u16);                                      /* extern */
s16 sins(u16);                                      /* extern */

void func_8002D4E0(void *arg0, s32 arg1) {
    s16 temp_s0;
    s16 temp_s0_2;

    temp_s0 = sins(M2C_FIELD(arg0, u16 *, 0x12));
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) ((s32) (((s32) (arg1 * temp_s0) >> 0xF) * coss(M2C_FIELD(arg0, u16 *, 0x16))) >> 0xF);
    temp_s0_2 = coss(M2C_FIELD(arg0, u16 *, 0x12));
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) ((s32) (((s32) (arg1 * temp_s0_2) >> 0xF) * coss(M2C_FIELD(arg0, u16 *, 0x16))) >> 0xF);
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) ((s32) (arg1 * sins(M2C_FIELD(arg0, u16 *, 0x16))) >> 0xF);
}
