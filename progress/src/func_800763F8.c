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

M2C_UNK func_80023A74(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80023A98(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_800242A8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern s32 D_800B83B0;

void func_800763F8(void *arg0) {
    func_80023A74(0x48, 0x449);
    func_80023A98(0x14B, 0x44A, 1);
    func_800242A8(D_800B83B0 + 0x1D6, 0x44B, 0x10);
    M2C_FIELD(arg0, s32 *, 0xBC) = (s32) D_800B83B0;
    D_800B83B0 += 1;
}
