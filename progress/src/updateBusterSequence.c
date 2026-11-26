typedef struct Act364 {
    u32 id;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x5C];
    s32 c6C;
    s32 c70;
    s32 c74;
    u8 pad78[4];
    u32 state;
    u8 pad80[0xC];
    s32 c8C;
    struct Act364 *target;
    s32 c94;
    u8 pad98[4];
    void *fn;
    u8 padA0[8];
    struct Act364 *link;
    u8 padAC[0x14];
    s32 cC0;
    u8 padC4[0x3C];
    f32 c100;
} Act364;

extern f32 sqrtf(f32);
extern void func_80052A30(void);
extern void func_80052A5C(s32);
extern void func_800242A8(s32, s32, s32);
extern void func_80017ECC(s32, f32, f32, f32, s32, s32, s32);
extern Act364 *func_800232B4(s32, s32, s32, s32);
extern Act364 *findActor(s32, Act364 *);
extern s32 func_80023DBC(s32);
extern s32 func_80052B24(s32, u8 *, Act364 *);
extern f32 approachF32(f32, f32, f32);
extern void func_8002A360(s32, s32);
extern void func_80034F50();
extern void func_8007FD48();
extern void func_8007FACC();
extern void func_800393F4();
extern const f32 D_80009694;
extern const f32 D_80009698;
extern const f64 D_800096A0;
extern const f32 D_800096A8;
extern const f32 D_800096AC;
extern const f32 D_800096B0;
extern const f32 D_800096B4;
extern u8 D_8000966C[];
extern u8 D_800B3960[];
extern u8 D_800B396C[];
extern u8 D_800B3970[];
extern u8 D_800B3974[];
extern u8 D_800B3978[];
extern u8 D_800B5DD4[];
extern u8 D_800B83B0[];
extern u8 gCameraTarget[];

#define PLAYER (*(Act364 **) D_800B3960)
#define CAM (*(Act364 **) gCameraTarget)
#define GS32(x) (*(s32 *) (x))

static inline f32 len364(f32 x, f32 z) {
    return sqrtf(x * x + z * z);
}

/* Per-frame state machine for the Buster cutscene actor. Sets up the player and camera for each step, then clamps the camera distance and finds the nearest target actor. */
/* Per-frame state machine for the Buster cutscene actor: sets up the player and camera for each step, then clamps the camera distance and finds the nearest target actor. */ void updateBusterSequence(Act364 *o) {
    Act364 *actor;
    Act364 *pl;
    s32 soundId;
    s32 sceneId;
    f32 clampedZ;
    f32 camDist;
    f32 heightOk;
    f32 dxToCam;
    f32 maxCamDist;
    f32 camDistSq;

    switch (o->state) {
    case 0:
        GS32(D_800B3970) = 24;
        GS32(D_800B3974) = 8;
        GS32(D_800B3978) = 60;
        GS32(D_800B396C) = 995;
        PLAYER->link = NULL;
        PLAYER->c6C = 0;
        PLAYER->cC0 = 0;
        PLAYER->fn = func_80034F50;
        func_80052A30();
        GS32(D_800B5DD4) = 0;
        o->c70 = 0;
        o->c8C = 0;
        o->target = NULL;
        o->link = NULL;
        o->state++;
        soundId = GS32(D_800B83B0) + 470;
        o->c94 = soundId;
        func_800242A8(soundId, 0xAD3, 0);
        GS32(D_800B83B0)++;
        func_80017ECC(1, 0.0f, 0.0f, 0.0f, 0x4FA, -0xAAA, 0);
        o->c74 = 0;
        func_800232B4(0x127, 0, 0, 0)->fn = func_8007FD48;
        break;
    case 1:
        PLAYER->x = CAM->x;
        PLAYER->y = D_80009694;
        PLAYER->z = CAM->z - D_80009698;
        o->state++;
        break;
    case 2:
        actor = findActor(0x1027, 0);
        PLAYER->link = actor;
        if (actor == NULL) {
            break;
        }
        clampedZ = approachF32(actor->z - D_800096A0, PLAYER->z, 28.5f);
        PLAYER->z = clampedZ;
        if (clampedZ == actor->z - D_800096A0) {
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x2F);
            o->state++;
        }
        break;
    case 3:
        func_80052A5C(0x55E);
        sceneId = func_80023DBC(0xE45);
        func_80052A30();
        if (func_80052B24(sceneId, D_8000966C, o) != 0) {
            o->state++;
        }
        break;
    case 4:
        if (CAM->fn == func_800393F4) {
            func_80052A30();
        }
        break;
    case 5:
        o->c8C = 0;
        PLAYER->fn = func_8007FACC;
        PLAYER->state = 0;
        PLAYER->link = NULL;
        PLAYER->c100 = D_800096A8;
        GS32(D_800B5DD4) = 1;
        o->state++;
        CAM->fn = func_800393F4;
        break;
    case 6:
        actor = findActor(0x11F, 0);
        if (actor != NULL) {
            actor = findActor(0x11F, actor);
            if (actor != NULL) {
                actor->id = 0x120;
            }
        }
        o->state++;
        break;
    }
    maxCamDist = D_800096AC;
    camDistSq = CAM->x * CAM->x + CAM->z * CAM->z;
    camDist = sqrtf(camDistSq);
    if (maxCamDist < camDist) {
        CAM->x = CAM->x * maxCamDist / camDist;
        CAM->z = CAM->z * maxCamDist / camDist;
    }
    o->target = NULL;
    for (actor = findActor(0x11E, 0); actor != NULL; actor = findActor(0x11E, actor)) {
        heightOk = 0.0f;
        dxToCam = actor->x - CAM->x;
        if (CAM->y > actor->y) {
            heightOk = D_800096B4;
        }
        camDist = sqrtf(dxToCam * dxToCam + (actor->z - CAM->z) * (actor->z - CAM->z));
        if (camDist < 1150.0f && heightOk != 0.0f) {
            o->target = actor;
            break;
        }
    }
    if (o->link == NULL) {
        o->link = findActor(0x102D, 0);
    }
}
