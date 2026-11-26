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

s16 coss(u16);                                      /* extern */
M2C_UNK func_800134F0(void *);                      /* extern */
M2C_UNK func_80013550(void *);                      /* extern */
s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK syncActorPrevPos(void *);                      /* extern */
M2C_UNK func_8004F9D0(void *, s32);                 /* extern */
s16 sins(u16);                                      /* extern */
extern M2C_UNK gTextWaveTime;

void func_8001AA2C(void *arg0) {
    M2C_UNK *__base_D_800B9EA4;
    s32 k;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    k = 0x10E;
    M2C_FIELD(arg0, s32 *, 0) = k;
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x8C) = randomRange(-0x64, 0);
        M2C_FIELD(arg0, s32 *, 0x90) = randomRange(-0xC8, 0x64);
        k = 0xB94598;
        M2C_FIELD(arg0, s32 *, 0x6C) = k;
    }
    func_8004F9D0(arg0, M2C_FIELD(arg0, s32 *, 0x70));
    __base_D_800B9EA4 = &gTextWaveTime;
    {
        f32 t;
        s32 a;
        s32 r;
        t = (f32) (M2C_FIELD(arg0, f32 *, 8) + (f32) ((s32) (M2C_FIELD(arg0, s32 *, 0x90) * sins(M2C_FIELD(__base_D_800B9EA4, u16 *, 2))) >> 0xF));
        a = M2C_FIELD(__base_D_800B9EA4, u16 *, 2);
        M2C_FIELD(arg0, f32 *, 8) = t;
        r = (s32) ((s32) (coss(a) * 0x4B) >> 0xC);
        a = M2C_FIELD(__base_D_800B9EA4, u16 *, 2);
        M2C_FIELD(arg0, s32 *, 0x14) = r;
        M2C_FIELD(arg0, s32 *, 0x18) = (s32) ((s32) (sins(a) * 0x4B) >> 0xC);
    }
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) (M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(arg0, f32 *, 0x40));
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) - M2C_FIELD(arg0, f32 *, 0x48));
    syncActorPrevPos(arg0);
    func_800134F0(arg0);
    func_80013550(arg0);
}
