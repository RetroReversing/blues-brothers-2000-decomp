typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    s16 x, y, z;
    s16 pad[5];
} ModelVtx;

typedef struct {
    u16 v[3];
    u8 flags;
    u8 pad;
} ModelTri;

typedef struct {
    u8 pad0[4];
    Vec3 pos;
    u8 pad10[0xB8 - 0x10];
    s32 model;
} CollObj;

typedef struct {
    CollObj *obj;
    u16 tri;
} CollRec;

typedef struct {
    s32 kind;
    f32 height;
    Vec3 normal;
    f32 t;
    Vec3 world;
    Vec3 hit;
    CollObj *obj;
    ModelTri *tri;
} RayHit;

extern s32 D_800B76A0;
extern s32 D_800B76A4;
extern s32 D_800B76A8;
extern ModelTri *gObjTriLists[];
extern ModelVtx *gObjVertBases[];
extern CollRec D_80140FF8[];
extern RayHit D_80148CF8[];
extern Vec3 gCollideMin;
extern Vec3 gCollideMax;

void debugPrintf(char *);
f32 func_80094350(f32);
f32 sqrtf(f32);

s32 func_800493A0(Vec3 *start, Vec3 *end, s32 flags) {
    Vec3 p0;
    Vec3 p1;
    Vec3 min;
    Vec3 max;
    Vec3 dir;
    Vec3 hit;
    Vec3 world;
    Vec3 tv[3];
    Vec3 normal;
    Vec3 e0;
    Vec3 e1;
    RayHit best;
    Vec3 tmp;
    Vec3 c0;
    Vec3 c1;
    Vec3 c2;
    CollObj *prev;
    CollObj *obj;
    ModelTri *tris;
    ModelTri *tri;
    ModelVtx *verts;
    RayHit *e;
    s32 i;
    s32 k;
    f32 len0;
    f32 len1;
    f32 len2;
    f32 d0;
    f32 d1;
    f32 t;

    prev = NULL;
    D_800B76A4 = 0;
    if (start->x == end->x && start->y == end->y && start->z == end->z) {
        return 0;
    }
    if (start->x < gCollideMin.x || end->x < gCollideMin.x || gCollideMax.x < start->x || gCollideMax.x < end->x
        || start->z < gCollideMin.z || end->z < gCollideMin.z || gCollideMax.z < start->z || gCollideMax.z < end->z) {
    }
    for (i = 0; i < D_800B76A0; i++) {
        obj = D_80140FF8[i].obj;
        if (obj != prev) {
            p0.x = start->x - obj->pos.x;
            p0.y = start->y - obj->pos.y;
            p0.z = start->z - obj->pos.z;
            p1.x = end->x - obj->pos.x;
            p1.y = end->y - obj->pos.y;
            p1.z = end->z - obj->pos.z;
            dir.x = p1.x - p0.x;
            dir.y = p1.y - p0.y;
            dir.z = p1.z - p0.z;
            len0 = sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
            dir.x /= len0;
            dir.y /= len0;
            dir.z /= len0;
            if (p0.x < p1.x) {
                min.x = p0.x;
                max.x = p1.x;
            } else {
                min.x = p1.x;
                max.x = p0.x;
            }
            if (p0.y < p1.y) {
                min.y = p0.y;
                max.y = p1.y;
            } else {
                min.y = p1.y;
                max.y = p0.y;
            }
            if (p0.z < p1.z) {
                min.z = p0.z;
                max.z = p1.z;
            } else {
                min.z = p1.z;
                max.z = p0.z;
            }
            prev = obj;
            tris = gObjTriLists[obj->model];
            verts = gObjVertBases[obj->model];
        }
        tri = &tris[D_80140FF8[i].tri];
        if ((flags & 4) && !(tri->flags & 1)) {
            continue;
        }
        if ((flags & 8) && (tri->flags & 1)) {
            continue;
        }
        for (k = 0; k < 3; k++) {
            tv[k].x = verts[tri->v[k]].x;
            tv[k].y = verts[tri->v[k]].y;
            tv[k].z = verts[tri->v[k]].z;
        }
        if (max.y < tv[0].y) {
            continue;
        }
        if (min.y > tv[1].y && min.y > tv[2].y) {
            continue;
        }
        e0.x = tv[1].x - tv[0].x;
        e0.y = tv[1].y - tv[0].y;
        e0.z = tv[1].z - tv[0].z;
        e1.x = tv[2].x - tv[0].x;
        e1.y = tv[2].y - tv[0].y;
        e1.z = tv[2].z - tv[0].z;
        normal.x = e0.y * e1.z - e0.z * e1.y;
        normal.y = e0.z * e1.x - e0.x * e1.z;
        normal.z = e0.x * e1.y - e0.y * e1.x;
        if ((p0.x == tv[0].x && p0.y == tv[0].y && p0.z == tv[0].z)
            || (p0.x == tv[1].x && p0.y == tv[1].y && p0.z == tv[1].z)
            || (p0.x == tv[2].x && p0.y == tv[2].y && p0.z == tv[2].z)) {
            t = 0.0f;
        } else if ((p1.x == tv[0].x && p1.y == tv[0].y && p1.z == tv[0].z)
            || (p1.x == tv[1].x && p1.y == tv[1].y && p1.z == tv[1].z)
            || (p1.x == tv[2].x && p1.y == tv[2].y && p1.z == tv[2].z)) {
            t = 1.0f;
            if ((flags & 1) && D_800B76A4 > 0) {
                continue;
            }
        } else {
            f32 sign;

            tmp.x = p0.x - tv[0].x;
            tmp.y = p0.y - tv[0].y;
            tmp.z = p0.z - tv[0].z;
            d0 = normal.x * tmp.x + normal.y * tmp.y + normal.z * tmp.z;
            tmp.x = p1.x - tv[0].x;
            tmp.y = p1.y - tv[0].y;
            tmp.z = p1.z - tv[0].z;
            d1 = normal.x * tmp.x + normal.y * tmp.y + normal.z * tmp.z;
            sign = -1.0f;
            if (d0 >= 0.0 && d1 < 0.0) {
                sign = 1.0f;
            }
            if (!(d0 >= 0.0 && d1 < 0.0) && !((flags & 0x10) && d1 >= 0.0 && d0 < 0.0)) {
                continue;
            }
            t = d0 - d1;
            t = d0 / t;
            if (t < 0.0 || t > 1.0) {
                continue;
            }
            if ((flags & 1) && D_800B76A4 > 0 && best.t <= t) {
                continue;
            }
            hit.x = p0.x + (p1.x - p0.x) * t;
            hit.y = p0.y + (p1.y - p0.y) * t;
            hit.z = p0.z + (p1.z - p0.z) * t;
            tmp.x = tv[1].x - tv[0].x;
            tmp.y = tv[1].y - tv[0].y;
            tmp.z = tv[1].z - tv[0].z;
            c0.x = tmp.y * dir.z - tmp.z * dir.y;
            c0.y = tmp.z * dir.x - tmp.x * dir.z;
            c0.z = tmp.x * dir.y - tmp.y * dir.x;
            tmp.x = tv[2].x - tv[1].x;
            tmp.y = tv[2].y - tv[1].y;
            tmp.z = tv[2].z - tv[1].z;
            c1.x = tmp.y * dir.z - tmp.z * dir.y;
            c1.y = tmp.z * dir.x - tmp.x * dir.z;
            c1.z = tmp.x * dir.y - tmp.y * dir.x;
            tmp.x = tv[0].x - tv[2].x;
            tmp.y = tv[0].y - tv[2].y;
            tmp.z = tv[0].z - tv[2].z;
            c2.x = tmp.y * dir.z - tmp.z * dir.y;
            c2.y = tmp.z * dir.x - tmp.x * dir.z;
            c2.z = tmp.x * dir.y - tmp.y * dir.x;
            tmp.x = hit.x - tv[0].x;
            tmp.y = hit.y - tv[0].y;
            tmp.z = hit.z - tv[0].z;
            if (sign * (c0.x * tmp.x + c0.y * tmp.y + c0.z * tmp.z) <= 0.0) {
                continue;
            }
            tmp.x = hit.x - tv[1].x;
            tmp.y = hit.y - tv[1].y;
            tmp.z = hit.z - tv[1].z;
            if (sign * (c1.x * tmp.x + c1.y * tmp.y + c1.z * tmp.z) <= 0.0) {
                continue;
            }
            tmp.x = hit.x - tv[2].x;
            tmp.y = hit.y - tv[2].y;
            tmp.z = hit.z - tv[2].z;
            if (sign * (c2.x * tmp.x + c2.y * tmp.y + c2.z * tmp.z) <= 0.0) {
                continue;
            }
        }
        world.x = hit.x + obj->pos.x;
        world.y = hit.y + obj->pos.y;
        world.z = hit.z + obj->pos.z;
        if (flags & 1) {
            best.kind = 1;
            best.height = start->y - hit.y;
            best.normal.x = normal.x;
            best.normal.y = normal.y;
            best.normal.z = normal.z;
            best.t = t;
            best.world.x = world.x;
            best.world.y = world.y;
            best.world.z = world.z;
            best.hit.x = hit.x;
            best.hit.y = hit.y;
            best.hit.z = hit.z;
            best.obj = obj;
            best.tri = tri;
        } else {
            if (D_800B76A4 >= 0x80) {
                debugPrintf("intersections array overflow!");
            }
            if (flags & 2) {
                tri->flags |= 8;
                D_800B76A8++;
            }
            len1 = sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
            normal.x /= len1;
            normal.y /= len1;
            normal.z /= len1;
            D_80148CF8[D_800B76A4].kind = 1;
            D_80148CF8[D_800B76A4].height = start->y - hit.y;
            D_80148CF8[D_800B76A4].normal.x = normal.x;
            D_80148CF8[D_800B76A4].normal.y = normal.y;
            D_80148CF8[D_800B76A4].normal.z = normal.z;
            D_80148CF8[D_800B76A4].t = t;
            D_80148CF8[D_800B76A4].world.x = world.x;
            D_80148CF8[D_800B76A4].world.y = world.y;
            D_80148CF8[D_800B76A4].world.z = world.z;
            D_80148CF8[D_800B76A4].hit.x = hit.x;
            D_80148CF8[D_800B76A4].hit.y = hit.y;
            D_80148CF8[D_800B76A4].hit.z = hit.z;
            D_80148CF8[D_800B76A4].obj = obj;
            D_80148CF8[D_800B76A4].tri = tri;
        }
        D_800B76A4++;
    }
    if (flags & 1) {
        if (D_800B76A4 > 0) {
            e = D_80148CF8;
            e->kind = best.kind;
            e->height = best.height;
            e->normal = best.normal;
            e->t = best.t;
            e->world = best.world;
            e->hit = best.hit;
            e->obj = best.obj;
            e->tri = best.tri;
            len2 = sqrtf(e->normal.x * e->normal.x + e->normal.y * e->normal.y + e->normal.z * e->normal.z);
            e->normal.x /= len2;
            e->normal.y /= len2;
            e->normal.z /= len2;
            if (flags & 2) {
                e->tri->flags |= 8;
                D_800B76A8++;
            }
        } else {
            D_80148CF8[0].kind = 0;
        }
    }
    return D_800B76A4;
}
