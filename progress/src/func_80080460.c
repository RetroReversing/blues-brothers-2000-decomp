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


s32 func_8002D5CC(void *);
extern void *D_800B3960;
#define F(o,t) M2C_FIELD(arg0, t *, o)

void func_80080460(void *arg0) {
    void *temp_v0;
    s32 t, u, a, b;

    temp_v0 = F(0xA4, void*);
    if (temp_v0 != NULL) {
        F(4,f32) = M2C_FIELD(temp_v0, f32 *, 4);
        F(0xC,f32) = M2C_FIELD(temp_v0, f32 *, 0xC);
    }
    F(0x10,s32) = M2C_FIELD(D_800B3960, s32 *, 0x10);
    if (func_8002D5CC(arg0) != 0) {
        do { a = F(0x7C,s32); t = F(0x80,s32); } while (0);
        F(0x7C,s32) = a + 1;
        u = F(0x80,s32);
        u -= 5;
        b = F(0x74,s32);
        F(0x64,s32) = t;
        F(0x80,s32) = u;
        F(0x74,s32) = b ^ 1;
    }
    if (F(0x74,s32) != 0) {
        F(0x68,s32) = -1;
    } else {
        F(0x68,s32) = 7;
    }

    if (F(0x7C,s32) >= 6) {
        (*(void (**)(void *))((s8 *)arg0 + 0xA0))(arg0);
    }
}
