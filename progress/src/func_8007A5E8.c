void *func_80042F00(s32, s32, s32, s32);
void actorSetAnim(void *, s32, s32);
void func_80050460(void (*)(void *), char *);
extern char D_8014AA50[];
void animStepKeys(void *);
void func_8005668C(void *);
void func_8007A29C(void *);
void func_8007A3FC(void *);

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 pad10[0x24];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    u8 pad40[0x5C];
    void (*unk9C)(void *);
    u8 padA0[8];
    void *unkA8;
} Obj;

typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
    s32 unk20;
} State;
extern State D_800BD0E0;

Obj *func_8007A5E8(Obj *arg0) {
    Obj *a;
    Obj *b;

    func_80050460(func_8007A29C, &D_8014AA50[2]);
    a = func_80042F00(0x51, 0, 0, 0);
    actorSetAnim(a, 0x15E, 0x100);
    a->unk0 = 0x1022;
    a->unk34 += 0x20;
    a->unk3C = a->unk34;
    a->unk38 = a->unk3C;
    b = func_80042F00(0x6E, 0, 0, 0);
    actorSetAnim(b, 0x160, 0x100);
    b->unk0 = 0x1022;
    b->unk34 = a->unk34;
    b->unk3C = b->unk34;
    b->unk38 = b->unk3C;
    a->unkA8 = b;
    if (arg0 != NULL) {
        a->unk4 = arg0->unk4;
        a->unk8 = arg0->unk8;
        a->unkC = arg0->unkC;
        b->unk4 = arg0->unk4;
        b->unk8 = arg0->unk8;
        b->unkC = arg0->unkC;
    }
    if (D_800BD0E0.unk20 == 3) {
        switch (D_800BD0E0.unk1C) {
        case 0:
            a->unk9C = func_8005668C;
            break;
        case 12:
            a->unk9C = func_8007A3FC;
            break;
        }
    } else {
        a->unk9C = animStepKeys;
        b->unk9C = animStepKeys;
    }
    return a;
}
