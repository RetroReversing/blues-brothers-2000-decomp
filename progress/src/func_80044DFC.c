typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 fmt;
    u8 pad1;
    u8 ws;
    u8 ts;
    u8 npal;
} TexHeader;

typedef struct {
    s32 unk0;
    TexHeader *tex;
    s32 unk8;
} TexEntry;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 index;
} TexRef;

Gfx *func_800455C0(Gfx *gfx);

#define G(gfx, a, b) { Gfx *_g = (gfx)++; _g->w0 = (a); _g->w1 = (b); }
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define TXL2WORDS(txls, b_txl) MAX(1, ((txls) * (b_txl) / 8))
#define CALC_DXT(width, b_txl) (((1 << 11) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))

Gfx *func_80044DFC(Gfx *gfx, TexRef *ref, TexEntry *table) {
    TexEntry *entry;
    TexHeader *hdr;
    u8 *img;
    u8 *pal;
    s32 ws;
    s32 ts;
    s32 npal;
    s32 width;
    s32 height;
    s32 lrs;
    s32 cms;
    s32 cmt;

    cmt = cms = 0;
    entry = (TexEntry *)(ref->index * sizeof(TexEntry) + (u32)table);
    img = (u8 *)entry->tex;
    G(gfx, 0xE7000000, 0);
    hdr = entry->tex;
    img += 8;
    npal = hdr->npal + 1;
    width = 1 << hdr->ws;
    height = 1 << hdr->ts;
    ws = hdr->ws;
    ts = hdr->ts;
    switch (hdr->fmt) {
    case 1:
        pal = img;
        npal += 3;
        npal &= 0xFFFC;
        img += npal * 2;
        G(gfx, 0xFD500000, (u32)img);
        G(gfx, 0xF5500000, 0x07000000 | ((cmt & 3) << 18) | ((ts & 0xF) << 14) | ((cms & 3) << 8) | ((ws & 0xF) << 4));
        G(gfx, 0xE6000000, 0);
        G(gfx, 0xF3000000, 0x07000000 | ((((((width * height + 3) >> 2) - 1) < 0x800 ? (((width * height + 3) >> 2) - 1) : 0x7FF) & 0xFFF) << 12) | (CALC_DXT(width, 0) & 0xFFF));
        G(gfx, 0xE7000000, 0);
        G(gfx, 0xF5400000, ((cmt & 3) << 18) | ((ts & 0xF) << 14) | ((cms & 3) << 8) | ((ws & 0xF) << 4));
        G(gfx, 0xFD100000, (u32)pal);
        G(gfx, 0xE8000000, 0);
        G(gfx, 0xF5000100, 0x07000000);
        G(gfx, 0xE6000000, 0);
        G(gfx, 0xF0000000, 0x0703C000);
        G(gfx, 0xE7000000, 0);
        G(gfx, 0xE3001001, 0x8000);
        break;
    case 3:
        pal = img;
        npal += 3;
        npal &= 0xFFFC;
        img += npal * 2;
        G(gfx, 0xFD500000, (u32)img);
        G(gfx, 0xF5500000, 0x07000000 | ((cmt & 3) << 18) | ((ts & 0xF) << 14) | ((cms & 3) << 8) | ((ws & 0xF) << 4));
        G(gfx, 0xE6000000, 0);
        G(gfx, 0xF3000000, 0x07000000 | ((((((width * height + 1) >> 1) - 1) < 0x800 ? (((width * height + 1) >> 1) - 1) : 0x7FF) & 0xFFF) << 12) | (CALC_DXT(width, 1) & 0xFFF));
        G(gfx, 0xE7000000, 0);
        G(gfx, 0xF5480000 | ((((width * 1 + 7) >> 3) & 0x1FF) << 9), ((cmt & 3) << 18) | ((ts & 0xF) << 14) | ((cms & 3) << 8) | ((ws & 0xF) << 4));
        G(gfx, 0xFD100000, (u32)pal);
        G(gfx, 0xE8000000, 0);
        G(gfx, 0xF5000100, 0x07000000);
        G(gfx, 0xE6000000, 0);
        G(gfx, 0xF0000000, 0x073FC000);
        G(gfx, 0xE7000000, 0);
        G(gfx, 0xE3001001, 0x8000);
        break;
    case 4:
        G(gfx, 0xFD100000, (u32)img);
        G(gfx, 0xF5100000, 0x07000000 | ((cmt & 3) << 18) | ((ts & 0xF) << 14) | ((cms & 3) << 8) | ((ws & 0xF) << 4));
        G(gfx, 0xE6000000, 0);
        G(gfx, 0xF3000000, 0x07000000 | ((((width * height - 1) < 0x800 ? (width * height - 1) : 0x7FF) & 0xFFF) << 12) | (CALC_DXT(width, 2) & 0xFFF));
        G(gfx, 0xE7000000, 0);
        G(gfx, 0xF5100000 | ((((width * 2 + 7) >> 3) & 0x1FF) << 9), ((cmt & 3) << 18) | ((ts & 0xF) << 14) | ((cms & 3) << 8) | ((ws & 0xF) << 4));
        G(gfx, 0xE3001001, 0);
        break;
    case 5:
        G(gfx, 0xFD180000, (u32)img);
        G(gfx, 0xF5180000, 0x07000000 | ((cmt & 3) << 18) | ((ts & 0xF) << 14) | ((cms & 3) << 8) | ((ws & 0xF) << 4));
        G(gfx, 0xE6000000, 0);
        G(gfx, 0xF3000000, 0x07000000 | ((((width * height - 1) < 0x800 ? (width * height - 1) : 0x7FF) & 0xFFF) << 12) | (CALC_DXT(width, 4) & 0xFFF));
        G(gfx, 0xE7000000, 0);
        G(gfx, 0xF5180000 | ((((width * 2 + 7) >> 3) & 0x1FF) << 9), ((cmt & 3) << 18) | ((ts & 0xF) << 14) | ((cms & 3) << 8) | ((ws & 0xF) << 4));
        G(gfx, 0xE3001001, 0);
        break;
    case 2:
    case 6:
    case 7:
        break;
    }
    return func_800455C0(gfx);
}
