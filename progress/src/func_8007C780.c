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

M2C_UNK func_80023C58(s32);                         /* extern */
s32 func_80023D58(M2C_UNK);                         /* extern */
extern s32 D_800AE010;
extern M2C_UNK D_801700F0;
extern M2C_UNK D_801700F8;
extern s32 D_80170100;

void func_8007C780(void) {
    s32 temp_s1;

    temp_s1 = D_800AE010;
    func_80023C58(0x122);
    M2C_FIELD(&D_801700F0, s32 *, 0) = func_80023D58(0x1F1);
    M2C_FIELD(&D_801700F0, s32 *, 4) = func_80023D58(0x1F2);
    D_80170100 = func_80023D58(0x20E);
    M2C_FIELD(&D_801700F8, s32 *, 0) = func_80023D58(0xD40);
    M2C_FIELD(&D_801700F8, s32 *, 4) = func_80023D58(0xD3F);
    func_80023C58(temp_s1);
}
