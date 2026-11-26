typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 pad6[0x10 - 0x6];
} ModelVtx;

typedef struct {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0xB8 - 0x10];
    s32 model;
    u8 padBC[0xEC - 0xBC];
    s32 dl;
} Owner;

typedef struct {
    Owner *owner;
    u16 tri;
    u16 pad6;
} ShadowTri;

void collectCollisionCells(f32 *, f32 *, s32);
s32 func_80048C8C(f32 *, s32);
void func_8002E018(f32 *, f32 *, f32 *);
void func_8002E100(f32 *, f32 *);

extern s32 D_800B75F8;
extern s32 D_800B9EB8;
extern s32 D_801403B0;
extern f32 D_80148D14[];
extern Gfx *D_80177E18;
extern s32 D_800B74F8;
extern s32 D_800B76A0;
extern ShadowTri D_80140FF8[];
extern ModelVtx *D_800FA860[];
extern u16 *D_800F80E8[];
extern Vtx D_801403C0[][30];

void func_80046310(f32 *pos, f32 size, s32 flags) {
    f32 a[3];
    f32 b[3];
    f32 d[3];
    f32 n[3];
    f32 u[3];
    f32 v[3];
    f32 al[3];
    f32 minU;
    f32 minV;
    f32 maxY;
    f32 ylim;
    f32 yfl;
    f32 maxU;
    f32 maxV;
    f32 minY;
    f32 scale;
    f32 sc;
    f32 y;
    f64 h;
    Owner *last;
    ShadowTri *ent;
    ModelVtx *verts;
    u16 *tri;
    Vtx *vt;
    s32 i;
    s32 k;

    last = NULL;
    if (D_800B75F8 != D_800B9EB8) {
        D_800B75F8 = D_800B9EB8;
        D_801403B0 = 0;
    }
    h = size * 0.5;
    a[0] = pos[0] - h;
    a[1] = pos[1] - 2000.0;
    a[2] = pos[2] - h;
    b[0] = pos[0] + h;
    b[1] = pos[1];
    b[2] = pos[2] + h;
    collectCollisionCells(a, b, 0x11);
    a[0] = pos[0];
    a[1] = pos[1] + 8.333333334;
    a[2] = pos[2];
    if (func_80048C8C(a, 1) == 0) {
        return;
    }
    if (flags & 2) {
        scale = 1.0f;
    } else {
        scale = (a[1] - D_80148D14[0]) / 2000.0;
        if (1.0 < scale) {
            scale = 1.0f;
        }
        scale = 1.0 - scale;
        if (scale < 0.1) {
            scale = 0.1f;
        }
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xD9D0F9FA;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xD9FFFFFF;
        _g->w1 = 0x200405;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE3000C00;
        _g->w1 = 0x80000;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xD7000002;
        _g->w1 = 0xFFFFFFFF;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE3000A01;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xD9F0FFFF;
        _g->w1 = 0;
    }
    if (!(flags & 1)) {
        {
            Gfx *_g = D_80177E18++;
            _g->w0 = 0xE200001C;
            _g->w1 = 0x504E50;
        }
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xFC121824;
        _g->w1 = 0xFF33FFFF;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE2001E01;
        _g->w1 = 1;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xF9000000;
        _g->w1 = 0x8080800A;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE3001001;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xFD900000;
        _g->w1 = (u32) &D_800B74F8;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xF5900000;
        _g->w1 = 0x07080200;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE6000000;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xF3000000;
        _g->w1 = 0x0707F400;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xF5880400;
        _g->w1 = 0x80200;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xF2000000;
        _g->w1 = 0x3C03C;
    }
    for (i = 0; i < D_800B76A0; i++) {
        if (D_801403B0 >= 27) {
            break;
        }
        if (D_80140FF8[i].owner != last) {
            last = D_80140FF8[i].owner;
            d[0] = pos[0] - last->x;
            d[1] = pos[1] - last->y;
            d[2] = pos[2] - last->z;
            ylim = d[1] + 5.7;
            yfl = D_80148D14[0] - last->y;
            verts = D_800FA860[last->model];
            {
                Gfx *_g = D_80177E18++;
                _g->w0 = 0xDA380003;
                _g->w1 = last->dl + 0x80000000;
            }
        }
        tri = D_800F80E8[last->model] + D_80140FF8[i].tri * 4;
        a[0] = verts[tri[1]].x - verts[tri[0]].x;
        a[1] = verts[tri[1]].y - verts[tri[0]].y;
        a[2] = verts[tri[1]].z - verts[tri[0]].z;
        b[0] = verts[tri[2]].x - verts[tri[0]].x;
        b[1] = verts[tri[2]].y - verts[tri[0]].y;
        b[2] = verts[tri[2]].z - verts[tri[0]].z;
        if (a[2] * b[0] - a[0] * b[2] <= 0.0) {
            continue;
        }
        func_8002E018(n, a, b);
        func_8002E100(n, n);
        if (n[1] < 0.6) {
            continue;
        }
        sc = size * scale;
        for (k = 0; k < 3; k++) {
            u[k] = (d[0] - verts[tri[k]].x) / sc + 0.5;
            v[k] = (d[2] - verts[tri[k]].z) / sc + 0.5;
            al[k] = 1.0 - (d[1] - verts[tri[k]].y) / 2000.0;
            if (al[k] < 0.2) {
                al[k] = 0.2f;
            }
            if (al[k] < 0.0) {
                al[k] = 0.0f;
            }
            if (1.0 < al[k]) {
                al[k] = 1.0f;
            }
            if (k == 0) {
                maxU = u[0];
                maxV = v[0];
                minU = maxU;
                minV = maxV;
                minY = verts[tri[0]].y;
                maxY = minY;
            } else {
                if (u[k] < minU) {
                    minU = u[k];
                } else if (maxU < u[k]) {
                    maxU = u[k];
                }
                if (v[k] < minV) {
                    minV = v[k];
                } else if (maxV < v[k]) {
                    maxV = v[k];
                }
                y = verts[tri[k]].y;
                if (y < minY) {
                    minY = y;
                }
                if (maxY < y) {
                    maxY = y;
                }
            }
        }
        if (maxY < yfl || yfl < minY || 1.0 <= minU || maxU <= 0.0 || 1.0 <= minV || maxV <= 0.0 || ylim <= minY) {
            continue;
        }
        for (k = 0; k < 3; k++) {
            D_801403C0[D_800B9EB8][D_801403B0 + k].ob[0] = verts[tri[k]].x;
            D_801403C0[D_800B9EB8][D_801403B0 + k].ob[1] = verts[tri[k]].y;
            D_801403C0[D_800B9EB8][D_801403B0 + k].ob[2] = verts[tri[k]].z;
            D_801403C0[D_800B9EB8][D_801403B0 + k].flag = 0;
            D_801403C0[D_800B9EB8][D_801403B0 + k].tc[0] = u[k] * 16.0f * 32.0;
            D_801403C0[D_800B9EB8][D_801403B0 + k].tc[1] = v[k] * 16.0f * 32.0;
            D_801403C0[D_800B9EB8][D_801403B0 + k].cn[0] = 0;
            D_801403C0[D_800B9EB8][D_801403B0 + k].cn[1] = 0;
            D_801403C0[D_800B9EB8][D_801403B0 + k].cn[2] = 0;
            D_801403C0[D_800B9EB8][D_801403B0 + k].cn[3] = (u32) (al[k] * 120.0);
        }
        {
            Gfx *_g = D_80177E18++;
            _g->w0 = 0x01003006;
            _g->w1 = (u32) &D_801403C0[D_800B9EB8][D_801403B0];
        }
        {
            Gfx *_g = D_80177E18++;
            _g->w0 = 0x05000402;
            _g->w1 = 0;
        }
        D_801403B0 += 3;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xFA000000;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xE3000A01;
        _g->w1 = 0;
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xD7000002;
        _g->w1 = 0x80008000;
    }
}

