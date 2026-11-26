typedef void (*Fn)(void *);
typedef struct Actor {
    s32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    s32 x14;
    u8 pad18[0x64 - 0x18];
    s32 x64;
    s32 x68;
    u8 pad6C[0x70 - 0x6C];
    s32 x70;
    u8 pad74[0x7C - 0x74];
    s32 x7C;
    u8 pad80[0x88 - 0x80];
    s32 x88;
    u8 pad8C[0x9C - 0x8C];
    Fn x9C;
    u8 padA0[0xA8 - 0xA0];
    s32 xA8;
} Actor;
void *func_80017DEC(s32);
void *func_800232B4(s32, s32, s32, s32);
void *findActor(s32, void *);
s32 func_8002D260(s32);
s32 tickActorTimer(void *);
void syncActorPrevPos(void *);
f32 getCameraTargetDist(void *, f32, s32);
void func_80033DC4(void *);
void func_800340B4(void *);
f32 func_800385AC(void *);
void actorSetAnim(void *, s32, s32);
void func_80064024(void *);
void func_80080AF0(void *);
void debugPrintf(void *);
void func_8003930C(void *);
extern u8 D_80009734[];
extern u8 D_80009754[];
extern Actor *gCameraRig;
extern s32 gCamSpeedScale;
extern Actor *gCameraTarget;

/* Per-frame update for a camera quickcut trigger: when the player is far from the trigger it re-arms it, and when close it snaps the camera and rig to the matching start points and cuts to the trigger's camera. */ void updateCameraQuickcut(Actor *trigger) {
    Actor *marker;

    if (trigger->x7C == 0) {
        trigger->x68 = -1;
        trigger->x7C = 1;
        trigger->x0 = 0x900;
        trigger->x88 = 0;
    }
    if (225.0f < getCameraTargetDist(trigger, 250.0f, 0)) {
        trigger->x64 = 0;
        if (gCameraTarget->x8 - trigger->x8 < -900.0f && trigger->x88 != 0
            && gCameraRig->x9C == (Fn)func_80064024) {
            trigger->x88 = 0;
            func_80033DC4(gCameraRig);
            func_800340B4(gCameraRig);
            gCameraRig->x9C = func_800340B4;
            marker = func_800232B4(1, 0, 0, 0);
            marker->x9C = func_80080AF0;
            marker->x9C(marker);
            trigger->x64 = 300;
        }
    } else if (tickActorTimer(trigger) != 0 && !(gCameraTarget->x8 < trigger->x8)) {
        if (trigger->x88 == 0) {
            for (marker = findActor(0x901, NULL); marker != NULL; marker = findActor(0x901, marker)) {
                if (marker->x70 == trigger->x70) {
                    break;
                }
            }
            if (marker == NULL) {
                debugPrintf(D_80009734);
            }
            gCameraTarget->x4 = marker->x4;
            gCameraTarget->x8 = marker->x8;
            gCameraTarget->xC = marker->xC;
            for (marker = findActor(0x902, NULL); marker != NULL; marker = findActor(0x902, marker)) {
                if (marker->x70 == trigger->x70) {
                    break;
                }
            }
            if (marker == NULL) {
                debugPrintf(D_80009754);
            }
            gCameraRig->x4 = marker->x4;
            gCameraRig->x8 = marker->x8;
            gCameraRig->xC = marker->xC;
            gCameraRig->x9C = func_80064024;
            gCameraRig->xA8 = 0;

            syncActorPrevPos(gCameraRig);
            gCameraRig->x9C(gCameraRig);
        } else {
            gCameraRig->x9C = func_800340B4;
            marker = func_80017DEC(trigger->x70);
            if (marker != NULL) {
                gCameraRig->x4 = marker->x4;
                gCameraRig->x8 = marker->x8;
                gCameraRig->xC = marker->xC;
                gCameraRig->x10 = marker->x10;
                gCameraRig->x14 = marker->x14;
                func_80033DC4(gCameraRig);
                func_800340B4(gCameraRig);
            }
            gCameraTarget->x4 = trigger->x4;
            gCameraTarget->xC = trigger->xC;
            gCameraTarget->x8 = gCameraTarget->x8 + 150.0f;
        }
        gCameraTarget->x9C = func_8003930C;
        gCameraTarget->x64 = gCamSpeedScale * 25;
        gCameraTarget->x8 = func_800385AC(gCameraTarget);
        gCameraTarget->x10 = func_8002D260(gCameraRig->x10 + 0x8000);
        actorSetAnim(gCameraTarget, 2, 0x100);
        marker = func_800232B4(1, 0, 0, 0);
        marker->x9C = func_80080AF0;
        marker->x9C(marker);
        trigger->x64 = 300;
        trigger->x88 ^= 1;
    }
}
