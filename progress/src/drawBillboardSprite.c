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

/* Draws a textured, camera-facing quad for an object: returns 0 when it is out of range,
 * otherwise loads its texture, builds its transform, fills four vertices and emits the
 * display-list commands for the quad. */
s32 drawBillboardSprite(Obj *obj) {
    f32 m1[10];
    f32 m2[10];
    s32 pad[4];
    s32 s[4];
    s32 t[4];
    s32 col;
    s32 halfSize;
    s32 alpha;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 *imageData;
    s32 *imageHeader;
    s32 texFormat;
    s32 vtxIndex;
    s32 firstVtx;
    Vtx *v0;
    Vtx *v1;
    Vtx *v2;
    Vtx *v3;

    c2 = obj->x78;
    halfSize = obj->x70;
    alpha = obj->x5C;
    c1 = c2 >> 8;
    c0 = c2 & 0xFF;
    c2 >>= 16;
    c1 &= 0xFF;
    c2 &= 0xFF;
    if (func_8001EF80(obj, 100000) == 0) {
        return 0;
    }
    if (obj->x30 < (f32)-obj->x70) {
        return 0;
    }
    func_8001F230(obj);
    {
        GfxW *_g = GP++;
        _g->w0 = 0xE200001C;
        _g->w1 = 0x504340;
    }
    imageData = getImageAsset(obj->x60);
    imageHeader = imageData;
    if (obj->x74 == 0) {
        imageData += 4;
    }
    s[0] = 0;
    t[0] = 0;
    s[1] = 0x7C0;
    t[1] = 0;
    s[2] = 0x7C0;
    t[2] = 0x7C0;
    s[3] = 0;
    t[3] = 0x7C0;
    texFormat = 0x10;
    if (obj->x74 == 0 && imageHeader[2] == 0x20) {
        texFormat = 0x20;
    }
    loadTextureClamped(texFormat, imageData, 0, 0);
    if (obj->x7C == 0) {
        func_80024FE8(m1);
        func_80024B58(m2, m1, obj->x10);
        func_80024A3C(m1, m2, obj->x14);
        func_80024BE0(m2, m1, obj->x18);
        buildObjectMatrix(obj, m2, 1);
    } else {
        func_80024FE8(m1);
        buildObjectMatrix(obj, m1, 0);
    }
    firstVtx = vtxIndex = func_8001EAD0();
    if (vtxIndex == -1) {
        debugPrintf(D_80001230);
        return 1;
    }
    v0 = &D_800BD6C8[vtxIndex++];
    v1 = &D_800BD6C8[vtxIndex++];
    v2 = &D_800BD6C8[vtxIndex++];
    v3 = &D_800BD6C8[vtxIndex++];
    v0->ob[0] = -halfSize;
    v0->ob[1] = -halfSize;
    v0->ob[2] = 0;
    v0->cn[0] = c0;
    v0->cn[1] = c1;
    v0->cn[2] = c2;
    v0->cn[3] = alpha;
    v0->tc[0] = s[0];
    v0->tc[1] = t[0];
    v1->ob[0] = halfSize;
    v1->ob[1] = -halfSize;
    v1->ob[2] = 0;
    v1->cn[0] = c0;
    v1->cn[1] = c1;
    v1->cn[2] = c2;
    v1->cn[3] = alpha;
    v1->tc[0] = s[1];
    v1->tc[1] = t[1];
    v2->ob[0] = halfSize;
    v2->ob[1] = halfSize;
    v2->ob[2] = 0;
    v2->cn[0] = c0;
    v2->cn[1] = c1;
    v2->cn[2] = c2;
    v2->cn[3] = alpha;
    v2->tc[0] = s[2];
    v2->tc[1] = t[2];
    v3->ob[0] = -halfSize;
    v3->ob[1] = halfSize;
    v3->ob[2] = 0;
    v3->cn[0] = c0;
    v3->cn[1] = c1;
    v3->cn[2] = c2;
    v3->cn[3] = alpha;
    v3->tc[0] = s[3];
    v3->tc[1] = t[3];
    {
        GfxW *_g = GP++;
        _g->w0 = 0x01004008;
        _g->w1 = (u32)&D_800BD6C8[vtxIndex - 4];
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
    func_8001EB18(vtxIndex - firstVtx);
    return 1;
}
