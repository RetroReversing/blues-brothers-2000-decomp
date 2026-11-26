typedef struct {
    s32 unk0;
    u8 pad4[0x14 - 0x4];
    s32 unk14;
    u8 pad18[0x1C - 0x18];
    s32 unk1C;
    s32 unk20;
} Game_C874;

typedef struct {
    s32 unk0;
    u8 pad4[0x20 - 0x4];
    s32 unk20;
    u8 pad24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x34 - 0x30];
    s32 unk34;
    s32 unk38;
} Level_C874;

typedef struct {
    u8 pad0[0x1C];
    Level_C874 *levels;
} World_C874;

typedef struct {
    s32 unk0;
    u8 pad4[0x10 - 0x4];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x34 - 0x1C];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    u8 pad40[0x4C - 0x40];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    u8 pad58[0x5C - 0x58];
    s32 unk5C;
    u8 pad60[0x68 - 0x60];
    s32 unk68;
    u8 pad6C[0x7C - 0x6C];
    s32 unk7C;
    s32 unk80;
    u8 pad84[0x90 - 0x84];
    s32 unk90;
    u8 pad94[0x98 - 0x94];
    void *unk98;
    void *unk9C;
    u8 padA0[0xAC - 0xA0];
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
    u8 padBC[0xC0 - 0xBC];
    s32 unkC0;
    s32 unkC4;
    u8 padC8[0xE0 - 0xC8];
    s32 unkE0;
    s32 unkE4;
    u8 padE8[0xF0 - 0xE8];
    s32 unkF0;
    u8 padF4[0xF8 - 0xF4];
    s32 unkF8;
} Actor_C874;

void func_8000C458(void);
void func_8000C5B4(void);
void func_8000C75C(void);
void func_8000CF14(void);
void func_80015A90(s32);
void func_80023620(s32);
void func_8002369C(s32, s32);
Actor_C874 *findActor(s32, s32);
s32 countLiveObjects(s32);
s32 func_80023A04(void);
void func_80023C58(s32);
void func_80023C64(s32);
s32 func_80023E3C(s32);
void func_800242A8(s32, s32, s32);
void func_80025D00(s32);
void func_80027030(s32);
void func_8002A360(s32, s32);
void syncActorPrevPos(Actor_C874 *);
void func_8002E7B8(s32, s32);
void func_80034E40(s32);
void func_8003B234(s32);
void func_8003CAD4(Actor_C874 *, s32);
void func_8004145C(void);
void actorSetAnim(Actor_C874 *, s32, s32);
void func_8004EC20(void);
s32 func_8004EC68(s32, s32);
void func_80050430(void);
void func_80052A5C(s32);
void func_80088ED0(void);
void debugPrintf(char *, ...);
extern char D_80000484[];
extern World_C874 D_800AA134[];
extern s32 D_800AB408;
extern s32 D_800AB9C8;
extern s32 gCameraRig;
extern Actor_C874 *D_800B3964;
extern s32 D_800B396C;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 D_800B4C28;
extern s32 D_800B4CE4;
extern s32 D_800B4D2C;
extern s32 D_800B5DD4;
extern s32 D_800B7B0C;
extern s32 gAudioVolume[];
extern s32 D_800B83B0;
extern s32 gFrameScale;
extern Actor_C874 *gCameraTarget;
extern Game_C874 D_800BD0E0;
extern s32 D_800BD23C;
extern s32 gStickX;
extern s32 gStickY;
extern s32 D_8013FFBC;
extern s32 D_8014002C;
extern s32 D_80140228;
extern s32 D_80140230;
extern s32 D_8014AAB0;
extern s32 D_801700D8;
void drawHud(void);
extern u8 D_80023080[];
void func_800393F4(void);
void func_800414D0(void);

/* Resets game and level state, spawns the level's actors and objects, and sets up the level's scene and sound. */ void initLevel(void) {
    Level_C874 *level;
    Actor_C874 *actor;
    s32 result;

    level = D_800AA134[D_800BD0E0.unk20].levels;
    func_80025D00(0);
    func_80025D00(0);
    func_80025D00(0);
    D_800B4CE4 = 0;
    D_800BD23C = 0;
    D_8014002C = 0;
    D_800B4D2C = 0;
    D_800AB9C8 = 0;
    D_80140228 = 0;
    D_801700D8 = 8000;
    D_800AB408 = 0;
    D_800B396C = 995;
    D_800B4C28 = 30000;
    gCameraTarget->unk0 = 3;
    gCameraTarget->unkB8 = 1;
    gCameraTarget->unkE4 = func_80023E3C(1);
    gCameraTarget->unkF8 = 0;
    gCameraTarget->unk98 = func_800414D0;
    if (D_800BD0E0.unk14 <= 0) {
        D_800BD0E0.unk14 = 2;
    }
    if (D_800BD0E0.unk0 <= 0) {
        D_800BD0E0.unk0 = 3;
    }
    gCameraTarget->unkF0 = 0;
    func_80023620(1);
    func_8002369C(0x100, 0x1031);
    if (countLiveObjects(0) >= 7) {
        debugPrintf(D_80000484, countLiveObjects(0));
    }
    func_8000C458();
    D_8014AAB0 = func_80023A04();
    level += D_800BD0E0.unk1C;
    func_80023C64(0x12345678);
    func_80023C64(0x110);
    func_80023C58(0x110);
    func_80050430();
    func_8004EC20();
    func_80027030(1);
    func_80052A5C(0);
    func_800242A8(0x82, 0xDBC, 0);
    func_800242A8(0x90, 0xDA2, 0);
    func_800242A8(0x92, 0xDC5, 0);
    func_800242A8(0x93, 0xC8F, 0);
    func_800242A8(0x94, 0xE08, 0);
    func_800242A8(0x95, 0xDC0, 0);
    func_800242A8(0xA4, 0xCDE, 0);
    func_800242A8(0xA5, 0xCDF, 0);
    func_800242A8(0xA6, 0xCE0, 0);
    func_800242A8(0xA1, 0x3F3, 0);
    func_800242A8(0x7C, 0x68F, 0);
    func_800242A8(0x98, 0xDDC, 0);
    func_800242A8(0x9B, 0xDC7, 2);
    func_800242A8(0xA2, 0xDBA, 0);
    func_800242A8(0x87, 0xCDB, 0);
    switch (D_800BD0E0.unk20) {
    case 0:
        func_800242A8(0x96, 0xE05, 0);
        break;
    case 1:
        func_800242A8(0xA8, 0xC92, 0);
        func_800242A8(0x96, 0xD97, 0);
        break;
    case 2:
        func_800242A8(0x97, 0xDD7, 0);
        func_800242A8(0x96, 0xE05, 0);
        break;
    case 3:
        func_800242A8(0x96, 0xD98, 0);
        break;
    }
    gStickX = 0;
    gStickY = 0;
    gCameraTarget->unk0 = 3;
    gCameraTarget->unk3C = 0x100;
    gCameraTarget->unk38 = 0x100;
    gCameraTarget->unk34 = 0x100;
    gCameraTarget->unk9C = func_800393F4;
    gCameraTarget->unk4C = 0;
    gCameraTarget->unk50 = 0;
    gCameraTarget->unk54 = 0;
    gCameraTarget->unkAC = 0;
    gCameraTarget->unkB0 = 0;
    gCameraTarget->unkB4 = 0;
    gCameraTarget->unkC4 = 0;
    gCameraTarget->unkE0 = 0;
    gCameraTarget->unk18 = 0;
    gCameraTarget->unk14 = 0;
    gCameraTarget->unk5C = 0xFF;
    gCameraTarget->unk68 = 3;
    actorSetAnim(gCameraTarget, 1, 0x100);
    D_80140230 = 0;
    actor = findActor(6, 0);
    if (actor != NULL) {
        actor->unk68 = 0xF;
        actor->unk98 = drawHud;
        actor->unk90 = 0;
    }
    D_800B5DD4 = 1;
    gFrameScale = 0;
    func_80034E40(gCameraRig);
    D_8013FFBC = 0;
    D_800B3964->unkC0 = 0;
    D_800B3964->unk9C = (void *)level->unk28;
    D_800B3964->unk98 = D_80023080;
    D_800B3964->unk7C = 0;
    D_800B3964->unk80 = 0;
    D_800B83B0 = 0;
    if (level->unk34 != 0) {
        func_80015A90(level->unk34);
    }
    D_800B7B0C = level->unk20;
    D_800B3970 = level->unk27;
    D_800B3974 = level->unk26;
    D_800B3978 = level->unk25;
    func_8000CF14();
    result = func_8004EC68(level->unk0, level->unk2C);
    level->unk2C = result;
    if (result != 0) {
        func_8003B234(result);
    }
    syncActorPrevPos(gCameraTarget);
    func_8003CAD4(gCameraTarget, gCameraTarget->unk10);
    gFrameScale = 0;
    func_8002E7B8(0, 0);
    func_8004145C();
    func_8002A360(0, gAudioVolume[0] * 0x147);
    func_8002A360(1, gAudioVolume[1] * 0x147);
    func_8002A360(0xC, 0x80);
    if (level->unk38 != -1) {
        func_8002A360(3, level->unk38);
    }
    func_80088ED0();
    func_8000C5B4();
    func_8000C75C();
}
