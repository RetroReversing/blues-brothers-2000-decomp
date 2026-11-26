typedef struct Obj {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1C;
    s32 x20;
    s32 x24;
    u8 pad28[0x6C - 0x28];
    s32 x6C;
    s32 x70;
    s32 x74;
    s32 x78;
    s32 x7C;
    s32 x80;
    u8 pad84[0x90 - 0x84];
    s32 x90;
    s32 x94;
    u8 pad98[4];
    void *x9C;
    u8 padA0[0xC0 - 0xA0];
    s32 xC0;
} Obj;

extern void func_80034F1C(Obj *);
extern void func_80023078(void);
extern void func_800340B4(void);
extern Obj *D_800BD06C;

void func_80034E40(Obj *o) {
    Obj *p;

    o->x10 = 0;
    o->x18 = 0;
    o->x14 = -0x800;
    o->x78 = 0x44C;
    o->x9C = (s8 *)&func_80023078 + 8;
    o->x74 = 0;
    o->x78 = 0x1388;
    o->x9C = func_800340B4;
    o->x6C = 1;
    p = D_800BD06C;
    o->x7C = 0xBB8;
    o->x80 = -0x1000;
    o->x90 = 0x3E8;
    o->x94 = 0x1388;
    o->x1C = p->x4;
    o->x20 = p->x8;
    o->x24 = p->xC;
    o->xC0 = 0;
    o->x70 = 0x44C;
    o->x7C = 0x3E8;
    o->x80 = -0x800;
    func_80034F1C(o);
    o->x78 = o->x7C;
    o->x10 = o->x74;
    o->x14 = o->x80;
}
