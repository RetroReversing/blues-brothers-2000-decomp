typedef struct Obj68378 {
    s32 kind;
    f32 x, y, z;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x58 - 0x1C];
    s32 unk58;
    u8 pad5C[0x64 - 0x5C];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    s32 unk74;
    u8 pad78[0x7C - 0x78];
    s32 unk7C;
    u8 pad80[0x84 - 0x80];
    s32 unk84;
    s32 unk88;
    u8 pad8C[0x9C - 0x8C];
    void *unk9C;
    u8 padA0[0xA8 - 0xA0];
    struct Obj68378 *unkA8;
    u8 padAC[0xC0 - 0xAC];
    s32 unkC0;
    u8 padC4[0x108 - 0xC4];
} Obj68378;

typedef struct {
    s32 x, y, z;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Entry68378;

typedef struct {
    u8 pad0[0x34];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
} Player68378;

s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
Obj68378 *func_800232B4(s32, s32, s32, s32);
Obj68378 *findActor(s32, Obj68378 *);
void func_800242A8(s32, s32, s32);
void syncActorPrevPos(Obj68378 *);
Obj68378 *func_8002E374(s32);
Obj68378 *func_80051BE8(s32);
void func_80052A30(void);
void func_800682CC(void);
Obj68378 *func_80068A34(s32);
Obj68378 *func_8006AE5C(Obj68378 *);
void func_80017880(void);
void func_800646C0(void);
void func_80064730(void);
void cameraUpdateByMode(void);
void func_80068768(void);
void func_800690B0(void);
void func_8006982C(void);
extern Obj68378 *D_800AB9BC;
extern Obj68378 *D_800AB9C0;
extern Obj68378 *D_800B3960;
extern s32 D_800B5DD4;
extern Entry68378 D_800B8000[];
extern s32 D_800B83B0;
extern Player68378 *gCameraTarget;

/* Sets up the intro scene once: spawns the prop table, the camera and its target actors, then finishes the camera hand-off on later frames. */ void initIntroScene(Obj68378 *scene) {
    s32 i;
    s32 spawnId;
    Entry68378 *e;
    Obj68378 *actor;
    Obj68378 *keepActor;
    Obj68378 *targetActor;
    Obj68378 *p;
    Obj68378 *end;

    if (scene->unkC0 == 0) {
        i = 0;
        scene->unkC0 = 1;
        scene->unk64 = 100;
        scene->unk7C = 0;
        scene->unk74 = 0;
        scene->unk88 = 0;
        scene->unk84 = 0;
        gCameraTarget->unk3C = 320;
        gCameraTarget->unk38 = 320;
        gCameraTarget->unk34 = 320;
        func_800682CC();
        D_800B5DD4 = 0;
        func_80052A30();
        spawnId = D_800B83B0 + 470;
        D_800B83B0++;
        func_800242A8(spawnId, 0xDC9, i);
        for (i = 0; i < 14; i++) {
            actor = func_8002E374(spawnId);
            actor->x = D_800B8000[i].x;
            actor->y = D_800B8000[i].y;
            actor->z = D_800B8000[i].z;
            actor->unk10 = -(D_800B8000[i].unk10 << 16) / 360;
            actor->unk14 = (D_800B8000[i].unkC << 16) / 360;
            actor->unk18 = (D_800B8000[i].unk14 << 16) / 360;
            actor->unk74 = D_800B8000[i].unk18;
            actor->unk70 = D_800B8000[i].unk1C;
            actor->unk9C = func_800690B0;
        }
        keepActor = findActor(0x13C, NULL);
        if (keepActor != NULL) {
            keepActor->x = -593.0f;
            keepActor->y = 371.0f;
            keepActor->z = 2101.0f;
        }
        actor = func_80068A34(0);
        actor->x = 0.0f;
        actor->y = -35.0f;
        actor->z = 1535.0f;
        keepActor = func_8006AE5C(scene);
        keepActor->unk10 = 0x8000;
        keepActor->x = -500.0f;
        keepActor->y = 900.0f;
        keepActor->z = -2080.0f;
        keepActor->unk58 = packDrawFlags(1, 1, 2, 3, 0, 0, 1, 0);
        actor = func_80051BE8(0);
        actor->x = 406.0f;
        actor->y = 726.0f;
        actor->z = 1870.0f;
        scene->unk10 = 0x7000;
        actor = func_800232B4(1, 0, 0, 0);
        actor->unk9C = func_800646C0;
        actor->unk70 = 4;
        actor->y = 800.0f;
        actor->z = -1850.0f;
    }
    if (scene->unk7C == 0) {
        actor = findActor(0x8001, NULL);
        if (actor != NULL) {
            targetActor = findActor(0x1012, NULL);
            if (targetActor != NULL) {
                actor->unk9C = cameraUpdateByMode;
                actor->x = 0.0f;
                actor->unkC0 = 0;
                actor->unkA8 = targetActor;
                actor->y = 815.0f;
                actor->z = -2920.0f;
                syncActorPrevPos(actor);
                scene->unk7C = 1;
            }
        }
        actor = D_800AB9BC;
        scene->unk7C = 1;
        for (; actor <= D_800AB9C0; actor++) {
            if (actor->unk9C == func_80017880) {
                actor->unk9C = func_8006982C;
                actor->unk7C = 0;
            }
        }
    }
    if (scene->unk7C == 1) {
        scene->unk9C = func_80068768;
        scene->unk7C = 0;
        scene->unk70 = 0;
    }
    D_800B3960->unkA8 = keepActor;
    D_800B3960->unk9C = func_80064730;
}
