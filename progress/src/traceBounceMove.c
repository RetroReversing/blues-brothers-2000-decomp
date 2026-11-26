typedef struct Vec8CF8 {
    f32 x;
    f32 y;
    f32 z;
} Vec8CF8;

typedef struct Hit8CF8 {
    u8 pad0[8];
    Vec8CF8 n;
    u8 pad14[4];
    Vec8CF8 p;
    u8 pad24[0x10];
    s32 id;
} Hit8CF8;

extern f32 sqrtf(f32);
extern s32 probeCollision(Vec8CF8 *, Vec8CF8 *, s32);
extern const f32 D_80001540;
extern const f64 D_80001548;
extern u8 D_8014014C[];
extern u8 D_80140190[];
extern Hit8CF8 D_80148CF8;

#define DEPTH (*(s32 *) D_8014014C)
#define LASTID (*(s32 *) D_80140190)

/* Moves a point from `from` toward `to` with velocity `vel`. On each hit it reflects the remaining move and velocity off the surface, recursing up to 16 bounces. Writes the final position to out and velocity to outv. Returns 1 if it hit something, 0 if it did not. */
s32 traceBounceMove(Vec8CF8 *from, Vec8CF8 *to, Vec8CF8 *vel, Vec8CF8 *out, Vec8CF8 *outv) {
    Vec8CF8 a;
    Vec8CF8 b;
    Vec8CF8 c;
    Vec8CF8 v;
    Vec8CF8 cr;
    Vec8CF8 t;
    Vec8CF8 d;
    f32 len;
    f32 vlen;
    f32 k;
    Hit8CF8 *h;
    s32 ret;

    if (DEPTH == 0) {
        LASTID = 0;
    }
    DEPTH++;
    if (DEPTH > 16) {
        *out = *from;
        DEPTH--;
        return 1;
    }
    *out = *to;
    *outv = *vel;
    if (from->x == to->x && from->y == to->y && from->z == to->z) {
        DEPTH--;
        return 0;
    }
    a = *from;
    b = *to;
    v = *vel;
    d.x = b.x - a.x;
    d.y = b.y - a.y;
    d.z = b.z - a.z;
    len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
    k = len + D_80001540;
    d.x /= len;
    d.y /= len;
    d.z /= len;
    c.x = a.x + d.x * k;
    c.y = a.y + d.y * k;
    c.z = a.z + d.z * k;
    vlen = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    if (probeCollision(&a, &c, 1) > 0) {
        h = &D_80148CF8;
        if (h->id == LASTID) {
            DEPTH--;
            return 1;
        }
        cr.x = d.y * h->n.z - d.z * h->n.y;
        cr.y = d.z * h->n.x - d.x * h->n.z;
        cr.z = d.x * h->n.y - d.y * h->n.x;
        t.x = h->n.y * cr.z - h->n.z * cr.y;
        t.y = h->n.z * cr.x - h->n.x * cr.z;
        t.z = h->n.x * cr.y - h->n.y * cr.x;
        LASTID = h->id;
        b.x = h->p.x - d.x * D_80001548;
        b.y = h->p.y - d.y * D_80001548;
        b.z = h->p.z - d.z * D_80001548;
        b.x += t.x * len;
        b.y += t.y * len;
        b.z += t.z * len;
        v.x = t.x * vlen;
        v.y = t.y * vlen;
        v.z = t.z * vlen;
        *out = b;
        *outv = v;
        traceBounceMove(&a, &b, &v, out, outv);
        DEPTH--;
        return 1;
    }
    DEPTH--;
    return 0;
}
