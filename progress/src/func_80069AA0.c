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

s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
s32 tickActorTimer(void *);                          /* extern */
extern M2C_UNK D_8014AB70;

void func_80069AA0(void *arg0) {
    f32 temp_fv0;
    s32 temp_v1;

    M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + (f32) (randomRange(-1, 8) + 0xA));
    M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) + (f32) randomRange(-6, 6));
    if (tickActorTimer(arg0) != 0) {
        M2C_FIELD(arg0, s32 *, 0x64) = randomRange(4, 0xA);
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x8C) + 1;
        M2C_FIELD(arg0, s32 *, 0x8C) = temp_v1;
        if (temp_v1 >= 7) {
            M2C_FIELD(arg0, s32 *, 0x8C) = 0;
            temp_fv0 = M2C_FIELD(arg0, f32 *, 0x40) + (f32) randomRange(-0xA, 0xA);
            M2C_FIELD(arg0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x44);
            M2C_FIELD(arg0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0x48);
            M2C_FIELD(arg0, f32 *, 4) = temp_fv0;
            M2C_FIELD(arg0, s32 *, 0x64) = (s32) (randomRange(-0x14, 0x14) + 0x55);
        }
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) *(s32 *)((s8 *)&D_8014AB70 + M2C_FIELD(arg0, s32 *, 0x8C) * 4);
    }
}
