typedef struct Obj Obj;
struct Obj {
    s32 type;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x60];
    s32 unk70;
    u8 pad74[8];
    s32 unk7C;
    u8 pad80[0x1C];
    void (*handler)(Obj *);
    void (*unkA0)(Obj *);
    u8 padA4[4];
    Obj *unkA8;
    u8 padAC[0x14];
    s32 unkC0;
};

Obj *func_800232B4(s32, s32, s32, s32);
Obj *findActor(s32, s32);
void func_80034FEC(Obj *, s32 *);
void func_80034F50(Obj *);
void func_800393F4(Obj *);
void animStepKeys(Obj *);
void func_800743F8(Obj *);
void func_8007452C(Obj *);
extern Obj *gCameraRig;
extern Obj *D_800B3964;
extern s32 D_800B5DD4;
extern Obj *gCameraTarget;

void func_80074600(Obj *arg0) {
    s32 v[3];
    Obj *o;
    Obj *n;
    Obj *c;
    f32 dist;

    dist = 30000.0f;
    if (arg0->unk7C == 0) {
        o = func_800232B4(1, 0, 0, 0);
        o->handler = func_800743F8;
        o->unk70 = arg0->unk70;
        arg0->unk7C = 1;
        arg0->unkA8 = o;
        arg0->type = 0x11E;
        arg0->unkC0 = 0;
    }
    if (arg0->unkA8 != NULL) {
        v[0] = arg0->unkA8->x;
        v[1] = arg0->unkA8->y;
        v[2] = arg0->unkA8->z;
        func_80034FEC(arg0, v);
    }
    o = findActor(0x121, 0);
    if (o != NULL) {
        v[0] = arg0->x - o->x;
        v[1] = arg0->y - o->y;
        v[2] = arg0->z - o->z;
        dist = sqrtf(v[0] * v[0] + v[2] * v[2] + v[1] * v[1]);
    }
    if (dist > 200.0f) {
        return;
    }
    if (gCameraTarget->type == 3 && gCameraTarget->handler == func_800393F4) {
        arg0->handler = func_8007452C;
        arg0->unkC0 = 0;
        if (arg0->unkA8 != NULL) {
            arg0->unkA8->unkA0(arg0->unkA8);
            arg0->unkA8 = NULL;
        }
        if (o != NULL) {
            o->unkA0(o);
        }
        n = findActor(0x1023, 0);
        c = gCameraRig;
        if (c->handler != func_80034F50) {
            if (n == NULL) {
                n = arg0;
            }
            gCameraTarget->handler = animStepKeys;
            c->handler = func_80034F50;
            c->unkA8 = n;
            c->x = D_800B3964->x;
            c->y = D_800B3964->y;
            c->z = D_800B3964->z;
            D_800B5DD4 = 0;
            c->unkC0 = 0;
        }
        if (n != NULL) {
            arg0->x = n->x;
            arg0->z = n->z;
        }
    }
}
