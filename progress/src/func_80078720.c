typedef struct Obj {
    u8 pad0[0x70];
    s32 x70;
    u8 pad74[0x80 - 0x74];
    s32 x80;
} Obj;

extern s32 func_80024394(s32, s32);
extern Obj *func_80023874(s32, Obj *);
extern s32 D_8014A928[];

void func_80078720(Obj *o) {
    s32 r;
    s32 pair;
    Obj *c;

    r = func_80024394(0, (D_8014A928[o->x70] - 1) * 100);
    if (o->x70 & 1) {
        pair = o->x70 + 1;
    } else {
        pair = o->x70 - 1;
    }
    for (c = func_80023874(0x102F, NULL); c != NULL; c = func_80023874(0x102F, c)) {
        if (c->x70 == pair) {
            if (c->x80 != 0) {
                o->x80 = c->x80;
                return;
            }
            o->x80 = r;
            c->x80 = r;
            return;
        }
    }
    o->x80 = r;
}
