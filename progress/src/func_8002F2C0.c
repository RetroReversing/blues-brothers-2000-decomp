s32 func_8001EAD0(void);
void func_8001EB18(s32);
s32 func_8001EF80(void *, s32);
void func_8001F230(void *);
void buildObjectMatrix(void *, f32 *, s32);
s32 *getImageAsset(s32);
void func_80024A3C(f32 *, f32 *, s32);
void func_80024B58(f32 *, f32 *, s32);
void func_80024BE0(f32 *, f32 *, s32);
void func_80024FE8(f32 *);
void loadTextureClamped(s32, s32 *, s32, s32);
void debugPrintf(char *);

typedef struct GfxW {
    u32 w0;
    u32 w1;
} GfxW;

typedef struct Vtx {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx;

typedef struct Obj {
    char pad0[0x10];
    s32 x10;
    s32 x14;
    s32 x18;
    char pad1C[0x30 - 0x1C];
    f32 x30;
    char pad34[0x5C - 0x34];
    s32 x5C;
    s32 x60;
    char pad64[0x70 - 0x64];
    s32 x70;
    s32 x74;
    s32 x78;
    s32 x7C;
} Obj;

extern char D_80001230[];
extern Vtx D_800BD6C8[];
extern u8 D_80177E18[];
#define GP (*(GfxW **)D_80177E18)

s32 func_8002F2C0(Obj *arg0) {
    f32 m1[10];
    f32 m2[10];
    s32 pad[4];
    s32 s[4];
    s32 t[4];
    s32 col;
    s32 r;
    s32 a;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 *p;
    s32 *q;
    s32 fmt;
    s32 n;
    s32 start;
    Vtx *v0;
    Vtx *v1;
    Vtx *v2;
    Vtx *v3;

    c2 = arg0->x78;
    r = arg0->x70;
    a = arg0->x5C;
    c1 = c2 >> 8;
    c0 = c2 & 0xFF;
    c2 >>= 16;
    c1 &= 0xFF;
    c2 &= 0xFF;
    if (func_8001EF80(arg0, 100000) == 0) {
        return 0;
    }
    if (arg0->x30 < (f32)-arg0->x70) {
        return 0;
    }
    func_8001F230(arg0);
    {
        GfxW *_g = GP++;
        _g->w0 = 0xE200001C;
        _g->w1 = 0x504340;
    }
    p = getImageAsset(arg0->x60);
    q = p;
    if (arg0->x74 == 0) {
        p += 4;
    }
    s[0] = 0;
    t[0] = 0;
    s[1] = 0x7C0;
    t[1] = 0;
    s[2] = 0x7C0;
    t[2] = 0x7C0;
    s[3] = 0;
    t[3] = 0x7C0;
    fmt = 0x10;
    if (arg0->x74 == 0 && q[2] == 0x20) {
        fmt = 0x20;
    }
    loadTextureClamped(fmt, p, 0, 0);
    if (arg0->x7C == 0) {
        func_80024FE8(m1);
        func_80024B58(m2, m1, arg0->x10);
        func_80024A3C(m1, m2, arg0->x14);
        func_80024BE0(m2, m1, arg0->x18);
        buildObjectMatrix(arg0, m2, 1);
    } else {
        func_80024FE8(m1);
        buildObjectMatrix(arg0, m1, 0);
    }
    start = n = func_8001EAD0();
    if (n == -1) {
        debugPrintf(D_80001230);
        return 1;
    }
    v0 = &D_800BD6C8[n++];
    v1 = &D_800BD6C8[n++];
    v2 = &D_800BD6C8[n++];
    v3 = &D_800BD6C8[n++];
    v0->ob[0] = -r;
    v0->ob[1] = -r;
    v0->ob[2] = 0;
    v0->cn[0] = c0;
    v0->cn[1] = c1;
    v0->cn[2] = c2;
    v0->cn[3] = a;
    v0->tc[0] = s[0];
    v0->tc[1] = t[0];
    v1->ob[0] = r;
    v1->ob[1] = -r;
    v1->ob[2] = 0;
    v1->cn[0] = c0;
    v1->cn[1] = c1;
    v1->cn[2] = c2;
    v1->cn[3] = a;
    v1->tc[0] = s[1];
    v1->tc[1] = t[1];
    v2->ob[0] = r;
    v2->ob[1] = r;
    v2->ob[2] = 0;
    v2->cn[0] = c0;
    v2->cn[1] = c1;
    v2->cn[2] = c2;
    v2->cn[3] = a;
    v2->tc[0] = s[2];
    v2->tc[1] = t[2];
    v3->ob[0] = -r;
    v3->ob[1] = r;
    v3->ob[2] = 0;
    v3->cn[0] = c0;
    v3->cn[1] = c1;
    v3->cn[2] = c2;
    v3->cn[3] = a;
    v3->tc[0] = s[3];
    v3->tc[1] = t[3];
    {
        GfxW *_g = GP++;
        _g->w0 = 0x01004008;
        _g->w1 = (u32)&D_800BD6C8[n - 4];
    }
    {
        GfxW *_g = GP++;
        _g->w0 = 0x07000204;
        _g->w1 = 0x406;
    }
    {
        GfxW *_g = GP++;
        _g->w0 = 0x07000604;
        _g->w1 = 0x402;
    }
    func_8001EB18(n - start);
    return 1;
}
