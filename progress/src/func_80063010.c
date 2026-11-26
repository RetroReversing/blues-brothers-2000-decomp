typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx_t;

typedef union {
    Vtx_t v;
    s64 force_structure_alignment;
} Vtx;

typedef struct {
    u32 w0;
    u32 w1;
} GfxW;

typedef struct {
    u8 pad[0x230];
    Vtx vtx[2][14];
    s32 count;
} VtxBuf;

typedef struct {
    f32 x, y, z;
} Vec3f;

#define GW(pkt, a, b) { GfxW *_g = (GfxW *)(pkt); _g->w0 = (a); _g->w1 = (b); }

void func_80046310(void *, f32, s32);
extern VtxBuf *D_800B7FE0;
extern s32 D_800B9EB8;
extern GfxW *D_80177E18;

#define V(i, X, Y, Z, C) \
    D_800B7FE0->vtx[D_800B9EB8][D_800B7FE0->count + (i)].v.ob[0] = X; \
    D_800B7FE0->vtx[D_800B9EB8][D_800B7FE0->count + (i)].v.ob[1] = Y; \
    D_800B7FE0->vtx[D_800B9EB8][D_800B7FE0->count + (i)].v.ob[2] = Z; \
    D_800B7FE0->vtx[D_800B9EB8][D_800B7FE0->count + (i)].v.flag = 0; \
    D_800B7FE0->vtx[D_800B9EB8][D_800B7FE0->count + (i)].v.tc[0] = 0; \
    D_800B7FE0->vtx[D_800B9EB8][D_800B7FE0->count + (i)].v.tc[1] = 0; \
    D_800B7FE0->vtx[D_800B9EB8][D_800B7FE0->count + (i)].v.cn[0] = C; \
    D_800B7FE0->vtx[D_800B9EB8][D_800B7FE0->count + (i)].v.cn[1] = C; \
    D_800B7FE0->vtx[D_800B9EB8][D_800B7FE0->count + (i)].v.cn[2] = C; \
    D_800B7FE0->vtx[D_800B9EB8][D_800B7FE0->count + (i)].v.cn[3] = 0xFF;

void func_80063010(Vec3f *a, Vec3f *b) {
    GW(D_80177E18++, 0xE7000000, 0);
    GW(D_80177E18++, 0xD9D0F9FA, 0);
    GW(D_80177E18++, 0xD9FFFFFF, 0x200005);
    GW(D_80177E18++, 0xE3000A01, 0);
    GW(D_80177E18++, 0xE200001C, 0x055A4340);
    GW(D_80177E18++, 0xFCFFFFFF, 0xFFFE793C);
    GW(D_80177E18++, 0xF8000000, 0xFFFFFFFF);
    GW(D_80177E18++, 0xE3001801, 0x80);
    V(0, a->x - 50.0, a->y, a->z, 0)
    V(1, a->x, a->y, a->z, 0x12)
    V(2, a->x + 50.0, a->y, a->z, 0)
    V(3, b->x - 200.0, b->y, b->z, 0)
    V(4, b->x - 125.0, b->y, b->z, 0)
    V(5, b->x + 125.0, b->y, b->z, 0)
    V(6, b->x + 200.0, b->y, b->z, 0)
    GW(D_80177E18++, 0x0100700E, (u32)&D_800B7FE0->vtx[D_800B9EB8][D_800B7FE0->count]);
    GW(D_80177E18++, 0x06000206, 0x602);
    GW(D_80177E18++, 0x06080602, 0x20608);
    GW(D_80177E18++, 0x060A0802, 0x2080A);
    GW(D_80177E18++, 0x060C0A02, 0x20A0C);
    GW(D_80177E18++, 0x06040C02, 0x20C04);
    D_800B7FE0->count += 7;
    func_80046310(b, 400.0f, 3);
}
