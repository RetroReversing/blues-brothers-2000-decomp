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
extern Actor *D_800B3960;
extern s32 gCamSpeedScale;
extern Actor *gCameraTarget;

void func_80080620(Actor *arg0) {
    Actor *o;

    if (arg0->x7C == 0) {
        arg0->x68 = -1;
        arg0->x7C = 1;
        arg0->x0 = 0x900;
        arg0->x88 = 0;
    }
    if (225.0f < getCameraTargetDist(arg0, 250.0f, 0)) {
        arg0->x64 = 0;
        if (gCameraTarget->x8 - arg0->x8 < -900.0f && arg0->x88 != 0
            && D_800B3960->x9C == (Fn)func_80064024) {
            arg0->x88 = 0;
            func_80033DC4(D_800B3960);
            func_800340B4(D_800B3960);
            D_800B3960->x9C = func_800340B4;
            o = func_800232B4(1, 0, 0, 0);
            o->x9C = func_80080AF0;
            o->x9C(o);
            arg0->x64 = 300;
        }
    } else if (tickActorTimer(arg0) != 0 && !(gCameraTarget->x8 < arg0->x8)) {
        if (arg0->x88 == 0) {
            for (o = findActor(0x901, NULL); o != NULL; o = findActor(0x901, o)) {
                if (o->x70 == arg0->x70) {
                    break;
                }
            }
            if (o == NULL) {
                debugPrintf(D_80009734);
            }
            gCameraTarget->x4 = o->x4;
            gCameraTarget->x8 = o->x8;
            gCameraTarget->xC = o->xC;
            for (o = findActor(0x902, NULL); o != NULL; o = findActor(0x902, o)) {
                if (o->x70 == arg0->x70) {
                    break;
                }
            }
            if (o == NULL) {
                debugPrintf(D_80009754);
            }
            D_800B3960->x4 = o->x4;
            D_800B3960->x8 = o->x8;
            D_800B3960->xC = o->xC;
            D_800B3960->x9C = func_80064024;
            D_800B3960->xA8 = 0;

            syncActorPrevPos(D_800B3960);
            D_800B3960->x9C(D_800B3960);
        } else {
            D_800B3960->x9C = func_800340B4;
            o = func_80017DEC(arg0->x70);
            if (o != NULL) {
                D_800B3960->x4 = o->x4;
                D_800B3960->x8 = o->x8;
                D_800B3960->xC = o->xC;
                D_800B3960->x10 = o->x10;
                D_800B3960->x14 = o->x14;
                func_80033DC4(D_800B3960);
                func_800340B4(D_800B3960);
            }
            gCameraTarget->x4 = arg0->x4;
            gCameraTarget->xC = arg0->xC;
            gCameraTarget->x8 = gCameraTarget->x8 + 150.0f;
        }
        gCameraTarget->x9C = func_8003930C;
        gCameraTarget->x64 = gCamSpeedScale * 25;
        gCameraTarget->x8 = func_800385AC(gCameraTarget);
        gCameraTarget->x10 = func_8002D260(D_800B3960->x10 + 0x8000);
        actorSetAnim(gCameraTarget, 2, 0x100);
        o = func_800232B4(1, 0, 0, 0);
        o->x9C = func_80080AF0;
        o->x9C(o);
        arg0->x64 = 300;
        arg0->x88 ^= 1;
    }
}
