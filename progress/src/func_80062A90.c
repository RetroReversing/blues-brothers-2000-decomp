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
M2C_UNK sendCommand(M2C_UNK, M2C_UNK);
M2C_UNK func_8004BDCC();
M2C_UNK func_8004C004();
M2C_UNK func_8004DE9C();
f32 sqrtf(f32);
extern s32 gCameraRig;

typedef struct Part {
    char pad0[4];
    f32 x;
    f32 y;
    f32 z;
} Part;

typedef struct Cam {
    char pad0[0xC];
    Part *p0C;
    Part *p10;
    char pad14[0x1C];
    u8 m30[0x40];
    u8 m70[0x40];
    u8 mB0[0x40];
    u8 mF0[0x40];
    u8 m130[0x40];
    u8 m170[0x40];
    char pad1B0[0x244];
    s32 f3F4;
    s32 f3F8;
} Cam;
extern Cam *D_800B7FE0;

s32 func_80062A90(void) {
    f32 a[4];
    f32 b[4];
    f32 m[16];
    f32 len_1;
    f32 len_2;

    func_8004C004(D_800B7FE0->mB0, a);
    func_8004C004(D_800B7FE0->mF0, b);
    b[0] = b[0] - a[0];
    b[2] = b[2] - a[2];
    b[1] = b[1] - a[1];
    len_1 = sqrtf(b[0] * b[0] + b[1] * b[1] + b[2] * b[2]);
    b[0] = b[0] / len_1;
    b[1] = b[1] / len_1;
    b[2] = -0.15f;
    b[0] = b[0] * 1000.0;
    b[1] = b[1] * 1000.0;
    b[2] = -150.0f;
    D_800B7FE0->p0C->x = -b[0];
    D_800B7FE0->p0C->y = -b[1];
    D_800B7FE0->p0C->z = -b[2];
    func_8004C004(D_800B7FE0->m130, a);
    func_8004C004(D_800B7FE0->m170, b);
    b[0] = b[0] - a[0];
    b[2] = b[2] - a[2];
    b[1] = b[1] - a[1];
    len_2 = sqrtf(b[0] * b[0] + b[1] * b[1] + b[2] * b[2]);
    b[0] = b[0] / len_2;
    b[1] = b[1] / len_2;
    b[2] = -0.15f;
    b[0] = b[0] * 1000.0;
    b[1] = b[1] * 1000.0;
    b[2] = -150.0f;
    D_800B7FE0->p10->x = -b[0];
    D_800B7FE0->p10->y = -b[1];
    D_800B7FE0->p10->z = -b[2];
    func_8004C004(D_800B7FE0->m30, a);
    func_8004C004(D_800B7FE0->m70, b);
    func_8004BDCC(m, a, b);
    func_8004DE9C(gCameraRig, m);
    D_800B7FE0->f3F8 = D_800B7FE0->f3F8 + 1;
    if (D_800B7FE0->f3F8 >= 0x5E6) {
        sendCommand(0x1D, 0);
        if (D_800B7FE0->f3F4 == 0) {
            D_800B7FE0->f3F4 = 1;
        }
    }
    return D_800B7FE0->f3F4;
}


