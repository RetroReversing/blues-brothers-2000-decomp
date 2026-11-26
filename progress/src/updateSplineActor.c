s32 cameraGetMode(void);
s32 randomRange(s32, s32);
s32 func_8002444C(void);
void tickActorTimer(void *);
void syncActorPrevPos(void *);
void func_80043328(void *, s32, s32);
s32 func_8006BB14(void *);
s32 updateDistanceCull(void *);
void func_80080594(void *, s32);
s32 func_80080DE0(s32);
void initSpline(s32, s32);
void func_80083A28(void *);
s32 func_80083CC4(void *);
s32 func_80083E98(void *);
void fireActorEvents(void *);
s32 func_80085900(void *);
s32 func_80085A5C(void *);
s32 func_80085B8C(void *);
void debugPrintf(char *, s32);
void func_80084504(void);

typedef struct Ent {
    char pad0[4];
    s32 x4;
} Ent;

typedef struct Obj {
    char pad0[8];
    f32 x8;
    char padC[0x64 - 0xC];
    s32 x64;
    char pad68[0x70 - 0x68];
    s32 x70;
    s32 x74;
    s32 x78;
    s32 x7C;
    char pad80[0x8C - 0x80];
    s32 x8C;
    char pad90[0x9C - 0x90];
    void (*fn9C)(void);
    char padA0[0xAC - 0xA0];
    f32 xAC;
    char padB0[0xB4 - 0xB0];
    f32 xB4;
    s32 xB8;
    s32 xBC;
    char padC0[0xD8 - 0xC0];
    s32 (*fnD8)(struct Obj *);
    char padDC[0x104 - 0xDC];
    f32 x104;
} Obj;

extern char D_80009B04[];
extern char D_80009B1C[];
extern f32 D_80009B34;
extern f32 D_80009B38;
extern f32 D_80009B3C;
extern u8 D_800B9B18[];
extern Ent *gSplineSrcPoints[];

/* Per-frame update for an actor that rides a spline path: on first entry it starts the spline, then runs its state machine and debug-logs unexpected results. */ void updateSplineActor(Obj *actor) {
    s32 result;

    result = 1;
    if (actor->x7C == 0) {
        if (func_80080DE0(actor->x70) == 0) {
            initSpline(actor->x70, *(s32 *)D_800B9B18);
        }
        actor->x7C = 1;
        actor->x78 = 0;
        actor->fnD8 = NULL;
        syncActorPrevPos(actor);
        if (actor->xAC == 0.0f) {
            actor->xAC = D_80009B34;
        }
        if (actor->x104 == 0.0f) {
            actor->x104 = D_80009B38;
        }
        actor->xB4 = 0.0f;
        actor->xBC = 1;
        actor->x8 = gSplineSrcPoints[actor->x70]->x4;
        if (cameraGetMode() == 0x30 && actor->xB8 == 12) {
            actor->x8 -= D_80009B3C;
        }
        if (func_80085900(actor) == 0) {
            actor->x7C = 0;
            actor->fn9C = func_80084504;
            return;
        }
        actor->x64 = randomRange(25, 30) * 100;
    }
    if (updateDistanceCull(actor) != 0) {
        return;
    }
    tickActorTimer(actor);
    if (actor->fnD8 != NULL) {
        result = actor->fnD8(actor);
    }
    fireActorEvents(actor);
    if (result != 0) {
        switch (actor->x78) {
        case 0:
        case 2:
        case 3:
        case 4:
            switch (result) {
            case 1:
                actor->x78 = result;
                actor->fnD8 = func_80085A5C;
                break;
            case 2:
                actor->x78 = 4;
                actor->fnD8 = func_80083CC4;
                actor->x8C = 0;
                break;
            default:
                debugPrintf(D_80009B04, result);
                break;
            }
            break;
        case 6:
            actor->x78 = 4;
            actor->fnD8 = func_80083CC4;
            actor->x8C = 0;
            break;
        default:
            switch (result) {
            case 1:
                actor->x64 = randomRange(25, 30) * 100;
                actor->x78 = 0;
                actor->fnD8 = func_80083E98;
                if (func_8002444C() & 1) {
                    func_80080594(actor, 2);
                } else {
                    func_80080594(actor, 1);
                }
                break;
            case 2:
                actor->x78 = 3;
                actor->fnD8 = func_8006BB14;
                break;
            case 3:
                actor->x78 = 4;
                actor->fnD8 = func_80083CC4;
                actor->x8C = 0;
                break;
            case 4:
                actor->x78 = 2;
                actor->fnD8 = func_80085B8C;
                func_80080594(actor, 0);
                break;
            default:
                debugPrintf(D_80009B1C, result);
                break;
            }
            break;
        }
        func_80043328(actor, actor->x74 + actor->x78, 0x100);
        if (actor->fnD8 != NULL) {
            actor->fnD8(actor);
        }
    }
    func_80083A28(actor);
}
