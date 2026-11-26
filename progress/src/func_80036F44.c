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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 updateCameraView();
s32 func_80034FEC();
s32 func_80036FB8();
extern f32 D_8000147C;
extern void *gCameraTarget;

void func_80036F44(s32 arg0) {
    s32 sp10[3];

    sp10[0] = (s32) M2C_FIELD(gCameraTarget, f32 *, 4);
    sp10[1] = (s32) (M2C_FIELD(gCameraTarget, f32 *, 8) + D_8000147C);
    sp10[2] = (s32) M2C_FIELD(gCameraTarget, f32 *, 0xC);
    { func_80034FEC(arg0, sp10); }
    { updateCameraView(arg0); }
    func_80036FB8(arg0, 0xF);
}
