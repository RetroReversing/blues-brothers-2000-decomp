typedef struct GfxW {
    u32 w0;
    u32 w1;
} GfxW;

typedef struct RState {
    s32 x0;
    s32 x4;
    s32 x8;
    char padC[0x2C - 0xC];
    s32 x2C;
    s32 x30;
    char pad34[0x3C - 0x34];
    s32 x3C;
} RState;

extern RState D_800B2B20;
extern s32 D_800BD6B0;
extern GfxW *D_80177E18;

void setRenderState(s32 mode) {
    RState cur;
    s32 sync;

    sync = 0;
    cur.x2C = D_800B2B20.x2C;
    cur.x3C = D_800B2B20.x3C;
    cur.x30 = D_800B2B20.x30;
    cur.x8 = D_800B2B20.x8;
    if (mode == -1) {
        D_800B2B20.x2C = mode;
        D_800B2B20.x30 = mode;
        D_800B2B20.x3C = mode;
        D_800B2B20.x8 = 0;
        return;
    }
    D_800BD6B0++;
    cur.x8 = mode & 0xC0;
    switch (mode & 3) {
    case 1:
        cur.x2C = 0;
        break;
    case 2:
        cur.x2C = 0x3000;
        break;
    case 3:
        cur.x2C = 0x2000;
        break;
    }
    switch (mode & 0x30) {
    case 0x10:
        cur.x30 = 0;
        break;
    case 0x20:
        cur.x30 = 0x8000;
        break;
    case 0x30:
        cur.x30 = 0xC000;
        break;
    }
    switch (mode & 0xC) {
    case 4:
        cur.x3C = 0x80000;
        break;
    case 8:
        cur.x3C = 0;
        break;
    }
    if (cur.x8 != D_800B2B20.x8) {
        if (sync) {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE7000000;
            _g->w1 = 0;
            sync = 0;
        }
        D_800B2B20.x8 = cur.x8;
        switch (cur.x8) {
        case 0x40:
            {
                GfxW *_g = D_80177E18++;
                _g->w0 = 0xD7000002;
                _g->w1 = 0x80008000;
            }
            break;
        case 0x80:
            {
                GfxW *_g = D_80177E18++;
                _g->w0 = 0xD7000000;
                _g->w1 = 0x80008000;
            }
            break;
        }
    }
    if (cur.x2C != D_800B2B20.x2C) {
        if (sync) {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE7000000;
            _g->w1 = 0;
            sync = 0;
        }
        D_800B2B20.x2C = cur.x2C;
        {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE3001201;
            _g->w1 = cur.x2C;
        }
    }
    if (cur.x3C != D_800B2B20.x3C) {
        if (sync) {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE7000000;
            _g->w1 = 0;
            sync = 0;
        }
        D_800B2B20.x3C = cur.x3C;
        {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE3000C00;
            _g->w1 = cur.x3C;
        }
    }
    if (cur.x30 != D_800B2B20.x30) {
        if (sync) {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE7000000;
            _g->w1 = 0;
            sync = 0;
        }
        D_800B2B20.x30 = cur.x30;
        {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE3001001;
            _g->w1 = cur.x30;
        }
    }
}
