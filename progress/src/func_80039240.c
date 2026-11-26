typedef struct Obj {
    u8 pad0[8];
    f32 x8;
    u8 padC[4];
    s32 x10;
    u8 pad14[0x4C - 0x14];
    f32 x4C;
    u8 pad50[4];
    f32 x54;
    u8 pad58[0x9C - 0x58];
    void *x9C;
} Obj;

extern void func_80043328(Obj *, s32, s32);
extern s32 animStepKeys(Obj *);
extern s16 sins(u16);
extern s16 coss(u16);
extern void func_8002DA80(Obj *);
extern f32 func_800385AC(Obj *);
extern void func_8003CAD4(Obj *, s32);
extern void func_800393F4(void);

void func_80039240(Obj *o) {
    s32 r;
    s32 k;

    func_80043328(o, 2, 0x100);
    r = animStepKeys(o);
    k = 400;
    o->x4C = (sins(*(u16 *)((u8 *)o + 0x12)) * k) >> 15;
    o->x54 = (coss(*(u16 *)((u8 *)o + 0x12)) * k) >> 15;
    func_8002DA80(o);
    o->x8 = func_800385AC(o);
    if (r != 0) {
        func_8003CAD4(o, o->x10);
        o->x9C = func_800393F4;
    }
}
