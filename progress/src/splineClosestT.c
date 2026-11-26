typedef struct {
    s32 x, y, z;
} Vec3i_812B4;

typedef struct {
    f32 x, y, z;
} Vec3f_812B4;

typedef struct {
    u8 data[0x30];
} Spline_812B4;

extern s32 gSplinePointCount[];
extern Vec3i_812B4 *gSplineSrcPoints[];
extern Spline_812B4 *gSplineSegs[];

f32 sqrtf(f32);
f32 func_80080DFC(void *arg0, f32 arg1);
f32 func_80080E38(void *arg0, f32 arg1);
f32 func_80080E74(void *arg0, f32 arg1);

/* Finds the point on spline `path` closest to `pos` (searching the nearest control point and its neighbours) and returns its parameter t. Optionally returns that point's position and distance in the XZ plane. */
f32 splineClosestT(s32 path, Vec3f_812B4 *pos, f32 *outDist, Vec3f_812B4 *outPos) {
    s32 n;
    s32 best;
    s32 i;
    s32 k;
    Vec3i_812B4 *pts;
    Spline_812B4 *spl;
    f32 bestDist;
    f32 dist;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 t;
    f32 frac;
    f32 ret;
    f32 count;
    f32 step;
    f32 fbest;
    Vec3f_812B4 p;

    n = gSplinePointCount[path];
    bestDist = 1e9f;
    best = 0;
    if (n == 0) {
        return 0.0f;
    }
    pts = gSplineSrcPoints[path];
    for (i = 0; i < n; i++) {
        dx = pos->x - pts[i].x;
        dy = pos->y - pts[i].y;
        dz = pos->z - pts[i].z;
        dist = sqrtf(dx * dx + dy * dy + dz * dz);
        if (dist < bestDist) {
            best = i;
            bestDist = dist;
        }
    }
    ret = best;
    count = n;
    spl = gSplineSegs[path];
    t = ret - 1.0f;
    if (t < 0.0f) {
        t = 0.0f;
    }
    step = 0.005f;
    for (; t < (f32)best + 1.0; step = 0.005f, t += step) {
        if (count <= t) {
            return ret;
        }
        k = t;
        frac = t - k;
        p.x = func_80080DFC(&spl[k], frac);
        p.y = func_80080E38(&spl[k], frac);
        p.z = func_80080E74(&spl[k], frac);
        dx = pos->x - p.x;
        dz = pos->z - p.z;
        dist = sqrtf(dx * dx + dz * dz);
        if (dist <= bestDist) {
            bestDist = dist;
            ret = t;
            if (outPos != NULL) {
                outPos->x = p.x;
                outPos->y = p.y;
                outPos->z = p.z;
            }
            if (outDist != NULL) {
                *outDist = bestDist;
            }
        }
    }
    return ret;
}
