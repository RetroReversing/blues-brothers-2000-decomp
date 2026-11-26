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

M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
s32 func_8002D5CC(void *);                          /* extern */
M2C_UNK func_8002DA40(void *);                      /* extern */
extern f64 D_80009590;
extern void *D_801700E8;
extern M2C_UNK D_801700F0;

void func_8007C1C8(void *arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0xC0) & 2) {
        { M2C_FIELD(arg0, f32 *, 0x50) = (f32) ((f64) M2C_FIELD(arg0, f32 *, 0x50) * D_80009590); }
        { { M2C_FIELD(arg0, s32 *, 0xC0) = (s32) ((M2C_FIELD(arg0, s32 *, 0xC0) | 4) & ~2); } }
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 2);
    }
    if (M2C_FIELD(arg0, s32 *, 0xC0) & 1) {
        { M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0); }
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 9);
        M2C_FIELD(D_801700E8, s32 *, 0x8C) = (s32) (M2C_FIELD(D_801700E8, s32 *, 0x8C) + 1);
        return;
    }
    if (M2C_FIELD(arg0, f32 *, 8) < (f32) M2C_FIELD(arg0, s32 *, 0x94)) {
        { M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0); }
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x19);
        return;
    }
    { func_8002DA40(arg0); }
    if (func_8002D5CC(arg0) != 0) {
        { M2C_FIELD(arg0, s32 *, 0x64) = 2; }
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x80) ^ 1;
        M2C_FIELD(arg0, s32 *, 0x80) = temp_v0;
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) (&D_801700F0)[temp_v0];
    }
}

