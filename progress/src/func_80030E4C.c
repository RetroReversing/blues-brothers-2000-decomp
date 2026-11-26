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

M2C_UNK func_80023C58(M2C_UNK);                     /* extern */
s32 func_80023D58(M2C_UNK);                         /* extern */
M2C_UNK func_80027030(M2C_UNK);                     /* extern */
M2C_UNK func_80030C40(void *, M2C_UNK);             /* extern */
extern s32 D_800B28C0;

void func_80030E4C(void *arg0) {
    func_80023C58(0x10C);
    M2C_FIELD(arg0, s32 *, 0x60) = func_80023D58(0x207);
    M2C_FIELD(arg0, s32 *, 0x84) = func_80023D58(0x9E7);
    func_80027030(1);
    func_80030C40(arg0, 1);
    D_800B28C0 = 1;
}
