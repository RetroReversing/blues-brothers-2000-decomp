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

/* Fills in a collision triangle from three vertex indices: its cell bounds (box, in
   128-unit cells), its vertices ordered from lowest to highest, and its surface flags
   (1 = floor, 2 = wall) from the normal's Y component. */
void setupCollisionTri(Vtx16 *verts, s32 *idx, s8 *box, Tri *tri) {
    f32 edgeA[3];
    f32 edgeB[3];
    f32 normal[3];
    f32 normLen;
    s32 maxX;
    s32 minX;
    s32 maxZ;
    s32 minZ;
    s32 i;
    s32 lowIdx;

    minX = maxX = verts[idx[0]].x;
    minZ = maxZ = verts[idx[0]].z;
    for (i = 1; i < 3; i++) {
        if (verts[idx[i]].x < minX) {
            minX = verts[idx[i]].x;
        }
        if (maxX < verts[idx[i]].x) {
            maxX = verts[idx[i]].x;
        }
        if (verts[idx[i]].z < minZ) {
            minZ = verts[idx[i]].z;
        }
        if (maxZ < verts[idx[i]].z) {
            maxZ = verts[idx[i]].z;
        }
    }
    minX >>= 7;
    maxX >>= 7;
    minZ >>= 7;
    maxZ >>= 7;
    box[0] = minX;
    box[1] = maxX;
    box[2] = minZ;
    box[3] = maxZ;
    lowIdx = verts[idx[0]].y >= verts[idx[1]].y;
    if (verts[idx[2]].y < verts[idx[lowIdx]].y) {
        lowIdx = 2;
    }
    for (i = 0; i < 3; i++) {
        tri->v[i] = idx[(lowIdx + i) % 3];
    }
    edgeA[0] = verts[tri->v[1]].x - verts[tri->v[0]].x;
    edgeA[1] = verts[tri->v[1]].y - verts[tri->v[0]].y;
    edgeA[2] = verts[tri->v[1]].z - verts[tri->v[0]].z;
    edgeB[0] = verts[tri->v[2]].x - verts[tri->v[0]].x;
    edgeB[1] = verts[tri->v[2]].y - verts[tri->v[0]].y;
    edgeB[2] = verts[tri->v[2]].z - verts[tri->v[0]].z;
    normal[0] = edgeA[1] * edgeB[2] - edgeA[2] * edgeB[1];
    normal[1] = edgeA[2] * edgeB[0] - edgeA[0] * edgeB[2];
    normal[2] = edgeA[0] * edgeB[1] - edgeA[1] * edgeB[0];
    if (func_8002DD60(normal[0]) < 0.01 && func_8002DD60(normal[1]) < 0.01 && func_8002DD60(normal[2]) < 0.01) {
        normal[1] = 1.0f;
    }
    normLen = sqrtf(normal[0] * normal[0] + normal[1] * normal[1] + normal[2] * normal[2]);
    normal[0] /= normLen;
    normal[1] /= normLen;
    normal[2] /= normLen;
    tri->flags = 0;
    tri->x7 = D_80140FF3[0];
    if (func_8002DD60(normal[1]) < 0.5) {
        tri->flags |= 2;
    } else if (normal[1] >= 0.0) {
        tri->flags |= 1;
    }
}
