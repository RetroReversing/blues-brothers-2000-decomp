typedef struct {
    u32 w0;
    u32 w1;
} GfxWords;

typedef union {
    GfxWords words;
    long long force_structure_alignment;
} Gfx;

typedef struct {
    s32 width;
    s32 height;
    s32 bpp;
    s32 pad;
    u8 pixels[1];
} Image;

extern Gfx *D_80177E18;
extern s32 D_80107890;

void func_800226A0(s32);
void func_8002220C(s32);
s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_80029F8C(s32);
void func_800226E4(void);

#define G(a, b) { Gfx *_g = (Gfx *)(D_80177E18++); _g->words.w0 = (a); _g->words.w1 = (b); }
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define TXL2WORDS(txls, b_txl) MAX(1, ((txls) * (b_txl) / 8))
#define CALC_DXT(width, b_txl) (((1 << 11) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))

s32 func_80029738(Image *img, s32 x0, s32 y0, s32 x1, s32 y1) {
    s32 h;
    s32 texw;
    s32 rows;
    s32 texh;
    s32 bpp;
    u8 *pixels;
    s32 dsdx;
    s32 top;
    s32 dtdy;
    s32 offset;
    s32 n;
    s32 strip;
    s32 yscale;
    s32 w;
    s32 hh;

    w = x1 - x0 + 1;
    top = y1 - y0;
    texh = top + 1;
    if (w < 3 || texh < 3) {
        return;
    }
    bpp = img->bpp;
    w = img->width;
    (void)&dsdx;
    dsdx = (w << 10) / (x1 - x0 + 1);
    h = texh;
    texh = img->height;
    dtdy = (w << 10) / h;
    pixels = img->pixels;
    rows = texh;
    texw = w;
    yscale = 1;
    func_800226A0(0);
    func_8002220C(func_800221C0(0, 0, 1, 2, 0, 0, 1, 1));
    G(0xFC30B261, 0xFF67FFFF);
    G(0xE200001C, 0x00504A50);
    func_80029F8C(0x5B);
    offset = 0;
    
    D_80107890 = (y0 << 2);
    switch (bpp) {
    case 16:
        while (rows > 0) {
            n = rows;
            if (texw * rows > 0x800) {
                n = 0x800 / texw;
            }
            G(0xFD100000, (u32)(pixels + offset));
            G(0xF5100000, 0x07080200);
            G(0xE6000000, 0);
            G(0xF3000000, 0x07000000 | (((top = ((texw * n - 1) < 0x800 ? (texw * n - 1) : 0x7FF)) & 0xFFF) << 12) | (CALC_DXT(texw, 2) & 0xFFF));
            G(0xE7000000, 0);
            G(0xF5100000 | ((((texw * 2 + 7) >> 3) & 0x1FF) << 9), 0x00080200);
            G(0xF2000000, ((((texw - 1) << 2) & 0xFFF) << 12) | (((n - 1) << 2) & 0xFFF));
            G(0xE4000000 | (((x1 << 2) & 0xFFF) << 12) | ((y1 << 2) & 0xFFF), (((x0 << 2) & 0xFFF) << 12) | ((y0 << 2) & 0xFFF));
            G(0xE1000000, 0);
            G(0xF1000000, (dsdx << 16) | (dtdy & 0xFFFF));
            rows -= n;
            offset += texw * (n << 1);
            D_80107890 += yscale * n;
        }
        break;
    case 32:
        while (rows >= 2) {
            hh = h << 2;
            n = rows;
            if (texw * rows > 0x200) {
                n = 0x200 / texw;
                strip = (n * hh) / texh;
            }
            G(0xFD180000, (u32)(pixels + offset));
            G(0xF5180000, 0x07080200);
            G(0xE6000000, 0);
            G(0xF3000000, 0x07000000 | ((((texw * n - 1) < 0x800 ? (texw * n - 1) : 0x7FF) & 0xFFF) << 12) | (CALC_DXT(texw, 4) & 0xFFF));
            offset += texw * ((n - 1) << 2);
            rows -= n - 1;
            n--;
            dtdy = (n << 12) / strip;
            G(0xE7000000, 0);
            G(0xF5180000 | ((((texw * 2 + 7) >> 3) & 0x1FF) << 9), 0x00080200);
            G(0xF2000000, ((((texw - 1) << 2) & 0xFFF) << 12) | ((n << 2) & 0xFFF));
            G(0xE4000000 | (((x1 << 2) & 0xFFF) << 12) | ((D_80107890 + strip) & 0xFFF), (((x0 << 2) & 0xFFF) << 12) | (D_80107890 & 0xFFF));
            G(0xE1000000, 0);
            G(0xF1000000, (dsdx << 16) | (dtdy & 0xFFFF));
            D_80107890 += strip;
        }
        break;
    }
    G(0xE7000000, 0);
    func_800226E4();
    return texw;
}
