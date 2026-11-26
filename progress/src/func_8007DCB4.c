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

M2C_UNK func_8001C508(void *);                      /* extern */
void *func_800551F8(M2C_UNK);                       /* extern */
extern f32 D_800095E4;
extern f32 D_800095E8;
extern f32 D_800095EC;

void func_8007DCB4(void *arg0) {
    void *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        temp_v0 = func_800551F8(0);
        M2C_FIELD(temp_v0, f32 *, 4) = (f32) D_800095E4;
        M2C_FIELD(temp_v0, f32 *, 8) = (f32) D_800095E8;
        M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) D_800095EC;
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
    }
    func_8001C508(arg0);
}
