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

s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
s32 func_80023D58(M2C_UNK);                         /* extern */
M2C_UNK func_8004F9D0(void *, s32);                 /* extern */
extern f32 D_80009194;
extern M2C_UNK func_800741F8;

void func_800743F8(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x58) = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0);
        M2C_FIELD(arg0, s32 *, 0x5C) = 0x40;
        M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_800741F8;
        M2C_FIELD(arg0, s32 *, 0x60) = func_80023D58(0x1FB);
        M2C_FIELD(arg0, s32 *, 0) = 0x123;
    }
    func_8004F9D0(arg0, M2C_FIELD(arg0, s32 *, 0x70));
    M2C_FIELD(arg0, f32 *, 8) = (f32) D_80009194;
}
