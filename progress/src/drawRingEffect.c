typedef struct {
    u32 w0;
    u32 w1;
} GfxW30600;

typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx30600;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x30 - 0x1C];
    f32 unk30;
    u8 pad34[0x58 - 0x34];
    s32 unk58;
    u8 pad5C[0x60 - 0x5C];
    s32 unk60;
    u8 pad64[0x70 - 0x64];
    s32 unk70;
} Obj30600;

typedef struct {
    u8 pad0[0x8];
    s32 unk8;
    u8 padC[0x10 - 0xC];
    u8 data[1];
} Tex30600;

#define SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define TRI_W1(v0, v1, v2) (SHIFTL((v0) * 2, 16, 8) | SHIFTL((v1) * 2, 8, 8) | SHIFTL((v2) * 2, 0, 8))
#define QUAD_W1F(v0, v1, v2, v3, flag) (((flag) == 0) ? TRI_W1(v0, v1, v2) : ((flag) == 1) ? TRI_W1(v1, v2, v3) : ((flag) == 2) ? TRI_W1(v2, v3, v0) : TRI_W1(v3, v0, v1))
#define QUAD_W2F(v0, v1, v2, v3, flag) (((flag) == 0) ? TRI_W1(v0, v2, v3) : ((flag) == 1) ? TRI_W1(v1, v3, v0) : ((flag) == 2) ? TRI_W1(v2, v0, v1) : TRI_W1(v3, v1, v2))
#define QUAD(pkt, v0, v1, v2, v3, flag) { GfxW30600 *_g = (GfxW30600 *)(pkt); _g->w0 = (SHIFTL(7, 24, 8) | QUAD_W1F(v0, v1, v2, v3, flag)); _g->w1 = QUAD_W2F(v0, v1, v2, v3, flag); }

s16 sins(u16);
s16 coss(u16);
s32 getVertexSlot(void);
void bumpVertexCount(s32);
s32 isObjectInRange(void *, s32);
void func_8001F230(void *);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void buildObjectMatrix(void *, void *, s32);
Tex30600 *getImageAsset(s32);
void func_80024A3C(void *, void *, s32);
void func_80024B58(void *, void *, s32);
void func_80024BE0(void *, void *, s32);
void func_80024FE8(void *);
void loadTexture(s32, void *, s32, s32);
void debugPrintf(char *);
extern char D_80001230[];
extern Vtx30600 spriteVerts[];
extern GfxW30600 *D_80177E18;

/* Draws a ring-shaped effect around an object: loads its texture, builds a cylinder of vertices and quads, and submits it to the display list. */
s32 drawRingEffect(Obj30600 *obj) {
    u8 mtxA[0x28];
    u8 mtxB[0x38];
    s32 ra[4];
    s32 rb[4];
    s32 cr;
    s32 cg;
    s32 cb;
    s32 radiusTop;
    s32 radiusBottom;
    s32 texHeight;
    s32 vtxBase;
    s32 vtxIdx;
    s32 segments;
    s32 i;
    s32 t;
    s32 texStep;
    s32 fmt;
    u16 ang;
    Vtx30600 *v;
    Tex30600 *tex;
    u8 *data;

    obj->unk58 = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0);
    cb = 0x2C;
    radiusTop = 0x44C;
    radiusBottom = 0x708;
    texHeight = 0x7C0;
    cr = 0xD1;
    cg = 0xBD;
    if (isObjectInRange(obj, 100000) == 0) {
        return 0;
    }
    if (obj->unk30 < (f32)-obj->unk70) {
        return 0;
    }
    {
        GfxW30600 *_g = D_80177E18++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    func_8001F230(obj);
    texStep = 0x7C0;
    tex = getImageAsset(obj->unk60);
    data = (u8 *)tex;
    data += 0x10;
    ra[0] = 0;
    rb[0] = 0;
    ra[1] = texStep;
    rb[1] = 0;
    ra[2] = texStep;
    rb[2] = texStep;
    ra[3] = 0;
    rb[3] = texStep;
    if (tex->unk8 == 0x20) {
        loadTexture(0x20, data, 0, 0);
    } else {
        loadTexture(0x10, data, 0, 0);
    }
    func_80024FE8(mtxA);
    func_80024B58(mtxB, mtxA, obj->unk10);
    func_80024A3C(mtxA, mtxB, obj->unk14);
    func_80024BE0(mtxB, mtxA, obj->unk18);
    buildObjectMatrix(obj, mtxB, 1);
    vtxIdx = getVertexSlot();
    vtxBase = vtxIdx;
    if (vtxIdx == -1) {
        debugPrintf(D_80001230);
        return 1;
    }
    segments = 14;
    for (i = 0, t = 0; i <= segments; i++) {
        ang = (i << 16) / segments;
        spriteVerts[vtxIdx].ob[0] = (radiusTop * sins(ang)) >> 15;
        spriteVerts[vtxIdx].ob[2] = (radiusTop * coss(ang)) >> 15;
        spriteVerts[vtxIdx].ob[1] = 100;
        spriteVerts[vtxIdx].cn[0] = cb;
        spriteVerts[vtxIdx].cn[1] = cr;
        spriteVerts[vtxIdx].cn[2] = cg;
        spriteVerts[vtxIdx].cn[3] = 0;
        spriteVerts[vtxIdx].tc[0] = t;
        spriteVerts[vtxIdx].tc[1] = texHeight;
        vtxIdx++;
        spriteVerts[vtxIdx].ob[0] = (radiusBottom * sins(ang)) >> 15;
        spriteVerts[vtxIdx].ob[2] = (radiusBottom * coss(ang)) >> 15;
        spriteVerts[vtxIdx].cn[0] = cb;
        spriteVerts[vtxIdx].ob[1] = 0;
        spriteVerts[vtxIdx].cn[1] = cr;
        spriteVerts[vtxIdx].cn[2] = cg;
        spriteVerts[vtxIdx].cn[3] = 0x60;
        spriteVerts[vtxIdx].tc[0] = t;
        spriteVerts[vtxIdx].tc[1] = 0;
        vtxIdx++;
        t += texStep;
    }
    {
        GfxW30600 *_g = D_80177E18++;
        _g->w0 = 0x01000000 | ((segments * 2 + 2) << 12) | ((segments * 2 + 2) << 1);
        _g->w1 = (u32)&spriteVerts[vtxBase];
    }
    for (i = 0; i < segments * 2; i += 2) {
        QUAD(D_80177E18++, i, i + 1, i + 3, i + 2, i);
        QUAD(D_80177E18++, i, i + 2, i + 3, i + 1, i);
    }
    bumpVertexCount(vtxIdx - vtxBase);
    {
        GfxW30600 *_g = D_80177E18++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    return 1;
}
