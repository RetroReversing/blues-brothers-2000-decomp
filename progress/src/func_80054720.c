/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_BITS_F32(expr) (m2c_bits = (u32)(expr), *(f32 *)&m2c_bits)
extern u32 m2c_bits;
#define M2C_PTR_FROM_F32(type, expr) ((type)(m2c_fbits = (expr), *(u32 *)&m2c_fbits))
extern f32 m2c_fbits;
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

M2C_UNK func_80023A74(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80023A98(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
s32 func_80023D58(M2C_UNK);                         /* extern */
extern s32 D_8014AB3C;
extern s32 D_8014AB44;

void func_80054720(void) {
    func_80023A74(0xE, 0x480);
    func_80023A98(0x45, 0x47C, 0);
    func_80023A98(0x46, 0x47D, 0);
    func_80023A98(0x47, 0x47D, 0);
    func_80023A98(0x48, 0x47E, 0);
    func_80023A98(0x49, 0x47F, 0);
    D_8014AB3C = func_80023D58(0x198);
    D_8014AB44 = func_80023D58(0x199);
}
