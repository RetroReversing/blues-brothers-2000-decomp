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
    u8 pad0[4];
    f32 x;
    u8 pad8[0x64 - 0x8];
    s32 timer;
    u8 pad68[0x9C - 0x68];
    void *cb;
} Obj;

s32 func_80082400(void);
s32 func_80023DBC(s32);
s32 func_80023D58(s32);
f32 approachF32(f32, f32, f32);
void actorSetAnim(s32, s32, s32);
void updateComboInput(s32);
s32 func_80086004(void);
void func_80087160(s32);
void func_80086028(Obj *);
extern Info gComboDefs[];
extern s32 gCamSpeedScale;
extern s32 gComboBeat;
extern s32 D_801719A8;
extern Rec gComboSlots[];
extern Obj *D_80171A30;
extern s32 D_80171A34;
extern s32 D_80171A50;
extern s32 func_80085F58;

void func_8008626C(Obj *o)
{
    char buf[32];
    s32 lim;
    s32 m;
    s32 v;

    lim = func_80082400() + 1;
    func_80023DBC(0xE33);
    D_80171A30->x = approachF32(140.0f, D_80171A30->x, 4.0f);
    gComboBeat += gCamSpeedScale;
    m = gComboBeat % 144;
    updateComboInput(0);
    if (m / 2 == 18) {
        D_80171A34++;
        if (gComboSlots[0].pad != 0) {
            D_80171A50++;
            actorSetAnim(D_801719A8, gComboDefs[func_80086004()].b, 0x100);
            v = gComboDefs[func_80086004()].a;
            gComboSlots[0].pad = 0;
            gComboSlots[0].b[0] = 0;
            gComboSlots[0].b[1] = 0;
            gComboSlots[0].b[2] = 0;
            gComboSlots[0].b[3] = 0;
            gComboSlots[0].b[4] = 0;
            gComboSlots[0].b[5] = 0;
            gComboSlots[0].n = v;
            gComboSlots[0].type++;
            func_80087160(func_80023D58(0x150));
            if (gComboSlots[0].type >= lim) {
                o->cb = (void *)func_80086028;
                gComboSlots[0].type = 0;
                o->timer = 100;
            }
            gComboSlots[0].n = gComboDefs[func_80086004()].a;
            D_80171A34 = 0;
        } else {
            actorSetAnim(D_801719A8, 0x16B, 0x100);
            func_80087160(func_80023D58(0x192));
        }
    }
    if (D_80171A34 >= 4) {
        o->cb = &func_80085F58 + 2;
        func_80087160(func_80023D58(0x201));
        actorSetAnim(D_801719A8, 0x179, 0x100);
    }
}
