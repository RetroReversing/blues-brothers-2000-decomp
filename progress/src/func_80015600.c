/* adapted from similar verified C in func_80015738 in BLUES BROTHERS 2000 (matched), with its names changed by decompdecomp */
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

s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
void *spawnEffectObj(M2C_UNK, s32, s32, s32);        /* extern */
void *func_800239E0();                              /* extern */
s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
s32 func_8002D1A0();                                /* extern */
M2C_UNK func_8002D4E0(void *, s32);                 /* extern */
M2C_UNK syncActorPrevPos(void *);                      /* extern */
extern s32 D_800BD170;
void func_80015518(void);
void func_8002F8D0(void);

void *func_80015600(void *arg0) {
    void *p;

    p = func_800239E0();
    if (p != NULL) {
        return p;
    }
    {
        p = spawnEffectObj(1, (s32) M2C_FIELD(arg0, f32 *, 4), (s32) M2C_FIELD(arg0, f32 *, 8), (s32) M2C_FIELD(arg0, f32 *, 0xC));
        M2C_FIELD(p, s32 *, 0x64) = 0xC8;
        M2C_FIELD(p, void **, 0x98) = func_8002F8D0;
        M2C_FIELD(p, s32 *, 0x60) = (s32) D_800BD170;
        M2C_FIELD(p, s32 *, 0x70) = randomRange(0xA, 0x32);
        M2C_FIELD(p, s32 *, 0x74) = 0;
        M2C_FIELD(p, s32 *, 0x78) = 0xFFFFFF;
        M2C_FIELD(p, s32 *, 0x7C) = 1;
        M2C_FIELD(p, s32 *, 0x58) = packDrawFlags(0, 1, 4, 3, 0, 0, 1, 0);
        M2C_FIELD(p, s32 *, 0x68) = 0xE;
        M2C_FIELD(p, s32 *, 0x5C) = 0xFF;
        M2C_FIELD(p, s32 *, 0x64) = 0xC8;
        M2C_FIELD(p, void **, 0x9C) = func_80015518;
        M2C_FIELD(p, s32 *, 0x10) = func_8002D1A0();
        M2C_FIELD(p, s32 *, 0x14) = randomRange(0x1000, 0x4000);
        func_8002D4E0(p, randomRange(0x3E8, 0x7D0));
        syncActorPrevPos(p);
        M2C_FIELD(p, s32 *, 0x80) = 0;
    }
    return p;
}

