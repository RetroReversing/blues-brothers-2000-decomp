typedef struct Obj {
    s32 f0;
    f32 x, y, z;
    u8 pad10[0x24];
    s32 f34;
    s32 f38;
    s32 f3C;
    u8 pad40[0x18];
    s32 f58;
    u8 pad5C[8];
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    u8 pad74[4];
    s32 f78;
    u8 pad7C[4];
    s32 f80;
    u8 pad84[0x10];
    s32 f94;
    u8 pad98[4];
    void *f9C;
    u8 padA0[4];
    struct Obj *fA4;
} Obj;
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
s32 randomRange(s32, s32);
Obj *func_8002E374(s32);
void debugPrintf(char *);
extern char D_800090D8[];
extern s32 D_800B7B0C;
extern s32 D_800B8380;
extern s32 *D_801700B0;
void func_80072DA4(void);

Obj *func_800730E0(Obj *parent) {
    s32 r;
    Obj *o;

    if (parent == NULL) {
        debugPrintf(D_800090D8);
    }
    r = randomRange(0, D_800B8380 - 1);
    o = func_8002E374(D_801700B0[r]);
    o->f9C = func_80072DA4;
    o->x = parent->x;
    o->y = parent->y;
    o->z = parent->z;
    o->f70 = parent->f70;
    o->f78 = r;
    o->f80 = 1;
    o->fA4 = parent;
    o->f58 = packDrawFlags(0, 1, 2, 3, D_800B7B0C, 0, 1, 0);
    o->f6C = 0xB8FD2A;
    o->f34 -= 40; o->f38 = o->f34; o->f3C = o->f34;
    o->f94 /= 3;
    o->f64 = randomRange(100, 500);
    o->f0 = 0x1030;
    return o;
}
