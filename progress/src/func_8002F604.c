typedef struct Vtx {
    s16 x;
    s16 y;
    s16 z;
    s16 flag;
    s16 s;
    s16 t;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Vtx;
typedef struct Gfx {
    u32 w0;
    u32 w1;
} Gfx;
typedef struct Obj {
    char pad0[0x10];
    s32 f10;
    s32 f14;
    s32 f18;
    char pad1C[0x14];
    f32 f30;
    char pad34[0x28];
    s32 f5C;
    s32 f60;
    char pad64[0x0C];
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
} Obj;
s32 getVertexSlot();
s32 bumpVertexCount();
s32 isObjectInRange();
s32 func_8001F230();
s32 buildObjectMatrix();
u8 *getImageAsset();
s32 func_80024A3C();
s32 func_80024B58();
s32 func_80024BE0();
s32 func_80024FE8();
s32 loadTextureClamped();
s32 debugPrintf();
extern char D_80001230[];
extern Vtx spriteVerts[];
extern Gfx *D_80177E18;

s32 func_8002F604(Obj *obj) {
    s32 col;
    s32 size;
    s32 alpha;
    s32 r;
    s32 g;
    s32 b;
    u8 *p;
    u8 *q;
    s32 w;
    f32 sp10[10];
    f32 sp38[14];
    s32 idx;
    s32 start;
    s16 sMax;
    s16 tMax;
    Vtx *v0;
    Vtx *v1;
    Vtx *v2;
    Vtx *v3;
    Gfx *g1;
    Gfx *g2;

    b = obj->f78;
    size = obj->f70;
    alpha = obj->f5C;
    r = b & 0xFF;
    g = b >> 8;
    b = b >> 16;
    g &= 0xFF;
    b &= 0xFF;
    if (isObjectInRange(obj, 0x7530) == 0) {
        return 0;
    }
    if (obj->f30 < (f32) -obj->f70) {
        return 0;
    }
    func_8001F230(obj);
    p = getImageAsset(obj->f60);
    q = p;
    if (obj->f74 == 0) {
        q = p + 0x10;
    }
    sMax = 0x7C0;
    tMax = sMax;
    if (obj->f74 == 0 && *(s32 *)(p + 8) == 0x20) {
        loadTextureClamped(0x20, q, 0, 0);
    } else {
        loadTextureClamped(0x10, q, 0, 0);
    }
    if (obj->f7C == 0) {
        func_80024FE8(sp10);
        func_80024B58(sp38, sp10, obj->f10);
        func_80024A3C(sp10, sp38, obj->f14);
        func_80024BE0(sp38, sp10, obj->f18);
        buildObjectMatrix(obj, sp38, 1);
    } else {
        func_80024FE8(sp10);
        buildObjectMatrix(obj, sp10, 0);
    }
    idx = getVertexSlot();
    start = idx;
    if (idx == -1) {
        debugPrintf(D_80001230);
        return 1;
    }
    v0 = &spriteVerts[idx++];
    v1 = &spriteVerts[idx++];
    v2 = &spriteVerts[idx++];
    v3 = &spriteVerts[idx++];
    v0->x = size;
    v0->z = size;
    v0->y = 0;
    v0->r = r;
    v0->g = g;
    v0->b = b;
    v0->a = alpha;
    v0->s = 0;
    v0->t = 0;
    v1->x = size;
    v1->z = -size;
    v1->y = 0;
    v1->r = r;
    v1->g = g;
    v1->b = b;
    v1->a = alpha;
    v1->s = sMax;
    v1->t = 0;
    v2->x = -size;
    v2->z = -size;
    v2->y = 0;
    v2->r = r;
    v2->g = g;
    v2->b = b;
    v2->a = alpha;
    v2->s = sMax;
    v2->t = tMax;
    v3->x = -size;
    v3->z = size;
    v3->y = 0;
    v3->r = r;
    v3->g = g;
    v3->b = b;
    v3->a = alpha;
    v3->s = 0;
    v3->t = tMax;
    g1 = D_80177E18++;
    g1->w1 = (u32) &spriteVerts[idx - 4];
    g1->w0 = 0x01004008;
    g2 = D_80177E18++;
    g2->w0 = 0x07000204;
    g2->w1 = 0x406;
    bumpVertexCount(idx - start, g1);
    return 1;
}
