typedef struct Obj Obj;
s32 cameraGetMode(void);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
Obj *spawnEffectObj(s32, s32, s32, s32);
s32 func_80023DBC(s32);
s32 heapAlloc(s32);
void syncActorPrevPos(Obj *);
Obj *func_80042F00(s32, s32, s32, s32);
void func_80043328(Obj *, s32, s32);
void func_80047864(s32, s32, s32, s32, s32);
s32 func_80047898(void);
void func_80050460(void *, void *);
Obj *func_80076BF0(Obj *);
void func_8000F670();
extern char func_80023078[];
void func_80065C20();
void func_80065D2C();
void func_80065F84();
void func_80066628();
void func_8006776C();
void func_8006808C();
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ u8 pad10[0x48];
    /* 0x58 */ s32 f58;
    /* 0x5C */ u8 pad5C[0x1C];
    /* 0x78 */ s32 f78;
    /* 0x7C */ s32 f7C;
    /* 0x80 */ s32 f80;
    /* 0x84 */ u8 pad84[8];
    /* 0x8C */ s32 f8C;
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[4];
    /* 0x98 */ void *f98;
    /* 0x9C */ void *f9C;
    /* 0xA0 */ void *fA0;
    /* 0xA4 */ Obj *fA4;
    /* 0xA8 */ Obj *fA8;
    /* 0xAC */ u8 padAC[0x10];
    /* 0xBC */ s32 fBC;
    /* 0xC0 */ u8 padC0[0x18];
    /* 0xD8 */ void *fD8;
    /* 0xDC */ u8 padDC[0xC];
    /* 0xE8 */ s32 fE8;
    /* 0xEC */ u8 padEC[8];
    /* 0xF4 */ s32 fF4;
    /* 0xF8 */ u8 padF8[0x10];
};
extern Obj *D_800AB9BC;
extern Obj *D_800AB9C0;
extern u8 D_800BCFB8[];
extern char D_8014AA5C[];

Obj *func_80065D68(Obj *arg0) {
    Obj *o;
    Obj *p;
    Obj *c;
    s32 h;
    s32 i;

    if (D_800BCFB8[cameraGetMode()] != 0) {
        return func_80076BF0(arg0);
    }
    func_80050460(func_80065C20, D_8014AA5C);
    o = func_80042F00(0x34, 0, 0, 0);
    func_80043328(o, 0xF4, 0x100);
    o->f0 = 0x101E;
    o->f9C = func_80065F84;
    if (arg0 != 0) {
        o->x = arg0->x;
        o->y = arg0->y;
        o->z = arg0->z;
    }
    syncActorPrevPos(o);
    o->fD8 = func_80066628;
    o->f78 = 4;
    o->f7C = 0;
    o->f80 = 0x19;
    o->f8C = heapAlloc(0x100);
    o->f98 = func_8006776C;
    o->fA0 = func_80065D2C;
    o->fBC = func_80023DBC(0xEAB);
    o->f58 = packDrawFlags(1, 1, 2, 3, 1, 0, 1, 0);
    h = func_80047898();
    o->fE8 = h;
    func_80047864(h, 0, 0, -0x78, 0);
    func_80047864(h, 0, 0, -0x78, 0);
    for (p = D_800AB9BC; p <= D_800AB9C0; p++) {
        if (p->f9C == func_8000F670) {
            o->fA8 = p;
            p->f9C = func_80023078 + 8;
            break;
        }
    }
    for (i = 0; i < 4; i++) {
        p = spawnEffectObj(1, 0, 0, 0);
        p->f90 = i + 1;
        p->fA4 = o;
        p->f9C = func_8006808C;
        p->fF4 = 0;
    }
    return o;
}

