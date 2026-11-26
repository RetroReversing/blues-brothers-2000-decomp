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
extern ModelTri *D_800F80E8[];
extern ModelVtx *D_800FA860[];
extern CollRec D_80140FF8[];
extern RayHit D_80148CF8[];
extern Vec3 D_8014A8F8;
extern Vec3 D_8014A908;

void func_800899DC(char *);
extern char D_80007D14[];
f32 func_80094350(f32);
f32 func_8002DD60(f32);
f32 sqrtf(f32);

s32 func_8004A200(f32 x0, f32 x1, f32 y0, f32 y1, f32 z0, f32 z1, s32 flags) {
    Vec3 p0;
    Vec3 p1;
    Vec3 tv[3];
    Vec3 normal;
    Vec3 e0;
    Vec3 e1;
    Vec3 a;
    Vec3 b;
    Vec3 dir;
    Vec3 hit;
    Vec3 tmp;
    Vec3 c0;
    Vec3 c1;
    Vec3 c2;
    CollObj *prev;
    CollObj *obj;
    ModelTri *tris;
    ModelTri *tri;
    ModelVtx *verts;
    s32 i;
    s32 k;
    s32 j;
    f32 len0;
    f32 len1;
    f32 len2;
    f32 d0;
    f32 d1;
    f32 t;

    prev = NULL;
    D_800B76A4 = 0;
    if (x0 < D_8014A8F8.x || D_8014A908.x < x1 || y0 < D_8014A8F8.y || D_8014A908.y < y1
        || z0 < D_8014A8F8.z || D_8014A908.z < z1) {
        func_800899DC("Box outside of defined collision volume");
    }
    for (i = 0; i < D_800B76A0; i++) {
        obj = D_80140FF8[i].obj;
        if (obj != prev) {
            p0.x = x0 - obj->pos.x;
            p0.y = y0 - obj->pos.y;
            p0.z = z0 - obj->pos.z;
            p1.x = x1 - obj->pos.x;
            p1.y = y1 - obj->pos.y;
            p1.z = z1 - obj->pos.z;
            prev = obj;
            tris = D_800F80E8[obj->model];
            verts = D_800FA860[obj->model];
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
        if (p1.y < tv[0].y) {
            continue;
        }
        if (p0.y > tv[1].y && p0.y > tv[2].y) {
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
        if (func_8002DD60(normal.x) < 0.01 && func_8002DD60(normal.y) < 0.01 && func_8002DD60(normal.z) < 0.01) {
            normal.y = 1.0f;
        }
        len0 = sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        normal.x /= len0;
        normal.y /= len0;
        normal.z /= len0;
        if (tv[0].x > p0.x && tv[0].x < p1.x && tv[0].y > p0.y && tv[0].y < p1.y
            && tv[0].z > p0.z && tv[0].z < p1.z) {
            goto found;
        }
        if (tv[1].x > p0.x && tv[1].x < p1.x && tv[1].y > p0.y && tv[1].y < p1.y
            && tv[1].z > p0.z && tv[1].z < p1.z) {
            goto found;
        }
        if (tv[2].x > p0.x && tv[2].x < p1.x && tv[2].y > p0.y && tv[2].y < p1.y
            && tv[2].z > p0.z && tv[2].z < p1.z) {
            goto found;
        }
        for (k = 0; k < 3; k++) {
            j = (k + 1) % 3;
            if ((tv[k].x < p0.x && p0.x < tv[j].x) || (p0.x < tv[k].x && tv[j].x < p0.x)) {
                t = (p0.x - tv[k].x) / (tv[j].x - tv[k].x);
                e0.y = tv[k].y + (tv[j].y - tv[k].y) * t;
                e0.z = tv[k].z + (tv[j].z - tv[k].z) * t;
                if (p0.y < e0.y && e0.y < p1.y && p0.z < e0.z && e0.z < p1.z) {
                    goto found;
                }
            }
            if ((tv[k].x < p1.x && p1.x < tv[j].x) || (p1.x < tv[k].x && tv[j].x < p1.x)) {
                t = (p1.x - tv[k].x) / (tv[j].x - tv[k].x);
                e0.y = tv[k].y + (tv[j].y - tv[k].y) * t;
                e0.z = tv[k].z + (tv[j].z - tv[k].z) * t;
                if (p0.y < e0.y && e0.y < p1.y && p0.z < e0.z && e0.z < p1.z) {
                    goto found;
                }
            }
            if ((tv[k].y < p0.y && p0.y < tv[j].y) || (p0.y < tv[k].y && tv[j].y < p0.y)) {
                t = (p0.y - tv[k].y) / (tv[j].y - tv[k].y);
                e0.x = tv[k].x + (tv[j].x - tv[k].x) * t;
                e0.z = tv[k].z + (tv[j].z - tv[k].z) * t;
                if (p0.x < e0.x && e0.x < p1.x && p0.z < e0.z && e0.z < p1.z) {
                    goto found;
                }
            }
            if ((tv[k].y < p1.y && p1.y < tv[j].y) || (p1.y < tv[k].y && tv[j].y < p1.y)) {
                t = (p1.y - tv[k].y) / (tv[j].y - tv[k].y);
                e0.x = tv[k].x + (tv[j].x - tv[k].x) * t;
                e0.z = tv[k].z + (tv[j].z - tv[k].z) * t;
                if (p0.x < e0.x && e0.x < p1.x && p0.z < e0.z && e0.z < p1.z) {
                    goto found;
                }
            }
            if ((tv[k].z < p0.z && p0.z < tv[j].z) || (p0.z < tv[k].z && tv[j].z < p0.z)) {
                t = (p0.z - tv[k].z) / (tv[j].z - tv[k].z);
                e0.x = tv[k].x + (tv[j].x - tv[k].x) * t;
                e0.y = tv[k].y + (tv[j].y - tv[k].y) * t;
                if (p0.x < e0.x && e0.x < p1.x && p0.y < e0.y && e0.y < p1.y) {
                    goto found;
                }
            }
            if ((tv[k].z < p1.z && p1.z < tv[j].z) || (p1.z < tv[k].z && tv[j].z < p1.z)) {
                t = (p1.z - tv[k].z) / (tv[j].z - tv[k].z);
                e0.x = tv[k].x + (tv[j].x - tv[k].x) * t;
                e0.y = tv[k].y + (tv[j].y - tv[k].y) * t;
                if (p0.x < e0.x && e0.x < p1.x && p0.y < e0.y && e0.y < p1.y) {
                    goto found;
                }
            }
        }
        for (k = 0; k < 12; k++) {
            if (k < 4) {
                a.y = p0.y;
                b.y = p1.y;
                if (k == 0) {
                    a.x = b.x = p0.x;
                    a.z = b.z = p0.z;
                } else if (k == 1) {
                    a.x = b.x = p0.x;
                    a.z = b.z = p1.z;
                } else if (k == 2) {
                    a.x = b.x = p1.x;
                    a.z = b.z = p1.z;
                } else if (k == 3) {
                    a.x = b.x = p1.x;
                    a.z = b.z = p0.z;
                }
            } else if (k < 8) {
                a.x = p0.x;
                b.x = p1.x;
                if (k == 4) {
                    a.y = b.y = p0.y;
                    a.z = b.z = p0.z;
                } else if (k == 5) {
                    a.y = b.y = p0.y;
                    a.z = b.z = p1.z;
                } else if (k == 6) {
                    a.y = b.y = p1.y;
                    a.z = b.z = p1.z;
                } else if (k == 7) {
                    a.y = b.y = p1.y;
                    a.z = b.z = p0.z;
                }
            } else {
                a.z = p0.z;
                b.z = p1.z;
                if (k == 8) {
                    a.x = b.x = p0.x;
                    a.y = b.y = p0.y;
                } else if (k == 9) {
                    a.x = b.x = p0.x;
                    a.y = b.y = p1.y;
                } else if (k == 10) {
                    a.x = b.x = p1.x;
                    a.y = b.y = p1.y;
                } else if (k == 11) {
                    a.x = b.x = p1.x;
                    a.y = b.y = p0.y;
                }
            }
            {
                f32 sign;

                dir.x = b.x - a.x;
                dir.y = b.y - a.y;
                dir.z = b.z - a.z;
                len1 = sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
                dir.x /= len1;
                dir.y /= len1;
                dir.z /= len1;
                tmp.x = a.x - tv[0].x;
                tmp.y = a.y - tv[0].y;
                tmp.z = a.z - tv[0].z;
                d0 = normal.x * tmp.x + normal.y * tmp.y + normal.z * tmp.z;
                tmp.x = b.x - tv[0].x;
                tmp.y = b.y - tv[0].y;
                tmp.z = b.z - tv[0].z;
                d1 = normal.x * tmp.x + normal.y * tmp.y + normal.z * tmp.z;
                sign = -1.0f;
                if (d0 >= 0.0 && d1 < 0.0) {
                    sign = 1.0f;
                }
                if (!(d0 >= 0.0 && d1 < 0.0) && !(d1 >= 0.0 && d0 < 0.0)) {
                    continue;
                }
                t = d0 - d1;
                t = d0 / t;
                if (t < 0.0 || t > 1.0) {
                    continue;
                }
                hit.x = a.x + (b.x - a.x) * t;
                hit.y = a.y + (b.y - a.y) * t;
                hit.z = a.z + (b.z - a.z) * t;
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
            goto found;
        }
        continue;
    found:
        if (D_800B76A4 >= 0x80) {
            func_800899DC(D_80007D14);
        }
        if (flags & 2) {
            tri->flags |= 8;
            D_800B76A8++;
        }
        len2 = sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        normal.x /= len2;
        normal.y /= len2;
        normal.z /= len2;
        D_80148CF8[D_800B76A4].kind = 1;
        D_80148CF8[D_800B76A4].height = 0.0f;
        D_80148CF8[D_800B76A4].normal.x = normal.x;
        D_80148CF8[D_800B76A4].normal.y = normal.y;
        D_80148CF8[D_800B76A4].normal.z = normal.z;
        D_80148CF8[D_800B76A4].t = 0.0f;
        D_80148CF8[D_800B76A4].world.x = 0.0f;
        D_80148CF8[D_800B76A4].world.y = 0.0f;
        D_80148CF8[D_800B76A4].world.z = 0.0f;
        D_80148CF8[D_800B76A4].hit.x = 0.0f;
        D_80148CF8[D_800B76A4].hit.y = 0.0f;
        D_80148CF8[D_800B76A4].hit.z = 0.0f;
        D_80148CF8[D_800B76A4].obj = obj;
        D_80148CF8[D_800B76A4].tri = tri;
        D_800B76A4++;
        if (flags & 1) {
            break;
        }
    }
    return D_800B76A4;
}
