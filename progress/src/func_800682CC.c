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

s32 func_80023D58(M2C_UNK);                         /* extern */
M2C_UNK func_80069F00(M2C_UNK);                     /* extern */
extern s32 D_8014AB38;
extern M2C_UNK D_8014AB48;
extern M2C_UNK D_8014AB70;

void func_800682CC(void) {
    M2C_FIELD(&D_8014AB70, s32 *, 0) = 0x196;
    M2C_FIELD(&D_8014AB70, s32 *, 4) = 0x19F;
    M2C_FIELD(&D_8014AB70, s32 *, 8) = 0x1A3;
    M2C_FIELD(&D_8014AB70, s32 *, 0xC) = 0x1A4;
    M2C_FIELD(&D_8014AB70, s32 *, 0x10) = 0x1A5;
    M2C_FIELD(&D_8014AB70, s32 *, 0x14) = 0x1A6;
    M2C_FIELD(&D_8014AB70, s32 *, 0x18) = 0x1A7;
    M2C_FIELD(&D_8014AB48, s32 *, 0) = func_80023D58(0x1A1);
    M2C_FIELD(&D_8014AB48, s32 *, 4) = func_80023D58(0x1A2);
    M2C_FIELD(&D_8014AB48, s32 *, 8) = func_80023D58(0x1B1);
    M2C_FIELD(&D_8014AB48, s32 *, 0xC) = func_80023D58(0x1A0);
    D_8014AB38 = func_80023D58(0x20C);
    func_80069F00(0);
}
