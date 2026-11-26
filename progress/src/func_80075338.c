typedef struct { s32 x, y, z; } Vec3i;
typedef struct Obj {
    s32 unk0;
    u8 pad4[0x58 - 4];
    s32 unk58;
    u8 pad5C[0x9C - 0x5C];
    void *unk9C;
    u8 padA0[0xB8 - 0xA0];
    s32 unkB8;
} Obj;

s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
s32 findActor(s32, s32);
Obj *func_80042F00(s32, s32, s32, s32);
void actorSetAnim(Obj *, s32, s32);
void func_80050460(void *, void *);
Obj *func_80076BF0(s32);
void func_800852CC(Obj *, s32);
extern s32 D_800B7B0C;
extern Vec3i D_800F4A00[];
extern Vec3i D_800F6188[];
extern u8 D_8014AA6E[];
void func_80075270(void);
void func_80075308(void);

Obj *func_80075338(s32 arg0) {
    Obj *o;

    if (findActor(0x100C, 0) != 0) {
        return func_80076BF0(arg0);
    }
    {
        func_80050460(func_80075308, D_8014AA6E);
        o = func_80042F00(0x5A, 0, 0, 0);
        actorSetAnim(o, 0x119, 0x100);
        o->unk0 = 0x100C;
        o->unk58 = packDrawFlags(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
        func_800852CC(o, arg0);
        o->unk9C = func_80075270;
        D_800F6188[o->unkB8].x = -200;
        D_800F6188[o->unkB8].y = -200;
        D_800F6188[o->unkB8].z = -200;
        D_800F4A00[o->unkB8].x = 200;
        D_800F4A00[o->unkB8].y = 200;
        D_800F4A00[o->unkB8].z = 200;
        return o;
    }
}
