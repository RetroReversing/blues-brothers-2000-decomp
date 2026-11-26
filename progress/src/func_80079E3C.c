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

void *func_80017C54(void *, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_80023D58(M2C_UNK);                         /* extern */
s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */

void func_80079E3C(void *arg0) {
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_s3;
    void *temp_v0;

    temp_s3 = randomRange(0, 0xFFFF);
    temp_s2 = randomRange(0x2000, 0x3E80);
    temp_s0 = func_80023D58(0x1E5);
    temp_v0 = func_80017C54(arg0, temp_s0, temp_s3, temp_s2, 0x190, 0, randomRange(0x80, 0x400));
    M2C_FIELD(temp_v0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
    { M2C_FIELD(temp_v0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8); }
    M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x70) = 0x14;
}
