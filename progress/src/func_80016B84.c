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

s32 func_800134F0();
s32 func_80013550();
s32 func_8002D620();
s32 func_8004F9D0();
s16 sins();
extern u16 D_800B9EA6;
extern char D_800F4A00[];

void func_80016B84(void *arg0) {
    char *__base_D_800F4A00;
    s32 temp_a1;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0) = 0x10E;
        __base_D_800F4A00 = D_800F4A00;
        M2C_FIELD(((M2C_FIELD(arg0, s32 *, 0xB8) * 0xC) + __base_D_800F4A00), s32 *, 4) = 0x32;
    }
    temp_a1 = M2C_FIELD(arg0, s32 *, 0x70);
    if (temp_a1 != 0) {
        func_8004F9D0(arg0, temp_a1);
    }
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) (M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(arg0, f32 *, 0x40));
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) - M2C_FIELD(arg0, f32 *, 0x48));
    func_8002D620(arg0);
    M2C_FIELD(arg0, f32 *, 8) += (f32) ((s32) (sins(D_800B9EA6) * 0x19) >> 0xD);
    func_800134F0(arg0);
    func_80013550(arg0);
}
