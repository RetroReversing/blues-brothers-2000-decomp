typedef struct Obj {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 rotA;
    /* 0x14 */ s32 rotB;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ s32 tx;
    /* 0x20 */ s32 ty;
    /* 0x24 */ s32 tz;
    /* 0x28 */ u8 pad28[0x18];
    /* 0x40 */ u8 sub40[0xC];
    /* 0x4C */ u8 sub4C[0x40];
    /* 0x8C */ u32 mode;
    /* 0x90 */ u32 state;
    /* 0x94 */ u8 pad94[0xC];
    /* 0xA0 */ void (*fn)(struct Obj *);
} Obj;
s32 func_80024394(s32, s32);                /* extern */
s32 func_80024B0C(s32);                             /* extern */
s32 func_80025100(s32, s32);                        /* extern */
s32 func_8002D204(s32, s32, s32);               /* extern */
s32 func_8002D4E0(Obj *, s32);             /* extern */
s32 func_8002D620(Obj *);                      /* extern */
f32 func_8002D66C(Obj *, s32, s32);        /* extern */
s32 func_8002DA80(Obj *);                      /* extern */
s32 func_80038C84(void *, void *, void *);      /* extern */
s32 func_8004303C(Obj *);                          /* extern */
s32 func_80043248(Obj *);                          /* extern */
s32 func_800433A8();   /* extern */
s32 func_8004EB60(Obj *);                      /* extern */
extern f32 D_80008314;
extern Obj *D_800BD06C;
extern s32 D_80107040[];


void func_80055604(Obj *o) {
    s32 a;
    s32 b;
    s32 dx;
    s32 dz;
    s32 dy;
    s32 dist;
    s32 hit;
    s32 tx;
    s32 tz;
    u32 mode;
    switch (o->state) {
    case 0:
        o->rotB = -0x4000;
        o->tx = (s32)o->x;
        o->state = 1;
        o->ty = (s32)o->y;
        o->tz = (s32)o->z;
        break;
    case 1:
        func_8004303C(o);
        dx = (s32)(D_800BD06C->x - o->x);
        dz = (s32)(D_800BD06C->z - o->z);
        if (dx * dx + dz * dz <= 0x3D08F) {
            o->state = 2;
            o->mode = 0;
            o->rotB = 0;
            func_800433A8(o, 0x4B, 0x100);
        }
        break;
    case 2:
        hit = func_8004303C(o);
        tx = o->tx;
        tz = o->tz;
        mode = o->mode;
        a = tx - (s32)o->x;
        b = tz - (s32)o->z;
        switch (mode) {
        case 0:
            if (a * a + b * b > 0x5F5E10) {
                o->mode = 1;
            } else {
                dx = (s32)(D_800BD06C->x - o->x);
                dz = (s32)(D_800BD06C->z - o->z);
                dy = (s32)((D_800BD06C->y - o->y) + D_80008314);
                o->rotA = func_8002D204(func_80025100(dx, dz), o->rotA, 0x400);
                o->rotB = func_8002D204(func_80025100(dy, func_80024B0C(dx * dx + dz * dz)), o->rotB, 0x400);
                func_8002D620(o);
                func_8002D4E0(o, 0x3E8);
                func_8002DA80(o);
                func_80038C84(o->sub40, &o->x, o->sub4C);
                if (hit != 0) {
                    func_800433A8(o, func_80024394(0, 1) + 0x4B, 0x100);
                }
            }
            break;
        case 1:
            dx = (s32)((f32)tx - o->x);
            dz = (s32)((f32)tz - o->z);
            dy = (s32)((f32)o->ty - o->y);
            dist = dx * dx + dz * dz;
            if (dist <= 0x3D08F) {
                o->state = mode;
                o->mode = 0;
                func_800433A8(o, 0x4A, 0x100);
            } else {
                o->rotA = func_8002D204(func_80025100(dx, dz), o->rotA, 0x400);
                o->rotB = func_8002D204(func_80025100(dy, func_80024B0C(dist)), o->rotB, 0x400);
                func_8002D620(o);
                func_8002D4E0(o, 0x320);
                func_8002DA80(o);
                func_80038C84(o->sub40, &o->x, o->sub4C);
            }
            break;
        }
        break;
    case 3:
        func_800433A8(o, 0x4D, 0x100);
        o->state = 4;
        break;
    case 4:
        if (func_80043248(o) != 0) {
            func_8004EB60(o);
            o->fn(o);
        }
        break;
    }
    if (((s32)func_8002D66C(o, 0x43C80000, 0) < 0x190) && (D_80107040[0] & 0x4000) && ((s32)o->state < 3)) {
        o->state = 3;
    }
}
