typedef struct {
    s32 unk0;
    f32 pos[3];
    u8 pad10[0x90 - 0x10];
    s32 mode;
    u8 pad94[0xB8 - 0x94];
    s32 type;
} Actor;

typedef struct {
    Actor *obj;
    u16 tri;
} Contact;

typedef struct {
    u16 v[4];
} Tri;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 pad6[0x10 - 0x6];
} Vert;

f32 func_8002DD60(f32);
void func_8002E018(f32 *, f32 *, f32 *);
f32 func_8002E0D0(f32 *, f32 *);
void func_8002E100(f32 *, f32 *);
void func_8002E1CC(f32 *, f32 *, f32);
f32 *vec3Sub(f32 *, f32 *, f32 *);
void func_8002E234(f32 *, f32 *, f32 *);
void func_8002E26C(f32 *, f32 *, f32 *, f32 *);
void func_80037050(f32 *, f32 *);
void func_80037064(s32 *, s32 *, s32, s32, s32);
void collectCollisionCells(f32 *, f32 *, s32);
extern f32 D_800B4C10[3];
extern f32 D_800B4C1C[3];
extern s32 D_800B76A0;
extern Tri *D_800F80E8[];
extern Vert *D_800FA860[];
extern f32 D_80140144;
extern Contact D_80140FF8[];

void func_80037164(Actor *arg0, f32 *pos, f32 *vel) {
    s32 box[6];
    s32 ofs[6];
    s32 pad0[6];
    f32 n[3];
    f32 e0[3];
    f32 e1[3];
    f32 e2[3];
    f32 pad1[3];
    f32 pad2[3];
    f32 tmp[3];
    f32 pad3[3];
    f32 bmin[3];
    f32 bmax[3];
    f32 pad4[3];
    f32 pad5[3];
    f32 proj[3];
    f32 q[3];
    f32 pad6[3];
    f32 v0[3];
    f32 v1[3];
    f32 v2[3];
    f32 p[3];
    f32 end[3];
    f32 hit[3];
    f32 pad7[3];
    s32 size = 300;
    s32 i;
    f32 d0;
    f32 d1;
    f32 s0;
    f32 s1;
    f32 s2;
    f32 t;
    f64 zero;
    f32 fz;

    if (arg0->mode == 1) {
        f32 *g = D_800B4C1C;
        if (g[1] < 0.8) {
            func_8002E1CC(tmp, g, -func_8002E0D0(g, vel));
            func_8002E234(tmp, tmp, vel);
            if (tmp[1] >= 0.0) {
                vel[0] = 0.0f;
                vel[2] = 0.0f;
            }
        }
        p[0] = vel[0];
        p[1] = 0.0f;
    } else {
        p[0] = vel[0];
        p[1] = vel[1];
    }
    do { p[2] = vel[2]; } while (0);
    pos[1] += 150.0f;
    func_8002E234(end, p, pos);
    ofs[0] = -size;
    ofs[2] = -size;
    ofs[1] = -150;
    ofs[3] = size;
    ofs[5] = size;
    ofs[4] = 150;
    func_80037064(box, ofs, pos[0], pos[1], pos[2]);
    bmin[0] = box[0];
    bmin[1] = box[1];
    bmin[2] = box[2];
    bmax[0] = box[3];
    bmax[1] = box[4];
    bmax[2] = box[5];
    if (bmin[0] > bmax[0]) {
        func_80037050(&bmin[0], &bmax[0]);
    }
    if (bmin[1] > bmax[1]) {
        func_80037050(&bmin[1], &bmax[1]);
    }
    if (bmin[2] > bmax[2]) {
        func_80037050(&bmin[2], &bmax[2]);
    }
    collectCollisionCells(bmin, bmax, 1);
    zero = 0.0;
    fz = 0.0f;
    i = 0;
    if (i < D_800B76A0)
    {
    do
    {
        Actor *o = D_80140FF8[i].obj;
        s32 type = o->type;
        Vert *verts = D_800FA860[type];
        Tri *tri = &D_800F80E8[type][D_80140FF8[i].tri];

        v0[0] = verts[tri->v[0]].x + o->pos[0];
        v0[1] = verts[tri->v[0]].y + o->pos[1];
        v0[2] = verts[tri->v[0]].z + o->pos[2];
        v1[0] = verts[tri->v[1]].x + o->pos[0];
        v1[1] = verts[tri->v[1]].y + o->pos[1];
        v1[2] = verts[tri->v[1]].z + o->pos[2];
        v2[0] = verts[tri->v[2]].x + o->pos[0];
        v2[1] = verts[tri->v[2]].y + o->pos[1];
        v2[2] = verts[tri->v[2]].z + o->pos[2];
        func_8002E26C(n, v0, v1, v2);
        if (n[1] >= 0.8) {
            goto next_i;
        }
        if (func_8002E0D0(n, vel) > fz) {
            goto next_i;
        }
        d0 = func_8002E0D0(n, vec3Sub(tmp, pos, v0));
        if (!(d0 >= zero) || !(d0 < 115.0f)) {
            goto next_i;
        }
        d1 = func_8002E0D0(n, vec3Sub(tmp, end, v0));
        func_8002E1CC(tmp, n, -d0);
        func_8002E234(proj, tmp, pos);
        n[0] = -n[0];
        n[1] = -n[1];
        n[2] = -n[2];
        func_8002E018(e0, vec3Sub(tmp, v1, v0), n);
        func_8002E018(e1, vec3Sub(tmp, v2, v1), n);
        func_8002E018(e2, vec3Sub(tmp, v0, v2), n);
        s0 = func_8002E0D0(e0, vec3Sub(tmp, proj, v0));
        s1 = func_8002E0D0(e1, vec3Sub(tmp, proj, v1));
        s2 = func_8002E0D0(e2, vec3Sub(tmp, proj, v2));
        if (!(s0 >= fz) || !(s1 >= fz) || !(s2 >= fz)) {
            t = d0 - d1;
            if (func_8002DD60(t) > 1e-7) {
            t = d0 / t;
            hit[0] = pos[0] + (end[0] - pos[0]) * t;
            hit[1] = pos[1] + (end[1] - pos[1]) * t;
            hit[2] = pos[2] + (end[2] - pos[2]) * t;
            s0 = func_8002E0D0(e0, vec3Sub(tmp, hit, v0));
            do { do { s1 = func_8002E0D0(e1, vec3Sub(tmp, hit, v1));
            s2 = func_8002E0D0(e2, vec3Sub(tmp, hit, v2)); } while (0); } while (0);
            if (s0 >= fz && s1 >= fz && s2 >= fz) {
                goto hit;
            }
            }
        } else {
        hit:
        q[0] = -n[0];
        q[1] = fz;
        q[2] = -n[2];
        func_8002E100(q, q);
        do { do { func_8002E1CC(tmp, q, -func_8002E0D0(q, vel)); } while (0); } while (0);
        if (tmp[1] != zero && n[1] < fz) {
            tmp[1] = fz;
        }
        func_8002E234(vel, tmp, vel);
        func_8002E1CC(tmp, n, (115.0f - d0) * -0.1);
        func_8002E234(vel, tmp, vel);
        D_80140144 = d0;
        D_800B4C10[0] = -n[0];
        D_800B4C10[1] = -n[1];
        D_800B4C10[2] = -n[2];
        }
    next_i:
      i++;
    }
    while (i < D_800B76A0);
    }
    pos[1] -= 150.0f;
}
