typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    s32 f10;
    u8 pad14[0x58];
    s32 f6C;
    u8 pad70[0x18];
    s32 f88;
    u8 pad8C[0x14];
    void (*fA0)(struct Obj *);
    u8 padA4[0x18];
    s32 fBC;
    u8 padC0[0x1C];
    f32 fDC;
} Obj;
f32 func_8002D858(Obj *, s32 *);
Obj *func_80023874(s32, s32);
s32 func_8004303C(Obj *);
void func_800773E8(Obj *);
float sqrtf(float);

s32 func_8007756C(Obj *o) {
    Obj *e;
    f32 dx;
    f32 dy;
    f32 dz;

    if (func_8002D858(o, &o->f10) < 490.0f) {
        return 2;
    }
    e = func_80023874(0x121, 0);
    if (e != NULL) {
        dx = e->x - o->x;
        dy = e->y - o->y;
        dz = e->z - o->z;
        if (sqrtf(dx * dx + dy * dy + dz * dz) < 300.0f) {
            e->fA0(e);
            return 3;
        }
    }
    if (func_8004303C(o)) {
        o->f6C = 0;
        o->f88++;
    }
    if (o->fBC / 2 + 1 < o->f88) {
        return 1;
    }
    if (o->fDC > 20.0f && o->f6C == 0) {
        o->f6C = 1;
        func_800773E8(o);
    }
    return 0;
}
