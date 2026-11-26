typedef f32 MtxF0F10[4][4];
typedef struct { s32 m[4][4]; } Mtx0F10;

typedef struct Xf0F10 {
    f32 scale[3];
    f32 rot[3];
    f32 pos[3];
} Xf0F10;

typedef struct Bone0F10 {
    u8 pad0[6];
    s16 nchild;
    s16 *children;
    u8 padC[4];
    f32 pos[3];
    f32 rot[3];
} Bone0F10;

typedef struct Model0F10 {
    u8 pad0[0xE];
    s16 root;
    u8 pad10[4];
    Bone0F10 *bones;
} Model0F10;

extern f32 func_80095DC0(f32);
extern f32 __cosf(f32);
extern void guMtxF2L(MtxF0F10 *, Mtx0F10 *);
extern const f32 D_80007878;
extern f32 D_800B5DE8[3][3];

void func_80040F10(Model0F10 *m, Xf0F10 *anim, s32 bone, Xf0F10 *parent, f32 (*pm)[3], Mtx0F10 *out) {
    Xf0F10 x;
    f32 r[3][3];
    MtxF0F10 mf;
    f32 t0;
    f32 t1;
    f32 t2;
    f32 sx;
    f32 cx;
    f32 sy;
    f32 cy;
    f32 sz;
    f32 cz;
    s32 i;
    f32 d0;
    f32 d1;
    f32 d2;

    if (bone < 0) {
        bone = m->root;
    }
    if (pm == NULL) {
        pm = D_800B5DE8;
    }
    x = *parent;
    if (anim != NULL) {
        x.scale[0] *= anim[bone].scale[0];
        x.scale[1] *= anim[bone].scale[1];
        x.scale[2] *= anim[bone].scale[2];
        x.rot[0] += anim[bone].rot[0];
        x.rot[1] += anim[bone].rot[1];
        x.rot[2] += anim[bone].rot[2];
        t0 = anim[bone].pos[0];
        t1 = anim[bone].pos[1];
        t2 = anim[bone].pos[2];
    } else {
        x.rot[0] += m->bones[bone].rot[0];
        x.rot[1] += m->bones[bone].rot[1];
        x.rot[2] += m->bones[bone].rot[2];
        t0 = m->bones[bone].pos[0];
        t1 = m->bones[bone].pos[1];
        t2 = m->bones[bone].pos[2];
    }
    d0 = (t0 * pm[0][0] + t1 * pm[1][0] + t2 * pm[2][0]) * parent->scale[0];
    d1 = (t0 * pm[0][1] + t1 * pm[1][1] + t2 * pm[2][1]) * parent->scale[1];
    d2 = (t0 * pm[0][2] + t1 * pm[1][2] + t2 * pm[2][2]) * parent->scale[2];
    x.pos[0] += d0;
    x.pos[1] += d1;
    x.pos[2] += d2;
    sx = func_80095DC0(x.rot[0]);
    cx = __cosf(x.rot[0]);
    sy = func_80095DC0(x.rot[1]);
    cy = __cosf(x.rot[1]);
    sz = func_80095DC0(x.rot[2]);
    cz = __cosf(x.rot[2]);
    r[0][0] = cy * cz;
    r[0][1] = cy * sz;
    r[0][2] = -sy;
    r[1][0] = sx * sy * cz + cx * -sz;
    r[1][1] = sx * sy * sz + cx * cz;
    r[1][2] = sx * cy;
    r[2][0] = cx * sy * cz + -sx * -sz;
    r[2][1] = cx * sy * sz + -sx * cz;
    r[2][2] = cx * cy;
    mf[0][0] = r[0][0] * x.scale[0];
    mf[0][1] = r[0][1] * x.scale[0];
    mf[0][2] = r[0][2] * x.scale[0];
    mf[0][3] = 0;
    mf[1][0] = r[1][0] * x.scale[1];
    mf[1][1] = r[1][1] * x.scale[1];
    mf[1][2] = r[1][2] * x.scale[1];
    mf[1][3] = 0;
    mf[2][0] = r[2][0] * x.scale[2];
    mf[2][1] = r[2][1] * x.scale[2];
    mf[2][2] = r[2][2] * x.scale[2];
    mf[2][3] = 0;
    mf[3][0] = x.pos[0];
    mf[3][1] = x.pos[1];
    mf[3][2] = x.pos[2];
    mf[3][3] = D_80007878;
    guMtxF2L(&mf, &out[bone]);
    for (i = 0; i < m->bones[bone].nchild; i++) {
        func_80040F10(m, anim, m->bones[bone].children[i], &x, r, out);
    }
}
