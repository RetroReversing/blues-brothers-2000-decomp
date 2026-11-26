typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern s32 D_80140304;
extern s32 D_80140308;

#define G(gfx, a, b) { Gfx *_g = (gfx)++; _g->w0 = (a); _g->w1 = (b); }

Gfx *func_800455C0(Gfx *gfx) {
    if (D_80140304 == 1) {
        G(gfx, 0xD7000002, 0x80008000);
        G(gfx, 0xE3000F00, 0);
        G(gfx, 0xE3000A01, 0);
        G(gfx, 0xFC127E04, 0xFFFFF9FC);
        G(gfx, 0xE200001C, 0x00552078);
        D_80140304 = 0;
        D_80140308 = -1;
    }
    return gfx;
}
