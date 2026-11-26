typedef struct {
    u32 w0;
    u32 w1;
} GfxWBE18;

#define SHL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define GW(pkt, a, b) { GfxWBE18 *_g = (GfxWBE18 *)(pkt); _g->w0 = (a); _g->w1 = (b); }

void setRenderState(s32);
extern GfxWBE18 *D_80177E18;

/* Queues RDP commands to load a texture (4/8-bit CI with optional palette, 16/32-bit RGBA) and set the render state. */ void loadTexture(s32 bitSize, void *texImage, void *palette) {
    s32 maskBits;
    s32 clampMode;

    maskBits = 5;
    clampMode = 0;
    if (bitSize == 4) {
        GW(D_80177E18++, 0xFD500000, (u32)texImage);
        GW(D_80177E18++, 0xF5500000, 0x07014050);
        GW(D_80177E18++, 0xE6000000, 0);
        GW(D_80177E18++, 0xF3000000, 0x070FF400);
        GW(D_80177E18++, 0xE7000000, 0);
        GW(D_80177E18++, 0xF5400400, 0x00014050);
        GW(D_80177E18++, 0xF2000000, 0x0007C07C);
        GW(D_80177E18++, 0xFD100000, (u32)palette);
        GW(D_80177E18++, 0xE8000000, 0);
        GW(D_80177E18++, 0xF5000100, 0x07000000);
        GW(D_80177E18++, 0xE6000000, 0);
        GW(D_80177E18++, 0xF0000000, 0x0703C000);
        GW(D_80177E18++, 0xE7000000, 0);
        setRenderState(0x60);
    }
    if (bitSize == 8) {
        if (palette != NULL) {
            GW(D_80177E18++, 0xFD500000, (u32)texImage);
            GW(D_80177E18++, 0xF5500000, 0x07014050);
            GW(D_80177E18++, 0xE6000000, 0);
            GW(D_80177E18++, 0xF3000000, 0x071FF200);
            GW(D_80177E18++, 0xE7000000, 0);
            GW(D_80177E18++, 0xF5480800, 0x00014050);
            GW(D_80177E18++, 0xF2000000, 0x0007C07C);
            GW(D_80177E18++, 0xFD100000, (u32)palette);
            GW(D_80177E18++, 0xE8000000, 0);
            GW(D_80177E18++, 0xF5000100, 0x07000000);
            GW(D_80177E18++, 0xE6000000, 0);
            GW(D_80177E18++, 0xF0000000, 0x073FC000);
            GW(D_80177E18++, 0xE7000000, 0);
            setRenderState(0x60);
        } else {
            GW(D_80177E18++, 0xFD900000, (u32)texImage);
            GW(D_80177E18++, 0xF5900000, 0x07014050);
            GW(D_80177E18++, 0xE6000000, 0);
            GW(D_80177E18++, 0xF3000000, 0x077FF100);
            GW(D_80177E18++, 0xE7000000, 0);
            GW(D_80177E18++, 0xF5881000, 0x00014050);
            GW(D_80177E18++, 0xF2000000, 0x000FC0FC);
            setRenderState(0x50);
        }
    }
    if (bitSize == 16) {
        GW(D_80177E18++, 0xFD100000, (u32)texImage);
        GW(D_80177E18++, 0xF5100000, SHL(7, 24, 3) | SHL(0, 20, 4) | SHL(clampMode, 18, 2) | SHL(maskBits, 14, 4) | SHL(0, 10, 4) | SHL(clampMode, 8, 2) | SHL(maskBits, 4, 4) | SHL(0, 0, 4));
        GW(D_80177E18++, 0xE6000000, 0);
        GW(D_80177E18++, 0xF3000000, 0x073FF100);
        GW(D_80177E18++, 0xE7000000, 0);
        GW(D_80177E18++, 0xF5101000, SHL(clampMode, 18, 2) | SHL(maskBits, 14, 4) | SHL(clampMode, 8, 2) | SHL(maskBits, 4, 4));
        GW(D_80177E18++, 0xF2000000, 0x0007C07C);
        setRenderState(0x50);
    }
    if (bitSize == 32) {
        GW(D_80177E18++, 0xFD180000, (u32)texImage);
        GW(D_80177E18++, 0xF5180000, SHL(7, 24, 3) | SHL(0, 20, 4) | SHL(clampMode, 18, 2) | SHL(maskBits, 14, 4) | SHL(0, 10, 4) | SHL(clampMode, 8, 2) | SHL(maskBits, 4, 4) | SHL(0, 0, 4));
        GW(D_80177E18++, 0xE6000000, 0);
        GW(D_80177E18++, 0xF3000000, 0x073FF080);
        GW(D_80177E18++, 0xE7000000, 0);
        GW(D_80177E18++, 0xF5181000, SHL(clampMode, 18, 2) | SHL(maskBits, 14, 4) | SHL(clampMode, 8, 2) | SHL(maskBits, 4, 4));
        GW(D_80177E18++, 0xF2000000, 0x0007C07C);
        setRenderState(0x50);
    }
}
