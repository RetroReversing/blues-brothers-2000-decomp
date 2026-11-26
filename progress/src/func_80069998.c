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

void *func_80023874(M2C_UNK, M2C_UNK);              /* extern */
f32 func_8002D340(f32, f32, f32);                   /* extern */
M2C_UNK func_800899DC(M2C_UNK *);                   /* extern */
extern M2C_UNK D_80008E3C;
extern f32 D_80008E54;
extern void *D_800B3964;

void func_80069998(void *arg0) {
    f32 temp_fs0;
    void *temp_v0;

    temp_v0 = func_80023874(0x127, 0);
    if (temp_v0 == NULL) {
        func_800899DC(&D_80008E3C);
    }
    M2C_FIELD(D_800B3964, s32 *, 0x74) = 1;
    M2C_FIELD(arg0, f32 *, 0xC) = func_8002D340(M2C_FIELD(temp_v0, f32 *, 0xC), M2C_FIELD(arg0, f32 *, 0xC), 350.0f);
    temp_fs0 = 50.0f;
    M2C_FIELD(arg0, f32 *, 8) = func_8002D340(M2C_FIELD(temp_v0, f32 *, 8), M2C_FIELD(arg0, f32 *, 8), temp_fs0);
    M2C_FIELD(arg0, f32 *, 4) = func_8002D340(M2C_FIELD(temp_v0, f32 *, 4), M2C_FIELD(arg0, f32 *, 4), temp_fs0);
    M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF;
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) - 3);
    if (M2C_FIELD(arg0, f32 *, 0xC) == M2C_FIELD(temp_v0, f32 *, 0xC)) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        M2C_FIELD(temp_v0, s32 *, 0x8C) = 1;
        M2C_FIELD(D_800B3964, s32 *, 0x74) = 0;
    }
}

