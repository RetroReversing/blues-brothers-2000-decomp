void *findActor(s32, s32);
f32 func_8002D77C(void *, f32, s32);
s32 isTargetVulnerable(void *, s32, s32, s32);
void actorSetAnim(void *, s32, s32, void *);
void debugPrintf(char *);
extern char D_80000BEC[];
extern void *gCameraRig;
extern s32 D_800B5DD4;
extern void *gCameraTarget;
extern s32 func_8001AC3C;
extern s32 func_80023078;
extern s32 func_80034F50;
extern s32 animStepKeys;

typedef struct { u8 pad_0[4]; f32 x; f32 y; f32 z; } Vec;

void func_8001AD84(void *arg0) {
    f32 lim;
    void *o;
    void *p;
    void *q;
    void *r;

    lim = 500.0f;
    if (func_8002D77C(arg0, lim, 0) < lim && *(s32 *)((s8 *)gCameraTarget + 0xB8) == 5 && isTargetVulnerable(arg0, 0, 1, 0) != 0) {
        *(void **)((s8 *)arg0 + 0x9C) = (s8 *)&func_80023078 + 8;
        o = findActor(0x137, 0);
        if (o != NULL) {
            *(void **)((s8 *)o + 0x9C) = &func_8001AC3C;
        }
        o = findActor(0x11F, 0);
        if (o != NULL) {
            ((Vec *)gCameraRig)->x = ((Vec *)o)->x;
            ((Vec *)gCameraRig)->y = ((Vec *)o)->y;
            ((Vec *)gCameraRig)->z = ((Vec *)o)->z;
            *(void **)((s8 *)gCameraRig + 0xD8) = *(void **)((s8 *)gCameraRig + 0x9C);
            *(void **)((s8 *)gCameraRig + 0x9C) = &func_80034F50;
            p = findActor(0x1002, 0);
D_800B5DD4 = 0;
q = gCameraTarget;
*(void **)((s8 *)gCameraRig + 0xA8) = p;
r = gCameraRig;
            actorSetAnim(q, 1, 0x100, r);
            *(void **)((s8 *)gCameraTarget + 0x9C) = &animStepKeys;
            *(s32 *)((s8 *)findActor(6, 0) + 0x68) = -1;
            return;
        }
        debugPrintf(D_80000BEC);
    }
}
