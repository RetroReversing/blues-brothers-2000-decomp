/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
void *spawnEffectObj(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void *func_800239E0();                              /* extern */
s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK syncActorPrevPos(void *);                      /* extern */
extern s32 D_800BD1E0;
extern M2C_UNK drawImageSprite;
extern M2C_UNK func_80085528;

void *func_80085650(void *arg0) {
    void *var_s0;

    var_s0 = func_800239E0();
    if (var_s0 != NULL) {
        return var_s0;
    }
    {
        var_s0 = spawnEffectObj(1, 0, 0, 0);
        M2C_FIELD(var_s0, M2C_UNK **, 0x98) = &drawImageSprite;
        M2C_FIELD(var_s0, s32 *, 0x60) = (s32) D_800BD1E0;
        M2C_FIELD(var_s0, M2C_UNK **, 0x9C) = &func_80085528;
        M2C_FIELD(var_s0, s32 *, 0x70) = randomRange(8, 0x1E);
        M2C_FIELD(var_s0, s32 *, 0x7C) = 1;
        M2C_FIELD(var_s0, s32 *, 0x74) = 0;
        M2C_FIELD(var_s0, s32 *, 0x78) = 0xFFFFFF;
        M2C_FIELD(var_s0, s32 *, 0x58) = packDrawFlags(0, 1, 1, 3, 0, 0, 2, 0);
        M2C_FIELD(var_s0, s32 *, 0x68) = 0xD;
        M2C_FIELD(var_s0, s32 *, 0x5C) = randomRange(0x60, 0x80);
        if (arg0 != NULL) {
            M2C_FIELD(var_s0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
            M2C_FIELD(var_s0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
            M2C_FIELD(var_s0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
            syncActorPrevPos(var_s0);
        }
    }
    return var_s0;
}
