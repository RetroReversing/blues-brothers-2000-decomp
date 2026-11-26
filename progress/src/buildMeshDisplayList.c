typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx;

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((1 << (w)) - 1)) << (s)))
#define __gsSP1Triangle_w1(v0, v1, v2) \
    (_SHIFTL((v0) * 2, 16, 8) | _SHIFTL((v1) * 2, 8, 8) | _SHIFTL((v2) * 2, 0, 8))
#define __gsSP1Triangle_w1f(v0, v1, v2, flag) \
    (((flag) == 0) ? __gsSP1Triangle_w1(v0, v1, v2) : \
     ((flag) == 1) ? __gsSP1Triangle_w1(v1, v2, v0) : __gsSP1Triangle_w1(v2, v0, v1))
#define __gsSP1Quadrangle_w1f(v0, v1, v2, v3, flag) \
    (((flag) == 0) ? __gsSP1Triangle_w1(v0, v1, v2) : \
     ((flag) == 1) ? __gsSP1Triangle_w1(v1, v2, v3) : \
     ((flag) == 2) ? __gsSP1Triangle_w1(v2, v3, v0) : __gsSP1Triangle_w1(v3, v0, v1))
#define __gsSP1Quadrangle_w2f(v0, v1, v2, v3, flag) \
    (((flag) == 0) ? __gsSP1Triangle_w1(v0, v2, v3) : \
     ((flag) == 1) ? __gsSP1Triangle_w1(v1, v3, v0) : \
     ((flag) == 2) ? __gsSP1Triangle_w1(v2, v0, v1) : __gsSP1Triangle_w1(v3, v1, v2))
#define gSPVertex(pkt, v, n, v0) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->w0 = _SHIFTL(0x01, 24, 8) | _SHIFTL((n), 12, 8) | _SHIFTL((v0) + (n), 1, 7); \
    _g->w1 = (u32)(v); }
#define gSP1Triangle(pkt, v0, v1, v2, flag) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->w0 = _SHIFTL(0x05, 24, 8) | __gsSP1Triangle_w1f(v0, v1, v2, flag); \
    _g->w1 = 0; }
#define gSP1Quadrangle(pkt, v0, v1, v2, v3, flag) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->w0 = (_SHIFTL(0x07, 24, 8) | __gsSP1Quadrangle_w1f(v0, v1, v2, v3, flag)); \
    _g->w1 = __gsSP1Quadrangle_w2f(v0, v1, v2, v3, flag); }
#define gSPEndDisplayList(pkt) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->w0 = _SHIFTL(0xDF, 24, 8); \
    _g->w1 = 0; }

/* Turns a compact mesh command stream into RDP display list commands. Opcodes:
   0x7013 load n vertices, 0x7003 triangle, 0x7004 quad, 0x7012 skip one word,
   0x7000 end. Loaded vertices get the stream's alpha. Returns the next free
   display list slot. */
/* Turns a compact mesh command stream into RDP display list commands. Opcodes: 0x7013 load n vertices, 0x7003 triangle, 0x7004 quad, 0x7012 skip one word, 0x7000 end. Loaded vertices get alpha 0x80. Returns the next free display list slot. */ Gfx *buildMeshDisplayList(s16 *cmdStream, Vtx *vtxBuf, Gfx *dl) {
    u8 vtxAlpha = 0x80;
    s32 vtxCount = 0;
    s32 vtxN, i;
    s32 idx0, idx1, idx2, idx3;

    for (;;) {
        switch (*cmdStream++) {
            case 0x7013:
                vtxN = *cmdStream++;
                gSPVertex(dl++, &vtxBuf[vtxCount], vtxN, 0);
                for (i = 0; i < vtxN; i++) {
                    vtxBuf[vtxCount + i].cn[3] = vtxAlpha;
                }
                vtxCount += vtxN;
                break;
            case 0x7003:
                idx0 = *cmdStream++;
                idx1 = *cmdStream++;
                idx2 = *cmdStream++;
                gSP1Triangle(dl++, idx0, idx1, idx2, idx0);
                break;
            case 0x7004:
                idx0 = *cmdStream++;
                idx1 = *cmdStream++;
                idx2 = *cmdStream++;
                idx3 = *cmdStream++;
                gSP1Quadrangle(dl++, idx0, idx1, idx2, idx3, idx0);
                break;
            case 0x7012:
                cmdStream++;
                break;
            case 0x7000:
                gSPEndDisplayList(dl++);
                return dl;
        }
    }
}
