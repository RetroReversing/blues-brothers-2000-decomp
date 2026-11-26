typedef struct Obj {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    u8 pad14[0x68 - 0x14];
    s32 x68;
    u8 pad6C[0x9C - 0x6C];
    void *x9C;
    void (*xA0)(struct Obj *);
    u8 padA4[4];
    s32 xA8;
    u8 padAC[0xD8 - 0xAC];
    s32 xD8;
} Obj;

extern s32 func_80043248(Obj *);
extern Obj *findActor(s32, Obj *);
extern s32 func_800232B4(s32, s32, s32, s32);
extern void actorSetAnim(Obj *, s32, s32);
extern void debugPrintf(void *, ...);
extern void func_80023848(void);
extern void func_8006B244(void);
extern s32 D_8000914C;
extern Obj *D_800B3960;

void func_80073A58(Obj *o) {
    Obj *c;

    if (func_80043248(o) != 0) {
        c = findActor(0x1023, NULL);
        if (c != NULL) {
c->x68 = 4;
c->xD8 = 0;
c->x10 = D_800B3960->x10 + 0x8000;
c->x9C = func_80023848;
            D_800B3960->xA8 = func_800232B4(1, c->x4, c->x8, c->xC);
        } else {
            debugPrintf(&D_8000914C);
        }
        c = findActor(0x1026, NULL);
        c->x8 = 0.0f;
        c->x4 = 1013.0f;
        c->xC = -5837.0f;
        actorSetAnim(c, 0xBA, 0x100);
        c->x9C = func_8006B244;
        c->x68 = 4;
        o->x68 = -1;
        o->xA0(o);
    }
}
