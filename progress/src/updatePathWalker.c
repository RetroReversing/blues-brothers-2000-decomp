typedef struct Vec3i {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

typedef struct Obj {
    s32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    char pad14[0x64 - 0x14];
    s32 x64;
    char pad68[0x9C - 0x68];
    void (*fn9C)(void);
    char padA0[0xBC - 0xA0];
    s32 xBC;
    s32 xC0;
    char padC4[0x108 - 0xC4];
} Obj;

Obj *getObjPoolStart(s32);
Obj *getObjPoolEnd(s32);
s32 randomRange(s32, s32);
s32 func_8002492C(f32, f32);
s32 approachAngle(s32, s32, s32);
s32 tickActorTimer(void *);
f32 func_8002DD60(f32);
f32 func_800385AC(void *);
void animStepKeys(void *);
void actorSetAnim(void *, s32, s32);
void debugPrintf(char *);
void func_8001B04C(void);
f32 sqrtf(f32);
s16 sins(u16);
s16 coss(u16);

extern char D_80000C04[];
extern f32 D_80000C10;
extern f32 D_80000C14;
extern f64 D_80000C18;
extern f32 D_80000C20;
extern f64 D_80000C28;
extern u8 D_800B9EC4[];
extern u8 gCamSpeedScale[];
extern u8 gCameraTarget[];
extern s32 D_8014A99C[];
extern u8 D_8014AA1C[];
#define BD (*(Obj **)gCameraTarget)

/* Walks the actor along the waypoint path and plays a random reaction when it passes a flagged actor. */ void updatePathWalker(Obj *walker) {
    Vec3i *waypoints;
    f32 dx;
    f32 dz;
    f32 distToTarget;
    f32 speed;
    f64 lim;
    f32 dy;
    Obj *other;
    Obj *lastActor;
    Obj *firstActor;
    s32 animChoice;

    waypoints = *(Vec3i **)D_8014AA1C;
    animStepKeys(walker);
    if (waypoints == NULL) {
        debugPrintf(D_80000C04);
        return;
    }
    if (walker->xC0 == 0) {
        BD->x0 = 0x101;
        walker->xBC = 0;
        walker->x4 = waypoints[walker->xBC].x;
        walker->xC = waypoints[walker->xBC].z;
        walker->x8 = func_800385AC(walker);
        actorSetAnim(walker, 4, 0x100);
        walker->xC0 = 1;
        walker->x0 = 3;
        BD = walker;
    }
    dx = waypoints[walker->xBC].x - walker->x4;
    dz = waypoints[walker->xBC].z - walker->xC;
    distToTarget = sqrtf(dx * dx + dz * dz);
    walker->x10 = approachAngle(func_8002492C(dx, dz), walker->x10, *(s32 *)gCamSpeedScale << 9);
    speed = *(f32 *)D_800B9EC4 * D_80000C10;
    walker->x4 += ((s32)speed * sins(walker->x10)) >> 15;
    walker->xC += ((s32)speed * coss(walker->x10)) >> 15;
    walker->x8 = func_800385AC(walker);
    if (distToTarget < D_80000C14) {
        if (++walker->xBC >= D_8014A99C[0] - 1) {
            walker->xBC = 0;
        }
    }
    if (tickActorTimer(walker) != 0) {
        walker->x64 = 0;
        firstActor = getObjPoolStart(0);
        lastActor = getObjPoolEnd(0);
        other = firstActor;
        if (other <= lastActor) {
            lim = D_80000C18;
            do {
                if (other->x0 & 0x1000) {
                    dx = walker->x4 - other->x4;
                    dy = walker->x8 - other->x8;
                    dz = walker->xC - other->xC;
                    if (!(D_80000C20 < dy) && !(lim < func_8002DD60(dx)) && !(lim < func_8002DD60(dz)) &&
                        !(D_80000C28 < (distToTarget = sqrtf(dx * dx + dz * dz)))) {
                        walker->fn9C = func_8001B04C;
                        animChoice = randomRange(0, 5);
                        if (animChoice == 0) {
                            actorSetAnim(walker, 13, 0x100);
                        } else if (animChoice == 1) {
                            actorSetAnim(walker, 14, 0x100);
                        } else if (animChoice == 2) {
                            actorSetAnim(walker, 15, 0x100);
                        } else if (animChoice == 3) {
                            actorSetAnim(walker, 30, 0x100);
                        } else {
                            actorSetAnim(walker, 18, 0x100);
                        }
                    }
                }
                other++;
            } while (other <= lastActor);
        }
    }
}
