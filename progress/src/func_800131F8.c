typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0x34];
    f32 f44;
    u8 pad48[0x54];
    void *f9C;
    u8 padA0[0xC];
    s32 fAC;
    f32 fB0;
    s32 fB4;
} Obj;
void func_8002D9B0(Obj *);
void func_8002D9F8(Obj *);
void func_8003BF98(Obj *);
extern Obj *D_800BD06C;
void func_80013308(void);

void func_800131F8(Obj *o) {
    s32 dx;
    s32 dz;

    o->fAC = 0;
    o->fB4 = 0;
    o->fB0 = -4900.0f;
    func_8002D9F8(o);
    func_8002D9B0(o);
    if (o->y < o->f44 - 5000.0f) {
        o->f9C = func_80013308;
    }
    dx = D_800BD06C->x - o->x;
    dz = D_800BD06C->z - o->z;
    if (abs(dx) < 201 && abs(dz) < 201 && abs((s32)(o->y - 400.0f - D_800BD06C->y + 200.0f)) < 400) {
        func_8003BF98(o);
    }
}

