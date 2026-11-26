/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_FIELD_PTR(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s16 coss(s32);                                      /* extern */
s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
void syncActorPrevPos(void *);                            /* extern */
extern void *D_800B3964;
extern s32 gTextWaveTime;
extern M2C_UNK func_80016F64;

void func_80016FC8(void *arg0) {
    f32 temp_fv0;

    if (M2C_FIELD_PTR(arg0, const s32 *, 0xC0) == 0) {
        M2C_FIELD(arg0, f32 *, 8) = -150.0f;
        syncActorPrevPos(arg0);
        M2C_FIELD(arg0, s32 *, 0xC0) = 1;
        M2C_FIELD(arg0, s32 *, 0x84) = randomRange(0x64, 0x96);
    }
    temp_fv0 = (f32) ((s32) (coss((gTextWaveTime * M2C_FIELD(arg0, const s32 *, 0x84)) & 0xFFFF) * 0xF) >> 0xD) + M2C_FIELD(arg0, const f32 *, 0x44);
    M2C_FIELD(arg0, s32 *, 0) = 0x105;
    M2C_FIELD(arg0, f32 *, 8) = temp_fv0;
    if (M2C_FIELD(D_800B3964, const s32 *, 0x7C) == 5) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80016F64;
    }
}
