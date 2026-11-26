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

void *func_800253A0(s32);
void func_8002E1FC(Vec3f *, Vec3f *, Vec3f *);
void func_80080F64(Seg *, Vec3f *, Vec3f *);
void func_80081074(Seg *, Vec3f *, Vec3f *, Vec3f *, Vec3f *);
void func_800899DC(char *, ...);

extern char D_800097D4[];
extern char D_800097F4[];
extern char D_80009810[];
extern f32 D_80009830;
extern const f32 D_80009834;
extern const f32 D_80009838;
extern s32 D_8014A928[];
extern Vec3i *D_8014A9A8[];
extern Vec3f D_80170600[];
extern Seg *D_801718C0[];
extern u8 D_80171938[];

void func_80081588(s32 idx, s32 closed) {
    s32 n;
    Vec3i *src;
    Seg *segs;
    Vec3f *pts;
    s32 i;
    s32 last;
    f32 k;

    n = D_8014A928[idx];
    src = D_8014A9A8[idx];
    segs = func_800253A0(n * 0x30);
    pts = func_800253A0(n * 0xC);
    if (D_801718C0[idx] != NULL) {
        func_800899DC(D_800097D4, idx, D_800097F4, 382);
        return;
    }
    if (n == 0) {
        func_800899DC(D_80009810, idx, D_800097F4, 387);
        return;
    }
    D_801718C0[idx] = segs;
    D_80171938[idx] = closed;
    for (i = 0; i < n; i++) {
        pts[i].x = src[i].x;
        pts[i].y = src[i].y;
        pts[i].z = src[i].z;
    }
    i = 1;
    if (i < n - 1) {
        k = D_80009830;
        do {
            func_8002E1FC(&D_80170600[i], &pts[i + 1], &pts[i - 1]);
            D_80170600[i].x *= k;
            D_80170600[i].y *= k;
            D_80170600[i].z *= k;
            i++;
        } while (i < n - 1);
    }
    if (closed) {
        func_8002E1FC(&D_80170600[0], &pts[1], &pts[n - 1]);
        D_80170600[0].x *= D_80009834;
        D_80170600[0].y *= D_80009834;
        D_80170600[0].z *= D_80009834;
        func_8002E1FC(&D_80170600[n - 1], &pts[0], &pts[n - 2]);
        D_80170600[n - 1].x *= D_80009834;
        D_80170600[n - 1].y *= D_80009834;
        D_80170600[n - 1].z *= D_80009834;
        for (i = 0; i <= n - 1; i++) {
            func_80081074(&segs[i], &pts[i], &pts[(i + 1) % n], &D_80170600[i], &D_80170600[(i + 1) % n]);
        }
    } else {
        func_8002E1FC(&D_80170600[0], &pts[1], &pts[0]);
        D_80170600[0].x *= D_80009838;
        D_80170600[0].y *= D_80009838;
        D_80170600[0].z *= D_80009838;
        func_8002E1FC(&D_80170600[n - 1], &pts[n - 1], &pts[n - 2]);
        D_80170600[n - 1].x *= D_80009838;
        D_80170600[n - 1].y *= D_80009838;
        D_80170600[n - 1].z *= D_80009838;
        for (i = 0; i <= n - 2; i++) {
            func_80080F64(&segs[i], &pts[i], &D_80170600[i]);
        }
    }
}
