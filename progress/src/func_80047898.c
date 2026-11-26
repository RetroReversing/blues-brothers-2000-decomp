/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

void *heapAlloc(M2C_UNK);                       /* extern */
M2C_UNK func_800477F0(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80047824(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80047864(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern f32 D_80007B70;

s32 func_80047898(void) {
    void *temp_v0;

    temp_v0 = heapAlloc(0x108);
    M2C_FIELD(temp_v0, s16 *, 0) = 2;
    M2C_FIELD(temp_v0, s16 *, 2) = 7;
    M2C_FIELD(temp_v0, s16 *, 4) = 0;
    M2C_FIELD(temp_v0, s16 *, 6) = 0;
    func_800477F0(temp_v0, 0x41, 0x41, 0x41);
    func_80047824(temp_v0, 0, 0xC8, 0xC8, 0xC8);
    func_80047864(temp_v0, 0, 0x78, 0, -0x78);
    func_80047824(temp_v0, 1, 0, 0, 0);
    func_80047864(temp_v0, 1, 0, -0x64, 0);
    M2C_FIELD(temp_v0, f32 *, 0xF8) = (f32) D_80007B70;
    M2C_FIELD(temp_v0, f32 *, 0xFC) = (f32) D_80007B70;
    M2C_FIELD(temp_v0, f32 *, 0x100) = (f32) D_80007B70;
    return (s32) temp_v0;
}
