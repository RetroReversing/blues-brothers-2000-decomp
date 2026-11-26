typedef struct { u32 w0, w1; } GfxW;
typedef struct {
    u8 pad0[0x28];
    f32 x28;
    f32 x2C;
    f32 x30;
    u8 pad34[0x5C - 0x34];
    s32 x5C;
    u8 pad60[0x74 - 0x60];
    s32 x74;
    s32 x78;
    s32 x7C;
    s32 x80;
    u8 pad84[0x94 - 0x84];
    s32 x94;
    u8 pad98[0xE4 - 0x98];
    s32 xE4;
} Obj;
void func_8001F1D0(void);
void func_8001F230(void *);
void func_80022C2C(void *, void *, s32);
void func_80027060(s32, s32, s32, s32);
void func_80029F8C(s32);
void func_8002DC84(void *);
extern GfxW *D_80177E18;

s32 func_8001FB54(Obj *arg0) {
    u8 sp10[0x38];
    s32 r;
    s32 x, y;

    r = arg0->x94;
    func_8001F1D0();
    if (r < abs((s32)arg0->x28)) {
        return 0;
    }
    if (r < abs((s32)arg0->x2C)) {
        return 0;
    }
    if (r < abs((s32)arg0->x30)) {
        return 0;
    }
    func_8001F230(arg0);
    func_80027060(0xFF, 0xFF, 0xFF, arg0->x5C);
    {
        GfxW *_g = D_80177E18++;
        _g->w0 = 0xFC30B261;
        _g->w1 = 0xFF67FFFF;
    }
    func_8002DC84(sp10);
    func_80022C2C(arg0, sp10, 1);
    x = arg0->x7C;
    y = arg0->x80;
    {
        GfxW *_g = D_80177E18++;
        _g->w0 = 0xF2000000 | ((x & 0xFFF) << 12) | (y & 0xFFF);
        _g->w1 = (((x + 0x20) & 0xFFF) << 12) | ((y + 0x20) & 0xFFF);
    }
    arg0->x7C += arg0->x74;
    arg0->x80 += arg0->x78;
    {
        GfxW *_g = D_80177E18++;
        _g->w0 = 0xDE000000;
        _g->w1 = arg0->xE4;
    }
    {
        GfxW *_g = D_80177E18++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    func_80029F8C(-1);
    return 1;
}
