extern u8 gCharToGlyph[];
extern u8 gGlyphPadding[];

s32 func_80028694(u8 *s) {
    s32 i;
    s32 w;

    i = 0;
    w = 0;
    for (;;) {
        u8 c = s[i];

        if (c == 0) {
            return w;
        }
        if (c == '~') {
            s[i] = ' ';
            return w;
        }
        if (c == ' ') {
            return w;
        }
        i++;
        c = gCharToGlyph[c];
        w += 13 - gGlyphPadding[c - 0x20];
    }
}
