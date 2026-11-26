typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    s16 x, y, z;
    s16 pad[5];
} ModelVtx;

typedef struct {
    u16 v[4];
} ModelTri;

typedef struct {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0x58 - 0x10];
    s32 flags58;
    u8 pad5C[0xB8 - 0x5C];
    s32 model;
    u8 padBC[0xF8 - 0xBC];
    s32 flagsF8;
} CollObj;

typedef struct {
    CollObj *obj;
    u16 tri;
} CollRec;

extern f32 D_800B4AB4;
extern s32 D_800B76A0;
extern ModelTri *D_800F80E8[];
extern ModelVtx *D_800FA860[];
extern CollRec D_80140FF8[];
extern Vec3 D_8013FFC0;

void func_80037050(f32 *, f32 *);
Vec3 *vec3Sub(Vec3 *, Vec3 *, Vec3 *);
void func_8002E100(Vec3 *, Vec3 *);
f32 func_8002E0D0(Vec3 *, Vec3 *);
void func_8002E26C(Vec3 *, Vec3 *, Vec3 *, Vec3 *);
void func_8002E1CC(Vec3 *, Vec3 *, f32);
void func_8002E234(Vec3 *, Vec3 *, Vec3 *);
void func_8002E018(Vec3 *, Vec3 *, Vec3 *);
f32 func_8002DD60(f32);
void func_800528CC(Vec3 *, Vec3 *, Vec3 *, Vec3 *, Vec3 *);
s32 func_80052760(Vec3 *, Vec3 *, Vec3 *, Vec3 *);

s32 raycastCollision(Vec3 *start, Vec3 *end, Vec3 *out) {
    Vec3 unused0;
    Vec3 min;
    Vec3 max;
    Vec3 unused1;
    Vec3 tmp;
    Vec3 p0;
    Vec3 p1;
    Vec3 hit;
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 normal;
    Vec3 e0;
    Vec3 e1;
    Vec3 e2;
    Vec3 dir;
    Vec3 bmin;
    Vec3 bmax;
    CollRec *rec;
    CollObj *obj;
    ModelTri *tri;
    ModelVtx *verts;
    s32 i;
    ModelTri *tris;
    f32 best;
    f32 d0;
    f32 d1;
    f32 sign;
    f32 diff;
    f32 t;
    f32 a;
    f32 b;
    f32 c;

    if (out != NULL) {
        out->x = end->x;
        out->y = end->y;
        out->z = end->z;
    }
    min.x = p0.x = start->x;
    min.y = p0.y = start->y;
    min.z = p0.z = start->z;
    max.x = p1.x = end->x;
    max.y = p1.y = end->y;
    max.z = p1.z = end->z;
    if (min.x > max.x) {
        func_80037050(&min.x, &max.x);
    }
    if (min.y > max.y) {
        func_80037050(&min.y, &max.y);
    }
    if (min.z > max.z) {
        func_80037050(&min.z, &max.z);
    }
    i = 0;
    min.x -= 150.0f;
    min.y -= 150.0f;
    min.z -= 150.0f;
    max.x += 150.0f;
    max.y += 150.0f;
    max.z += 150.0f;
    D_800B4AB4 = -2.0f;
    vec3Sub(&dir, &p1, &p0);
    func_8002E100(&dir, &dir);
    best = 2.0f;
    rec = D_80140FF8;
    for (; i < D_800B76A0; i++) {
        obj = D_80140FF8[i].obj;
        if (!(obj->flagsF8 & 8) && !(obj->flags58 & 0x1C)) {
            tris = D_800F80E8[obj->model];
            verts = D_800FA860[obj->model];
            tri = &tris[D_80140FF8[i].tri];
            v0.x = verts[tri->v[0]].x + obj->x;
            v0.y = verts[tri->v[0]].y + obj->y;
            v0.z = verts[tri->v[0]].z + obj->z;
            v1.x = verts[tri->v[1]].x + obj->x;
            v1.y = verts[tri->v[1]].y + obj->y;
            v1.z = verts[tri->v[1]].z + obj->z;
            v2.x = verts[tri->v[2]].x + obj->x;
            v2.y = verts[tri->v[2]].y + obj->y;
            v2.z = verts[tri->v[2]].z + obj->z;
            func_800528CC(&v0, &v1, &v2, &bmin, &bmax);
            if (func_80052760(&bmin, &bmax, &p0, &p1)) {
                func_8002E26C(&normal, &v0, &v1, &v2);
                d0 = func_8002E0D0(&normal, vec3Sub(&tmp, &p0, &v0));
                d1 = func_8002E0D0(&normal, vec3Sub(&tmp, &p1, &v0));
                sign = 0.0f;
                if (d0 >= 0.0 && d1 < 0.0) {
                    sign = 1.0f;
                }
                if (d0 < 0.0 && d1 >= 0.0) {
                    sign = -1.0f;
                }
                if (sign != 0.0) {
                    diff = d0 - d1;
                    if (func_8002DD60(diff) > 1e-7) {
                        diff = d0 / diff;
                        if (diff >= 0.0 && diff < 1.0) {
                            vec3Sub(&tmp, &p1, &p0);
                            func_8002E1CC(&hit, &tmp, diff);
                            func_8002E234(&hit, &hit, &p0);
                            func_8002E018(&e0, vec3Sub(&tmp, &v1, &v0), &dir);
                            func_8002E018(&e1, vec3Sub(&tmp, &v2, &v1), &dir);
                            func_8002E018(&e2, vec3Sub(&tmp, &v0, &v2), &dir);
                            a = sign * func_8002E0D0(&e0, vec3Sub(&tmp, &hit, &v0));
                            b = sign * func_8002E0D0(&e1, vec3Sub(&tmp, &hit, &v1));
                            c = sign * func_8002E0D0(&e2, vec3Sub(&tmp, &hit, &v2));
                            if (a > 0.0f && b > 0.0f && c > 0.0f) {
                                if (out == NULL) {
                                    return 1;
                                }
                                if (diff < best) {
                                    best = diff;
                                    D_8013FFC0.x = normal.x;
                                    D_8013FFC0.y = normal.y;
                                    D_8013FFC0.z = normal.z;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (best != 2.0) {
        vec3Sub(&tmp, &p1, &p0);
        func_8002E1CC(&hit, &tmp, best);
        func_8002E234(&hit, &hit, &p0);
        if (out != NULL) {
            out->x = hit.x;
            out->y = hit.y;
            out->z = hit.z;
        }
        return 1;
    }
    return 0;
}
