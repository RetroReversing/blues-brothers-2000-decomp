typedef struct { s32 m[4][4]; } Mtx5E34;
typedef f32 MtxF5E34[4][4];

typedef struct Model5E34 {
    u8 pad0[0xC];
    s16 count;
    u8 padE[0x16];
    f32 scale;
} Model5E34;

typedef struct Obj5E34 {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 rx;
    s32 ry;
    s32 rz;
    u8 pad1C[0xC];
    u8 o28[0xC];
    s32 sx;
    s32 sy;
    s32 sz;
    u8 pad40[0x78];
    s32 kind;
    u8 padBC[8];
    Mtx5E34 *mtx;
    u8 padC8[0x18];
    struct { u8 pad[0x20]; s32 v20; } *anim;
} Obj5E34;

typedef struct Pos5E34 {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
} Pos5E34;

extern s32 coss(u16);
extern s32 sins(u16);
extern Pos5E34 *func_80012718(Obj5E34 *);
extern void func_80022EDC(Mtx5E34 *, s32 *, s32, void *);
extern Model5E34 *func_80023E18(s32);
extern void func_80024A3C(s32 *, s32 *, s32);
extern void func_80024B58(s32 *, s32 *, s32);
extern void func_80024BE0(s32 *, s32 *, s32);
extern void func_80024FE8(s32 *);
extern void func_8002D620(Pos5E34 *);
extern void func_80040F10(Model5E34 *, s32, s32, f32 *, s32, Mtx5E34 *);
extern Pos5E34 *func_80085650(s32);
extern void guMtxCatL(Mtx5E34 *, Mtx5E34 *, Mtx5E34 *);
extern void guMtxL2F(MtxF5E34 *, Mtx5E34 *);
extern f64 D_80007A10;
extern s32 D_800B74E4[];
extern s32 D_800B83C8[];
extern s32 D_800B9EB8[];
extern s32 D_800FB038[];
extern s32 D_80140260[];
extern Mtx5E34 *D_80140310[];

s32 func_80045E34(Obj5E34 *o) {
    Mtx5E34 m;
    f32 sc[9];
    s32 pos[3];
    s32 rot[3];
    s32 ma[10];
    s32 mb[10];
    Mtx5E34 mtx[38];
    MtxF5E34 mf[38];
    void *anim;
    Mtx5E34 *buf;
    Model5E34 *model;
    s32 n;
    s32 count;
    s32 i;
    s32 j;
    s16 c;
    s16 s;
    MtxF5E34 *f;
    Pos5E34 *p;

    anim = o->anim;
    buf = o->mtx;
    if (anim == NULL || buf == NULL) {
        return 0;
    }
    model = func_80023E18(D_800FB038[o->kind]);
    n = model->count;
    func_80024FE8(ma);
    func_80024B58(mb, ma, o->rx);
    func_80024A3C(ma, mb, -o->ry);
    func_80024BE0(mb, ma, -o->rz);
    func_80022EDC(&m, mb, 1, o->o28);
    sc[0] = model->scale;
    sc[1] = model->scale;
    sc[2] = model->scale;
    sc[0] *= o->sx;
    sc[1] *= o->sy;
    sc[2] *= o->sz;
    sc[3] = 0;
    sc[4] = 0;
    sc[5] = 0;
    sc[6] = 0;
    sc[7] = 0;
    sc[8] = 0;
    sc[0] *= D_80007A10;
    sc[1] *= D_80007A10;
    sc[2] *= D_80007A10;
    func_80040F10(model, ((s32 *) anim)[8], -1, sc, 0, &buf[n * D_800B9EB8[0]]);
    count = n;
    if (count >= 38) {
        count = 37;
    }
    D_800B74E4[0] = count;
    for (i = 0; i < count; i++) {
        D_80140260[i] = i;
        D_80140310[i] = &mtx[i];
    }
    for (i = 0; i < count; i++) {
        for (j = 0; j < D_800B74E4[0]; j++) {
            if (D_80140260[j] == i) {
                break;
            }
        }
        if (j < D_800B74E4[0]) {
            *D_80140310[j] = buf[n * D_800B9EB8[0] + i];
        }
        guMtxCatL(&buf[n * D_800B9EB8[0] + i], &m, &buf[n * D_800B9EB8[0] + i]);
    }
    f = mf;
    for (i = 0; i < count; i++) {
        guMtxL2F(&mf[i], &mtx[i]);
        pos[0] = (*f)[3][0];
        pos[1] = (*f)[3][1];
        pos[2] = (*f)[3][2];
        c = coss(o->rx);
        s = sins(o->rx);
        rot[0] = ((pos[0] * c) >> 15) + ((pos[2] * s) >> 15);
        s = sins(o->rx);
        c = coss(o->rx);
        rot[1] = pos[1];
        rot[2] = -((pos[0] * s) >> 15) + ((pos[2] * c) >> 15);
        if (D_800B83C8[0]) {
            p = func_80012718(o);
        } else {
            p = func_80085650(0);
        }
        p->x = o->x + rot[0];
        p->y = o->y + rot[1];
        p->z = o->z + rot[2];
        func_8002D620(p);
        f++;
    }
}
