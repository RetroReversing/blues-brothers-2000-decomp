/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 randomRange(s32, s32);                /* extern */
s32 animStepKeys(void *);                          /* extern */
s32 func_80043328(void *, s32, s32);    /* extern */
extern f32 D_80008EC4;
void func_8006ABD8(void *);

void func_8006AD48(void *arg0) {
    s32 var_a1;
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x8C) = randomRange(1, 4);
        M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) - D_80008EC4);
    }
    temp_v0 = animStepKeys(arg0);
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v0;
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s32 *, 0x8C) = (s32) (M2C_FIELD(arg0, s32 *, 0x8C) - 1);
    }
    if (M2C_FIELD(arg0, s32 *, 0x8C) == 0) {
        if (M2C_FIELD(arg0, s32 *, 0xD0) == 0x1A4) {
            func_80043328(arg0, 0x1A5, 0x100);
        } else {
            func_80043328(arg0, 0x1A4, 0x100);
        }
        M2C_FIELD(arg0, s32 *, 0x8C) = randomRange(1, 4);
    }
    if (M2C_FIELD(arg0, s32 *, 0xC0) != 0) {
        M2C_FIELD(arg0, void **, 0x9C) = func_8006ABD8;
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
    }
}

