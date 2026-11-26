typedef struct Vec3i {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct Seg {
    char pad[0x30];
} Seg;

void *heapAlloc(s32);
void vec3Sub(Vec3f *, Vec3f *, Vec3f *);
void initSplineEndSegment(Seg *, Vec3f *, Vec3f *);
void initSplineSegment(Seg *, Vec3f *, Vec3f *, Vec3f *, Vec3f *);
void debugPrintf(char *, ...);

extern char D_800097D4[];
extern char D_800097F4[];
extern char D_80009810[];
extern f32 D_80009830;
extern const f32 D_80009834;
extern const f32 D_80009838;
extern s32 gSplinePointCount[];
extern Vec3i *gSplineSrcPoints[];
extern Vec3f gSplineTangents[];
extern Seg *gSplineSegs[];
extern u8 gSplineClosed[];

/* Builds the spline with index idx from its control points: computes a tangent
 * per point (scaled by the spline's tension) and one segment per span. Open
 * splines end with the endpoint segment. Fails with a debug message if the spline
 * is already built or has no points. */
void initSpline(s32 idx, s32 closed) {
    s32 n;
    Vec3i *src;
    Seg *segs;
    Vec3f *pts;
    s32 i;
    s32 last;
    f32 k;

    n = gSplinePointCount[idx];
    src = gSplineSrcPoints[idx];
    segs = heapAlloc(n * 0x30);
    pts = heapAlloc(n * 0xC);
    if (gSplineSegs[idx] != NULL) {
        debugPrintf(D_800097D4, idx, D_800097F4, 382);
        return;
    }
    if (n == 0) {
        debugPrintf(D_80009810, idx, D_800097F4, 387);
        return;
    }
    gSplineSegs[idx] = segs;
    gSplineClosed[idx] = closed;
    for (i = 0; i < n; i++) {
        pts[i].x = src[i].x;
        pts[i].y = src[i].y;
        pts[i].z = src[i].z;
    }
    i = 1;
    if (i < n - 1) {
        k = D_80009830;
        do {
            vec3Sub(&gSplineTangents[i], &pts[i + 1], &pts[i - 1]);
            gSplineTangents[i].x *= k;
            gSplineTangents[i].y *= k;
            gSplineTangents[i].z *= k;
            i++;
        } while (i < n - 1);
    }
    if (closed) {
        vec3Sub(&gSplineTangents[0], &pts[1], &pts[n - 1]);
        gSplineTangents[0].x *= D_80009834;
        gSplineTangents[0].y *= D_80009834;
        gSplineTangents[0].z *= D_80009834;
        vec3Sub(&gSplineTangents[n - 1], &pts[0], &pts[n - 2]);
        gSplineTangents[n - 1].x *= D_80009834;
        gSplineTangents[n - 1].y *= D_80009834;
        gSplineTangents[n - 1].z *= D_80009834;
        for (i = 0; i <= n - 1; i++) {
            initSplineSegment(&segs[i], &pts[i], &pts[(i + 1) % n], &gSplineTangents[i], &gSplineTangents[(i + 1) % n]);
        }
    } else {
        vec3Sub(&gSplineTangents[0], &pts[1], &pts[0]);
        gSplineTangents[0].x *= D_80009838;
        gSplineTangents[0].y *= D_80009838;
        gSplineTangents[0].z *= D_80009838;
        vec3Sub(&gSplineTangents[n - 1], &pts[n - 1], &pts[n - 2]);
        gSplineTangents[n - 1].x *= D_80009838;
        gSplineTangents[n - 1].y *= D_80009838;
        gSplineTangents[n - 1].z *= D_80009838;
        for (i = 0; i <= n - 2; i++) {
            initSplineEndSegment(&segs[i], &pts[i], &gSplineTangents[i]);
        }
    }
}
