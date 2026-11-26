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
void *func_80042F00(M2C_UNK, s32, s32, s32);        /* extern */
M2C_UNK func_800433A8(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_800B8300;
extern M2C_UNK func_8006E4B8;

void *func_8006E7B0(void *arg0) {
    void *temp_v0;

    func_80023A74(0x30, 0x2B6);
    do { func_80023A98(0xBA, 0x2BD, 0); } while (0);
    temp_v0 = func_80042F00(0x30, (s32) M2C_FIELD(arg0, f32 *, 4), (s32) M2C_FIELD(arg0, f32 *, 8), (s32) M2C_FIELD(arg0, f32 *, 0xC));
    func_800433A8(temp_v0, 0xBA, 0x100);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8006E4B8;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x70) = &D_800B8300;
    return temp_v0;
}
