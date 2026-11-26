extern s32 gFontScale;
extern char gCharToGlyph[];
extern char gGlyphPadding[];

u8 *func_8002856C(u8 *arg0, s32 arg1) {
    u8 *word;
    s32 total;
    s32 idx;
    s32 c;
    s32 sp;
    u8 *base;
    u8 *tbl;
    u8 *r;
    total = 0;
    loop_goto_1:
        idx = *arg0;
        arg0++;
        c = (u8) idx;
        if (c == (sp = 0x20)) {
            word = arg0 - 1;
        }
        r = arg0;
        if (c == 0) {
            goto out;
        }
        tbl = (u8 *) gCharToGlyph;
        base = (u8 *) gGlyphPadding;
        c = tbl[c];
        total += 2 + (0xB - base[c - 0x20]) / gFontScale;
        if (total <= arg1) {
            goto loop_goto_1;
        }
        r = word;
    out:
    return r;
}

