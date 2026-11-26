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
} Unk8002FBC0;

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

void loadTextureClamped(s32 type, void *img, void *pal, s32);

/* Draws one textured, flat-coloured sprite quad centred on the object, reserving four
   vertices and emitting the display list commands for it. Returns 0 when the object
   is culled or out of range, 1 otherwise. */
s32 drawQuadSprite(Unk8002FBC0 *obj) {
    s32 halfWidth;
    s32 colorR;
    s32 colorG;
    s32 colorB;
    s32 colorA;
    s32 *texData;
    s32 *imgData;
    s32 fmt;
    s32 texW;
    s32 texH;
    s32 firstSlot;
    s32 vtxIndex;
    VtxW *vtx0;
    VtxW *vtx1;
    VtxW *vtx2;
    VtxW *vtx3;
    f32 mtxA[10];
    f32 mtxB[14];

    colorB = obj->unk78;
    halfWidth = obj->unk70;
    colorA = obj->unk5C;
    colorG = colorB >> 8;
    colorR = colorB & 0xFF;
    colorB >>= 16;
    colorG &= 0xFF;
    colorB &= 0xFF;
    if (isObjectInRange(obj, 8000) == 0) {
        return 0;
    }
    if (obj->unk30 < (f32)-obj->unk70) {
        return 0;
    }
    func_8001F230(obj);
    texData = getImageAsset(obj->unk60);
    imgData = texData;
    if (obj->unk74 == 0) {
        imgData = texData + 4;
    }
    texW = 0x7C0;
    texH = 0x7C0;
    if (obj->unk74 == 0 && texData[2] == 32) {
        loadTextureClamped(32, imgData, NULL, 0);
    } else {
        loadTextureClamped(16, imgData, NULL, 0);
    }
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
    vtxIndex = getVertexSlot();
    firstSlot = vtxIndex;
    if (vtxIndex == -1) {
        debugPrintf(D_80001230);
        return 1;
    }
    vtx0 = &spriteVerts[vtxIndex++];
    vtx1 = &spriteVerts[vtxIndex++];
    vtx2 = &spriteVerts[vtxIndex++];
    vtx3 = &spriteVerts[vtxIndex++];
    vtx0->ob[0] = halfWidth;
    vtx0->ob[1] = halfWidth * 2;
    vtx0->ob[2] = 0;
    vtx0->cn[0] = colorR;
    vtx0->cn[1] = colorG;
    vtx0->cn[2] = colorB;
    vtx0->cn[3] = colorA;
    vtx0->tc[0] = texW;
    vtx0->tc[1] = texH;
    vtx1->ob[0] = halfWidth;
    vtx1->ob[1] = 0;
    vtx1->ob[2] = 0;
    vtx1->cn[0] = colorR;
    vtx1->cn[1] = colorG;
    vtx1->cn[2] = colorB;
    vtx1->cn[3] = colorA;
    vtx1->tc[0] = texW;
    vtx1->tc[1] = 0;
    vtx2->ob[0] = -halfWidth;
    vtx2->ob[1] = 0;
    vtx2->ob[2] = 0;
    vtx2->cn[0] = colorR;
    vtx2->cn[1] = colorG;
    vtx2->cn[2] = colorB;
    vtx2->cn[3] = colorA;
    vtx2->tc[0] = 0;
    vtx2->tc[1] = 0;
    vtx3->ob[0] = -halfWidth;
    vtx3->ob[1] = halfWidth * 2;
    vtx3->ob[2] = 0;
    vtx3->cn[0] = colorR;
    vtx3->cn[1] = colorG;
    vtx3->cn[2] = colorB;
    vtx3->cn[3] = colorA;
    vtx3->tc[0] = 0;
    vtx3->tc[1] = texH;
    {
        GfxW *gp = D_80177E18++;
        gp->w0 = 0x01004008;
        gp->w1 = (u32)&spriteVerts[vtxIndex - 4];
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
    bumpVertexCount(vtxIndex - firstSlot);
    {
        GfxW *gp = D_80177E18++;
        gp->w0 = 0xE7000000;
        gp->w1 = 0;
    }
    return 1;
}
