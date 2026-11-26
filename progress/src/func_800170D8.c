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

M2C_UNK func_80026C28(M2C_UNK *, s32, s32);         /* extern */
s32 func_80026CB4(s32, M2C_UNK *);                  /* extern */
s8 *strchr(M2C_UNK *, M2C_UNK);                     /* extern */
extern M2C_UNK D_800AA46C;
extern M2C_UNK func_80023078;

void func_800170D8(s32 arg0, void *arg1) {
    char sp10[0x40];
    M2C_UNK *var_s0;
    s8 *temp_v0;

    if (M2C_FIELD(arg1, s32 *, 0x9C) == (&func_80023078 + 2)) {
        func_80026C28(sp10, arg0, arg0);
        temp_v0 = strchr(sp10, 0x2E);
        if (temp_v0 != NULL) {
            *temp_v0 = 0;
        }
        var_s0 = &D_800AA46C; loop: if (var_s0[0] != 0) { if (func_80026CB4(var_s0[0], sp10) == 0) { M2C_FIELD(arg1, s32 *, 0x9C) = var_s0[1]; return; } var_s0 += 2; goto loop; }
    }
}
