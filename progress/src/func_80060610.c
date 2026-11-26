/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 func_8002492C(f32, f32);                        /* extern */
s32 func_8002DA80(void *);                      /* extern */
f32 func_8002DD60(f32);                             /* extern */
s32 updateBlockerEnemy(void *);                      /* extern */
s32 func_80060214(void *);                      /* extern */
s32 updateDistanceCull();                                /* extern */

void func_80060610(void *arg0) {
    s32 x0;
    s32 x1;
    s32 z0;
    s32 z1;
    s32 flag;

    x0 = M2C_FIELD(arg0, f32 *, 0x40) - 100.0f;
    x1 = M2C_FIELD(arg0, f32 *, 0x40) + 100.0f;
    z0 = M2C_FIELD(arg0, f32 *, 0x48) - 500.0f;
    z1 = M2C_FIELD(arg0, f32 *, 0x48) + 500.0f;
    if (updateDistanceCull() == 0) {
        func_80060214(arg0);
        if (M2C_FIELD(arg0, s32 *, 0x80) == 0) {
            func_8002DA80(arg0);
            flag = 0;
            if (M2C_FIELD(arg0, f32 *, 4) < x0) {
                M2C_FIELD(arg0, f32 *, 0x4C) = func_8002DD60(M2C_FIELD(arg0, f32 *, 0x4C));
                flag = 1;
            }
            if (x1 < M2C_FIELD(arg0, f32 *, 4)) {
                M2C_FIELD(arg0, f32 *, 0x4C) = -func_8002DD60(M2C_FIELD(arg0, f32 *, 0x4C));
                flag = 1;
            }
            if (M2C_FIELD(arg0, f32 *, 0xC) < z0) {
                M2C_FIELD(arg0, f32 *, 0x54) = func_8002DD60(M2C_FIELD(arg0, f32 *, 0x54));
                flag = 1;
            }
            if (z1 < M2C_FIELD(arg0, f32 *, 0xC)) {
                M2C_FIELD(arg0, f32 *, 0x54) = -func_8002DD60(M2C_FIELD(arg0, f32 *, 0x54));
                flag = 1;
            }
            if (flag != 0) {
                M2C_FIELD(arg0, s32 *, 0x10) = func_8002492C(M2C_FIELD(arg0, f32 *, 0x4C), M2C_FIELD(arg0, f32 *, 0x54));
            }
            updateBlockerEnemy(arg0);
        }
    }
}
