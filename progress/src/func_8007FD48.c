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
extern void *D_800B3960;
extern void *D_800B3964;
extern M2C_UNK func_80073328;
extern M2C_UNK func_8007F990;

void func_8007FD48(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_80073328;
        M2C_FIELD(arg0, s32 *, 0x60) = func_80023D58(0x211);
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x80) = 0;
        M2C_FIELD(arg0, s32 *, 0x84) = 0;
    }
    M2C_FIELD(arg0, s32 *, 0x68) = -1;
    if ((M2C_FIELD(D_800B3960, s32 *, 0x9C) == &func_8007F990) && (M2C_FIELD(D_800B3964, s32 *, 0x8C) != 0) && ((M2C_FIELD(arg0, s32 *, 0x80) != 0) || (M2C_FIELD(arg0, s32 *, 0x84) != 0))) {
        M2C_FIELD(arg0, s32 *, 0x68) = 0xD;
    }
}
