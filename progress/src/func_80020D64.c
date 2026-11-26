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

s16 coss(s32);                                      /* extern */
M2C_UNK func_80020B3C(void *);                      /* extern */
M2C_UNK func_8003B828(s32, M2C_UNK);                /* extern */
extern s32 D_800B9EA4;
extern s32 D_800BD06C;

void func_80020D64(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC0) == 2) {
        func_8003B828(D_800BD06C, 0);
    }
    M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 0x44) + (f32) ((s32) (coss(((M2C_FIELD(arg0, s32 *, 0x8C) + D_800B9EA4) * 0xB4) & 0xFFFC) * 0x4B) >> 0xE));
    func_80020B3C(arg0);
}
