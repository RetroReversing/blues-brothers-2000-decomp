typedef struct {
    s32 type;
    s32 acc;
    s32 n;
    s32 pad;
    u8 b[8];
    s16 h[8];
} Rec;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Info;
typedef struct {
    u8 pad0[0x64];
    s32 timer;
    u8 pad68[0x9C - 0x68];
    void *cb;
    u8 padA0[0xD0 - 0xA0];
    s32 anim;
    u8 padD4[0xDC - 0xD4];
    f32 frame;
} Obj;

s32 randomRange(s32, s32);
s32 tickActorTimer(Obj *);
void actorSetAnim(Obj *, s32, s32);
s32 func_80082400(void);
s32 func_80082688(s32, s32);
void updateComboInput(s32);
void func_80083354(s32);
void func_80083604(void);
void resolveComboBeat(Obj *);
extern Info gComboDefs[];
extern s32 gCamSpeedScale;
extern s32 gComboBeat;
extern s32 D_80171994;
extern Obj *gComboActorA;
extern Obj *gComboActorB;
extern Rec gComboSlots[];

void func_80082990(Obj *o)
{
    s32 snd[2];
    s32 m;
    s32 i;
    s32 any;
    f64 f;

    func_80082400();
    if (gComboActorA->anim == 0x17B) {
        f = *(volatile f32 *)&gComboActorA->frame;
    }
    if (gComboActorB->anim == 0x18B) {
        f = *(volatile f32 *)&gComboActorB->frame;
    }
    gComboBeat += gCamSpeedScale;
    m = gComboBeat % 144;
    updateComboInput(0);
    if (D_80171994 != 0) {
        updateComboInput(1);
    } else if (tickActorTimer(o) != 0) {
        if (randomRange(0, 100) >= 91) {
            func_80083354(1);
        }
        o->timer = 10;
    }
    if (func_80082688(m, 0x24) == 0) {
        return;
    }
    any = 0;
    for (i = 0; i < 2; i++) {
        if (gComboSlots[i].pad != 0) {
            snd[i] = gComboDefs[gComboSlots[i].type].b;
            if (i != 0) {
                snd[i] += 0x20;
            } else {
                snd[0] += 0x10;
            }
            gComboSlots[i].pad = 0;
            gComboSlots[i].b[0] = 0;
            gComboSlots[i].b[1] = 0;
            gComboSlots[i].b[2] = 0;
            gComboSlots[i].b[3] = 0;
            gComboSlots[i].b[4] = 0;
            gComboSlots[i].b[5] = 0;
            gComboSlots[i].type++;
            if (gComboSlots[i].type >= 12) {
                o->cb = (void *)resolveComboBeat;
                gComboSlots[i].type = 0;
                o->timer = 100;
            }
            gComboSlots[i].n = gComboDefs[gComboSlots[i].type].a;
            any = 1;
        } else if (i == 0) {
            snd[0] = 0x17B;
        } else {
            snd[i] = 0x18B;
        }
    }
    if (any) {
        func_80083604();
    }
    actorSetAnim(gComboActorA, snd[0], 0x100);
    actorSetAnim(gComboActorB, snd[1], 0x100);
}
