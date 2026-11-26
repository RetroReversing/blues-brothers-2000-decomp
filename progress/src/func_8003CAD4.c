/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

extern M2C_UNK D_801401F0;
extern s32 D_801401FC;

void func_8003CAD4(void *arg0, s32 arg1) {
    M2C_FIELD(&D_801401F0, s32 *, 0) = (s32) M2C_FIELD(arg0, f32 *, 4);
    M2C_FIELD(&D_801401F0, s32 *, 4) = (s32) M2C_FIELD(arg0, f32 *, 8);
    {
        D_801401FC = arg1;
        M2C_FIELD(&D_801401F0, s32 *, 8) = (s32) M2C_FIELD(arg0, f32 *, 0xC);
    }
}
