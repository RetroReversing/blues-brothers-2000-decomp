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
    u8 pad74[4];
    s32 unk78;
    s32 unk7C;
} Unk8002F8D0;

extern VtxW spriteVerts[];
extern GfxW *D_80177E18;
extern char D_80001230[];

s32 isObjectInRange(void *arg0, s32 arg1);
void func_8001F230(void *arg0);
s32 *getImageAsset(s32 arg0);
void func_8002C3B8(s32 *);
void func_80024FE8(void *arg0);
void func_80024B58(void *arg0, void *arg1, s32 arg2);
void func_80024A3C(void *arg0, void *arg1, s32 arg2);
void func_80024BE0(void *arg0, void *arg1, s32 arg2);
s32 buildObjectMatrix(void *obj, void *rot, s32 mul);
s32 getVertexSlot(void);
void setRenderState(s32 mode);
s32 bumpVertexCount(s32 arg0);
void debugPrintf(void *, ...);

s32 func_8002F8D0(Unk8002F8D0 *arg0) {
    s32 size;
    s32 color;
    s32 r;
    s32 g;
    s32 b;
    s32 a;
    s32 *dims;
    s32 w;
    s32 h;
    s32 idx;
    s32 i;
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
    if (isObjectInRange(arg0, 10000) == 0) {
        return 0;
    }
    if (arg0->unk30 < (f32)-arg0->unk70) {
        return 0;
    }
    func_8001F230(arg0);
    dims = getImageAsset(arg0->unk60);
    w = dims[0] << 6;
    h = dims[1] << 6;
    func_8002C3B8(dims);
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
    idx = getVertexSlot();
    if (idx == -1) {
        debugPrintf(D_80001230);
        return 1;
    }
    w >>= 6;
    h >>= 6;
    spriteVerts[idx].ob[0] = size;
    spriteVerts[idx].ob[1] = size;
    spriteVerts[idx].ob[2] = 0;
    spriteVerts[idx + 1].ob[0] = size;
    spriteVerts[idx + 1].ob[1] = -size;
    spriteVerts[idx + 1].ob[2] = 0;
    spriteVerts[idx + 2].ob[0] = -size;
    spriteVerts[idx + 2].ob[1] = -size;
    spriteVerts[idx + 2].ob[2] = 0;
    spriteVerts[idx + 3].ob[0] = -size;
    spriteVerts[idx + 3].ob[1] = size;
    spriteVerts[idx + 3].ob[2] = 0;
    spriteVerts[idx].tc[0] = 0;
    spriteVerts[idx].tc[1] = 0;
    spriteVerts[idx + 1].tc[0] = w << 6;
    spriteVerts[idx + 1].tc[1] = 0;
    spriteVerts[idx + 2].tc[0] = w << 6;
    spriteVerts[idx + 2].tc[1] = h << 6;
    spriteVerts[idx + 3].tc[0] = 0;
    spriteVerts[idx + 3].tc[1] = h << 6;
    for (i = 0; i < 4; i++) {
        spriteVerts[idx + i].cn[0] = r;
        spriteVerts[idx + i].cn[1] = g;
        spriteVerts[idx + i].cn[2] = b;
        spriteVerts[idx + i].cn[3] = a;
    }
    {
        GfxW *gp = D_80177E18++;
        gp->w0 = 0x01004008;
        gp->w1 = (u32)&spriteVerts[idx];
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
    {
        GfxW *gp = D_80177E18++;
        gp->w0 = 0xE7000000;
        gp->w1 = 0;
    }
    setRenderState(-1);
    bumpVertexCount(4);
    return 1;
}
