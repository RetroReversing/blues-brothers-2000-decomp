typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 pad6[10];
} MVtx16;

typedef struct {
    s32 kind;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0xB8 - 0x10];
    s32 model;
} Owner;

typedef struct {
    Owner *owner;
    u16 tri;
    u16 pad6;
} ShadowTri;

typedef struct {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x44 - 0x10];
    f32 f44;
    u8 pad48[0x50 - 0x48];
    f32 f50;
    u8 pad54[0x90 - 0x54];
    s32 f90;
} Probe;

f32 func_8002DD60(f32);
Vec3 *func_8002E018(Vec3 *, Vec3 *, Vec3 *);
f32 func_8002E0D0(Vec3 *, Vec3 *);
Vec3 *func_8002E1CC(Vec3 *, Vec3 *, f32);
Vec3 *func_8002E1FC(Vec3 *, Vec3 *, Vec3 *);
Vec3 *func_8002E234(Vec3 *, Vec3 *, Vec3 *);
void func_8002E26C(Vec3 *, Vec3 *, Vec3 *, Vec3 *);
void func_80037050(f32 *, f32 *);
void func_80037064(s32 *, s32 *, s32, s32, s32);
void func_800370B4(s32 *, s32 *, s32 *);
void func_80048820(Vec3 *, Vec3 *, s32);

extern Vec3 D_800B4C1C;
extern s32 D_800B76A0;
extern u16 *D_800F80E8[];
extern MVtx16 *D_800FA860[];
extern s32 D_80140140;
extern s32 D_80140148;
extern MVtx16 D_80140790[3];
extern Vec3 D_80140FC8;
extern ShadowTri D_80140FF8[];

f32 func_800379C8(Probe *o) {
    Vec3 lo;
    Vec3 hi;
    Vec3 unused38;
    Vec3 n;
    Vec3 e0;
    Vec3 e1;
    Vec3 e2;
    Vec3 unused88;
    Vec3 ndir;
    Vec3 dir;
    Vec3 unusedB8;
    Vec3 tmp;
    Vec3 unusedD8;
    Vec3 p0;
    Vec3 p1;
    Vec3 hit;
    Vec3 rel;
    Vec3 q0;
    Vec3 q1;
    Vec3 c0;
    Vec3 c1;
    Vec3 c2;
    s32 box[6];
    s32 b0[6];
    s32 b1[6];
    Vec3 best;
    f32 bestT;
    s32 i;
    f32 bestUp;
    f32 bestDown;
    f32 margin;
    f32 bestY;
    f32 result;
    f32 ret;
    f32 d0;
    f32 d1;
    f32 den;
    f32 t;
    f32 s0;
    f32 dd;
    f32 du;
    f32 dt;
    Owner *owner;
    u16 *tri;
    MVtx16 *verts;
    u16 **tt;
    u16 **ts;
    MVtx16 **vs;

    bestY = -1000000.0f;
    result = 0.0f;
    margin = 100.0f;
    if (o->f90 == 0) {
        margin = 0.0f;
    }
    p0.x = o->x;
    p0.y = o->y + 100000.0f;
    p0.z = o->z;
    p1.x = o->x;
    p1.y = o->y - 100000.0f;
    p1.z = o->z;
    q0.x = o->x;
    q0.y = o->f44 + 300.0f;
    q0.z = o->z;
    q1.x = o->x;
    q1.y = o->y + 300.0f;
    q1.z = o->z;
    box[0] = -0x73;
    box[1] = 2;
    box[2] = -0x73;
    box[3] = 0x73;
    box[4] = 0x131;
    box[5] = 0x73;
    func_80037064(b0, box, (s32) o->x, -100000, (s32) o->z);
    func_80037064(b1, box, (s32) o->x, 100000, (s32) o->z);
    func_800370B4(box, b1, b0);
    lo.x = box[0];
    hi.x = box[3];
    lo.y = box[1];
    lo.z = box[2];
    hi.y = box[4];
    hi.z = box[5];
    if (hi.x < lo.x) {
        func_80037050(&lo.x, &hi.x);
    }
    if (lo.y > hi.y) {
        func_80037050(&lo.y, &hi.y);
    }
    if (lo.z > hi.z) {
        func_80037050(&lo.z, &hi.z);
    }
    func_80048820(&lo, &hi, 9);
    func_8002E1FC(&dir, &p1, &p0);
    D_80140140 = -1000000;
    bestT = 2.0f;
    ndir.x = -dir.x;
    ndir.y = -dir.y;
    bestUp = 1000000.0f;
    bestDown = 1000000.0f;
    ndir.z = -dir.z;
    for (i = 0; i < D_800B76A0; i++)
    {
      tt = D_800F80E8;
      owner = D_80140FF8[i].owner;
      ts = &tt[owner->model];
      vs = &D_800FA860[owner->model];
      tri = *ts + D_80140FF8[i].tri * 4;
      verts = *vs;
      c0.x = verts[tri[0]].x + owner->x;
      c0.y = verts[tri[0]].y + owner->y;
      c0.z = verts[tri[0]].z + owner->z;
      c1.x = verts[tri[1]].x + owner->x;
      c1.y = verts[tri[1]].y + owner->y;
      c1.z = verts[tri[1]].z + owner->z;
      c2.x = verts[tri[2]].x + owner->x;
      c2.y = verts[tri[2]].y + owner->y;
      c2.z = verts[tri[2]].z + owner->z;
      func_8002E26C(&n, &c0, &c1, &c2);
      if (n.y < 0.0 && o->f50 > 0.0f) {
          d0 = func_8002E0D0(&n, func_8002E1FC(&tmp, &q0, &c0));
          d1 = func_8002E0D0(&n, func_8002E1FC(&tmp, &q1, &c0));
          if (d0 >= 0.0f) {
              if (d1 < 0.0) {
                  t = d0 - d1;
                  if (func_8002DD60(t) > 1e-07) {
                      t = d0 / t;
                      if (t >= 0.0f && t <= 1.0) {
                          func_8002E1FC(&tmp, &p1, &p0);
                          func_8002E1CC(&hit, &tmp, t);
                          func_8002E234(&hit, &hit, &p0);
                          func_8002E018(&e0, func_8002E1FC(&tmp, &c1, &c0), &ndir);
                          func_8002E018(&e1, func_8002E1FC(&tmp, &c2, &c1), &ndir);
                          func_8002E018(&e2, func_8002E1FC(&tmp, &c0, &c2), &ndir);
                          s0 = func_8002E0D0(&e0, func_8002E1FC(&tmp, &hit, &c0));
                          d0 = func_8002E0D0(&e1, func_8002E1FC(&tmp, &hit, &c1));
                          d1 = func_8002E0D0(&e2, func_8002E1FC(&tmp, &hit, &c2));
                          if (s0 >= 0.0f) {
                              if (d0 >= 0.0f && d1 >= 0.0f) {
                                  o->f50 = 0.0f;
                              }
                          }
                      }
                  }
              }
          }
      }
      d0 = func_8002E0D0(&n, func_8002E1FC(&tmp, &p0, &c0));
      d1 = func_8002E0D0(&n, func_8002E1FC(&tmp, &p1, &c0));
      if (d0 >= 0.0f) {
          if (d1 < 0.0) {
              t = d0 - d1;
              if (func_8002DD60(t) > 1e-07) {
                  t = d0 / t;
                  if (t >= 0.0f && t <= 1.0) {
                      func_8002E1FC(&tmp, &p1, &p0);
                      func_8002E1CC(&hit, &tmp, t);
                      func_8002E234(&hit, &hit, &p0);
                      func_8002E018(&e0, func_8002E1FC(&tmp, &c1, &c0), &dir);
                      func_8002E018(&e1, func_8002E1FC(&tmp, &c2, &c1), &dir);
                      func_8002E018(&e2, func_8002E1FC(&tmp, &c0, &c2), &dir);
                      s0 = func_8002E0D0(&e0, func_8002E1FC(&tmp, &hit, &c0));
                      d0 = func_8002E0D0(&e1, func_8002E1FC(&tmp, &hit, &c1));
                      d1 = func_8002E0D0(&e2, func_8002E1FC(&tmp, &hit, &c2));
                      if (s0 >= 0.0f) {
                          if (d0 >= 0.0f && d1 >= 0.0f) {
                              if (owner->kind == 0x13B) {
                                  D_80140140 = hit.y;
                              } else {
                                  dd = (o->f44 + margin) - hit.y;
                                  if (dd >= 0.0f && dd < bestDown) {
                                      D_800B4C1C.x = n.x;
                                      D_800B4C1C.y = n.y;
                                      D_800B4C1C.z = n.z;
                                      rel.x = hit.x - owner->x;
                                      result = hit.y;
                                      rel.y = result - owner->y;
                                      bestDown = dd;
                                      rel.z = hit.z - owner->z;
                                      D_80140790[0] = verts[tri[0]];
                                      D_80140790[1] = verts[tri[1]];
                                      bestT = t;
                                      D_80140790[2] = verts[tri[2]];
                                      D_80140FC8 = rel;
                                      D_80140148 = ((u8 *) tri)[7];
                                  }
                                  du = (hit.y - o->f44) - margin;
                                  if (du >= 0.0f && du < bestUp) {
                                      bestY = hit.y;
                                      bestUp = du;
                                      best.x = n.x;
                                      best.y = n.y;
                                      best.z = n.z;
                                  }
                              }
                          }
                      }
                  }
              }
          }
      }
    }
    dd = bestY - o->f44;
    if (o->f50 <= 0.0f && bestY != -1000000.0 && dd < 200.0f) {
        ret = bestY;
    } else {
        if (bestT != 2.0) {
            return result;
        }
        if (bestY == -1000000.0) {
            return -1000000.0f;
        }
        ret = bestY;
    }
    D_800B4C1C.x = best.x;
    D_800B4C1C.y = best.y;
    D_800B4C1C.z = best.z;
    return ret;
}
