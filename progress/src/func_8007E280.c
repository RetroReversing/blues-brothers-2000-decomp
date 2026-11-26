typedef struct Obj {
    u8 pad0[0xC];
    f32 y;
    s32 ang;
    u8 pad14[0x64 - 0x14];
    s32 unk64;
    u8 pad68[0x88 - 0x68];
    s32 state;
    u8 pad8C[0xA8 - 0x8C];
    struct Obj *link;
    u8 padAC[0xD8 - 0xAC];
    s32 (*fn)(struct Obj *);
} Obj;

typedef struct { s32 x, y, z; } Vec3i;

Obj *findActor(s32, Obj *);
s32 animStepKeys(Obj *);
s32 func_8007DDB8(Obj *, Vec3i *, Vec3i *);
s32 func_8007E1AC(Obj *);
extern Obj *D_800B3960;
typedef struct { u8 pad[0x7C]; s32 mode; } Game;
extern Game *D_800B3964;
extern s32 D_800B4988;
extern s32 D_800B5DD4;
extern Vec3i D_800B86C0;
extern Vec3i D_800B86D8;

s32 func_8007E280(Obj *obj) {
    Obj *p;

    if (obj->state == 0) {
        obj->state = 1;
        obj->unk64 = 200;
    }
    D_800B5DD4 = 0;
    D_800B4988 = 30;
    obj->ang = D_800B3960->ang;
    if (findActor(0x801, 0) != 0) {
        return 0;
    }
    if (D_800B3964->mode != 4) {
        return 0;
    }
    p = D_800B3960;
    p->y = obj->y - 4500.0f;
    p->link = obj;
    obj->ang = p->ang + 0x8000;
    if (func_8007DDB8(obj, &D_800B86D8, &D_800B86C0) == 0) {
        return 0;
    }
    animStepKeys(obj->link);
    if (animStepKeys(obj) == 0) {
        return 0;
    }
    obj->state++;
    if (obj->state >= 4) {
        obj->fn = func_8007E1AC;
        obj->state = 0;
        return 0;
    }
    return 0;
}
