typedef struct Part13A8 {
    s32 x;
    s32 y;
    s32 z;
    s32 vx;
    s32 vy;
    s32 vz;
} Part13A8;

typedef struct Obj13A8 {
    u8 pad0[0x58];
    s32 c58;
    u8 pad5C[0xC];
    s32 c68;
    u8 pad6C[8];
    s32 grav;
    s32 speed;
    s32 spread;
    s32 dir;
    s32 count;
    s32 next;
    u8 pad8C[0x38];
    Part13A8 *parts;
} Obj13A8;

extern void *func_800253A0(s32);
extern s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_80024394(s32, s32);
extern s32 func_8002D1A0(void);
extern s32 sins(u16);
extern s32 coss(u16);
extern u8 D_800B9EA0[];

void func_800213A8(Obj13A8 *o) {
    Part13A8 *p;
    Part13A8 *q;
    s32 i;
    s32 j;
    s32 r;
    u16 a;
    u16 b;
    s16 s;
    s16 c;

    if (o->parts == NULL) {
        o->c68 = 13;
        q = o->parts = func_800253A0(o->count * 24);
        for (i = 0; i < o->count; i++) {
            q[i].x = 0;
            q[i].y = 0;
            q[i].z = 0;
            q[i].vx = 0;
            q[i].vy = 0;
            q[i].vz = 0;
        }
        o->c58 = func_800221C0(0, 1, 1, 3, 0, 0, 1, 0);
    }
    j = o->next;
    q = o->parts;
    if (j == o->count) {
        j = 0;
    }
    for (i = 0; i < o->count; i++) {
        p = &q[i];
        p->vy -= o->grav * (*(s32 *)D_800B9EA0) / 100;
        p->x += p->vx * (*(s32 *)D_800B9EA0) / 100;
        p->z += p->vz * (*(s32 *)D_800B9EA0) / 100;
        p->y += p->vy * (*(s32 *)D_800B9EA0) / 100;
        if (i == o->next) {
            r = o->speed + func_80024394(0, 100);
            a = func_8002D1A0();
            b = func_80024394(o->dir - 1000, o->dir + 1000);
            s = sins(a);
            c = coss(b);
            p->vx = ((r * s) >> 15) * c >> 15;
            s = coss(a);
            c = coss(b);
            p->vz = ((r * s) >> 15) * c >> 15;
            s = sins(b);
            p->y = 10;
            p->vy = (r * s) >> 15;
            p->x = func_80024394(-o->spread, o->spread);
            p->z = func_80024394(-o->spread, o->spread);
        }
        if (i == j) {
            r = o->speed + func_80024394(0, 100);
            a = func_8002D1A0();
            b = func_80024394(o->dir - 1000, o->dir + 1000);
            s = sins(a);
            c = coss(b);
            p->vx = ((r * s) >> 15) * c >> 15;
            s = coss(a);
            c = coss(b);
            p->vz = ((r * s) >> 15) * c >> 15;
            s = sins(b);
            p->y = 10;
            p->vy = (r * s) >> 15;
            p->x = func_80024394(-o->spread, o->spread);
            p->z = func_80024394(-o->spread, o->spread);
        }
    }
    if (o->count >= 91) {
        o->next += 5;
    } else {
        o->next += 2;
    }
    o->next = o->next % o->count;
}
