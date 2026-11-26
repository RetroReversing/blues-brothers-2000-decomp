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

Gfx *buildMeshDisplayList(s16 *cmd, Vtx *vtx, Gfx *gfx) {
    u8 alpha = 0x80;
    s32 count = 0;
    s32 n, i;
    s32 a, b, c, d;

    for (;;) {
        switch (*cmd++) {
            case 0x7013:
                n = *cmd++;
                gSPVertex(gfx++, &vtx[count], n, 0);
                for (i = 0; i < n; i++) {
                    vtx[count + i].cn[3] = alpha;
                }
                count += n;
                break;
            case 0x7003:
                a = *cmd++;
                b = *cmd++;
                c = *cmd++;
                gSP1Triangle(gfx++, a, b, c, a);
                break;
            case 0x7004:
                a = *cmd++;
                b = *cmd++;
                c = *cmd++;
                d = *cmd++;
                gSP1Quadrangle(gfx++, a, b, c, d, a);
                break;
            case 0x7012:
                cmd++;
                break;
            case 0x7000:
                gSPEndDisplayList(gfx++);
                return gfx;
        }
    }
}
