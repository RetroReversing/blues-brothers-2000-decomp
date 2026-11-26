typedef struct Obj {
    u8 pad0[0x68];
    s32 x68;
    u8 pad6C[4];
    s32 x70;
    s32 x74;
    u8 pad78[4];
    s32 x7C;
    u8 pad80[0x9C - 0x80];
    void *x9C;
    u8 padA0[4];
    struct Obj *xA4;
    struct Obj *xA8;
    f32 xAC;
    u8 padB0[4];
    s32 xB4;
    s32 xB8;
} Obj;

extern void initSpline(s32, s32);
extern Obj *findActor(s32, Obj *);
extern Obj *func_8002E374(s32);
extern void updateCamPathFollow(void);
extern f32 D_80009534;

void func_8007BC24(Obj *o) {
    s32 id;
    Obj *c;
    Obj *n;

    if (o->x7C == 0) {
        o->x7C = 1;
        initSpline(o->x70, 0);
        return;
    }
    if (o->xA8 != NULL) {
        return;
    }
    switch (o->x74) {
    case 0:
    default:
        id = 0x11E;
        break;
    case 1:
        id = 0x11F;
        break;
    case 2:
        id = 0x120;
        break;
    case 3:
        id = 0x121;
        break;
    }
    c = findActor(id, NULL);
    if (c != NULL) {
        n = func_8002E374(c->xB8);
        o->xA8 = n;
        n->x70 = o->x70;
        n->x74 = o->x74;
        n->x9C = updateCamPathFollow;
        n->xA4 = o;
        n->xAC = 0.142f;
        n->xB4 = 0;
        n->x68 = -1;
    }
}
