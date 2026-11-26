typedef struct Obj {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
} Obj;

extern f32 func_8002DD60(f32);
extern s32 func_80025100(s32, s32);
extern f32 sqrtf(f32);
extern Obj *D_800BD06C;

f32 func_8002D66C(Obj *o, f32 r, s32 *ang) {
    Obj *p;
    f32 dx;
    f32 dy;
    f32 dz;

    p = D_800BD06C;
    dx = p->x4 - o->x4;
    dy = p->x8 - o->x8;
    dz = p->xC - o->xC;
    if (r < func_8002DD60(dx)) {
        return r;
    }
    if (r < func_8002DD60(dz)) {
        return r;
    }
    if (300.0f < func_8002DD60(dy)) {
        return r;
    }
    if (ang != NULL) {
        *ang = func_80025100(dx, dz);
    }
    return sqrtf(dx * dx + dz * dz);
}
