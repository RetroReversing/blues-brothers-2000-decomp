typedef struct { u32 w0, w1; } Gfx;
typedef struct { s16 x, y, z, flag; s16 s, t; u8 r, g, b, a; } Vtx;
typedef struct Obj {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ s32 f18;
    /* 0x1C */ u8 pad1C[0x43];
    /* 0x5F */ u8 alpha;
    /* 0x60 */ s32 f60;
} Obj;
s32 getVertexSlot(void);
s32 bumpVertexCount(s32);
void func_8001F1D0(Obj *);
void func_8001F230(void);
void buildObjectMatrix(Obj *, void *, s32);
s32 getImageAsset(s32);
void func_80024A3C(void *, void *, s32);
void func_80024B58(void *, void *, s32);
void func_80024BE0(void *, void *, s32);
void func_80024FE8(void *);
void setRenderState(s32);
void loadTextureClamped(s32, s32, s32, s32);
extern Vtx spriteVerts[];
extern Gfx *D_80177E18;

s32 func_800741F8(Obj *arg0) {
    u8 unused[16];
    f32 m1[10];
    f32 m2[10];
    f32 *a;
    f32 *b;
    s32 lo;
    s32 hi;
    s32 n;
    s32 i;
    Gfx *g;

    func_8001F230();
    func_8001F1D0(arg0);
    a = m1;
    func_80024FE8(a);
    b = m2;
    func_80024B58(b, a, arg0->f10);
    func_80024A3C(a, b, arg0->f14);
    func_80024BE0(b, a, arg0->f18);
    buildObjectMatrix(arg0, b, 1);
    lo = -350;
    hi = 350;
    if (arg0->f60 != 0) {
        loadTextureClamped(0x20, getImageAsset(arg0->f60) + 0x10, 0, 0);
    }
    n = getVertexSlot();
    spriteVerts[n].x = lo;
    spriteVerts[n].y = 0;
    spriteVerts[n].z = lo;
    spriteVerts[n + 1].x = hi;
    spriteVerts[n + 1].y = 0;
    spriteVerts[n + 1].z = lo;
    spriteVerts[n + 2].x = hi;
    spriteVerts[n + 2].y = 0;
    spriteVerts[n + 2].z = hi;
    spriteVerts[n + 3].x = lo;
    spriteVerts[n + 3].y = 0;
    spriteVerts[n + 3].z = hi;
    spriteVerts[n].s = 0;
    spriteVerts[n].t = 0;
    spriteVerts[n + 1].s = 0x7C0;
    spriteVerts[n + 1].t = 0;
    spriteVerts[n + 2].s = 0x7C0;
    spriteVerts[n + 2].t = 0x7C0;
    spriteVerts[n + 3].s = 0;
    spriteVerts[n + 3].t = 0x7C0;
    for (i = 0; i < 4; i++) {
        spriteVerts[n + i].r = 0xFF;
        spriteVerts[n + i].g = 0xFF;
        spriteVerts[n + i].b = 0xFF;
        spriteVerts[n + i].a = arg0->alpha;
    }
    g = D_80177E18++;
    g->w0 = 0x01004008;
    g->w1 = (u32)&spriteVerts[n];
    g = D_80177E18++;
    g->w0 = 0x07000604;
    g->w1 = 0x402;
    g = D_80177E18++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    setRenderState(-1);
    bumpVertexCount(4);
    return 0;
}
