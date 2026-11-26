typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

typedef struct {
    u8 pad0[0x28];
    f32 rot[3];
    u8 pad34[0x58 - 0x34];
    s32 unk58;
    u8 pad5C[0x74 - 0x5C];
    s32 count;
    u8 pad78[0xC4 - 0x78];
    Vec3i *points;
} Obj;

typedef struct {
    s32 unk0;
    f32 pos[3];
} Cam;

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define __gsSP1Triangle_w1(v0, v1, v2) (_SHIFTL((v0) * 2, 16, 8) | _SHIFTL((v1) * 2, 8, 8) | _SHIFTL((v2) * 2, 0, 8))
#define __gsSP1Quadrangle_w1f(v0, v1, v2, v3, flag)            \
    (((flag) == 0)   ? __gsSP1Triangle_w1(v0, v1, v2)          \
     : ((flag) == 1) ? __gsSP1Triangle_w1(v1, v2, v3)          \
     : ((flag) == 2) ? __gsSP1Triangle_w1(v2, v3, v0)          \
                     : __gsSP1Triangle_w1(v3, v0, v1))
#define __gsSP1Quadrangle_w2f(v0, v1, v2, v3, flag)            \
    (((flag) == 0)   ? __gsSP1Triangle_w1(v0, v2, v3)          \
     : ((flag) == 1) ? __gsSP1Triangle_w1(v1, v3, v0)          \
     : ((flag) == 2) ? __gsSP1Triangle_w1(v2, v0, v1)          \
                     : __gsSP1Triangle_w1(v3, v1, v2))
#define gSP1Quadrangle(pkt, v0, v1, v2, v3, flag)                                         \
    {                                                                                     \
        Gfx *_g = (Gfx *)(pkt);                                                           \
        _g->w0 = (_SHIFTL(0x07, 24, 8) | __gsSP1Quadrangle_w1f(v0, v1, v2, v3, flag));    \
        _g->w1 = __gsSP1Quadrangle_w2f(v0, v1, v2, v3, flag);                             \
    }
#define gSPVertex(pkt, v, n, v0)                                                          \
    {                                                                                     \
        Gfx *_g = (Gfx *)(pkt);                                                           \
        _g->w0 = _SHIFTL(0x01, 24, 8) | _SHIFTL((n), 12, 8) | _SHIFTL((v0) + (n), 1, 7); \
        _g->w1 = (u32)(v);                                                                \
    }

s32 func_8001EAD0(s32);
void func_8001EB18(s32);
void func_8001F230(Obj *);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void buildObjectMatrix(Obj *, f32 (*)[3], s32);
void func_80024C68(Vec3i *, void *, s32 *);
void func_80024FE8(f32 (*)[3]);
extern Cam *gCameraRig;
extern Vtx D_800BD6C8[];
extern Vec3i D_800CD170[];
extern Vec3i D_800CD350[];
extern Gfx *D_80177E18;
extern u8 D_80177E28[];

s32 func_800202BC(Obj *arg0) {
    s32 d[3];
    f32 m[3][3];
    f32 m2[3][3];
    Vec3i *p;
    s32 value;
    s32 count;
    s32 i;
    s32 k;
    s32 base;
    s32 a;
    s32 c;
    s32 e;
    
    s32 last;
    s32 nv;

    p = arg0->points;
    if (p == NULL) {
        return;
    }
    count = arg0->count;
    for (i = 0; i < count; p++, i++) {
        d[0] = p->x - (s32)gCameraRig->pos[0];
        d[1] = p->y - (s32)gCameraRig->pos[1];
        d[2] = p->z - (s32)gCameraRig->pos[2];
        if (abs(d[0]) > 10000 || abs(d[1]) > 10000 || abs(d[2]) > 10000) {
            return;
        }
        func_80024C68(&D_800CD350[i], D_80177E28, d);
    }
    arg0->unk58 = packDrawFlags(0, 1, 1, 1, 0, 0, 1, 0);
    func_8001F230(arg0);
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE200001C;
        _g->w1 = 0x504A50;
    }
    arg0->rot[0] = arg0->rot[1] = arg0->rot[2] = 0.0f;
    func_80024FE8(m);
    buildObjectMatrix(arg0, m, 0);
    last = count - 1;
    for (i = 0; i < count; i++) {
        D_800CD170[i].x = 0;
        D_800CD170[i].y = -100;
        D_800CD170[i].z = 0;
    }
    base = func_8001EAD0(last);
    for (i = k = 0; i < count; i++) {
        Vtx *v = &D_800BD6C8[k++ + base];
        Vtx *v2;
        Vtx *v3;
        u8 alpha;
        v->ob[0] = D_800CD350[i].x + D_800CD170[i].x;
        v->ob[1] = D_800CD350[i].y + D_800CD170[i].y;
        v->ob[2] = D_800CD350[i].z + D_800CD170[i].z;
        v->cn[0] = 0xFF;
        v->cn[1] = 0;
        v->cn[2] = 0xFF;
        v->cn[3] = 0;
        v2 = &D_800BD6C8[k++ + base];
        v2->ob[0] = D_800CD350[i].x;
        v2->ob[1] = D_800CD350[i].y;
        value = 0xFF;
        v2->ob[2] = D_800CD350[i].z;
        v2->cn[0] = 0xFF;
        v2->cn[1] = value;
        v2->cn[2] = 0xFF;
        alpha = 0x80;
        v2->cn[3] = alpha;
        v3 = &D_800BD6C8[k++ + base];
        v3->ob[0] = D_800CD350[i].x - D_800CD170[i].x;
        v3->ob[1] = D_800CD350[i].y - D_800CD170[i].y;
        v3->ob[2] = D_800CD350[i].z - D_800CD170[i].z;
        v3->cn[0] = 0xFF;
        value = 0;
        v3->cn[1] = value;
        v3->cn[2] = 0xFF;
        alpha = 0;
        v3->cn[3] = alpha;
    }
    nv = k;
    gSPVertex(D_80177E18++, &D_800BD6C8[base], nv, 0);
    for (i = 0; i < count - 1; i++) {
        base = i * 3;
        a = base;
        k = base + 1;
        c = base + 4;
        e = base + 3;
        gSP1Quadrangle(D_80177E18++, a, k, c, e, a);
        gSP1Quadrangle(D_80177E18++, e, c, k, a, a);
        a = base + 1;
        k = base + 2;
        c = base + 5;
        e = base + 4;
        gSP1Quadrangle(D_80177E18++, a, k, c, e, a);
        gSP1Quadrangle(D_80177E18++, e, c, k, a, a);
    }
    func_8001EB18(nv);
    return 1;
}


