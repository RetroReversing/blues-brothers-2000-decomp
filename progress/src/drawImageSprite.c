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

/* Draws an image-sized sprite quad for an object: the texture size comes from the
   image asset header, the quad is a fixed four vertices, and the render state is
   reset afterwards. Returns 0 when the object is culled, 1 otherwise. */
s32 drawImageSprite(Unk8002F8D0 *obj) {
    s32 halfSize;
    s32 color;
    s32 colorR;
    s32 colorG;
    s32 colorB;
    s32 colorA;
    s32 *imgDims;
    s32 texWidth;
    s32 texHeight;
    s32 firstVtx;
    s32 vtxIdx;
    f32 mtxA[10];
    f32 mtxB[14];

    colorB = obj->unk78;
    halfSize = obj->unk70;
    colorA = obj->unk5C;
    colorG = colorB >> 8;
    colorR = colorB & 0xFF;
    colorB >>= 16;
    colorG &= 0xFF;
    colorB &= 0xFF;
    if (isObjectInRange(obj, 10000) == 0) {
        return 0;
    }
    if (obj->unk30 < (f32)-obj->unk70) {
        return 0;
    }
    func_8001F230(obj);
    imgDims = getImageAsset(obj->unk60);
    texWidth = imgDims[0] << 6;
    texHeight = imgDims[1] << 6;
    func_8002C3B8(imgDims);
    if (obj->unk7C == 0) {
        func_80024FE8(mtxA);
        func_80024B58(mtxB, mtxA, obj->unk10);
        func_80024A3C(mtxA, mtxB, obj->unk14);
        func_80024BE0(mtxB, mtxA, obj->unk18);
        buildObjectMatrix(obj, mtxB, 1);
    } else {
        func_80024FE8(mtxA);
        func_80024BE0(mtxB, mtxA, obj->unk18);
        buildObjectMatrix(obj, mtxB, 0);
    }
    firstVtx = getVertexSlot();
    if (firstVtx == -1) {
        debugPrintf(D_80001230);
        return 1;
    }
    texWidth >>= 6;
    texHeight >>= 6;
    spriteVerts[firstVtx].ob[0] = halfSize;
    spriteVerts[firstVtx].ob[1] = halfSize;
    spriteVerts[firstVtx].ob[2] = 0;
    spriteVerts[firstVtx + 1].ob[0] = halfSize;
    spriteVerts[firstVtx + 1].ob[1] = -halfSize;
    spriteVerts[firstVtx + 1].ob[2] = 0;
    spriteVerts[firstVtx + 2].ob[0] = -halfSize;
    spriteVerts[firstVtx + 2].ob[1] = -halfSize;
    spriteVerts[firstVtx + 2].ob[2] = 0;
    spriteVerts[firstVtx + 3].ob[0] = -halfSize;
    spriteVerts[firstVtx + 3].ob[1] = halfSize;
    spriteVerts[firstVtx + 3].ob[2] = 0;
    spriteVerts[firstVtx].tc[0] = 0;
    spriteVerts[firstVtx].tc[1] = 0;
    spriteVerts[firstVtx + 1].tc[0] = texWidth << 6;
    spriteVerts[firstVtx + 1].tc[1] = 0;
    spriteVerts[firstVtx + 2].tc[0] = texWidth << 6;
    spriteVerts[firstVtx + 2].tc[1] = texHeight << 6;
    spriteVerts[firstVtx + 3].tc[0] = 0;
    spriteVerts[firstVtx + 3].tc[1] = texHeight << 6;
    for (vtxIdx = 0; vtxIdx < 4; vtxIdx++) {
        spriteVerts[firstVtx + vtxIdx].cn[0] = colorR;
        spriteVerts[firstVtx + vtxIdx].cn[1] = colorG;
        spriteVerts[firstVtx + vtxIdx].cn[2] = colorB;
        spriteVerts[firstVtx + vtxIdx].cn[3] = colorA;
    }
    {
        GfxW *gp = D_80177E18++;
        gp->w0 = 0x01004008;
        gp->w1 = (u32)&spriteVerts[firstVtx];
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
