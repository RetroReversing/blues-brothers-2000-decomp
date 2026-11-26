typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} VtxW;

typedef struct { u32 w0, w1; } GfxW;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x30 - 0x1C];
    f32 unk30;
    u8 pad34[0x5C - 0x34];
    s32 unk5C;
    s32 unk60;
    u8 pad64[0x70 - 0x64];
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
} Unk8002FEDC;

extern VtxW D_800BD6C8[];
extern GfxW *D_80177E18;
extern char D_80001230[];

s32 func_8001EF80(void *arg0, s32 arg1);
void func_8001F230(void *arg0);
s32 *getImageAsset(s32 arg0);
void func_8002C3B8(s32 *);
void func_80024FE8(void *arg0);
void func_80024B58(void *arg0, void *arg1, s32 arg2);
void func_80024A3C(void *arg0, void *arg1, s32 arg2);
void func_80024BE0(void *arg0, void *arg1, s32 arg2);
s32 buildObjectMatrix(void *obj, void *rot, s32 mul);
s32 func_8001EAD0(void);
void setRenderState(s32 mode);
s32 func_8001EB18(s32 arg0);
void debugPrintf(void *, ...);

void loadTextureClamped(s32 type, void *img, void *pal, s32);

s32 func_8002FEDC(Unk8002FEDC *arg0) {
    s32 size;
    s32 r;
    s32 g;
    s32 b;
    s32 a;
    s32 *tex;
    s32 *img;
    s32 fmt;
    s32 w;
    s32 h;
    s32 idx;
    s32 i;
    VtxW *v0;
    VtxW *v1;
    VtxW *v2;
    VtxW *v3;
    f32 m1[10];
    f32 m2[14];

    b = arg0->unk78;
    size = arg0->unk70;
    a = arg0->unk5C;
    g = b >> 8;
    r = b & 0xFF;
    b >>= 16;
    g &= 0xFF;
    b &= 0xFF;
    func_8001F230(arg0);
    {
        GfxW *gp = D_80177E18++;
        gp->w0 = 0xE200001C;
        gp->w1 = 0x00553048;
    }
    tex = getImageAsset(arg0->unk60);
    img = tex;
    if (arg0->unk74 == 0) {
        img = tex + 4;
    }
    w = 0x7C0;
    h = 0x7C0;
    if (arg0->unk74 == 0 && tex[2] == 32) {
        loadTextureClamped(32, img, NULL, 0);
    } else {
        loadTextureClamped(16, img, NULL, 0);
    }
    if (arg0->unk7C == 0) {
        func_80024FE8(m1);
        func_80024B58(m2, m1, arg0->unk10);
        func_80024A3C(m1, m2, arg0->unk14);
        func_80024BE0(m2, m1, arg0->unk18);
        buildObjectMatrix(arg0, m2, 1);
    } else {
        func_80024FE8(m1);
        func_80024BE0(m2, m1, arg0->unk18);
        buildObjectMatrix(arg0, m2, 0);
    }
    i = func_8001EAD0();
    idx = i;
    if (i == -1) {
        debugPrintf(D_80001230);
        return 1;
    }
    v0 = &D_800BD6C8[i++];
    v1 = &D_800BD6C8[i++];
    v2 = &D_800BD6C8[i++];
    v3 = &D_800BD6C8[i++];
    v0->ob[0] = size;
    v0->ob[1] = size * 2;
    v0->ob[2] = 0;
    v0->cn[0] = r;
    v0->cn[1] = g;
    v0->cn[2] = b;
    v0->cn[3] = a;
    v0->tc[0] = w;
    v0->tc[1] = h;
    v1->ob[0] = size;
    v1->ob[1] = 0;
    v1->ob[2] = 0;
    v1->cn[0] = r;
    v1->cn[1] = g;
    v1->cn[2] = b;
    v1->cn[3] = a;
    v1->tc[0] = w;
    v1->tc[1] = 0;
    v2->ob[0] = -size;
    v2->ob[1] = 0;
    v2->ob[2] = 0;
    v2->cn[0] = r;
    v2->cn[1] = g;
    v2->cn[2] = b;
    v2->cn[3] = a;
    v2->tc[0] = 0;
    v2->tc[1] = 0;
    v3->ob[0] = -size;
    v3->ob[1] = size * 2;
    v3->ob[2] = 0;
    v3->cn[0] = r;
    v3->cn[1] = g;
    v3->cn[2] = b;
    v3->cn[3] = a;
    v3->tc[0] = 0;
    v3->tc[1] = h;
    {
        GfxW *gp = D_80177E18++;
        gp->w0 = 0x01004008;
        gp->w1 = (u32)&D_800BD6C8[i - 4];
    }
    {
        GfxW *gp = D_80177E18++;
        gp->w0 = 0x07000204;
        gp->w1 = 0x406;
    }
    {
        GfxW *gp = D_80177E18++;
        gp->w0 = 0x07000604;
        gp->w1 = 0x402;
    }
    func_8001EB18(i - idx);
    {
        GfxW *gp = D_80177E18++;
        gp->w0 = 0xE7000000;
        gp->w1 = 0;
    }
    return 1;
}
