typedef struct Obj {
    u8 pad0[0x80];
    s32 x80;
    u8 pad84[0x9C - 0x84];
    void *x9C;
    u8 padA0[0xF0 - 0xA0];
    s32 xF0;
} Obj;

extern s32 func_80083920(Obj *, s32);
extern void func_80043328(Obj *, s32, s32);
extern void actorSetAnim(Obj *, s32, s32);
extern void func_8002ADFC(s32, s32, Obj *);
extern s32 animStepKeys(Obj *);
extern void func_8005FD0C(void);

s32 func_80060214(Obj *o) {
    s32 r;

    r = func_80083920(o, o->x80);
    switch (r) {
    case 1:
        o->x80 = r;
        func_80043328(o, 0x59, 0x100);
        o->xF0 = 0xC0;
        break;
    case 2:
        o->x9C = func_8005FD0C;
        o->xF0 = 0xFF;
        func_8002ADFC(0x26, 0x1F4, o);
        actorSetAnim(o, 0x57, 0x100);
        return 1;
    }
    if (animStepKeys(o) != 0) {
        if (o->x80 != 0) {
            actorSetAnim(o, 0x55, 0x100);
            o->x80 = 0;
        } else {
            func_8002ADFC(0x27, 0x1F4, o);
        }
    }
    return 0;
}
