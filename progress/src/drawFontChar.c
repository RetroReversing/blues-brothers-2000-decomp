typedef struct { u32 w0, w1; } Gfx;

s32 coss(u16);
s32 sins(u16);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void setDrawMode(s32);
void drawImage(void *, s32, s32, s32);
void setRenderState(s32);
extern u8 gFontTexture[];
extern u8 gFontIconOpen[];
extern u8 gFontIconClose[];
extern u8 gFontIconTilde[];
extern s32 gFontScale;
extern u8 gHighCharToGlyph[];
extern u8 gCharToGlyph[];
extern u8 gGlyphPadding[];
extern union { s32 w; u16 h[2]; } gTextWaveAngle;
extern s32 gTextWaveTime;
extern s32 D_80107650;
extern s32 gTextPenX;
extern s32 gTextPenY;
extern Gfx *D_80177E18;

#define GFX(a, b) { Gfx *_g = D_80177E18++; _g->w0 = (a); _g->w1 = (b); }

/* Draws one font character (or an icon for { ~ }) at the text pen and moves the pen right. */ void drawFontChar(s32 code, s32 isFirst)
{
    u8 rawChar;
    s32 special;
    s32 glyphIndex;
    
    s32 penX4;
    s32 penY;
    s32 step;
    s32 temp;
    u32 tex;

    special = 0;
    gTextWaveAngle.w += 8000;
    if (code == '{') {
        drawImage(gFontIconOpen, gTextPenX, gTextPenY - 2, 0);
        special = 1;
    }
    if (code == '~') {
        drawImage(gFontIconTilde, gTextPenX, gTextPenY - 2, 0);
        special = 1;
    }
    if (code == '}') {
        drawImage(gFontIconClose, gTextPenX, gTextPenY - 2, 0);
        special = 1;
    }
    if (special) {
        setDrawMode(packDrawFlags(0, 0, 1, 2, 0, 0, 1, 1));
        GFX(0xE200001C, 0x504A50);
        setRenderState(0x5B);
        GFX(0xFCFFB3FF, 0xFF65FEFF);
        gTextPenX += 16;
        return;
    }
    rawChar = code;
    code = gCharToGlyph[code];
    D_80107650 = glyphIndex;
    glyphIndex = code - 0x20;
    GFX(0xE7000000, 0);
    tex = (u32)gFontTexture;
    tex += glyphIndex * 0xD0;
    tex &= ~7;
    GFX(0xFD900000, tex);
    GFX(0xF5900000, 0x07080200);
    GFX(0xE6000000, 0);
    GFX(0xF3000000, 0x07067400);
    GFX(0xE7000000, 0);
    GFX(0xF5880400, 0x00080200);
    GFX(0xF2000000, 0x0003C030);
    if (isFirst) {
        gTextWaveAngle.w = 0;
        setDrawMode(packDrawFlags(0, 0, 1, 2, 0, 0, 1, 1));
        GFX(0xE200001C, 0x504A50);
        setRenderState(0x5B);
        GFX(0xFCFFB3FF, 0xFF65FEFF);
    }
    coss(gTextWaveAngle.h[1] + gTextWaveTime * 200);
    sins(gTextWaveAngle.h[1] + gTextWaveTime * 200);
    step = 64 / gFontScale;
    penX4 = gTextPenX * 4;
    penY = gTextPenY;
    code = penX4 + step;
    temp = (penY * 4 + 0x34) & 0xFFF;
    GFX(0xE4000000 | ((code & 0xFFF) << 12) | temp, ((penX4 & 0xFFF) << 12) | ((penY * 4) & 0xFFF));
    GFX(0xE1000000, 0);
    GFX(0xF1000000, (gFontScale << 26) | 0x400);
    if (rawChar >= 0xC0) {
        tex = (u32)gFontTexture;
        code = penX4 + 64;
        tex += (gHighCharToGlyph[rawChar - 0xC0] - 0x20) * 0xD0;
        tex &= ~7;
    GFX(0xFD900000, tex);
        GFX(0xF5900000, 0x07080200);
        GFX(0xE6000000, 0);
        GFX(0xF3000000, 0x07067400);
        GFX(0xE7000000, 0);
        GFX(0xF5880400, 0x00080200);
        GFX(0xF2000000, 0x0003C030);
        GFX(0xE4000000 | ((code & 0xFFF) << 12) | ((penY * 4 + 0x34) & 0xFFF), ((penX4 & 0xFFF) << 12) | (((penY - 3) * 4) & 0xFFF));
        GFX(0xE1000000, 0);
        GFX(0xF1000000, 0x04000400);
    }
    gTextPenX = ((gTextPenX)) + ((2 + (11 - gGlyphPadding[glyphIndex]) / gFontScale));
}


