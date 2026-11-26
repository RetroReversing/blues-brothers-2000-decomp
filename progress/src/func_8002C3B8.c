typedef struct {
    u32 w0;
    u32 w1;
} GfxW;

typedef struct {
    s32 width;
    s32 height;
    s32 type;
    s32 pad;
    u8 data[1];
} TexHeader;

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define GW(pkt, a, b) { GfxW *_g = (GfxW *)(pkt); _g->w0 = (a); _g->w1 = (b); }

#define G_TX_DXT_FRAC 11
#define G_TX_LDBLK_MAX_TXL 2047
#define TXL2WORDS(txls, b_txl) MAX(1, ((txls) * (b_txl) / 8))
#define CALC_DXT(width, b_txl) (((1 << G_TX_DXT_FRAC) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))
#define TXL2WORDS_4b(txls) MAX(1, ((txls) / 16))
#define CALC_DXT_4b(width) (((1 << G_TX_DXT_FRAC) + TXL2WORDS_4b(width) - 1) / TXL2WORDS_4b(width))

#define SetTimg(pkt, fmt, siz, img) GW(pkt, 0xFD000000 | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2), (u32)(img))
#define SetTile(pkt, fmt, siz, line, tmem, tile, pal, cmt, maskt, shiftt, cms, masks, shifts) \
    GW(pkt, 0xF5000000 | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL(line, 9, 9) | _SHIFTL(tmem, 0, 9), \
       _SHIFTL(tile, 24, 3) | _SHIFTL(pal, 20, 4) | _SHIFTL(cmt, 18, 2) | _SHIFTL(maskt, 14, 4) | _SHIFTL(shiftt, 10, 4) \
       | _SHIFTL(cms, 8, 2) | _SHIFTL(masks, 4, 4) | _SHIFTL(shifts, 0, 4))
#define LoadSync(pkt) GW(pkt, 0xE6000000, 0)
#define PipeSync(pkt) GW(pkt, 0xE7000000, 0)
#define TileSync(pkt) GW(pkt, 0xE8000000, 0)
#define LoadBlock(pkt, tile, uls, ult, lrs, dxt) \
    GW(pkt, 0xF3000000 | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12), \
       _SHIFTL(tile, 24, 3) | _SHIFTL(MIN(lrs, G_TX_LDBLK_MAX_TXL), 12, 12) | _SHIFTL(dxt, 0, 12))
#define SetTileSize(pkt, t, uls, ult, lrs, lrt) \
    GW(pkt, 0xF2000000 | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12), \
       _SHIFTL(t, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12))
#define LoadTLUTCmd(pkt, tile, count) GW(pkt, 0xF0000000, _SHIFTL(tile, 24, 3) | _SHIFTL(count, 14, 10))

#define LTB_A(pkt, timg, fmt, siz, lsiz, incr, shift, bytes, linebytes, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt) \
{ \
    SetTimg(pkt, fmt, lsiz, timg); \
    { s32 _z = 0; SetTile(pkt, fmt, lsiz, 0, 0, 7, 0, cmt, _z, _z, cms, _z, _z); } \
    LoadSync(pkt); \
    LoadBlock(pkt, 7, 0, 0, ((((width) * (height)) + incr) >> shift) - 1, CALC_DXT(width, bytes)); \
} \

#define LTB_B(pkt, timg, fmt, siz, lsiz, incr, shift, bytes, linebytes, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt) \
{ \
    PipeSync(pkt); \
    SetTile(pkt, fmt, siz, ((((width) * linebytes) + 7) >> 3), 0, 0, pal, cmt, maskt, shiftt, cms, masks, shifts); \
    SetTileSize(pkt, 0, 0, 0, ((width) - 1) << 2, ((height) - 1) << 2); \
}

#define LTB4_A(pkt, timg, fmt, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt) \
{ \
    SetTimg(pkt, fmt, 2, timg); \
    SetTile(pkt, fmt, 2, 0, 0, 7, 0, cmt, 0, 0, cms, 0, 0); \
    LoadSync(pkt); \
    LoadBlock(pkt, 7, 0, 0, ((((width) * (height)) + 3) >> 2) - 1, CALC_DXT_4b(width)); \
} \

#define LTB4_B(pkt, timg, fmt, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt) \
{ \
    PipeSync(pkt); \
    SetTile(pkt, fmt, 0, ((((width) >> 1) + 7) >> 3), 0, 0, pal, cmt, maskt, shiftt, cms, masks, shifts); \
    SetTileSize(pkt, 0, 0, 0, ((width) - 1) << 2, ((height) - 1) << 2); \
}

#define LoadTLUT(pkt, dram, count) \
{ \
    SetTimg(pkt, 0, 2, dram); \
    TileSync(pkt); \
    SetTile(pkt, 0, 0, 0, 256, 7, 0, 0, 0, 0, 0, 0, 0); \
    LoadSync(pkt); \
    LoadTLUTCmd(pkt, 7, count); \
    PipeSync(pkt); \
}

void setRenderState(s32);
extern GfxW *D_80177E18;

void func_8002C3B8(TexHeader *tex) {
    s32 width;
    s32 height;
    s32 type;
    void *img;
    void *pal;
    s32 mask;
    s32 cm;

    img = tex->data;
    pal = img;
    mask = 0;
    cm = 2;
    width = tex->width;
    type = tex->type;
    height = tex->height;
    if (type == 4) { LTB4_A(D_80177E18++, img, 2, width, height, 0, cm, cm, mask, mask, 0, 0); LTB4_B(D_80177E18++, img, 2, width, height, 0, cm, cm, mask, mask, 0, 0); LoadTLUT(D_80177E18++, pal, 15); setRenderState(0x60); }
    if (type == 8) { do { if (pal != NULL) { LTB_A(D_80177E18++, img, 2, 1, 2, 1, 1, 1, 1, width, height, 0, cm, cm, mask, mask, 0, 0); do { LTB_B(D_80177E18++, img, 2, 1, 2, 1, 1, 1, 1, width, height, 0, cm, cm, mask, mask, 0, 0); LoadTLUT(D_80177E18++, pal, 255); setRenderState(0x60); } while (0); } else { LTB_A(D_80177E18++, img, 4, 1, 2, 1, 1, 1, 1, width, height, 0, cm, cm, mask, mask, 0, 0); LTB_B(D_80177E18++, img, 4, 1, 2, 1, 1, 1, 1, width, height, 0, cm, cm, mask, mask, 0, 0); setRenderState(0x50); } } while (0); }
    if (type == 16) { LTB_A(D_80177E18++, img, 0, 2, 2, 0, 0, 2, 2, width, height, 0, cm, cm, mask, mask, 0, 0); LTB_B(D_80177E18++, img, 0, 2, 2, 0, 0, 2, 2, width, height, 0, cm, cm, mask, mask, 0, 0); setRenderState(0x50); }
    if (type == 32) { LTB_A(D_80177E18++, img, 0, 3, 3, 0, 0, 4, 2, width, height, 0, cm, cm, mask, mask, 0, 0); LTB_B(D_80177E18++, img, 0, 3, 3, 0, 0, 4, 2, width, height, 0, cm, cm, mask, mask, 0, 0); setRenderState(0x50); }
}
