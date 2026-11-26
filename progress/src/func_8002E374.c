typedef struct Obj {
    u8 pad0[0x58];
    s32 f58;
    u8 pad5C[0x38];
    s32 f94;
    void *f98;
    u8 pad9C[0x1C];
    s32 fB8;
    u8 padBC[0x14];
    s32 fD0;
    u8 padD4[0x10];
    s32 fE4;
} Obj;
typedef struct Def {
    u16 f0;
    u16 flags;
} Def;
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
Obj *spawnEffectObj(s32, s32, s32, s32);
Def *getImageAsset(s32);
s32 func_80023E3C(s32);
extern s32 D_800B7B0C;
extern s32 D_800FB038[];
void func_8001F26C(void);

Obj *func_8002E374(s32 id) {
    Def *def;
    Obj *o;

    def = getImageAsset(D_800FB038[id]);
    o = spawnEffectObj(1, 0, 0, 0);
    o->fD0 = -1;
    o->fE4 = func_80023E3C(id);
    o->fB8 = id;
    if (def->flags & 2) {
        o->f58 = packDrawFlags(1, 1, 0, 3, D_800B7B0C, 0, 1, 0);
    } else {
        o->f58 = packDrawFlags(0, 1, 0, 3, D_800B7B0C, 0, 1, 0);
    }
    o->f94 = 30000;
    o->f98 = func_8001F26C;
    return o;
}
