typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[4];
    s32 f14;
    u8 pad18[0x64];
    s32 f7C;
    u8 pad80[0x20];
    void (*fA0)(struct Obj *);
} Obj;
s32 func_8002D5CC(Obj *);
void func_8003C140(Obj *);
extern Obj *D_800BD06C;

void func_8000E570(Obj *o) {
    s32 t;
    s32 q;
    s32 dz;
    s32 dx;
    s32 dy;

    if (func_8002D5CC(o) != 0) {
        o->fA0(o);
        return;
    }
    dz = o->f7C / 50;
    o->z -= dz;
    o->y -= dz / 2;
    o->f14 -= o->f7C;
    o->f7C += 0x80;
    dx = D_800BD06C->x - o->x;
    dz = D_800BD06C->z - o->z;
    dy = D_800BD06C->y - o->y;
    if (abs(dx) < 19001 && abs(dz) < 19001 && abs(dy) < 19001 && dx * dx + dz * dz + dy * dy <= 0x4203F) {
        func_8003C140(D_800BD06C);
    }
}
