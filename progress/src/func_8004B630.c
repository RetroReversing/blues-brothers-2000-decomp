typedef struct Vtx16 {
    s16 x;
    s16 y;
    s16 z;
    char pad[10];
} Vtx16;

typedef struct Tri {
    u16 v[3];
    u8 flags;
    u8 x7;
} Tri;

f32 func_8002DD60(f32);
f32 sqrtf(f32);

extern u8 D_80140FF3[];

void func_8004B630(Vtx16 *verts, s32 *idx, s8 *box, Tri *tri) {
    f32 a[3];
    f32 b[3];
    f32 n[3];
    f32 len;
    s32 maxx;
    s32 minx;
    s32 maxz;
    s32 minz;
    s32 i;
    s32 first;

    minx = maxx = verts[idx[0]].x;
    minz = maxz = verts[idx[0]].z;
    for (i = 1; i < 3; i++) {
        if (verts[idx[i]].x < minx) {
            minx = verts[idx[i]].x;
        }
        if (maxx < verts[idx[i]].x) {
            maxx = verts[idx[i]].x;
        }
        if (verts[idx[i]].z < minz) {
            minz = verts[idx[i]].z;
        }
        if (maxz < verts[idx[i]].z) {
            maxz = verts[idx[i]].z;
        }
    }
    minx >>= 7;
    maxx >>= 7;
    minz >>= 7;
    maxz >>= 7;
    box[0] = minx;
    box[1] = maxx;
    box[2] = minz;
    box[3] = maxz;
    first = verts[idx[0]].y >= verts[idx[1]].y;
    if (verts[idx[2]].y < verts[idx[first]].y) {
        first = 2;
    }
    for (i = 0; i < 3; i++) {
        tri->v[i] = idx[(first + i) % 3];
    }
    a[0] = verts[tri->v[1]].x - verts[tri->v[0]].x;
    a[1] = verts[tri->v[1]].y - verts[tri->v[0]].y;
    a[2] = verts[tri->v[1]].z - verts[tri->v[0]].z;
    b[0] = verts[tri->v[2]].x - verts[tri->v[0]].x;
    b[1] = verts[tri->v[2]].y - verts[tri->v[0]].y;
    b[2] = verts[tri->v[2]].z - verts[tri->v[0]].z;
    n[0] = a[1] * b[2] - a[2] * b[1];
    n[1] = a[2] * b[0] - a[0] * b[2];
    n[2] = a[0] * b[1] - a[1] * b[0];
    if (func_8002DD60(n[0]) < 0.01 && func_8002DD60(n[1]) < 0.01 && func_8002DD60(n[2]) < 0.01) {
        n[1] = 1.0f;
    }
    len = sqrtf(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    n[0] /= len;
    n[1] /= len;
    n[2] /= len;
    tri->flags = 0;
    tri->x7 = D_80140FF3[0];
    if (func_8002DD60(n[1]) < 0.5) {
        tri->flags |= 2;
    } else if (n[1] >= 0.0) {
        tri->flags |= 1;
    }
}
