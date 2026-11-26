typedef struct {
    u32 w0;
    u32 w1;
} Gfx424;

typedef struct {
    s16 x, y, z;
    s16 pad[5];
} MdlVtx;

typedef struct {
    void *p0;
    u8 pad4[2];
    s16 n;
    void *p8;
    u8 padC[0x28 - 0xC];
} MdlPart;

typedef struct {
    void *p0;
    void *tex;
    s16 id;
    s8 kind;
    u8 padB;
} MdlTex;

typedef struct {
    u16 magic;
    u16 flags;
    s32 nverts;
    u8 pad8[4];
    s16 nparts;
    u8 padE[2];
    s16 ntex;
    u8 pad12[2];
    MdlPart *parts;
    MdlTex *texs;
    MdlVtx *verts;
    u8 *cmds;
} MdlHdr;

typedef struct {
    s32 x, y, z;
} Vec3i424;

void *func_80024324(s32);
Gfx424 *func_800434B0(Gfx424 *, s32);
Gfx424 *func_800434B8(Gfx424 *, u8 *, MdlTex *);
Gfx424 *func_80044DFC(Gfx424 *, u8 *, MdlTex *);
Gfx424 *func_800455C0(Gfx424 *);
Gfx424 *func_80045678(Gfx424 *, s32, s32);
void func_800899C4(char *);
void debugPrintf(char *);
f32 sqrtf(f32);
extern void *D_800B7478[];
extern s32 D_800B74E0;
extern s32 D_800B7B0C;
extern Vec3i424 D_800F4A00[];
extern Vec3i424 D_800F6188[];
extern s32 D_800F7910[];
extern s32 gObjTriCounts[];
extern s32 D_800FA854;
extern MdlVtx *gObjVertBases[];
extern s32 D_801402FC;
extern s32 D_80140300;
extern s32 D_80140304;
extern s32 D_80140308;
extern s32 D_801403A8;

Gfx424 *func_800424FC(s32 flags, s32 index, MdlHdr *hdr_in, Gfx424 *gfx) {
  MdlHdr * hdr;
    s32 unused10[3];
    s32 unused20[3];
    s32 min[3];
    s32 max[3];
    MdlVtx *vtx;
    s32 skip;
    u8 *base;
    MdlVtx *v;
    MdlTex *texs;
    MdlTex *t;
    MdlPart *p;
    MdlPart *parts;
    MdlVtx *pv;
    u8 *cmd;
    u8 *op;
    u8 *op5;
    u8 *op6;
    f32 radius;
    f32 len;
    s32 i;
    s32 k;
    s32 kt;
    s32 j;
    s32 k_arm;
    s32 n;
    s32 vbase;
    s32 vnext;
    u32 c;
    s32 r;
    s32 r_b1;
    s32 g;
    s32 b;
    u32 c2;
    s32 r2;
    s32 g2;
    s32 b2;
    s32 p0, p1, p2, p3;
    Gfx424 *dl_1;
    Gfx424 *dl_2;
    s32 debug;
  hdr = hdr_in;
    debug = 0;

    D_80140300 = 1;
    D_80140304 = 0;
    D_80140308 = -1;
    skip = 0;
    D_800FA854 = 0;
    base = (u8 *)hdr;
    if (hdr->magic != 0x103) {
        debugPrintf("wrong rsp version");
    }
    hdr->texs = (MdlTex *)((s32)hdr->texs + (s32)hdr);
    hdr->cmds = (u8 *)((s32)hdr->cmds + (s32)hdr);
    hdr->verts = (MdlVtx *)((s32)hdr->verts + (s32)hdr);
    hdr->parts = (MdlPart *)((s32)hdr->parts + (s32)hdr);
    D_801402FC = hdr->flags & 1;
    D_801403A8 = hdr->flags & 2;
    if (D_801402FC) {
        flags = (D_800B74E0 != 0) * 2;
    }
    min[0] = 0x7FFFFFFF;
    min[1] = 0x7FFFFFFF;
    min[2] = 0x7FFFFFFF;
    max[0] = 0x80000001;
    max[1] = 0x80000001;
    max[2] = 0x80000001;
    pv = hdr->verts;
    gObjVertBases[index] = pv;
    radius = 0.0f;
    for (g = 0; g < hdr->nverts; g++) {
        v = &pv[g];
        if (v->x < min[0]) {
            min[0] = v->x;
        }
        if (v->y < min[1]) {
            min[1] = v->y;
        }
        if (v->z < min[2]) {
            min[2] = v->z;
        }
        if (max[0] < v->x) {
            max[0] = v->x;
        }
        if (max[1] < v->y) {
            max[1] = v->y;
        }
        if (max[2] < v->z) {
            max[2] = v->z;
        }
        len = sqrtf((f32)v->x * v->x + (f32)v->y * v->y + (f32)v->z * v->z);
        if (radius < len) {
            radius = len;
        }
    }
    D_800F6188[index].x = min[0];
    D_800F6188[index].y = min[1];
    D_800F6188[index].z = min[2];
    D_800F4A00[index].x = max[0];
    D_800F4A00[index].y = max[1];
    D_800F4A00[index].z = max[2];
    D_800F7910[index] = radius;
    parts = hdr->parts;
    for (i = 0; i < hdr->nparts; i++) {
        p = &parts[i];
        p->p8 = (void *)((s32)p->p8 + (s32)base);
        p->p0 = (void *)((s32)p->p0 + (s32)base);
        for (j = 0; j < p->n; j++) {
        }
    }
    texs = hdr->texs;
    for (i = 0; i < hdr->ntex; i++) {
        t = &texs[i];
        t->p0 = (void *)((s32)t->p0 + (s32)base);
        if ((k = t->kind) <= 0) {
            if ((k = (s32)t->tex) != 0) {
                t->tex = (void *)(k + (s32)base);
            } else {
                k = t->id;
                if (k == -1) {
                    debugPrintf("-1 tbk index");
                }
                t->tex = func_80024324(k);
            }
        } else {
            t->tex = D_800B7478[k - 1];
        }
    }
    vnext = 0;
    vbase = 0;
    cmd = hdr->cmds;
    vtx = hdr->verts;
    {
        Gfx424 *_g = gfx++;
        _g->w0 = 0xE2001E01;
        _g->w1 = 1;
    }
    {
        Gfx424 *_g = gfx++;
        _g->w0 = 0xF9000000;
        _g->w1 = 0;
    }
    {
        Gfx424 *_g = gfx++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    gfx = func_80045678(gfx, 0, flags);
    for (;;) {
        switch (*cmd) {
        case 0:
            if (debug) {
                func_800899C4("MTXLOAD\n");
            }
            {
                Gfx424 *_g = gfx++;
                _g->w1 = ((cmd[1] + (cmd[2] << 8)) << 6) + 0x01000000;
                _g->w0 = 0xDA380003;
            }
            cmd += 3;
            break;
        case 1:
            op = cmd;
            cmd += 2;
            n = op[1] & 0x3F;
            if (op[1] & 0xC0) {
                gfx = func_800434B0(gfx, 1);
            } else {
                gfx = func_800434B0(gfx, 0);
            }
            {
                Gfx424 *_g = gfx++;
                _g->w0 = 0x01000000 | (n << 12) | (((vbase + n) & 0x7F) << 1);
                _g->w1 = (u32)&vtx[vnext];
            }
            for (i = 0; i < n; i++) {
                ((u8 *)&vtx[vnext + i])[0xF] = 0x80;
            }
            vnext += op[1] & 0x3F;
            vbase += op[1] & 0x3F;
            break;
        case 2:
            n = cmd[1];
            p0 = cmd[2]; p1 = cmd[3]; p2 = cmd[4]; p3 = cmd[5];
            c = (p0 << 24) | (p1 << 16) | (p2 << 8) | p3;
            {
                Gfx424 *_g = gfx++;
                _g->w0 = (n << 1) | 0x02100000;
                _g->w1 = c;
            }
            cmd += 6;
            break;
        case 3:
            cmd += 6;
            n = cmd[-5];
            p0 = cmd[-4]; p1 = cmd[-3]; p2 = cmd[-2]; p3 = cmd[-1];
            c = (p0 << 24) | (p1 << 16) | (p2 << 8) | p3;
            {
                Gfx424 *_g = gfx++;
                _g->w0 = (n << 1) | 0x02140000;
                _g->w1 = c;
            }
            break;
        case 4:
            if (skip == 0) {
                vbase = 0;
                dl_1 = gfx++;
                b = cmd[2] + (cmd[1] << 8);
                {
                    s32 w = b;
                    kt = ((u32)b >> 5);
                    b = (b >> 10);
                    r = w & 0x1F;
                    kt &= 0x1F;
                    b &= 0x1F;
                }
                if (r == 0) {
                    dl_1->w0 = (kt << 9) | (b << 1) | 0x05000000;
                } else if (r == 1) {
                    dl_1->w0 = (((kt << 1) & 0xFF) << 16) | ((b << 9) & 0xFE00) | 0x05000002;
                } else {
                    dl_1->w0 = (((b << 1) & 0xFF) << 16) | (r << 9) | ((kt << 1) & 0xFF) | 0x05000000;
                }
                dl_1->w1 = 0;
            }
            cmd += 3;
            D_800FA854++;
            break;
        case 5:
            op5 = cmd;
            cmd += 5;
            if (skip == 0) {
                vbase = 0;
                dl_2 = gfx++;
                b = op5[2] + (op5[1] << 8);
                {
                    s32 w = b;
                    kt = ((u32)b >> 5);
                    b = (b >> 10);
                    r = w & 0x1F;
                    kt &= 0x1F;
                    b &= 0x1F;
                }
                k_arm = op5[4] + (op5[3] << 8);
                {
                    s32 w = k_arm;
                    g2 = ((u32)k_arm >> 5);
                    k_arm = (k_arm >> 10);
                    g2 &= 0x1F;
                    k_arm &= 0x1F;
                    r2 = w & 0x1F;
                }
                if (r == 0) {
                    dl_2->w0 = (kt << 9) | (b << 1) | 0x06000000;
                } else if (r == 1) {
                    dl_2->w0 = (((kt << 1) & 0xFF) << 16) | ((b << 9) & 0xFE00) | 0x06000002;
                } else {
                    dl_2->w0 = (((b << 1) & 0xFF) << 16) | (r << 9) | ((kt << 1) & 0xFF) | 0x06000000;
                }
                if (r2 == 0) {
                    dl_2->w1 = ((g2 << 9) & 0xFE00) | ((k_arm << 1) & 0xFF);
                } else if (r2 == 1) {
                    dl_2->w1 = (((g2 << 1) & 0xFF) << 16) | ((k_arm << 9) & 0xFE00) | 2;
                } else {
                    dl_2->w1 = (((k_arm << 1) & 0xFF) << 16) | (r2 << 9) | ((g2 << 1) & 0xFF);
                }
            }
            D_800FA854 += 2;
            break;
        case 6:
            n = cmd[2];
            op6 = cmd;
            if (!(flags & 0x20)) {
                if (D_800B7B0C == 0 && (flags & 1)) {
                    D_80140300 = cmd[1] & 1;
                }
                if (flags & 2) {
                    gfx = func_80044DFC(gfx, op6, texs);
                } else {
                    gfx = func_800434B8(gfx, op6, texs);
                }
                gfx = func_80045678(gfx, ((u8 *)texs[n].tex)[1] & 2, flags);
                skip = op6[7] == 3;
            }
            cmd += 8;
            break;
        case 0xFF:
            {
                Gfx424 *_g = gfx++;
                _g->w0 = 0xE7000000;
                _g->w1 = 0;
            }
            gfx = func_800455C0(gfx);
            {
                Gfx424 *_g = gfx++;
                _g->w0 = 0xDF000000;
                _g->w1 = 0;
            }
            gObjTriCounts[index] = D_800FA854;
            return gfx;
        default:
            debugPrintf("BAD RSP COMMAND");
            break;
        }
    }
}

