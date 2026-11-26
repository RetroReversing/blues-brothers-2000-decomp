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

M2C_UNK func_8002ADFC(M2C_UNK, M2C_UNK, void *);    /* extern */
M2C_UNK func_80043248(void *);                      /* extern */
extern f32 D_800095F4;
extern f32 D_800095F8;

void func_8007E030(void *arg0) {
    f32 temp_fv1;

    if (M2C_FIELD(arg0, s32 *, 0x78) == 3) {
        temp_fv1 = M2C_FIELD(arg0, f32 *, 0xDC);
        if ((D_800095F4 <= temp_fv1) && (temp_fv1 < D_800095F8)) {
            func_8002ADFC(0xCB, 0x1770, arg0);
        }
    }
    func_80043248(M2C_FIELD(arg0, void **, 0xA8));
    func_80043248(arg0);
}
