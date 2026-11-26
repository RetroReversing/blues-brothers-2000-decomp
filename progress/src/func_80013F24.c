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

s32 collectCollisionCells(f32 *, f32 *, s32);
s32 func_80048C8C(f32 *, s32);
extern f32 D_80148D14;

void func_80013F24(void *arg0) {
    f32 sp10[3];

    sp10[0] = *(f32 *)((s8 *)arg0 + 4);
    sp10[1] = *(f32 *)((s8 *)arg0 + 8);
    sp10[2] = *(f32 *)((s8 *)arg0 + 0xC);
    collectCollisionCells(sp10, sp10, 0);
    if (func_80048C8C(sp10, 1) != 0) {
        *(f32 *)((s8 *)arg0 + 8) = D_80148D14;
    }
}
