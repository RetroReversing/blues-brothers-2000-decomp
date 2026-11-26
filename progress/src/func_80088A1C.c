/* adapted from similar verified C in func_8008896C in BLUES BROTHERS 2000 (matched), with its names changed by decompdecomp */
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

s32 tickActorTimer(void *);                          /* extern */
M2C_UNK func_8002E7B8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80082494(void *);                      /* extern */
M2C_UNK func_800888E0(M2C_UNK);                     /* extern */
extern s32 D_800B4988;
extern s32 D_800B5DD4;
extern s32 gFrameScale;

void func_80088A1C(void *arg0) {
    s32 temp_v1;
    s32 temp_v0;
    s32 temp_a0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x70);
    temp_a0 = gFrameScale;
    do { D_800B5DD4 = 0; } while (0);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x74);
    temp_v1 = temp_v1 - temp_a0;
    temp_v0 = temp_v0 - temp_a0;
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v1;
    M2C_FIELD(arg0, s32 *, 0x74) = temp_v0;
    if (temp_v1 <= 0) {
        func_800888E0(3);
        M2C_FIELD(arg0, s32 *, 0x70) = 0xF4240;
    }
    if (M2C_FIELD(arg0, s32 *, 0x74) <= 0) {
        func_800888E0(4);
        M2C_FIELD(arg0, s32 *, 0x74) = 0xF4240;
    }
    D_800B4988 = 0x1E;
    if (tickActorTimer(arg0) != 0) {
        func_8002E7B8(1, 0);
        func_80082494(arg0);
    }
}
