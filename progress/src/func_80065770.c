typedef struct Obj {
    s32 f0;
    f32 x, y, z;
    u8 pad10[0x4C];
    s32 f5C;
    s32 f60;
    u8 pad64[8];
    s32 f6C;
    u8 pad70[0x28];
    void (*f98)(void);
    void *f9C;
    void (*fA0)(struct Obj *);
    struct Obj *fA4;
    u8 padA8[0x18];
    s32 fC0;
} Obj;
void func_80065630(void);
void func_8002F2C0(void);
void func_80065260(void);
extern s32 D_800B7FF0;
extern s32 D_8014AB58;
extern s32 D_8014AB5C;
extern s32 D_8014AB60;
extern s32 D_8014AB64;

void func_80065770(Obj *o) {
    if (o->fC0 == 0) {
        D_800B7FF0 = 0;
        o->fC0 = 1;
        func_80065630();
        o->f6C = -1;
        o->f98 = func_8002F2C0;
    }
    o->x = o->fA4->x;
    o->y = o->fA4->y + 400.0f;
    o->f5C -= 6;
    if (o->f5C < 0) {
        o->f5C = 0;
    }
    if (o->fA4->f9C != func_80065260) {
        o->fA0(o);
        return;
    }
    if (o->fA4->y > -1500.0f) {
        o->f60 = D_8014AB58;
        D_800B7FF0 = 1;
    }
    if (o->fA4->y > -600.0f) {
        D_800B7FF0 = 0;
        o->f60 = D_8014AB5C;
    }
    if (o->fA4->y > 500.0f) {
        D_800B7FF0 = 0;
        o->f60 = D_8014AB60;
    }
    if (o->fA4->y > 1200.0f) {
        D_800B7FF0 = 0;
        o->f60 = D_8014AB64;
    }
    if (o->f6C != o->f60) {
        o->f5C = 0xD0;
    }
    o->f6C = o->f60;
}
