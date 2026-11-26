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

/* Draws a width x height image as RDP texture tiles in strips of up to 0x1000 pixels, at (posX, posY). */ s32 drawImageTiles(u8 *pixels, s32 w_in, s32 height, s32 posX, s32 posY, s32 renderMode) {
  s32 w;
    s32 pixelOffset;
    s32 stripRows;
    s32 scaleX;
    s32 scaleY;
  w = w_in;

    scaleX = 1;
    scaleY = 1;
    func_800226A0(renderMode);
    setDrawMode(packDrawFlags(0, 0, scaleX, 2, 0, 0, scaleX, scaleX));
    GFX(0xFC30B261, 0xFF67FFFF);
    GFX(0xE200001C, 0x504A50);
    setRenderState(0x59);
    pixelOffset = 0;
    while (height > 0) {
        stripRows = height;
        if (w * height > 0x1000) {
            stripRows = 0x1000 / w;
        }
        GFX(0xFD900000, (u32)(pixels + pixelOffset));
        GFX(0xF5900000, 0x07080200);
        GFX(0xE6000000, 0);
        GFX(0xF3000000, 0x07000000 | ((MIN(((w * stripRows + 1) >> 1) - 1, 0x7FF) & 0xFFF) << 12) | (CALC_DXT(w, 1) & 0xFFF));
        GFX(0xE7000000, 0);
        GFX(0xF5880000 | (((((w * 1) + 7) >> 3) & 0x1FF) << 9), 0x80200);
        GFX(0xF2000000, ((((w - 1) << 2) & 0xFFF) << 12) | (((stripRows - 1) << 2) & 0xFFF));
        GFX(0xE4000000 | ((((posX + scaleX * w / scaleY) << 2) & 0xFFF) << 12) | (((posY + scaleX * stripRows) << 2) & 0xFFF),
            (((posX << 2) & 0xFFF) << 12) | ((posY << 2) & 0xFFF));
        GFX(0xE1000000, 0);
        GFX(0xF1000000, ((scaleX << 10) << 16) | (scaleY << 10));
        height -= stripRows;
        pixelOffset += w * stripRows;
        posY += scaleX * stripRows;
    }
    GFX(0xE7000000, 0);
    func_800226E4();
    return w;
}

