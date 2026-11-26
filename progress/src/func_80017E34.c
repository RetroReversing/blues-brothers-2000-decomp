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

M2C_UNK func_8001FF64();                            /* extern */
s32 func_8002D5CC(void *);                          /* extern */
M2C_UNK func_80036FB8(void *, M2C_UNK);             /* extern */
extern s32 D_800BCFB0;
extern s32 D_800BCFFC;
extern s32 D_800BD05C;
extern s32 D_800BD068;
extern void *D_800BD06C;
extern f32 D_800BD070;
extern f32 D_800BD074;
extern f32 D_800BD078;

void func_80017E34(void *arg0) {
    func_8001FF64();
    func_80036FB8(arg0, 0xF);
    if (func_8002D5CC(arg0) != 0) {
        M2C_FIELD(arg0, s32 *, 0x9C) = (s32) D_800BCFB0;
        M2C_FIELD(arg0, f32 *, 4) = (f32) D_800BD070;
        M2C_FIELD(arg0, f32 *, 8) = (f32) D_800BD074;
        M2C_FIELD(arg0, f32 *, 0xC) = (f32) D_800BD078;
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) D_800BD05C;
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) D_800BD068;
        M2C_FIELD(D_800BD06C, s32 *, 0x9C) = (s32) D_800BCFFC;
    }
}
