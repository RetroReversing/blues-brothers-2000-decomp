s32 func_8001EF80(void *, s32);
s32 func_8001F0AC(void *, s32);
void func_8001F230(void *);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void setDrawMode(s32);
void func_80022C2C(void *, f32 *, s32);
void func_8002338C(void *);
void func_80027060(s32, s32, s32, s32);
void setRenderState(s32);
void func_8002DAE0(f32 *, f32 *, f32);
void func_8002DB6C(f32 *, f32 *, f32);
void func_8002DBF8(f32 *, f32 *, f32);
void mtxIdentity3(f32 *);
f32 func_8002DD60(f32);
void func_800479B0(s32);
f32 sinApprox(f32);

typedef struct GfxW {
    u32 w0;
    u32 w1;
} GfxW;

typedef struct Obj {
    char pad0[0x10];
    s32 x10;
    s32 x14;
    s32 x18;
    char pad1C[0x28 - 0x1C];
    f32 x28;
    f32 x2C;
    f32 x30;
    char pad34[0x58 - 0x34];
    s32 x58;
    s32 x5C;
    char pad60[0x68 - 0x60];
    s32 x68;
    char pad6C[0x94 - 0x6C];
    s32 x94;
    char pad98[0xB8 - 0x98];
    s32 xB8;
    char padBC[0xE4 - 0xBC];
    u32 xE4;
    s32 xE8;
    char padEC[0xF0 - 0xEC];
    s32 xF0;
    char padF4[0xF8 - 0xF4];
    s32 xF8;
} Obj;

extern f32 D_80000E50;
extern f64 D_80000E58;
extern s32 D_800AB408[];
extern s32 gCamSpeedScale[];
extern u8 D_800BD114[];
extern s32 D_800F7910[];
extern s32 gObjTriCounts[];
extern u8 D_80177E18[];
#define GP (*(GfxW **)D_80177E18)

s32 drawActorModel(Obj *arg0) {
    f32 m1[10];
    f32 m2[10];
    f32 f;
    f32 rx;
    f32 ry;
    f32 rz;
    s32 ok;
    s32 t;
    s32 v;

    arg0->xF8 &= ~4;
    v = arg0->x94;
    if (D_800AB408[0] == 0) {
        ok = func_8001EF80(arg0, v);
    } else {
        ok = func_8001F0AC(arg0, 0x12C0);
    }
    if (ok == 0) {
        return 0;
    }
    f = D_800F7910[arg0->xB8];
    f /= sinApprox(D_80000E50);
    f += arg0->x30;
    if (f < 0.0f) {
        return 0;
    }
    if (func_8002DD60(arg0->x28) > f + f) {
        return 0;
    }
    if (f < func_8002DD60(arg0->x2C)) {
        return 0;
    }
    func_8001F230(arg0);
    if (arg0->x5C != 0xFF) {
        s32 a;
        s32 c;
        a = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0);
        c = arg0->x5C;
        arg0->x68 = 13;
        setDrawMode(a);
        func_80027060(0xFF, 0xFF, 0xFF, c);
        {
            GfxW *_g = GP++;
            _g->w0 = 0xFCFFFFFF;
            _g->w1 = 0xFFFCF67B;
        }
    } else if (arg0->xF0 != 0) {
        arg0->x68 = 3;
        setDrawMode(arg0->x58);
        func_80027060(0xFF, 0xFF, 0xFF, arg0->xF0);
        {
            GfxW *_g = GP++;
            _g->w0 = 0xFC35426A;
            _g->w1 = 0x1184FE7F;
        }
    }
    t = arg0->xF0 - gCamSpeedScale[0] * 8;
    arg0->xF0 = t;
    if (t <= 0) {
        arg0->xF0 = 0;
    }
    rx = arg0->x10;
    rx *= D_80000E58;
    ry = arg0->x14;
    ry *= D_80000E58;
    rz = arg0->x18;
    rz *= D_80000E58;
    mtxIdentity3(m1);
    func_8002DB6C(m2, m1, rx);
    func_8002DAE0(m1, m2, ry);
    func_8002DBF8(m2, m1, rz);
    func_80022C2C(arg0, m2, 1);
    if (arg0->xE8 != 0) {
        func_800479B0(arg0->xE8);
    }
    {
        GfxW *_g = GP++;
        _g->w0 = 0xDE000000;
        _g->w1 = arg0->xE4;
    }
    {
        GfxW *_g = GP++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    setRenderState(-1);
    *(s32 *)D_800BD114 += gObjTriCounts[arg0->xB8];
    if (arg0->xF8 & 1) {
        func_8002338C(arg0);
    }
    arg0->xF8 |= 4;
    return 1;
}
