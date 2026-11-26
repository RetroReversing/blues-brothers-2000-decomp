typedef struct Obj {
    u8 pad0[0x18];
    s32 f18;
    u8 pad1C[0x40];
    s32 f5C;
    u8 pad60[0x10];
    s32 f70;
    u8 pad74[0x2C];
    void (*fA0)(struct Obj *);
} Obj;
extern s32 D_800B9EA0;

void func_80015E24(Obj *o) {
    o->f5C -= D_800B9EA0 * 8;
    o->f18 += 0x400;
    o->f70 = o->f5C * 90 / 255;
    if (o->f5C <= 0) {
        o->fA0(o);
    }
}
