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
typedef struct { u32 w0; u32 w1; } Gfx;
s32 func_8001EF80();
s32 func_8001F0AC();
s32 func_8001F230();
s32 func_80022C2C();
s32 func_8002338C();
s32 func_80027060();
s32 setRenderState();
s32 func_8002DAE0(s32 *, s32 *, f32);
s32 func_8002DB6C(s32 *, s32 *, f32);
s32 func_8002DBF8(s32 *, s32 *, f32);
s32 mtxIdentity3();
f32 func_8002DD60(f32);
s32 func_800479B0();
f32 sinApprox(f32);
extern u8 D_800A9554[];
extern s32 D_800AB408;
extern s32 gCamSpeedScale;
extern s32 D_800BD114;
extern s32 D_800F7910[];
extern s32 D_800F90A0[];
extern Gfx *D_80177E18;

typedef struct Act {
    char pad0[0x10];
    s32 f10;
    s32 f14;
    s32 f18;
    char pad1C[0xC];
    f32 f28;
    f32 f2C;
    f32 f30;
    char pad34[0x40];
    s32 f74;
    char pad78[0x1C];
    s32 f94;
    char pad98[0x20];
    s32 fB8;
    char padBC[0x28];
    s32 fE4;
    s32 fE8;
    char padEC[4];
    s32 fF0;
    char padF4[4];
    s32 fF8;
} Act;

s32 func_8001F5A4(Act *self) {
    s32 sp10[10];
    s32 sp38[10];
    u8 *c;
    s32 r, g, b;
    s32 ok;
    u8 *base;
    s32 v94;
    f32 t;
    f32 a, bb, cc;

    base = D_800A9554;
    v94 = self->f94;
    c = base + self->f74 * 3;
    r = c[0];
    g = c[1];
    b = c[2];
    self->fF8 &= ~4;
    if (D_800AB408 == 0) {
        ok = func_8001EF80(self, v94);
    } else {
        ok = func_8001F0AC(self, 0x12C0);
    }
    if (ok == 0) {
        return 0;
    }
    t = (f32) D_800F7910[self->fB8];
    t /= sinApprox(0.9250245f);
    t += self->f30;
    if (t < 0.0f) {
        return 0;
    }
    if (func_8002DD60(self->f28) > 2.0f * t) {
        return 0;
    }
    if (t < func_8002DD60(self->f2C)) {
        return 0;
    }
    func_8001F230(self);
    func_80027060(r, g, b, 0xFF);
    {
        Gfx *g1 = D_80177E18++;
        g1->w1 = -0x805;
        g1->w0 = 0xFC11FE23;
    }
    self->fF0 = self->fF0 - gCamSpeedScale * 8;
    if (self->fF0 <= 0) {
        self->fF0 = 0;
    }
    a = (f32) self->f10;
    a *= 0.00009587379760742188;
    bb = (f32) self->f14;
    bb *= 0.00009587379760742188;
    cc = (f32) self->f18;
    cc *= 0.00009587379760742188;
    mtxIdentity3(sp10);
    func_8002DB6C(sp38, sp10, a);
    func_8002DAE0(sp10, sp38, bb);
    func_8002DBF8(sp38, sp10, cc);
    func_80022C2C(self, sp38, 1);
    if (self->fE8 != 0) {
        func_800479B0(self->fE8);
    }
    {
        Gfx *g2 = D_80177E18++;
        g2->w0 = 0xDE000000;
        g2->w1 = self->fE4;
    }
    {
        Gfx *g3 = D_80177E18++;
        g3->w0 = 0xE7000000;
        g3->w1 = 0;
    }
    setRenderState(-1);
    D_800BD114 += D_800F90A0[self->fB8];
    if (self->fF8 & 1) {
        func_8002338C(self);
    }
    self->fF8 |= 4;
    return 1;
}
