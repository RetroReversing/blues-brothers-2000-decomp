typedef struct { f32 x, y, z; } Vec3f;
typedef struct { s32 x, y, z; } Vec3i;
typedef struct { Vec3f n; f32 d; } Plane;
typedef struct { s16 x, y, z; s16 pad[5]; } Vtx16;
typedef struct { u16 v[4]; } Tri;
typedef struct {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0xB8 - 0x10];
    s32 model;
} Obj;
typedef struct { Obj *obj; u16 tri; u16 pad; } Hit;

f32 func_8002DD60(f32);
Vec3f *func_8002E018(Plane *, Vec3f *, Vec3f *);
f32 func_8002E0D0(Plane *, Vec3f *);
Vec3f *func_8002E1CC(Vec3f *, Vec3f *, f32);
Vec3f *vec3Sub(Vec3f *, Vec3f *, Vec3f *);
Vec3f *func_8002E234(Vec3f *, Vec3f *, Vec3f *);
void func_8002E26C(Plane *, Vec3f *, Vec3f *, Vec3f *);
void func_80037050(f32 *, f32 *);
void func_80037064(Vec3i *, Vec3i *, s32, s32, s32);
void func_800370B4(Vec3i *, Vec3i *, Vec3i *);
void collectCollisionCells(Vec3f *, Vec3f *, s32);
extern s32 D_800B76A0;
extern Tri *D_800F80E8[];
extern Vtx16 *D_800FA860[];
extern Hit D_80140FF8[];

f32 func_800385AC(Obj *a)
{
    Vec3f bmin;
    Vec3f bmax;
    Vec3f unused38;
    Plane pl[4];
    Vec3f unused88;
    Vec3f dir;
    Vec3f unusedA8;
    Vec3f tmp;
    Vec3f unusedC8;
    Vec3f top;
    Vec3f bot;
    Vec3f hit;
    Vec3f v0;
    Vec3f v1;
    Vec3f v2;
    Vec3i box[2];
    Vec3i b1[2];
    Vec3i b2[2];
    Vec3f unused180;
    s32 i;
    f32 above;
    f32 below;
    f32 bestAbove;
    f32 bestBelow;
    f32 d1, d2, diff, t, e0, e1, e2, h;
    Tri *tri;
    Vtx16 *vtx;
    Obj *o;
    Tri **tt;
    Tri **ts;
    Vtx16 **vs;

    top.x = a->x;
    top.y = a->y + 100000.0f;
    top.z = a->z;
    bot.x = a->x;
    bot.y = a->y - 100000.0f;
    bot.z = a->z;
    below = 0.0f;
    above = 0.0f;
    box[0].x = -115;
    box[0].y = 2;
    box[0].z = -115;
    box[1].x = 115;
    box[1].y = 305;
    box[1].z = 115;
    func_80037064(b1, box, a->x, -100000, a->z);
    func_80037064(b2, box, a->x, 100000, a->z);
    func_800370B4(box, b2, b1);
    bmin.x = box[0].x;
    bmin.y = box[0].y;
    bmin.z = box[0].z;
    bmax.x = box[1].x;
    bmax.y = box[1].y;
    bmax.z = box[1].z;
    if (bmax.x < bmin.x) {
        func_80037050(&bmin.x, &bmax.x);
    }
    if (bmin.y > bmax.y) {
        func_80037050(&bmin.y, &bmax.y);
    }
    if (bmin.z > bmax.z) {
        func_80037050(&bmin.z, &bmax.z);
    }
    collectCollisionCells(&bmin, &bmax, 1);
    vec3Sub(&dir, &bot, &top);
    bestBelow = 1000000.0f;
    bestAbove = bestBelow;
    for (i = 0; i < D_800B76A0; i++) {
        tt = D_800F80E8;
        o = D_80140FF8[i].obj;
        ts = &tt[o->model];
        vs = &D_800FA860[o->model];
        tri = &(*ts)[D_80140FF8[i].tri];
        vtx = *vs;
        v0.x = vtx[tri->v[0]].x + o->x;
        v0.y = vtx[tri->v[0]].y + o->y;
        v0.z = vtx[tri->v[0]].z + o->z;
        v1.x = vtx[tri->v[1]].x + o->x;
        v1.y = vtx[tri->v[1]].y + o->y;
        v1.z = vtx[tri->v[1]].z + o->z;
        v2.x = vtx[tri->v[2]].x + o->x;
        v2.y = vtx[tri->v[2]].y + o->y;
        v2.z = vtx[tri->v[2]].z + o->z;
        func_8002E26C(&pl[0], &v0, &v1, &v2);
        d1 = func_8002E0D0(&pl[0], vec3Sub(&tmp, &top, &v0));
        d2 = func_8002E0D0(&pl[0], vec3Sub(&tmp, &bot, &v0));
        if (d1 >= 0.0f && d2 < 0.0) {
            diff = d1 - d2;
            if (func_8002DD60(diff) > 1e-7) {
                t = d1 / diff;
                if (t >= 0.0f && t <= 1.0) {
                    vec3Sub(&tmp, &bot, &top);
                    func_8002E1CC(&hit, &tmp, t);
                    func_8002E234(&hit, &hit, &top);
                    func_8002E018(&pl[1], vec3Sub(&tmp, &v1, &v0), &dir);
                    func_8002E018(&pl[2], vec3Sub(&tmp, &v2, &v1), &dir);
                    func_8002E018(&pl[3], vec3Sub(&tmp, &v0, &v2), &dir);
                    e0 = func_8002E0D0(&pl[1], vec3Sub(&tmp, &hit, &v0));
                    d1 = func_8002E0D0(&pl[2], vec3Sub(&tmp, &hit, &v1));
                    d2 = func_8002E0D0(&pl[3], vec3Sub(&tmp, &hit, &v2));
                    if (e0 >= 0.0f && d1 >= 0.0f && d2 >= 0.0f) {
                        h = (a->y - hit.y) + 100.0f;
                        if (h >= 0.0f && h < bestAbove) {
                            above = hit.y;
                            bestAbove = h;
                        }
                        if (h < 0.0f && func_8002DD60(h) < bestBelow) {
                            below = hit.y;
                            bestBelow = h;
                        }
                    }
                }
            }
        }
    }
    if (bestAbove != 1000000.0f) {
        return above;
    }
    if (bestBelow == 1000000.0f) {
        return a->y;
    }
    return below;
}



