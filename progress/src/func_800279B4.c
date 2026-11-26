typedef struct GfxW {
    u32 w0;
    u32 w1;
} GfxW;

void func_800226A0(s32);
void func_800226E4(void);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void setDrawMode(s32);
void setRenderState(s32);

extern GfxW *D_80177E18;

#define GFX(a, b) { GfxW *_g = D_80177E18++; _g->w0 = (a); _g->w1 = (b); }
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define TXL2WORDS(txls, b_txl) MAX(1, ((txls) * (b_txl) / 8))
#define CALC_DXT(width, b_txl) (((1 << 11) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))

s32 func_800279B4(u8 *img, s32 w_in, s32 h, s32 x, s32 y, s32 arg5) {
  s32 w;
    s32 off;
    s32 rows;
    s32 sx;
    s32 sy;
  w = w_in;

    sx = 1;
    sy = 1;
    func_800226A0(arg5);
    setDrawMode(packDrawFlags(0, 0, sx, 2, 0, 0, sx, sx));
    GFX(0xFC30B261, 0xFF67FFFF);
    GFX(0xE200001C, 0x504A50);
    setRenderState(0x59);
    off = 0;
    while (h > 0) {
        rows = h;
        if (w * h > 0x1000) {
            rows = 0x1000 / w;
        }
        GFX(0xFD900000, (u32)(img + off));
        GFX(0xF5900000, 0x07080200);
        GFX(0xE6000000, 0);
        GFX(0xF3000000, 0x07000000 | ((MIN(((w * rows + 1) >> 1) - 1, 0x7FF) & 0xFFF) << 12) | (CALC_DXT(w, 1) & 0xFFF));
        GFX(0xE7000000, 0);
        GFX(0xF5880000 | (((((w * 1) + 7) >> 3) & 0x1FF) << 9), 0x80200);
        GFX(0xF2000000, ((((w - 1) << 2) & 0xFFF) << 12) | (((rows - 1) << 2) & 0xFFF));
        GFX(0xE4000000 | ((((x + sx * w / sy) << 2) & 0xFFF) << 12) | (((y + sx * rows) << 2) & 0xFFF),
            (((x << 2) & 0xFFF) << 12) | ((y << 2) & 0xFFF));
        GFX(0xE1000000, 0);
        GFX(0xF1000000, ((sx << 10) << 16) | (sy << 10));
        h -= rows;
        off += w * rows;
        y += sx * rows;
    }
    GFX(0xE7000000, 0);
    func_800226E4();
    return w;
}

