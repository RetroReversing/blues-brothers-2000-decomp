typedef struct Obj {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    u8 pad10[0x60 - 0x10];
    s32 x60;
    u8 pad64[0x70 - 0x64];
    s32 x70;
    u8 pad74[0x7C - 0x74];
    s32 x7C;
    u8 pad80[0x9C - 0x80];
    void *x9C;
} Obj;

extern Obj *func_800232B4(s32, s32, s32, s32);
extern void func_80065630(Obj *);
extern void func_800694A0(void);
extern s32 D_8014AB48[];

Obj *func_80069404(Obj *o) {
    Obj *c;
    s32 v;

    c = func_800232B4(0x101, o->x4, o->x8 + 200.0f, o->xC);
    func_80065630(c);
    v = D_8014AB48[o->x70];
    c->x7C = 0;
    c->x9C = func_800694A0;
    c->x60 = v;
    return c;
}
