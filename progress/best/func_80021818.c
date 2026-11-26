typedef struct {
    u32 w0;
    u32 w1;
} GfxWords;

typedef union {
    GfxWords words;
    long long force_structure_alignment;
} Gfx;

typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx;

typedef struct {
    s32 width;
    s32 height;
    s32 bpp;
    s32 pad;
    u8 pixels[1];
} Image;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    u8 pad[0xC];
} Particle;

typedef struct {
    u8 pad0[0x12];
    u16 yaw;
} Camera;

typedef struct {
    u8 pad0[0x30];
    f32 unk30;
    u8 pad34[0x60 - 0x34];
    s32 image;
    u8 pad64[0x70 - 0x64];
    s32 size;
    u8 pad74[0x84 - 0x74];
    s32 count;
    s32 phase;
    u8 pad8C[0xC4 - 0x8C];
    Particle *parts;
} Emitter;

extern Gfx *D_80177E18;
extern Camera *volatile D_800B3960;
extern Vtx D_800BD6C8[];

void func_8001F230(Emitter *);
void func_8001F1D0(Emitter *);
void func_80024FE8(void *);
s32 func_80022728(Emitter *, void *, s32);
Image *func_80023E18(s32);
s32 func_8001EAD0(void);
s32 func_8001EB18(s32);
void func_80029F8C(s32);
s16 sins(u16);
s16 coss(u16);

#define G(a, b) { Gfx *_g = (Gfx *)(D_80177E18++); _g->words.w0 = (a); _g->words.w1 = (b); }
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define TXL2WORDS(txls, b_txl) MAX(1, ((txls) * (b_txl) / 8))
#define CALC_DXT(width, b_txl) (((1 << 11) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))

void func_80021818(Emitter *obj) {
    f32 unused[8];
    f32 m[3][3];
    f32 m2[3][3];
    f32 pos[3];
    Image *img;
    u8 *pixels;
    s32 bpp;
    s32 w;
    s32 h;
    s32 alpha;
    Vtx *v;
    s32 x1;
    s32 y1;
    s32 r;
    s32 z1;
  s32 key;
    s32 x2;
    s32 y2;
    
    Particle *p;
    
    s32 fade;
    s16 a;
    s32 col0;
    s32 col1;
    s32 col2;

    col0 = 0xFF;
    col1 = 0xFF;
    col2 = 0xFF;
    func_8001F230(obj);
    func_8001F1D0(obj);
    if (5000.0f < obj->unk30) {
        return;
    }
    fade = (5000.0f - obj->unk30) * 255.0f / 3000.0f;
    if (fade < 0) {
        fade = 0;
    }
    if (fade >= 0x100) {
        fade = 0xFF;
    }
    alpha = fade;
    func_80024FE8(m);
    func_80022728(obj, m, 1);
    img = func_80023E18(obj->image);
    h = img->height;
    w = img->width;
    bpp = img->bpp;
    G(0xE7000000, 0);
    pixels = img->pixels;
    switch (bpp) {
    case 16:
        G(0xFD100000, (u32)pixels);
        G(0xF5100000, 0x07080200);
        G(0xE6000000, 0);
        G(0xF3000000, 0x07000000 | ((((w * h - 1) < 0x800 ? (w * h - 1) : 0x7FF) & 0xFFF) << 12) | (CALC_DXT(w, 2) & 0xFFF));
        G(0xE7000000, 0);
        G(0xF5100000 | ((((w * 2 + 7) >> 3) & 0x1FF) << 9), 0x00080200);
        G(0xF2000000, ((((w - 1) << 2) & 0xFFF) << 12) | (((h - 1) << 2) & 0xFFF));
        G(0xE3001001, 0);
        break;
    case 32:
        G(0xFD180000, (u32)pixels);
        G(0xF5180000, 0x07080200);
        G(0xE6000000, 0);
        G(0xF3000000, 0x07000000 | ((((w * h - 1) < 0x800 ? (w * h - 1) : 0x7FF) & 0xFFF) << 12) | (CALC_DXT(w, 4) & 0xFFF));
        G(0xE7000000, 0);
        G(0xF5180000 | ((((w * 2 + 7) >> 3) & 0x1FF) << 9), 0x00080200);
        G(0xF2000000, ((((w - 1) << 2) & 0xFFF) << 12) | (((h - 1) << 2) & 0xFFF));
        G(0xE3001001, 0);
        break;
    }
    v = &D_800BD6C8[func_8001EAD0()];
    r = obj->size;
    y1 = -r;
    x1 = ((y1 * coss(D_800B3960->yaw)) >> 15) + ((y1 * sins(D_800B3960->yaw)) >> 15);
    z1 = -((y1 * sins(D_800B3960->yaw)) >> 15) + ((y1 * coss(D_800B3960->yaw)) >> 15);
    x2 = ((r * coss(D_800B3960->yaw)) >> 15) + ((r * sins(D_800B3960->yaw)) >> 15);
    bpp = -((r * sins(D_800B3960->yaw)) >> 15) + ((r * coss(D_800B3960->yaw)) >> 15);
    y2 = r;
    p = obj->parts;
    if (p == NULL) {
        return;
    }
    key = z1;
    for (r = 0; r < obj->count; r++) {
        fade = r - obj->phase;
        if (fade < 0) {
            fade += 100;
        }
        fade *= 3;
        if (fade >= 0x100) {
            fade = 0xFF;
        }
        pos[0] = p->x;
        pos[1] = p->y;
        pos[2] = p->z;
        a = (alpha * fade) >> 8;
        v->ob[0] = x1 + pos[0];
        v->ob[2] = key + pos[2];
        v->ob[1] = y1 + pos[1];
        v->tc[0] = 0;
        v->tc[1] = 0;
        v->cn[0] = col0;
        v->cn[1] = col1;
        v->cn[2] = col2;
        v->cn[3] = a;
        v++;
        v->ob[0] = (pos[0]) + (x1);
        v->ob[1] = y2 + pos[1];
        v->ob[2] = key + pos[2];
        v->cn[0] = col0;
        v->cn[1] = col1;
        v->cn[2] = col2;
        v->cn[3] = a;
        v->tc[0] = w << 6;
        v->tc[1] = 0;
        v++;
        v->ob[0] = x2 + pos[0];
        v->ob[1] = y2 + pos[1];
        v->ob[2] = bpp + pos[2];
        v->cn[0] = col0;
        v->cn[1] = col1;
        v->cn[2] = col2;
        v->cn[3] = a;
        v->tc[0] = w << 6;
        v->tc[1] = h << 6;
        v++;
        v->ob[0] = x2 + pos[0];
        v->ob[1] = y1 + pos[1];
        v->ob[2] = bpp + pos[2];
        v->tc[0] = 0;
        v->tc[1] = h << 6;
        v->cn[0] = col0;
        v->cn[1] = col1;
        v->cn[2] = col2;
        v->cn[3] = a;
        v++;
        G(0x01004008, (u32)(v - 4));
        G(0x07000204, 0x406);
        func_8001EB18(4);
        p++;
    }
    func_80029F8C(-1);
}


