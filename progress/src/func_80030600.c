typedef struct {
    u32 w0;
    u32 w1;
} GfxW30600;

typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx30600;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x30 - 0x1C];
    f32 unk30;
    u8 pad34[0x58 - 0x34];
    s32 unk58;
    u8 pad5C[0x60 - 0x5C];
    s32 unk60;
    u8 pad64[0x70 - 0x64];
    s32 unk70;
} Obj30600;

typedef struct {
    u8 pad0[0x8];
    s32 unk8;
    u8 padC[0x10 - 0xC];
    u8 data[1];
} Tex30600;

#define SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define TRI_W1(v0, v1, v2) (SHIFTL((v0) * 2, 16, 8) | SHIFTL((v1) * 2, 8, 8) | SHIFTL((v2) * 2, 0, 8))
#define QUAD_W1F(v0, v1, v2, v3, flag) (((flag) == 0) ? TRI_W1(v0, v1, v2) : ((flag) == 1) ? TRI_W1(v1, v2, v3) : ((flag) == 2) ? TRI_W1(v2, v3, v0) : TRI_W1(v3, v0, v1))
#define QUAD_W2F(v0, v1, v2, v3, flag) (((flag) == 0) ? TRI_W1(v0, v2, v3) : ((flag) == 1) ? TRI_W1(v1, v3, v0) : ((flag) == 2) ? TRI_W1(v2, v0, v1) : TRI_W1(v3, v1, v2))
#define QUAD(pkt, v0, v1, v2, v3, flag) { GfxW30600 *_g = (GfxW30600 *)(pkt); _g->w0 = (SHIFTL(7, 24, 8) | QUAD_W1F(v0, v1, v2, v3, flag)); _g->w1 = QUAD_W2F(v0, v1, v2, v3, flag); }

s16 sins(u16);
s16 coss(u16);
s32 func_8001EAD0(void);
void func_8001EB18(s32);
s32 func_8001EF80(void *, s32);
void func_8001F230(void *);
s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_80022728(void *, void *, s32);
Tex30600 *func_80023E18(s32);
void func_80024A3C(void *, void *, s32);
void func_80024B58(void *, void *, s32);
void func_80024BE0(void *, void *, s32);
void func_80024FE8(void *);
void func_8002BE18(s32, void *, s32, s32);
void func_800899DC(char *);
extern char D_80001230[];
extern Vtx30600 D_800BD6C8[];
extern GfxW30600 *D_80177E18;

s32 func_80030600(Obj30600 *arg0) {
    u8 mtxA[0x28];
    u8 mtxB[0x38];
    s32 ra[4];
    s32 rb[4];
    s32 cr;
    s32 cg;
    s32 cb;
    s32 k0;
    s32 k1;
    s32 th;
    s32 base;
    s32 idx;
    s32 n;
    s32 i;
    s32 t;
    s32 step;
    s32 fmt;
    u16 ang;
    Vtx30600 *v;
    Tex30600 *tex;
    u8 *data;

    arg0->unk58 = func_800221C0(0, 1, 1, 3, 0, 0, 1, 0);
    cb = 0x2C;
    k0 = 0x44C;
    k1 = 0x708;
    th = 0x7C0;
    cr = 0xD1;
    cg = 0xBD;
    if (func_8001EF80(arg0, 100000) == 0) {
        return 0;
    }
    if (arg0->unk30 < (f32)-arg0->unk70) {
        return 0;
    }
    {
        GfxW30600 *_g = D_80177E18++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    func_8001F230(arg0);
    step = 0x7C0;
    tex = func_80023E18(arg0->unk60);
    data = (u8 *)tex;
    data += 0x10;
    ra[0] = 0;
    rb[0] = 0;
    ra[1] = step;
    rb[1] = 0;
    ra[2] = step;
    rb[2] = step;
    ra[3] = 0;
    rb[3] = step;
    if (tex->unk8 == 0x20) {
        func_8002BE18(0x20, data, 0, 0);
    } else {
        func_8002BE18(0x10, data, 0, 0);
    }
    func_80024FE8(mtxA);
    func_80024B58(mtxB, mtxA, arg0->unk10);
    func_80024A3C(mtxA, mtxB, arg0->unk14);
    func_80024BE0(mtxB, mtxA, arg0->unk18);
    func_80022728(arg0, mtxB, 1);
    idx = func_8001EAD0();
    base = idx;
    if (idx == -1) {
        func_800899DC(D_80001230);
        return 1;
    }
    n = 14;
    for (i = 0, t = 0; i <= n; i++) {
        ang = (i << 16) / n;
        D_800BD6C8[idx].ob[0] = (k0 * sins(ang)) >> 15;
        D_800BD6C8[idx].ob[2] = (k0 * coss(ang)) >> 15;
        D_800BD6C8[idx].ob[1] = 100;
        D_800BD6C8[idx].cn[0] = cb;
        D_800BD6C8[idx].cn[1] = cr;
        D_800BD6C8[idx].cn[2] = cg;
        D_800BD6C8[idx].cn[3] = 0;
        D_800BD6C8[idx].tc[0] = t;
        D_800BD6C8[idx].tc[1] = th;
        idx++;
        D_800BD6C8[idx].ob[0] = (k1 * sins(ang)) >> 15;
        D_800BD6C8[idx].ob[2] = (k1 * coss(ang)) >> 15;
        D_800BD6C8[idx].cn[0] = cb;
        D_800BD6C8[idx].ob[1] = 0;
        D_800BD6C8[idx].cn[1] = cr;
        D_800BD6C8[idx].cn[2] = cg;
        D_800BD6C8[idx].cn[3] = 0x60;
        D_800BD6C8[idx].tc[0] = t;
        D_800BD6C8[idx].tc[1] = 0;
        idx++;
        t += step;
    }
    {
        GfxW30600 *_g = D_80177E18++;
        _g->w0 = 0x01000000 | ((n * 2 + 2) << 12) | ((n * 2 + 2) << 1);
        _g->w1 = (u32)&D_800BD6C8[base];
    }
    for (i = 0; i < n * 2; i += 2) {
        QUAD(D_80177E18++, i, i + 1, i + 3, i + 2, i);
        QUAD(D_80177E18++, i, i + 2, i + 3, i + 1, i);
    }
    func_8001EB18(idx - base);
    {
        GfxW30600 *_g = D_80177E18++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    return 1;
}
