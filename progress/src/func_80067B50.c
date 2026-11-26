typedef struct Obj {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    u8 pad10[0x90 - 0x10];
    s32 x90;
    u8 pad94[0xC0 - 0x94];
    s32 xC0;
} Obj;

extern f32 func_8002D66C(Obj *, f32, s32 *);
extern s32 func_80013654(Obj *);
extern s32 func_800137E0(Obj *);
extern Obj *D_800BD06C;

s32 func_80067B50(Obj *o) {
    f32 d;
    f32 t;
    f32 x;
    f32 z;
    Obj *p;

    d = func_8002D66C(o, 400.0f, NULL);
    o->x90 = d;
    if (d == 0.0f) {
        return 0;
    }
    if (360.0f <= d) {
        return 0;
    }
    if (d < 350.0f) {
        p = D_800BD06C;
        t = 350.0f - d;
        x = (o->x4 - p->x4) * t / d;
        z = (o->xC - p->xC) * t / d;
        p->x4 -= x;
        p->xC -= z;
        o->xC0 |= 1;
    }
    if (func_80013654(D_800BD06C) != 0) {
        o->xC0 |= 2;
    }
    if (func_800137E0(D_800BD06C) != 0) {
        o->xC0 |= 8;
    }
    return 0;
}
