typedef struct { u32 w0, w1; } GfxW;
extern s32 D_80140304;
extern s32 D_80140308;

GfxW *func_800454FC(GfxW *g) {
    if (D_80140304 == 0) {
        {
            GfxW *_g = (GfxW *)(g++);
            _g->w0 = 0xD7001802;
            _g->w1 = 0x80008000;
        }
        {
            GfxW *_g = (GfxW *)(g++);
            _g->w0 = 0xE3000F00;
            _g->w1 = 0x10000;
        }
        {
            GfxW *_g = (GfxW *)(g++);
            _g->w0 = 0xE3000A01;
            _g->w1 = 0x100000;
        }
        {
            GfxW *_g = (GfxW *)(g++);
            _g->w0 = 0xFC26A004;
            _g->w1 = 0x1FFC93FC;
        }
        {
            GfxW *_g = (GfxW *)(g++);
            _g->w0 = 0xE200001C;
            _g->w1 = 0x0C192078;
        }
        D_80140304 = 1;
        D_80140308 = -1;
    }
    return g;
}
