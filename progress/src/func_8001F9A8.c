typedef struct { u32 w0; u32 w1; } GfxW;
typedef struct Obj {
    u8 pad0[0x28];
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x74 - 0x34];
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    u8 pad84[0x94 - 0x84];
    s32 unk94;
    u8 pad98[0xE4 - 0x98];
    s32 unkE4;
} Obj;

int abs(int);
void func_8001F1D0(void);
void func_8001F230(Obj *);
void func_80022C2C(Obj *, void *, s32);
void func_80027060(s32, s32, s32, s32);
void setRenderState(s32);
void mtxIdentity3(void *);
extern s32 D_800B7B0C;
extern GfxW *D_80177E18;

s32 func_8001F9A8(Obj *arg0) {
    u8 mtx[0x38];
    s32 r;

    r = arg0->unk94;
    func_8001F1D0();
    arg0->unk7C += arg0->unk74;
    arg0->unk80 += arg0->unk78;
    if (r < abs((s32)arg0->unk28)) {
        return 0;
    }
    if (r < abs((s32)arg0->unk2C)) {
        return 0;
    }
    if (r < abs((s32)arg0->unk30)) {
        return 0;
    }
    func_8001F230(arg0);
    if (D_800B7B0C == 1) {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xFC1217FF;
        _g->w1 = 0xFFFFFE38;
        func_80027060(0xFF, 0xFF, 0xFF, 0x80);
    }
    mtxIdentity3(mtx);
    func_80022C2C(arg0, mtx, 1);
    {
        s32 x = arg0->unk7C;
        s32 y = arg0->unk80;
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xF2000000 | ((x & 0xFFF) << 12) | (y & 0xFFF);
        _g->w1 = (((x + 0x20) & 0xFFF) << 12) | ((y + 0x20) & 0xFFF);
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xDE000000;
        _g->w1 = arg0->unkE4;
    }
    {
        GfxW *_g = (GfxW *)(D_80177E18++);
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    setRenderState(-1);
    return 1;
}
