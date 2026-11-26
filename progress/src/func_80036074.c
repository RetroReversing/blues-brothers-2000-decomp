typedef struct Obj6074 {
    char pad0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 rx;
    s32 ry;
    char pad18[0x54];
    s32 idx;
    char pad70[8];
    s32 o78;
    s32 o7C;
} Obj6074;

typedef struct Cam6074 {
    s32 pad0;
    f32 x;
    f32 y;
    f32 z;
} Cam6074;

typedef struct Vec6074 {
    f32 x;
    f32 y;
    f32 z;
} Vec6074;

typedef struct Rec6074 {
    s32 dist;
    s32 pad;
} Rec6074;

extern f32 __cosf(f32);
extern f32 func_80095DC0(f32);
f32 sqrtf(f32);
extern void func_8002DC84(s32 *);
extern void func_8002DB6C(s32 *, s32 *, f32);
extern void func_8002DAE0(s32 *, s32 *, f32);
extern void func_8002DD8C(Vec6074 *, s32 *, f32 *);
extern void func_80036CF8(f32 *, f32 *, Vec6074 *, f32 *);
extern void func_80036BD0(f32 *, f32 *, Vec6074 *, f32 *);
extern void func_80048820(f32 *, f32 *, s32);
extern s32 func_80035364(f32 *, Vec6074 *, Vec6074 *);
extern s32 func_8002E1FC(f32 *, Vec6074 *, f32 *);
extern f32 func_8002E080(s32);
extern f64 D_80001428;
extern f32 D_80001430;
extern f32 D_80001434;
extern f32 D_80001438;
extern f32 D_8000143C;
extern f32 D_80001440;
extern f32 D_80001444;
extern f64 D_80001448;
extern Rec6074 D_800B4ABC[];
extern f32 D_800B4B84[][3];
extern u8 D_800BD06C[];

#define CAM (*(Cam6074 **)D_800BD06C)

s32 func_80036074(Obj6074 *arg0) {
    f32 cam[8];
    f32 off[4];
    s32 m1[10];
    s32 m2[10];
    Vec6074 pts[5];
    f32 a[4];
    f32 b[8];
    f32 c[4];
    Vec6074 hits[5];
    f32 rx;
    f32 ry;
    f32 r;
    f32 t;
    s32 i;
    s32 n;
    s32 bit;
    s32 mask;
    f32 d;

    rx = arg0->ry;
    ry = arg0->rx;
    rx *= D_80001428;
    ry *= D_80001428;
    r = (f32) D_800B4ABC[arg0->idx].dist;
    off[0] = arg0->x;
    off[1] = arg0->y;
    off[2] = arg0->z;
    cam[0] = CAM->x;
    cam[1] = CAM->y + D_80001430;
    cam[2] = CAM->z;
    func_8002DC84(m1);
    func_8002DC84(m2);
    func_8002DB6C(m1, m2, ry);
    func_8002DAE0(m2, m1, -rx);
    t = r * __cosf(rx);
    t *= func_80095DC0(ry);
    off[0] = cam[0] - t;
    off[1] = cam[1] - r * func_80095DC0(rx);
    t = r * __cosf(rx);
    t *= __cosf(ry);
    off[2] = cam[2] - t;
    mask = 0;
    bit = 1;
    r = D_80001434;
    for (i = 1; i < 5; i++) {
        func_8002DD8C(&pts[i], m2, D_800B4B84[i]);
        pts[i].x += off[0];
        pts[i].y += off[1];
        pts[i].z += off[2];
        if (i == 1) {
            func_80036CF8(a, b, &pts[1], cam);
        } else {
            func_80036BD0(a, b, &pts[i], cam);
        }
    }
    func_80048820(a, b, 3);
    for (i = 1; i < 5; i++) {
        if (func_80035364(cam, &pts[i], &hits[i]) != 0) {
            d = func_8002E080(func_8002E1FC(c, &hits[i], cam));
            if (d < r) {
                r = d;
            }
            mask |= bit;
        }
        bit <<= 1;
    }
    if (mask == 0) {
        return 0;
    }
    r -= D_80001438;
    if (r < D_8000143C) {
        return 1;
    }
    r = sqrtf(r * r - D_80001440 - D_80001444) + D_80001448;
    t = r * __cosf(rx);
    t *= func_80095DC0(ry);
    off[0] = cam[0] - t;
    off[1] = cam[1] - r * func_80095DC0(rx);
    t = r * __cosf(rx);
    t *= __cosf(ry);
    off[2] = cam[2] - t;
    mask = 0;
    for (i = 1; i < 5; i++) {
        func_8002DD8C(&pts[i], m2, D_800B4B84[i]);
        pts[i].x += off[0];
        pts[i].y += off[1];
        pts[i].z += off[2];
        if (func_80035364(cam, &pts[i], NULL) != 0) {
            mask |= bit;
        }
        bit <<= 1;
    }
    if (mask != 0) {
        return mask;
    }
    n = r;
    arg0->o78 = n;
    arg0->o7C = n;
    return 0;
}
