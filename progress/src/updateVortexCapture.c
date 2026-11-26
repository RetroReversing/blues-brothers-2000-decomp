s16 coss(u16);
s16 sins(u16);
void spawnSparkle(void *);
void *findActor(s32, void *);
void sendCommand(s32, s32);
s32 approachAngle(s32, s32, s32);
void syncActorPrevPos(void *, void *);
f32 getCameraTargetDist(void *, f32, s32 *);
void actorSetAnim(void *, s32, s32);
void updateFlungPlayer(void *);

typedef struct Obj {
    char pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    char pad14[0x4C - 0x14];
    f32 x4C;
    f32 x50;
    f32 x54;
    char pad58[0x64 - 0x58];
    s32 x64;
    char pad68[0x70 - 0x68];
    s32 x70;
    char pad74[0x9C - 0x74];
    void (*fn9C)(void *);
    char padA0[0xAC - 0xA0];
    s32 xAC;
    s32 xB0;
    s32 xB4;
    char padB8[0xD0 - 0xB8];
    s32 xD0;
} Obj;

extern f32 vortexPullRadius;
extern f32 vortexCaptureRadius;
extern f32 D_800004F4;
extern f32 D_800004F8;
extern f32 D_800004FC;
extern f32 D_80000500;
extern f32 D_80000504;
extern Obj *D_800B3964[];
extern s32 gCamSpeedScale[];
extern u8 gCameraTarget[];
#define PLAYER (*(Obj **)gCameraTarget)

/* Vortex enemy: pulls the player within 600 units toward it and, once close enough, captures the player and flings them to the matching marker. */
void updateVortexCapture(Obj *vortex) {
    s32 angle;
    f32 pullRadius;
    f32 dist;
    s32 speed;
    s32 i;
    s32 t;
    Obj *target;

    pullRadius = vortexPullRadius;
    dist = getCameraTargetDist(vortex, pullRadius, &angle);
    if (pullRadius <= dist) {
        return;
    }
    if (PLAYER->xC < vortex->xC - vortexCaptureRadius) {
        return;
    }
    if (PLAYER->x8 > vortex->x8) {
        return;
    }
    if (PLAYER->xD0 != 11) {
        return;
    }
    speed = (s32)(pullRadius - dist);
    speed *= 20;
    speed = (gCamSpeedScale[0] * speed) / 600;
    if (vortexCaptureRadius <= dist) {
        PLAYER->x10 = approachAngle(angle + 0x8000, PLAYER->x10, gCamSpeedScale[0] << 9);
        PLAYER->xC += (speed * coss(angle - 0x8000)) >> 15;
        PLAYER->x4 += (speed * sins(angle - 0x8000)) >> 15;
        return;
    }
    if (dist < vortexCaptureRadius) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x57);
        for (i = 0; i < 4; i++) {
            spawnSparkle(vortex);
        }
        PLAYER->x8 = D_800004F4;
        if (vortex->x70 == 3) {
            PLAYER->x8 = D_800004F8;
        }
        PLAYER->xC = D_800004FC;
        target = findActor(0x1021, 0);
        while (target != 0) {
            if (target->x70 == vortex->x70) {
                PLAYER->x4 = target->x4;
                break;
            }
            target = findActor(0x1021, target);
        }
        if (target != 0) {
            D_800B3964[0]->x70 = target->x70;
        }
        PLAYER->x4C = 0.0f;
        PLAYER->x50 = 0.0f;
        PLAYER->x54 = D_80000500;
        PLAYER->x10 = 0x8000;
        syncActorPrevPos(PLAYER, target);
        PLAYER->fn9C = updateFlungPlayer;
        PLAYER->xAC = 0;
        PLAYER->xB0 = 0;
        PLAYER->xB4 = 0;
        PLAYER->x64 = 300;
        PLAYER->x50 = D_80000504;
        actorSetAnim(PLAYER, 0x10, 0x100);
    }
}
