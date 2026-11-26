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

typedef struct B8F5D8E { s32 a; s32 b; } B8F5D8E;
typedef struct B8F5D8S { u8 pad0[0x10]; s32 f10; u8 pad14[4]; B8F5D8E e[1]; } B8F5D8S;
typedef struct B8F5D8 { u8 pad0[4]; s32 f4; u8 pad8[0x3C]; s32 f44; s32 f48; u8 pad4C[0x2C]; B8F5D8S *f78; s32 f7C; s32 f80; u8 pad84[0x1A]; s16 f9E; u8 padA0[6]; s16 fA6; u8 padA8[8]; s16 fB0; } B8F5D8;
extern s32 D_8017B220;
void func_8008F2A8();

s32 func_8008F5D8(B8F5D8 *arg0, B8F5D8S *arg1, s32 arg2, s16 arg3, s32 arg4, s32 arg5) {
    s32 t;
    s32 v;

    func_8008F2A8();
    arg0->fA6 = arg2;
    arg0->f78 = arg1;
    arg0->f9E = arg3;
    arg0->fB0 = arg4;
    arg0->f44 = D_8017B220;
    arg0->f48 = arg5;
    t = arg1->f10;
    D_8017B220++;
    if (t != 0) {
        arg0->f7C = t;
    }
    v = arg1->e[arg2].a;
    arg0->f80 = v;
    arg0->f4 = v;
    return arg0->f44;
}
