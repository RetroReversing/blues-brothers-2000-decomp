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

s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_8002220C(s32);
void func_80022728(Obj *, f32 *, s32);
void func_80024FE8(f32 *);
void func_8002710C(s32, s32, s32, s32);
void func_80029F8C(s32);
s16 sins(u16);
s16 coss(u16);

extern Vtx D_8013FB30[];
extern GfxW *D_80177E18;

#define GFX(a, b) { GfxW *_g = D_80177E18++; _g->w0 = (a); _g->w1 = (b); }

void func_800301E8(u8 *img, s32 zoom) {
    f32 m[10];
    s32 s[4];
    s32 t[4];
    Obj obj;
    s32 i;
    s32 r;
    s32 size;
    s32 k;
    s32 r_;
    s32 g_;
    s32 b_;
    s32 a_;

    size = 600;
    r_ = 0xFF;
    g_ = 0xFF;
    b_ = 0xFF;
    a_ = 0xFF;
    func_8002220C(func_800221C0(0, 0, 1, 2, 0, 0, 1, 1));
    func_80029F8C(0x5B);
    GFX(0xFCFFFFFF, 0xFFFDF2F9);
    GFX(0xE200001C, 0x504340);
    GFX(0xE2001E01, 1);
    GFX(0xF9000000, 100);
    GFX(0xE3000A01, 0);
    func_8002710C(0, 0, 0, 0xFF);
    k = 0x1000;
    GFX(0xFD900000, (u32)img);
    GFX(0xF5900000, 0x07080200);
    GFX(0xE6000000, 0);
    GFX(0xF3000000, 0x077FF100);
    GFX(0xE7000000, 0);
    GFX(0xF5880000 | k, 0x80200);
    GFX(0xF2000000, 0xFC0FC);
    r = zoom * 0xC000 / 320;
    obj.x18 = zoom * 160 + 0xE000;
    for (i = 0; i < 4; i++) {
        s[i] = ((r * sins(obj.x18 + (i << 14))) >> 15) + k;
        t[i] = ((r * coss(obj.x18 + (i << 14))) >> 15) + k;
    }
    obj.x28 = 0;
    obj.x2C = 0;
    obj.x34 = 0x100;
    obj.x38 = 0x100;
    obj.x3C = 0x100;
    obj.x30 = 1000.0f;
    func_80024FE8(m);
    func_80022728(&obj, m, 0);
    D_8013FB30[0].ob[0] = -size;
    D_8013FB30[0].ob[1] = -size;
    D_8013FB30[0].ob[2] = 0;
    D_8013FB30[0].cn[0] = r_;
    D_8013FB30[0].cn[1] = g_;
    D_8013FB30[0].cn[2] = b_;
    D_8013FB30[0].cn[3] = a_;
    D_8013FB30[0].tc[0] = s[0];
    D_8013FB30[0].tc[1] = t[0];
    D_8013FB30[1].ob[0] = size;
    D_8013FB30[1].ob[1] = -size;
    D_8013FB30[1].ob[2] = 0;
    D_8013FB30[1].cn[0] = r_;
    D_8013FB30[1].cn[1] = g_;
    D_8013FB30[1].cn[2] = b_;
    D_8013FB30[1].cn[3] = a_;
    D_8013FB30[1].tc[0] = s[1];
    D_8013FB30[1].tc[1] = t[1];
    D_8013FB30[2].ob[0] = size;
    D_8013FB30[2].ob[1] = size;
    D_8013FB30[2].ob[2] = 0;
    D_8013FB30[2].cn[0] = r_;
    D_8013FB30[2].cn[1] = g_;
    D_8013FB30[2].cn[2] = b_;
    D_8013FB30[2].cn[3] = a_;
    D_8013FB30[2].tc[0] = s[2];
    D_8013FB30[2].tc[1] = t[2];
    D_8013FB30[3].ob[0] = -size;
    D_8013FB30[3].ob[1] = size;
    D_8013FB30[3].ob[2] = 0;
    D_8013FB30[3].cn[0] = r_;
    D_8013FB30[3].cn[1] = g_;
    D_8013FB30[3].cn[2] = b_;
    D_8013FB30[3].cn[3] = a_;
    D_8013FB30[3].tc[0] = s[3];
    D_8013FB30[3].tc[1] = t[3];
    GFX(0x01004008, (u32)D_8013FB30);
    GFX(0x07000204, 0x406);
    GFX(0x07000604, 0x402);
}


