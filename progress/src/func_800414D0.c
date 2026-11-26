typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    s32 m[4][4];
} Mtx;

typedef struct {
    f32 scale[3];
    s32 rot[3];
    s32 pos[3];
} Xform;

typedef struct {
    u8 pad0[0xC];
    s16 count;
    u8 padE[0x24 - 0xE];
    f32 scale;
} Model;

typedef struct {
    u8 pad0[0x20];
    s32 unk20;
} Anim;

typedef struct {
    s32 unk0;
    f32 pos[3];
    s32 rot[3];
    u8 pad1C[0x28 - 0x1C];
    f32 view[3];
    s32 scale[3];
    u8 pad40[0x58 - 0x40];
    s32 unk58;
    s32 unk5C;
    u8 pad60[0x68 - 0x60];
    s32 unk68;
    u8 pad6C[0xB8 - 0x6C];
    s32 type;
    u8 padBC[0xC4 - 0xBC];
    Mtx *mtx;
    u8 padC8[0xD0 - 0xC8];
    s32 unkD0;
    u8 padD4[0xE0 - 0xD4];
    Anim *anim;
    s32 unkE4;
    s32 unkE8;
    u8 padEC[0xF0 - 0xEC];
    s32 unkF0;
    u8 padF4[0xF8 - 0xF4];
    s32 flags;
} Obj;

s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_8002220C(s32);
void func_80022EDC(Mtx *, f32 (*)[3], s32, f32 *);
Model *func_80023E18(s32);
s32 func_80024394(s32, s32);
void func_80024A3C(f32 (*)[3], f32 (*)[3], s32);
void func_80024B58(f32 (*)[3], f32 (*)[3], s32);
void func_80024BE0(f32 (*)[3], f32 (*)[3], s32);
void func_80024FE8(f32 (*)[3]);
Mtx *func_800253A0(s32);
void func_80027060(s32, s32, s32, s32);
void func_80029F8C(s32);
f32 func_8002DD60(f32);
void func_8002DD8C(f32 *, void *, f32 *);
void func_8003ECB8(Anim *, f32);
void func_80040F10(Model *, s32, s32, Xform *, s32, Mtx *);
Anim *func_80041418(Model *);
void func_800433A8(Obj *, s32, s32);
void func_800479B0(s32);
void func_800899DC(char *, s32);
void guMtxCatL(Mtx *, Mtx *, Mtx *);

extern char D_800078C4[];
extern f32 *D_800B3960;
extern s32 D_800B74E4;
extern s32 D_800B74E8;
extern s32 D_800B9EB8;
extern s32 D_800B9ECC;
extern s32 D_800BD058;
extern s32 D_800BD114;
extern s32 D_800CD148;
extern s32 D_800F90A0[];
extern s32 D_800FB038[];
extern s32 D_80140260[];
extern Mtx *D_80140310[];
extern Gfx *D_80177E18;

void func_800414D0(Obj *arg0) {
    f32 m1[3][3];
    f32 m2[3][3];
    f32 d[3];
    Xform xf;
    Mtx mtx;
    Anim *anim = arg0->anim;
    Mtx *mtxs = arg0->mtx;
    s32 dist = D_800B74E8;
    s32 lit = 0;
    Model *model;
    s32 n;
    f32 fdist;
    f32 z;
    s32 alpha;
    s32 r;
    s32 i;
    s32 j;

    model = func_80023E18(D_800FB038[arg0->type]);
    n = model->count;
    d[0] = arg0->pos[0] - D_800B3960[1];
    d[1] = arg0->pos[1] - D_800B3960[2];
    d[2] = arg0->pos[2] - D_800B3960[3];
    fdist = dist;
    if (fdist < func_8002DD60(d[0]) || fdist < func_8002DD60(d[1]) || fdist < func_8002DD60(d[2])) {
        goto hide;
    }
    func_8002DD8C(arg0->view, &D_800CD148, d);
    if (fdist < func_8002DD60(arg0->view[0]) || fdist < func_8002DD60(arg0->view[1]) || fdist < func_8002DD60(arg0->view[2])) {
        goto hide;
    }
    z = arg0->view[2];
    if (z < -100.0f) {
        goto hide;
    }
    if (arg0->type != 0x1A) {
        if (func_8002DD60(arg0->view[0]) > 2.0f * z || z < func_8002DD60(arg0->view[1] * 0.25f)) {
            goto hide;
        }
    }
    func_80029F8C(-1);
    func_80029F8C(0x57);
    if ((f32)(dist - 1000) < arg0->view[2]) {
        r = func_800221C0(1, 1, 1, 3, 0, 0, 1, 0);
        alpha = (f32)arg0->unk5C * (fdist - arg0->view[2]) / 1000.0f;
        arg0->unk68 = 0xD;
        func_8002220C(r);
        func_80027060(0xFF, 0xFF, 0xFF, alpha);
        {
            Gfx *_g = D_80177E18++;
            _g->w0 = 0xFC40B281;
            _g->w1 = 0xFF67FFFF;
        }
    } else {
        alpha = arg0->unk5C;
        if (alpha != 0xFF) {
            r = func_800221C0(1, 1, 1, 3, 0, 0, 1, 0);
            alpha = arg0->unk5C;
            arg0->unk68 = 0xD;
            func_8002220C(r);
            func_80027060(0xFF, 0xFF, 0xFF, alpha);
            {
                Gfx *_g = D_80177E18++;
                _g->w0 = 0xFC40B281;
                _g->w1 = 0xFF67FFFF;
            }
        } else if (arg0->unkF0 != 0) {
            r = func_800221C0(1, 1, 2, 3, 0, 0, 1, 0);
            arg0->unk68 = 3;
            {
                Gfx *_g = D_80177E18++;
                _g->w0 = 0xE3000A01;
                _g->w1 = 0;
            }
            func_8002220C(r);
            if (arg0->flags & 2) {
                func_80027060(0, 0xFF, 0xFF, arg0->unkF0);
                lit = 1;
            }
            if (arg0->flags & 0x10) {
                func_80027060(0xFF, 0, 0, arg0->unkF0);
                lit++;
            }
            if (lit == 0) {
                func_80027060(0xFF, 0xFF, 0xFF, arg0->unkF0);
            }
            {
                Gfx *_g = D_80177E18++;
                _g->w0 = 0xFC35426A;
                _g->w1 = 0x1184FE7F;
            }
        } else {
            arg0->unk68 = 3;
            func_8002220C(arg0->unk58);
            arg0->unk5C = alpha;
        }
    }
    if (arg0->unk0 == 0x101) {
        arg0->unkF0 -= D_800B9ECC;
    } else {
        arg0->unkF0 -= D_800B9ECC * 4;
    }
    if (arg0->unkF0 <= 0) {
        arg0->unkF0 = 0;
        arg0->flags &= ~2;
    }
    if (arg0->anim == NULL) {
        Model *m = func_80023E18(D_800FB038[arg0->type]);
        if (m == NULL) {
            func_800899DC(D_800078C4, arg0->type);
        }
        anim = func_80041418(m);
        arg0->anim = anim;
        func_800433A8(arg0, arg0->unkD0, 0x100);
        func_8003ECB8(anim, func_80024394(0, 5));
    }
    if (arg0->mtx == NULL) {
        mtxs = func_800253A0(model->count << 7);
        arg0->mtx = mtxs;
    }
    func_80024FE8(m1);
    func_80024B58(m2, m1, arg0->rot[0]);
    func_80024A3C(m1, m2, -arg0->rot[1]);
    func_80024BE0(m2, m1, -arg0->rot[2]);
    func_80022EDC(&mtx, m2, 1, arg0->view);
    xf.scale[0] = model->scale;
    xf.scale[1] = model->scale;
    xf.scale[2] = model->scale;
    xf.scale[0] *= arg0->scale[0];
    xf.scale[1] *= arg0->scale[1];
    xf.scale[2] *= arg0->scale[2];
    xf.rot[0] = 0;
    xf.rot[1] = 0;
    xf.rot[2] = 0;
    xf.pos[0] = 0;
    xf.pos[1] = 0;
    xf.pos[2] = 0;
    xf.scale[0] *= 0.00390625;
    xf.scale[1] *= 0.00390625;
    xf.scale[2] *= 0.00390625;
    if (anim != NULL) {
        func_80040F10(model, anim->unk20, -1, &xf, 0, &mtxs[n * D_800B9EB8]);
    } else {
        func_80040F10(model, 0, -1, &xf, 0, &mtxs[n * D_800B9EB8]);
    }
    for (i = 0; i < model->count; i++) {
        for (j = 0; j < D_800B74E4; j++) {
            if (D_80140260[j] == i) {
                break;
            }
        }
        if (j < D_800B74E4) {
            *D_80140310[j] = mtxs[n * D_800B9EB8 + i];
        }
        guMtxCatL(&mtxs[n * D_800B9EB8 + i], &mtx, &mtxs[n * D_800B9EB8 + i]);
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xDB060004;
        _g->w1 = (u32)&mtxs[n * D_800B9EB8] + 0x80000000;
    }
    if (arg0->unkE8 != 0) {
        func_800479B0(arg0->unkE8);
    }
    {
        Gfx *_g = D_80177E18++;
        _g->w0 = 0xDE000000;
        _g->w1 = arg0->unkE4;
    }
    func_80029F8C(-1);
    D_800B74E4 = 0;
    D_800BD058++;
    D_800BD114 += D_800F90A0[arg0->type];
    arg0->flags |= 4;
    return;
hide:
    D_800B74E4 = 0;
    arg0->flags &= ~4;
}
