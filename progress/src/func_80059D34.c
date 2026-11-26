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

s32 actorSetAnim();
extern f32 D_8000851C;
extern s32 func_800393F4;

void func_80059D34(void *arg0) {
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) D_8000851C;
    actorSetAnim(arg0, 0x10, 0x100);
    M2C_FIELD(arg0, s32 *, 0x94) = 0x7D0;
    M2C_FIELD(arg0, s32 **, 0x9C) = &func_800393F4;
}
