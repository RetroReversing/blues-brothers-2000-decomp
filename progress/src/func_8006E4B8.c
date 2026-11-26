typedef struct Obj {
    s32 f0;
    f32 x, y, z;
    u8 pad10[0x24];
    s32 f34;
    s32 f38;
    s32 f3C;
    u8 pad40[0x28];
    s32 f68;
    u8 pad6C[4];
    s32 *f70;
    u8 pad74[8];
    s32 f7C;
    u8 pad80[0x28];
    struct Obj *fA8;
} Obj;
typedef struct { u8 pad[0x54]; s32 flags[24]; } Rec;
Obj *func_80013110(Obj *);
s32 func_80023874(s32, s32);
s32 func_80024394(s32, s32);
s32 func_8004303C(Obj *);
void func_80043328(Obj *, s32, s32);
s32 func_8006DA0C(Obj *);
extern u8 *D_800B3964;
extern f32 D_80009020;
extern Rec D_8014ABC0[];

void func_8006E4B8(Obj *o) {
    s32 *info;
    s32 n;
    s32 mask;
    s32 word;

    if (o->f7C == 0) {
o->f34 = 400;
o->f7C = 1;
o->f38 = 400;
o->f3C = o->f34;
    }
    if (func_80023874(0x103, 0) == 0) {
        if (o->fA8 != NULL) {
            o->fA8->f68 = -1;
        }
        o->f68 = -1;
        return;
    }
    if (func_8006DA0C(o) != 0) {
        return;
    }
    info = o->f70;
    n = info[1];
    mask = 1 << (n & 0x1F);
    word = n / 32;
    if (!(D_8014ABC0[*(s32 *)(D_800B3964 + 0x84)].flags[word] & mask)) {
        o->f68 = -1;
        if (o->fA8 == NULL) {
            o->fA8 = func_80013110(o);
            o->fA8->y += D_80009020;
        }
        o->fA8->f68 = 3;
        return;
    }
    o->f68 = 4;
    if (o->fA8 != NULL) {
        o->fA8->f68 = -1;
    }
    if (func_8004303C(o) != 0) {
        func_80043328(o, func_80024394(0, info[0]) ? info[2] : info[3], 0x100);
    }
}
