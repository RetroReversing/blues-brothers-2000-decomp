typedef struct {
    u32 w0;
    u32 w1;
} GfxW914C;

typedef struct {
    s16 vscale[4];
    s16 vtrans[4];
} Vp914C;

#define SHL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define GW(pkt, a, b) { GfxW914C *_g = (GfxW914C *)(pkt); _g->w0 = (a); _g->w1 = (b); }
#define gMoveWd(pkt, index, offset, data) GW(pkt, SHL(0xDB, 24, 8) | SHL(offset, 0, 16) | SHL(index, 16, 8), (u32)(data))
#define gSPSegment(pkt, seg, base) gMoveWd(pkt, 0x06, (seg) * 4, base)
#define gSPViewport(pkt, v) GW(pkt, SHL(0xDC, 24, 8) | SHL((sizeof(Vp914C) - 1) / 8, 19, 5) | SHL(0, 8, 8) | SHL(8, 0, 8), (u32)(v))
#define gSPDisplayList(pkt, dl) GW(pkt, SHL(0xDE, 24, 8) | SHL(0, 16, 8) | SHL(0, 0, 16), (u32)(dl))
#define gSPSetOtherMode(pkt, cmd, sft, len, data) GW(pkt, SHL(cmd, 24, 8) | SHL(32 - (sft) - (len), 8, 8) | SHL((len) - 1, 0, 8), (u32)(data))
#define gDPPipelineMode(pkt, mode) gSPSetOtherMode(pkt, 0xE3, 23, 1, mode)
#define gDPSetCycleType(pkt, type) gSPSetOtherMode(pkt, 0xE3, 20, 2, type)
#define gDPSetTextureFilter(pkt, type) gSPSetOtherMode(pkt, 0xE3, 12, 2, type)
#define gSPClipRatio(pkt, r) { gMoveWd(pkt, 0x04, 0x04, (u32)(r) & 0xFFFF); gMoveWd(pkt, 0x04, 0x0C, (u32)(r) & 0xFFFF); gMoveWd(pkt, 0x04, 0x14, (u32)(-(s32)(r)) & 0xFFFF); gMoveWd(pkt, 0x04, 0x1C, (u32)(-(s32)(r)) & 0xFFFF); }
#define gDPSetScissor(pkt, mode, ulx, uly, lrx, lry) GW(pkt, SHL(0xED, 24, 8) | SHL((int)((f32)(ulx) * 4.0f), 12, 12) | SHL((int)((f32)(uly) * 4.0f), 0, 12), SHL(mode, 24, 2) | SHL((int)((f32)(lrx) * 4.0f), 12, 12) | SHL((int)((f32)(lry) * 4.0f), 0, 12))
#define gSPGeometryMode(pkt, c, s) GW(pkt, SHL(0xD9, 24, 8) | SHL(~(u32)(c), 0, 24), (u32)(s))
#define gSPSetGeometryMode(pkt, word) gSPGeometryMode(pkt, 0, word)
#define gSetImage(pkt, cmd, fmt, siz, width, i) GW(pkt, SHL(cmd, 24, 8) | SHL(fmt, 21, 3) | SHL(siz, 19, 2) | SHL((width) - 1, 0, 12), (u32)(i))
#define gDPSetColorImage(pkt, f, s, w, i) gSetImage(pkt, 0xFF, f, s, w, i)
#define gDPSetDepthImage(pkt, i) gSetImage(pkt, 0xFE, 0, 0, 1, i)
#define gDPSetTextureImage(pkt, f, s, w, i) gSetImage(pkt, 0xFD, f, s, w, i)
#define gDPNoParam(pkt, cmd) GW(pkt, SHL(cmd, 24, 8), 0)
#define gDPTileSync(pkt) gDPNoParam(pkt, 0xE8)
#define gDPLoadSync(pkt) gDPNoParam(pkt, 0xE6)
#define gDPPipeSync(pkt) gDPNoParam(pkt, 0xE7)
#define gDPSetTile(pkt, fmt, siz, line, tmem, tile, palette, cmt, maskt, shiftt, cms, masks, shifts) GW(pkt, SHL(0xF5, 24, 8) | SHL(fmt, 21, 3) | SHL(siz, 19, 2) | SHL(line, 9, 9) | SHL(tmem, 0, 9), SHL(tile, 24, 3) | SHL(palette, 20, 4) | SHL(cmt, 18, 2) | SHL(maskt, 14, 4) | SHL(shiftt, 10, 4) | SHL(cms, 8, 2) | SHL(masks, 4, 4) | SHL(shifts, 0, 4))
#define gDPLoadTLUTCmd(pkt, tile, count) GW(pkt, SHL(0xF0, 24, 8), SHL((tile), 24, 3) | SHL((count), 14, 10))
#define gDPLoadTLUT_pal256(pkt, dram) { gDPSetTextureImage(pkt, 0, 2, 1, dram); gDPTileSync(pkt); gDPSetTile(pkt, 0, 0, 0, 256, 7, 0, 0, 0, 0, 0, 0, 0); gDPLoadSync(pkt); gDPLoadTLUTCmd(pkt, 7, 255); gDPPipeSync(pkt); }
#define gDPSetFillColor(pkt, d) GW(pkt, SHL(0xF7, 24, 8), (d))
#define gDPFillRectangle(pkt, ulx, uly, lrx, lry) GW(pkt, SHL(0xF6, 24, 8) | SHL((lrx), 14, 10) | SHL((lry), 2, 10), SHL((ulx), 14, 10) | SHL((uly), 2, 10))
#define GPACK_RGBA5551(r, g, b, a) ((((r) << 8) & 0xf800) | (((g) << 3) & 0x7c0) | (((b) >> 2) & 0x3e) | ((a) & 0x1))
#define GPACK_ZDZ(z, dz) ((z) << 2 | (dz))

void func_8001EBF4(s32);
u32 osVirtualToPhysical(void *);
void func_800479B0(s32);
s32 randomRange(s32, s32);
extern GfxW914C D_800AC2F8[];
extern GfxW914C D_800AC330[];
extern s32 D_800B9C70;
extern s32 gScreenWidth;
extern s32 gScreenHeight;
extern u16 D_800B9C84[];
extern s32 D_800B9EB8;
extern s32 D_800B9EC0;
extern s32 D_800B9ED0;
extern s32 D_800B9ED4;
extern s32 D_800B9ED8;
extern Vp914C D_800B9EE0;
extern Vp914C D_800B9EF0;
extern s32 D_800CD0C8[];
extern GfxW914C *D_800CD0D8[];
extern s32 D_80140228;
extern s32 D_801407C0;
extern s32 D_80176728;
extern s32 D_80176DB0;
extern s32 D_801771C0;
extern GfxW914C *D_80177E18;
extern s32 D_80177E20;
extern GfxW914C D_80177E58[];
extern GfxW914C *D_80178144;
extern s32 D_80178178;
extern s32 D_80178230[];
extern GfxW914C *D_80178238;
extern void *D_80178244;
extern s32 D_80178288;

/* Builds the per-frame RDP display list: viewport, Z and colour buffers, clears, and the letterbox band when partialClear is set. */
void buildFrameDisplayList(s32 partialClear) {
    GfxW914C *gfx;
    s32 frame;
    u32 zBufferAddr;
    s32 one;

    D_80178238 = D_80177E58;
    func_8001EBF4(D_800B9EB8);
    frame = D_800B9EB8;
    D_800B9EB8 = frame ^ 1;
    D_80178144 = D_800CD0D8[frame];
    D_80176728 = D_800CD0C8[frame];
    D_80177E18 = D_80178144;
    gSPSegment(D_80177E18++, 0, 0);
    gSPSegment(D_80177E18++, 1, osVirtualToPhysical(D_80178244));
    D_80177E20 = 1;
    one = 1;
    gDPPipelineMode(D_80177E18++, 0);
    gSPViewport(D_80177E18++, &D_800B9EE0);
    gSPDisplayList(D_80177E18++, D_800AC330);
    gSPDisplayList(D_80177E18++, D_800AC2F8);
    func_800479B0(D_801407C0);
    D_800B9EF0.vtrans[0] = (gScreenWidth << one) + randomRange(-6, 6);
    D_800B9EF0.vtrans[1] = (gScreenHeight << one) + randomRange(-6, 6);
    if (D_80140228 != 0) {
        gSPViewport(D_80177E18++, &D_800B9EF0);
    }
    gSPClipRatio(D_80177E18++, 2);
    gDPSetScissor(D_80177E18++, 0, 0, 0, gScreenWidth, gScreenHeight);
    gSPSetGeometryMode(D_80177E18++, 1);
    gDPSetTextureFilter(D_80177E18++, 0);
    gDPLoadTLUT_pal256(D_80177E18++, D_800B9C84);
    zBufferAddr = 0x200000 - gScreenWidth * gScreenHeight * 2;
    gDPSetDepthImage(D_80177E18++, zBufferAddr);
    gDPSetCycleType(D_80177E18++, 0x300000);
    gDPSetColorImage(D_80177E18++, 0, 2, gScreenWidth, zBufferAddr);
    gDPSetFillColor(D_80177E18++, GPACK_ZDZ(0x3FFF, 0) << 16 | GPACK_ZDZ(0x3FFF, 0));
    gDPFillRectangle(D_80177E18++, 0, 0, gScreenWidth - 1, gScreenHeight - 1);
    gDPPipeSync(D_80177E18++);
    gDPSetCycleType(D_80177E18++, 0x300000);
    gDPSetColorImage(D_80177E18++, 0, 2, gScreenWidth, D_80178230[D_800B9EC0] + 0x80000000);
    D_801771C0 = GPACK_RGBA5551(D_800B9ED0, D_800B9ED8, D_800B9ED4, 1) << 16 | GPACK_RGBA5551(D_800B9ED0, D_800B9ED8, D_800B9ED4, 1);
    gDPSetFillColor(D_80177E18++, D_801771C0);
    if (partialClear == 0) {
        if (D_800B9C70 != 0) {
            gDPFillRectangle(D_80177E18++, 0, 0, gScreenWidth - 1, gScreenHeight - 1);
        }
    } else {
        gDPFillRectangle(D_80177E18++, 20, 10, gScreenWidth - 20, gScreenHeight / 4);
    }
    D_80178178 = 0xFF;
    D_80176DB0 = 0xFF;
    D_80178288 = 0xFF;
    gDPPipeSync(D_80177E18++);
    gDPSetCycleType(D_80177E18++, 0);
}
