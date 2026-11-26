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

void *spawnEffectObj(M2C_UNK, s32, s32, s32);        /* extern */
extern s32 D_800BD100;
extern M2C_UNK func_80023078;
void func_8002B390(void *arg0) {
    void *temp_v0;
    s32 v;

    temp_v0 = spawnEffectObj(0x118, (s32) M2C_FIELD(arg0, f32 *, 4), (s32) M2C_FIELD(arg0, f32 *, 8), (s32) M2C_FIELD(arg0, f32 *, 0xC));
    M2C_FIELD(temp_v0, s32 *, 0x74) = (s32) D_800BD100;
    v = M2C_FIELD(arg0, s32 *, 0x78);
    M2C_FIELD(temp_v0, void **, 0x9C) = (void *) (&func_80023078 + 2);
    M2C_FIELD(temp_v0, s32 *, 0x78) = (s32) (v * 0x64);
}
