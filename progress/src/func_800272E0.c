typedef struct GfxW {
    u32 w0;
    u32 w1;
} GfxW;

typedef struct {
    s32 w;
    s32 h;
    s32 fmt;
    s32 pad;
    u8 data[1];
} Img;

void func_80029F8C(s32);
void func_800226A0(s32);
void func_800226E4(void);
s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_8002220C(s32);

extern GfxW *D_80177E18;

#define GFX(a, b) { GfxW *_g = D_80177E18++; _g->w0 = (a); _g->w1 = (b); }
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define TXL2WORDS(txls, b_txl) MAX(1, ((txls) * (b_txl) / 8))
#define CALC_DXT(width, b_txl) (((1 << 11) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))

s32 func_800272E0(Img *img, s32 x, s32 y, s32 flags)
{
    s32 w;
    s32 h;
    s32 off;
    s32 rows;
    s32 sx;
    s32 sy;
    s32 fmt;
    u8 *data;
    s32 iw;
    s32 ih;

    sx = 1;
    sy = 1;
    if (img == NULL) {
        return 0;
    }
    iw = img->w;
    ih = img->h;
    if (flags & 2) {
        x -= iw / 2;
    }
    if (flags & 4) {
        y -= ih / 2;
    }
    h = ih;
    data = img->data;
    w = iw;
    fmt = img->fmt;
    func_800226A0(flags);
    func_8002220C(func_800221C0(0, 0, sx, 2, 0, 0, sx, sx));
    GFX(0xFC30B261, 0xFF67FFFF);
    GFX(0xE200001C, 0x504A50);
    func_80029F8C(0x59);
    off = 0;
    switch (fmt) {
    case 16:
        while (h > 0) {
            rows = h;
            if (w * h > 0x800) {
                rows = 0x800 / w;
            }
            { u8 *p; do { p = data; } while (0); GFX(0xFD100000, (u32)(p + off)); }
            GFX(0xF5100000, 0x07080200);
            GFX(0xE6000000, 0);
            GFX(0xF3000000, 0x07000000 | ((MIN(w * rows - 1, 0x7FF) & 0xFFF) << 12) | (CALC_DXT(w, 2) & 0xFFF));
            GFX(0xE7000000, 0);
            GFX(0xF5100000 | (((((w * 2) + 7) >> 3) & 0x1FF) << 9), 0x80200);
            GFX(0xF2000000, ((((w - 1) << 2) & 0xFFF) << 12) | (((rows - 1) << 2) & 0xFFF));
            GFX(0xE4000000 | ((((x + sx * w / sy) << 2) & 0xFFF) << 12) | (((y + sx * rows) << 2) & 0xFFF),
                (((x << 2) & 0xFFF) << 12) | ((y << 2) & 0xFFF));
            GFX(0xE1000000, 0);
            GFX(0xF1000000, ((sx << 10) << 16) | (sy << 10));
            h -= rows;
            off += w * (rows << 1);
            y += sx * rows;
        }
        break;
    case 32:
        while (h > 0) {
            rows = h;
            if (w * h > 0x400) {
                rows = 0x400 / w;
            }
            GFX(0xFD180000, (u32)(data + off));
            GFX(0xF5180000, 0x07080200);
            GFX(0xE6000000, 0);
            GFX(0xF3000000, 0x07000000 | ((MIN(w * rows - 1, 0x7FF) & 0xFFF) << 12) | (CALC_DXT(w, 4) & 0xFFF));
            GFX(0xE7000000, 0);
            GFX(0xF5180000 | (((((w * 2) + 7) >> 3) & 0x1FF) << 9), 0x80200);
            GFX(0xF2000000, ((((w - 1) << 2) & 0xFFF) << 12) | (((rows - 1) << 2) & 0xFFF));
            GFX(0xE4000000 | ((((x + sx * w / sy) << 2) & 0xFFF) << 12) | (((y + sx * rows) << 2) & 0xFFF),
                (((x << 2) & 0xFFF) << 12) | ((y << 2) & 0xFFF));
            GFX(0xE1000000, 0);
            GFX(0xF1000000, ((sx << 10) << 16) | (sy << 10));
            h -= rows;
            off += w * (rows << 2);
            y += sx * rows;
        }
        break;
    }
    GFX(0xE7000000, 0);
    func_800226E4();
    return w;
}
