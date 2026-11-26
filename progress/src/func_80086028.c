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
    s32 name;
    s32 c;
    s32 d;
} Entry;
typedef struct {
    u8 pad0[0x64];
    s32 timer;
    s32 unk68;
    u8 pad6C[0x9C - 0x6C];
    void *cb;
} Obj;

s32 func_80082400(void);
s32 func_80023DBC(s32);
s32 func_80023D58(s32);
void func_80026C04(void *, s32, s32);
void func_8002A360(s32, s32);
s32 tickActorTimer(Obj *);
void actorSetAnim(s32, s32, s32);
void startStoryDialog(s32, char *, Obj *);
void func_80081C10(void);
s32 func_80082688(s32, s32);
void func_80087160(s32);
s32 sprintf(char *, const char *, ...);
extern Entry D_800B8720[];
extern s32 D_800B9B40[];
extern s32 gCamSpeedScale;
extern s32 gComboBeat;
extern s32 D_801719A8;
extern Rec gComboSlots[];
extern Obj *D_80171A30;
extern s32 D_80171A34;
extern s32 D_80171A54;
extern s32 func_80085F58;

void func_80086028(Obj *o)
{
    char buf[32];
    s32 idx;
    s32 h;
    s32 m;

    idx = func_80082400();
    h = func_80023DBC(0xE33);
    gComboBeat += gCamSpeedScale;
    m = gComboBeat % 144;
    if (tickActorTimer(o) == 0) {
        return;
    }
    if (func_80082688(m, 0x24) == 0) {
        return;
    }
    gComboSlots[0].type = 0;
    actorSetAnim(D_801719A8, 0x178, 0x100);
    func_8002A360(0xC, 0x80);
    func_8002A360(8, 0x78);
    D_80171A54++;
    if (D_80171A54 >= D_800B9B40[idx]) {
        o->cb = &func_80085F58 + 2;
        func_80087160(func_80023D58(0x202));
        sprintf(buf, "%swin", D_800B8720[idx].name);
        startStoryDialog(h, buf, o);
    } else {
        if (D_80171A54 == 1) {
            func_80087160(func_80023D58(0x21D));
        }
        if (D_80171A54 == 2) {
            func_80087160(func_80023D58(0x21E));
        }
        if (D_80171A54 == 3) {
            func_80087160(func_80023D58(0x21F));
        }
        if (D_80171A54 == 4) {
            func_80087160(func_80023D58(0x220));
        }
        func_80081C10();
        func_80026C04(gComboSlots, 0, 0x50);
        gComboSlots[0].n = 5;
        D_80171A34 = 0;
        o->cb = &func_80085F58 + 26;
        o->timer = 200;
    }
    D_80171A30->unk68 = -1;
}
