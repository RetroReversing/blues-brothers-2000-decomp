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
extern s32 D_800BD07C;
extern M2C_UNK D_800BD168;
extern s32 D_800BD1E4;
extern M2C_UNK D_8013FF78;
extern s32 D_8013FF98;
extern s32 D_8013FF9C;

void func_80032D5C(void) {
    D_8013FF98 = func_80023D58(0xD8F);
    M2C_FIELD(&D_8013FF78, s32 *, 0) = func_80023D58(0xD88);
    M2C_FIELD(&D_8013FF78, s32 *, 4) = func_80023D58(0xD89);
    M2C_FIELD(&D_8013FF78, s32 *, 8) = func_80023D58(0xD8A);
    M2C_FIELD(&D_8013FF78, s32 *, 0xC) = func_80023D58(0xD8B);
    M2C_FIELD(&D_8013FF78, s32 *, 0x10) = func_80023D58(0xD8C);
    M2C_FIELD(&D_8013FF78, s32 *, 0x14) = func_80023D58(0xD8D);
    M2C_FIELD(&D_8013FF78, s32 *, 0x18) = func_80023D58(0xD8E);
    M2C_FIELD(&D_800BD168, s32 *, 0) = func_80023D58(0x1BB);
    M2C_FIELD(&D_800BD168, s32 *, 4) = func_80023D58(0x1C5);
    D_8013FF9C = func_80023D58(0xD84);
    D_800BD1E4 = func_80023D58(0x1EA);
    D_800BD07C = func_80023D58(0x1BF);
}
