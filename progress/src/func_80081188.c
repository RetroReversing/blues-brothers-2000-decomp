typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;
f32 sqrtf(f32);
extern s32 gSplinePointCount[];
extern Vec3i *gSplineSrcPoints[];

s32 func_80081188(s32 idx, f32 *pos, f32 *outDist) {
    s32 n;
    f32 best;
    s32 bestIdx;
    s32 i;
    Vec3i *p;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;

    n = gSplinePointCount[idx];
    best = 1e+09f;
    bestIdx = 0;
    if (n == 0) {
        return bestIdx;
    }
    p = gSplineSrcPoints[idx];
    for (i = 0; i < n; i++) {
        dx = pos[0] - p[i].x;
        dy = pos[1] - p[i].y;
        dz = pos[2] - p[i].z;
        d = sqrtf(dx * dx + dy * dy + dz * dz);
        if (d < best) {
            bestIdx = i;
            best = d;
        }
    }
    if (outDist != 0) {
        *outDist = best;
    }
    return bestIdx;
}
