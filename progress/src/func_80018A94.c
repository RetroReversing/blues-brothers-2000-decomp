/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

s32 func_8001B990(M2C_UNK, s32);                    /* extern */
s32 func_800221C0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
s32 func_80023E3C(s32);                             /* extern */
M2C_UNK func_8002D604(void *);                      /* extern */
f32 func_8002DD60(f32);                             /* extern */
extern f32 D_80000A98;
extern f32 D_80000A9C;
extern s32 D_800A9540;
extern void *D_800BD06C;

void func_80018A94(void *arg0) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;

    if (func_8001B990(0x100, M2C_FIELD(arg0, s32 *, 0x70)) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
    M2C_FIELD(arg0, s32 *, 0xB8) = 0xA2;
    M2C_FIELD(arg0, s32 *, 0xE4) = func_80023E3C(0xA2);
    M2C_FIELD(arg0, s32 *, 0x58) = func_800221C0(1, 1, 0, 3, 0, 1, 1, 0);
    func_8002D604(arg0);
    temp_fs1 = M2C_FIELD(arg0, f32 *, 0xC) - M2C_FIELD(D_800BD06C, f32 *, 0xC);
    temp_fs2 = 180.0f;
    temp_fs0 = M2C_FIELD(arg0, f32 *, 8) - M2C_FIELD(D_800BD06C, f32 *, 8);
    if ((func_8002DD60(M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(D_800BD06C, f32 *, 4)) < temp_fs2) && (func_8002DD60(temp_fs0) < 360.0f) && (func_8002DD60(temp_fs1) < temp_fs2)) {
        M2C_FIELD(D_800BD06C, s32 *, 0xF0) = 0xFF;
        D_800A9540 += 1;
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
        func_8001B990(0x200, M2C_FIELD(arg0, s32 *, 0x70));
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
