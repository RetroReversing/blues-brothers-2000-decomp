typedef struct Actor64130 {
    s32 unk0;
    f32 x;
    f32 y;
    f32 z;
    s32 unk10;
    u8 pad14[0x50 - 0x14];
    s32 unk50;
    u8 pad54[0x5C - 0x54];
    s32 unk5C;
    u8 pad60[0x64 - 0x60];
    s32 unk64;
    s32 unk68;
    u8 pad6C[0x70 - 0x6C];
    s32 unk70;
    u8 pad74[0x7C - 0x74];
    s32 unk7C;
    u8 pad80[0x90 - 0x80];
    s32 unk90;
    u8 pad94[0x9C - 0x94];
    void (*unk9C)(struct Actor64130 *);
    void (*unkA0)(struct Actor64130 *);
    u8 padA4[0xC0 - 0xA4];
    s32 unkC0;
} Actor64130;

s32 cameraGetMode(void);
s32 func_8001B990(s32, s32);
void func_800232B4(s32, s32, s32, s32);
Actor64130 *findActor(s32, s32);
s32 func_80023DBC(s32);
s32 func_8002D260(s32);
s32 tickActorTimer(Actor64130 *);
void syncActorPrevPos(Actor64130 *);
void func_80036DB4(Actor64130 *);
void func_800393F4(Actor64130 *);
void animStepKeys(Actor64130 *);
void actorSetAnim(Actor64130 *, s32, s32);
s32 func_800520D0(s32);
s32 func_80052100(s32);
void setActorState(s32, s32);
s32 *func_80052444(s32);
void func_80052A5C(s32);
s32 func_80052B24(s32, char *, Actor64130 *);
Actor64130 *func_8005EA88(Actor64130 *);
Actor64130 *spawnCutsceneActor(void);
void func_80063D3C(Actor64130 *);
void func_80063E50(void);
void func_80063EFC(Actor64130 *);
void func_80063F98(Actor64130 *);
void func_80064024(Actor64130 *);
extern u8 D_80023080[];
extern s32 D_800B4988;
extern s32 D_800B5DD4;
extern Actor64130 *gCameraRig;
extern u8 D_800BCFB8[];
extern Actor64130 *gCameraTarget;
extern s32 gPadPressed;

/* Runs the Elroom intro cutscene as a numbered state machine stored in scene->unk7C. */ void updateElroomScene(Actor64130 *scene) {
    Actor64130 *actor;

    if (scene->unk7C != -1) {
        D_800B4988 = 30;
        D_800B5DD4 = 0;
    }
    switch (scene->unk7C) {
    case 0:
        actor = findActor(0x140, 0);
        if (actor != NULL) {
            actor->unk9C = (void *)D_80023080;
            actor->unk68 = -1;
        }
        gCameraRig->unk9C = func_80036DB4;
        actor = findActor(0x11E, 0);
        if (actor == NULL) {
            break;
        }
        gCameraRig->unk9C = func_80036DB4;
        gCameraRig->x = actor->x;
        gCameraRig->y = actor->y;
        gCameraRig->z = actor->z;
        gCameraRig->unkC0 = 0;
        syncActorPrevPos(gCameraRig);
        gCameraRig->unk9C(gCameraRig);
        gCameraTarget->unk10 = func_8002D260(gCameraRig->unk10 + 0x8000);
        scene->unk7C++;
        if (func_8001B990(0x100, 0x3E) == 0) {
            break;
        }
        scene->unk7C = -1;
        D_800B4988 = 0;
        D_800B5DD4 = 1;
        if (D_800BCFB8[cameraGetMode()] == 0) {
            func_80063E50();
        }
        goto tail;
    case 1:
        scene->unk90 = 0;
        scene->unk7C++;
        gCameraTarget->unk68 = -1;
        gCameraTarget->unk9C = animStepKeys;
        func_800232B4(0x801, 0, 0, 0);
        break;
    case 2:
        *func_80052444(0) = 0x13D;
        setActorState(0x13D, 2);
        scene->unk7C++;
        break;
    case 3:
        if (func_800520D0(0x13D) != 1) {
            break;
        }
        actor = spawnCutsceneActor();
        actor->unk64 = 3000;
        actor->unkA0 = func_80063D3C;
        scene->unk64 = 1000;
        scene->unk7C++;
        actor->unk5C = 10;
        actor->unk70 = 4;
        break;
    case 4:
        scene->unk90++;
        if (tickActorTimer(scene) != 0 || (gPadPressed & 0x9000)) {
            if (scene->unk90 >= 11) {
                gPadPressed = 0;
                actor = findActor(0x13E, 0);
                if (actor != NULL) {
                    actor->unk70 = -8;
                }
                setActorState(0x13D, 3);
                scene->unk7C++;
            }
        }
        if (scene->unk90 >= 101) {
            scene->unk90 = 100;
        }
        break;
    case 5:
        if (func_800520D0(0x13E) == -1 && func_800520D0(0x13D) == 7) {
            scene->unk7C++;
        }
        actor = findActor(0x801, 0);
        if (actor != NULL) {
            actor->unkA0(actor);
        }
        break;
    case 6:
        gCameraTarget->unk0 = 3;
        gCameraTarget->unk50 = 0;
        gCameraTarget->unk90 = 1;
        if (func_80052B24(func_80023DBC(0xE39), "elroom_start", gCameraTarget) != 0) {
            scene->unk7C++;
        }
        break;
    case 7:
        if (findActor(0x801, 0) == NULL) {
            scene->unk7C++;
        }
        break;
    case 8:
        scene->unk7C++;
        if (findActor(0x11E, 0) == NULL) {
            break;
        }
        setActorState(0x13D, 5);
        actor = func_8005EA88(gCameraTarget);
        actor->unk9C = func_80063F98;
        actor->x = -3.0f;
        actor->y = 53.0f;
        actor->z = -1000.0f;
        actorSetAnim(actor, 0xDF, 0x100);
        actor->unk10 = 0;
        actor->unk0 = 0x13D;
        break;
    case 9:
        if (func_80052100(0x13D) != 0xDE) {
            break;
        }
        func_80052A5C(0x569);
        func_80052B24(func_80023DBC(0xE39), "guard", gCameraTarget);
        scene->unk7C++;
        break;
    case 10:
        if (findActor(0x801, 0) == NULL) {
            scene->unk7C++;
        }
        break;
    case 11:
        actor = findActor(0x13D, 0);
        actor->unk10 = 0x8000;
        actor->unk9C = func_80063EFC;
        actor->unk64 = 50;
        scene->unk64 = 500;
        scene->unk7C++;
        break;
    default:
        if (tickActorTimer(scene) == 0) {
            break;
        }
        setActorState(0x13D, 4);
    tail:
        scene->unk9C = (void *)D_80023080;
        gCameraTarget->unk9C = func_800393F4;
        gCameraTarget->unk68 = 3;
        gCameraTarget->unk10 = 0x8000;
        func_8001B990(0x200, 0x3E);
        D_800B5DD4 = 1;
        gCameraRig->unk9C = func_80064024;
        gCameraRig->x = -881.0f;
        gCameraRig->z = 58.0f;
        gCameraRig->y = 684.0f;
        syncActorPrevPos(gCameraRig);
        syncActorPrevPos(gCameraRig);
        break;
    }
}
