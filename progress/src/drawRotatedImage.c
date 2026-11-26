typedef struct GfxW {
    u32 w0;
    u32 w1;
} GfxW;

typedef struct Vtx {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx;

typedef struct Obj {
    char pad0[0x18];
    s32 x18;
    char pad1C[0x28 - 0x1C];
    s32 x28;
    s32 x2C;
    f32 x30;
    s32 x34;
    s32 x38;
    s32 x3C;
    char pad40[0x108 - 0x40];
} Obj;

s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void setDrawMode(s32);
void buildObjectMatrix(Obj *, f32 *, s32);
void func_80024FE8(f32 *);
void setTextColor(s32, s32, s32, s32);
void setRenderState(s32);
s16 sins(u16);
s16 coss(u16);

extern Vtx gImageVtx[];
extern GfxW *D_80177E18;

#define GFX(a, b) { GfxW *_g = D_80177E18++; _g->w0 = (a); _g->w1 = (b); }

/* Draws a full-screen texture (img) as a rotating quad whose rotation and texture
   coordinates depend on zoom. Appends the RDP commands to the display list. */
void drawRotatedImage(u8 *img, s32 zoom) {
    f32 rotMtx[10];
    s32 texS[4];
    s32 texT[4];
    Obj xform;
    s32 i;
    s32 texRadius;
    s32 halfSize;
    s32 texCenter;
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;

    halfSize = 600;
    red = 0xFF;
    green = 0xFF;
    blue = 0xFF;
    alpha = 0xFF;
    setDrawMode(packDrawFlags(0, 0, 1, 2, 0, 0, 1, 1));
    setRenderState(0x5B);
    GFX(0xFCFFFFFF, 0xFFFDF2F9);
    GFX(0xE200001C, 0x504340);
    GFX(0xE2001E01, 1);
    GFX(0xF9000000, 100);
    GFX(0xE3000A01, 0);
    setTextColor(0, 0, 0, 0xFF);
    texCenter = 0x1000;
    GFX(0xFD900000, (u32)img);
    GFX(0xF5900000, 0x07080200);
    GFX(0xE6000000, 0);
    GFX(0xF3000000, 0x077FF100);
    GFX(0xE7000000, 0);
    GFX(0xF5880000 | texCenter, 0x80200);
    GFX(0xF2000000, 0xFC0FC);
    texRadius = zoom * 0xC000 / 320;
    xform.x18 = zoom * 160 + 0xE000;
    for (i = 0; i < 4; i++) {
        texS[i] = ((texRadius * sins(xform.x18 + (i << 14))) >> 15) + texCenter;
        texT[i] = ((texRadius * coss(xform.x18 + (i << 14))) >> 15) + texCenter;
    }
    xform.x28 = 0;
    xform.x2C = 0;
    xform.x34 = 0x100;
    xform.x38 = 0x100;
    xform.x3C = 0x100;
    xform.x30 = 1000.0f;
    func_80024FE8(rotMtx);
    buildObjectMatrix(&xform, rotMtx, 0);
    gImageVtx[0].ob[0] = -halfSize;
    gImageVtx[0].ob[1] = -halfSize;
    gImageVtx[0].ob[2] = 0;
    gImageVtx[0].cn[0] = red;
    gImageVtx[0].cn[1] = green;
    gImageVtx[0].cn[2] = blue;
    gImageVtx[0].cn[3] = alpha;
    gImageVtx[0].tc[0] = texS[0];
    gImageVtx[0].tc[1] = texT[0];
    gImageVtx[1].ob[0] = halfSize;
    gImageVtx[1].ob[1] = -halfSize;
    gImageVtx[1].ob[2] = 0;
    gImageVtx[1].cn[0] = red;
    gImageVtx[1].cn[1] = green;
    gImageVtx[1].cn[2] = blue;
    gImageVtx[1].cn[3] = alpha;
    gImageVtx[1].tc[0] = texS[1];
    gImageVtx[1].tc[1] = texT[1];
    gImageVtx[2].ob[0] = halfSize;
    gImageVtx[2].ob[1] = halfSize;
    gImageVtx[2].ob[2] = 0;
    gImageVtx[2].cn[0] = red;
    gImageVtx[2].cn[1] = green;
    gImageVtx[2].cn[2] = blue;
    gImageVtx[2].cn[3] = alpha;
    gImageVtx[2].tc[0] = texS[2];
    gImageVtx[2].tc[1] = texT[2];
    gImageVtx[3].ob[0] = -halfSize;
    gImageVtx[3].ob[1] = halfSize;
    gImageVtx[3].ob[2] = 0;
    gImageVtx[3].cn[0] = red;
    gImageVtx[3].cn[1] = green;
    gImageVtx[3].cn[2] = blue;
    gImageVtx[3].cn[3] = alpha;
    gImageVtx[3].tc[0] = texS[3];
    gImageVtx[3].tc[1] = texT[3];
    GFX(0x01004008, (u32)gImageVtx);
    GFX(0x07000204, 0x406);
    GFX(0x07000604, 0x402);
}
