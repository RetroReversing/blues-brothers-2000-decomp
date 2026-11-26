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

extern RState gRdpStateCache;
extern s32 gRenderStateChanges;
extern GfxW *D_80177E18;

/* Updates the RDP render state from renderMode bits (-1 resets it). Compares the
 * requested state with gRdpStateCache and appends display-list commands only for
 * fields that changed, each preceded by a sync command when one is pending. */
void setRenderState(s32 renderMode) {
    RState want;
    s32 needSync;

    needSync = 0;
    want.x2C = gRdpStateCache.x2C;
    want.x3C = gRdpStateCache.x3C;
    want.x30 = gRdpStateCache.x30;
    want.x8 = gRdpStateCache.x8;
    if (renderMode == -1) {
        gRdpStateCache.x2C = renderMode;
        gRdpStateCache.x30 = renderMode;
        gRdpStateCache.x3C = renderMode;
        gRdpStateCache.x8 = 0;
        return;
    }
    gRenderStateChanges++;
    want.x8 = renderMode & 0xC0;
    switch (renderMode & 3) {
    case 1:
        want.x2C = 0;
        break;
    case 2:
        want.x2C = 0x3000;
        break;
    case 3:
        want.x2C = 0x2000;
        break;
    }
    switch (renderMode & 0x30) {
    case 0x10:
        want.x30 = 0;
        break;
    case 0x20:
        want.x30 = 0x8000;
        break;
    case 0x30:
        want.x30 = 0xC000;
        break;
    }
    switch (renderMode & 0xC) {
    case 4:
        want.x3C = 0x80000;
        break;
    case 8:
        want.x3C = 0;
        break;
    }
    if (want.x8 != gRdpStateCache.x8) {
        if (needSync) {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE7000000;
            _g->w1 = 0;
            needSync = 0;
        }
        gRdpStateCache.x8 = want.x8;
        switch (want.x8) {
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
    if (want.x2C != gRdpStateCache.x2C) {
        if (needSync) {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE7000000;
            _g->w1 = 0;
            needSync = 0;
        }
        gRdpStateCache.x2C = want.x2C;
        {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE3001201;
            _g->w1 = want.x2C;
        }
    }
    if (want.x3C != gRdpStateCache.x3C) {
        if (needSync) {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE7000000;
            _g->w1 = 0;
            needSync = 0;
        }
        gRdpStateCache.x3C = want.x3C;
        {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE3000C00;
            _g->w1 = want.x3C;
        }
    }
    if (want.x30 != gRdpStateCache.x30) {
        if (needSync) {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE7000000;
            _g->w1 = 0;
            needSync = 0;
        }
        gRdpStateCache.x30 = want.x30;
        {
            GfxW *_g = D_80177E18++;
            _g->w0 = 0xE3001001;
            _g->w1 = want.x30;
        }
    }
}
