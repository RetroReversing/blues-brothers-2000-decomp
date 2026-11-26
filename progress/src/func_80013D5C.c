typedef struct Obj {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    u8 pad10[0x64 - 0x10];
    s32 x64;
    u8 pad68[0xB8 - 0x68];
    s32 xB8;
} Obj;

typedef struct Range {
    s32 x;
    s32 y;
    s32 z;
} Range;

extern s32 func_8002D5CC(Obj *);
extern void func_8003BF98(Obj *);
extern Obj *D_800BD06C;
extern Range D_800F4A00[];
extern Range D_800F6188[];

void func_80013D5C(Obj *o) {
    Obj *p;
    s32 d;

    p = D_800BD06C;
    d = p->x4 - o->x4;
    if (d > 0 ? D_800F4A00[o->xB8].x < d : d < D_800F6188[o->xB8].x) {
        return;
    }
    d = p->xC - o->xC;
    if (d > 0 ? D_800F4A00[o->xB8].z < d : d < D_800F6188[o->xB8].z) {
        return;
    }
    if (func_8002D5CC(p) != 0 && p->x8 < o->x8 - 25.0f) {
        func_8003BF98(p);
        p->x64 = 50;
    }
}
