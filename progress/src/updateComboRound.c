typedef struct Obj {
    char pad0[4];
    f32 x4;
    char pad8[0x10 - 0x8];
    s32 x10;
    char pad14[0x64 - 0x14];
    s32 x64;
    s32 x68;
    char pad6C[0x9C - 0x6C];
    void *fn9C;
    char padA0[0xD0 - 0xA0];
    s32 xD0;
    char padD4[0xDC - 0xD4];
    f32 xDC;
} Obj;

typedef struct Slot {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    u8 x10[6];
} Slot;

typedef struct Pair {
    s32 x0;
    s32 x4;
    s32 x8;
} Pair;

typedef struct Name {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
} Name;

s32 func_80023D58(s32);
s32 func_80023DBC(s32);
void func_8002A360(s32, s32);
f32 approachF32(f32, f32, f32);
void actorSetAnim(void *, s32, s32);
void func_80052B24(s32, char *, void *);
s32 func_80082400(void);
void updateComboInput(s32);
void func_80087160(s32);
int sprintf(char *, const char *, ...);
extern char func_80085F58[];
void func_80086550(void);
void func_80086B3C(void);

extern char D_80009B40[];
extern char D_80009B54[];
extern f32 D_80009B5C;
extern f64 D_80009B60;
extern f64 D_80009B68;
extern f64 D_80009B70;
extern f64 D_80009B78;
extern Name D_800B8720[];
extern Pair gComboDefs[];
extern s32 D_800B9B40[];
extern u8 gCamSpeedScale[];
extern u8 gComboBeat[];
extern u8 D_801719A8[];
extern u8 D_801719AC[];
extern Slot gComboSlots;
extern u8 D_80171A30[];
extern u8 D_80171A34[];
extern u8 D_80171A50[];

/* Per-frame controller for a combo round: runs combo input, plays the beat animation, and shows the win or fail text when the round ends. */ void updateComboRound(Obj *owner) {
    char buf[0x20];
    s32 stage;
    s32 fontId;
    s32 beatPhase;
    f64 animTime;

    stage = func_80082400();
    fontId = func_80023DBC(0xE33);
    (*(Obj * *)D_80171A30)->x4 = approachF32(D_80009B5C, (*(Obj * *)D_80171A30)->x4, 4.0f);
    (*(s32 *)gComboBeat) += (*(s32 *)gCamSpeedScale);
    beatPhase = (*(s32 *)gComboBeat) % 144;
    updateComboInput(0);
    if (beatPhase / 2 == 18) {
        (*(s32 *)D_80171A34)++;
        if ((*(s32 *)D_80171A34) != 1) {
            if (gComboSlots.xC != 0) {
                (*(s32 *)D_80171A50)++;
                actorSetAnim((*(Obj * *)D_801719A8), gComboDefs[gComboSlots.x0].x4, 0x100);
                gComboSlots.x8 = gComboDefs[stage].x0;
                gComboSlots.xC = 0;
                gComboSlots.x10[0] = 0;
                gComboSlots.x10[1] = 0;
                gComboSlots.x10[2] = 0;
                gComboSlots.x10[3] = 0;
                gComboSlots.x10[4] = 0;
                gComboSlots.x10[5] = 0;
                func_80087160(func_80023D58(0x150));
            } else {
                func_80087160(func_80023D58(0x192));
                actorSetAnim((*(Obj * *)D_801719A8), 0x16B, 0x100);
            }
        }
    }
    if ((*(s32 *)D_80171A50) >= 3) {
        if (D_800B9B40[stage] == 0) {
            owner->fn9C = func_80085F58 + 8;
            func_80087160(func_80023D58(0x202));
            sprintf(buf, D_80009B40, D_800B8720[stage].x8);
            func_80052B24(fontId, buf, owner);
            (*(Obj * *)D_80171A30)->x68 = -1;
            actorSetAnim((*(Obj * *)D_801719A8), 0x178, 0x100);
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x78);
            return;
        }
        owner->x64 = 100;
        owner->fn9C = func_80086550;
        return;
    }
    if ((*(s32 *)D_80171A34) >= 7) {
        sprintf(buf, D_80009B54, D_800B8720[stage].x8);
        func_80052B24(fontId, buf, owner);
        owner->fn9C = func_80086B3C;
        actorSetAnim((*(Obj * *)D_801719A8), 1, 0x100);
        (*(Obj * *)D_801719AC)->x10 = -0x4000;
        actorSetAnim((*(Obj * *)D_801719AC), 0x18C, 0x100);
        (*(Obj * *)D_801719AC)->x10 = 0x8000;
        (*(Obj * *)D_80171A30)->x68 = -1;
        return;
    }
    if ((*(Obj * *)D_801719AC)->xD0 == 0x18B) {
        animTime = (*(Obj * *)D_801719AC)->xDC;
        if ((D_80009B60 <= animTime && animTime < D_80009B68) || (D_80009B70 <= animTime && animTime < D_80009B78)) {
            func_80082400();
        }
    }
}
