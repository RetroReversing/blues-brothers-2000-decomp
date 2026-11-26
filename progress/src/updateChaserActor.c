typedef struct Obj {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 rotA;
    /* 0x14 */ s32 rotB;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ s32 tx;
    /* 0x20 */ s32 ty;
    /* 0x24 */ s32 tz;
    /* 0x28 */ u8 pad28[0x18];
    /* 0x40 */ u8 sub40[0xC];
    /* 0x4C */ u8 sub4C[0x40];
    /* 0x8C */ u32 mode;
    /* 0x90 */ u32 state;
    /* 0x94 */ u8 pad94[0xC];
    /* 0xA0 */ void (*fn)(struct Obj *);
} Obj;
s32 randomRange(s32, s32);
s32 isqrtS32(s32);
s32 atan2S16(s32, s32);
s32 approachAngle(s32, s32, s32);
s32 func_8002D4E0(Obj *, s32);
s32 syncActorPrevPos(Obj *);
f32 getCameraTargetDist(Obj *, s32, s32);
s32 func_8002DA80(Obj *);
s32 func_80038C84(void *, void *, void *);
s32 animStepKeys(Obj *);
s32 func_80043248(Obj *);
void actorSetAnim(Obj *, s32, s32);
s32 func_8004EB60(Obj *);
extern f32 D_80008314;
extern Obj *gCameraTarget;
extern s32 D_80107040[];

#define CHASE_START_DIST_SQ 0x3D08F
#define CHASE_GIVE_UP_DIST_SQ 0x5F5E10
#define TURN_RATE 0x400

/* Chaser enemy: waits until the player (gCameraTarget) comes close, then turns toward and
   follows it. If it strays too far it goes back to its home point. Player-hit callback fn. */
void updateChaserActor(Obj *actor) {
    s32 homeDx;
    s32 homeDz;
    s32 dx;
    s32 dz;
    s32 dy;
    s32 dist;
    s32 animPlaying;
    s32 homeX;
    s32 homeZ;
    u32 mode;
    switch (actor->state) {
    case 0:
        actor->rotB = -0x4000;
        actor->tx = (s32)actor->x;
        actor->state = 1;
        actor->ty = (s32)actor->y;
        actor->tz = (s32)actor->z;
        break;
    case 1:
        animStepKeys(actor);
        dx = (s32)(gCameraTarget->x - actor->x);
        dz = (s32)(gCameraTarget->z - actor->z);
        if (dx * dx + dz * dz <= CHASE_START_DIST_SQ) {
            actor->state = 2;
            actor->mode = 0;
            actor->rotB = 0;
            actorSetAnim(actor, 0x4B, 0x100);
        }
        break;
    case 2:
        animPlaying = animStepKeys(actor);
        homeX = actor->tx;
        homeZ = actor->tz;
        mode = actor->mode;
        homeDx = homeX - (s32)actor->x;
        homeDz = homeZ - (s32)actor->z;
        switch (mode) {
        case 0:
            if (homeDx * homeDx + homeDz * homeDz > CHASE_GIVE_UP_DIST_SQ) {
                actor->mode = 1;
            } else {
                dx = (s32)(gCameraTarget->x - actor->x);
                dz = (s32)(gCameraTarget->z - actor->z);
                dy = (s32)((gCameraTarget->y - actor->y) + D_80008314);
                actor->rotA = approachAngle(atan2S16(dx, dz), actor->rotA, TURN_RATE);
                actor->rotB = approachAngle(atan2S16(dy, isqrtS32(dx * dx + dz * dz)), actor->rotB, TURN_RATE);
                syncActorPrevPos(actor);
                func_8002D4E0(actor, 0x3E8);
                func_8002DA80(actor);
                func_80038C84(actor->sub40, &actor->x, actor->sub4C);
                if (animPlaying != 0) {
                    actorSetAnim(actor, randomRange(0, 1) + 0x4B, 0x100);
                }
            }
            break;
        case 1:
            dx = (s32)((f32)homeX - actor->x);
            dz = (s32)((f32)homeZ - actor->z);
            dy = (s32)((f32)actor->ty - actor->y);
            dist = dx * dx + dz * dz;
            if (dist <= CHASE_START_DIST_SQ) {
                actor->state = mode;
                actor->mode = 0;
                actorSetAnim(actor, 0x4A, 0x100);
            } else {
                actor->rotA = approachAngle(atan2S16(dx, dz), actor->rotA, TURN_RATE);
                actor->rotB = approachAngle(atan2S16(dy, isqrtS32(dist)), actor->rotB, TURN_RATE);
                syncActorPrevPos(actor);
                func_8002D4E0(actor, 0x320);
                func_8002DA80(actor);
                func_80038C84(actor->sub40, &actor->x, actor->sub4C);
            }
            break;
        }
        break;
    case 3:
        actorSetAnim(actor, 0x4D, 0x100);
        actor->state = 4;
        break;
    case 4:
        if (func_80043248(actor) != 0) {
            func_8004EB60(actor);
            actor->fn(actor);
        }
        break;
    }
    if (((s32)getCameraTargetDist(actor, 0x43C80000, 0) < 0x190) && (D_80107040[0] & 0x4000) && ((s32)actor->state < 3)) {
        actor->state = 3;
    }
}
