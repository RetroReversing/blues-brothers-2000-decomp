typedef struct G G;
typedef void (*Fn)(G *);
struct G {
    s32 f0; f32 f4; f32 f8; f32 fC; s32 f10; s32 f14; u8 p0[0x4C]; s32 f64; s32 f68; u8 p1[4]; s32 f70; u8 p2[8]; s32 f7C;
    u8 p3[0x1C]; Fn f9C;
};
extern G *func_80017DEC(s32);
extern G *spawnEffectObj(s32, s32, s32, s32);
extern G *findActor(s32, G *);
extern s32 func_8002D260(s32);
extern s32 tickActorTimer(G *);
extern f32 getCameraTargetDist(G *, f32, s32);
extern void func_80033DC4(G *);
extern void func_800340B4(G *);
extern f32 func_800385AC(G *);
extern void actorSetAnim(G *, s32, s32);
extern void func_80080AF0(G *);
extern void func_8003930C(G *);
extern void debugPrintf();
extern G *gCameraRig;
extern s32 gCamSpeedScale;
extern G *gCameraTarget;

void func_80080BAC(G *arg0) {
    G *temp_v0_2;

    if (arg0->f7C == 0) {
        arg0->f68 = -1;
        arg0->f7C = 1;
        arg0->f0 = 0x900;
    }
    if (225.0f < getCameraTargetDist(arg0, 250.0f, 0)) {
        arg0->f64 = 0;
        return;
    }
    if ((tickActorTimer(arg0) != 0) && !(gCameraTarget->f8 < arg0->f8)) {
        temp_v0_2 = findActor(0x901, NULL);
        while (temp_v0_2 != NULL) {
            if (temp_v0_2->f70 == arg0->f70) {
                break;
            }
            temp_v0_2 = findActor(0x901, temp_v0_2);
        }
        if (temp_v0_2 == NULL) {
            debugPrintf("Can't find room startpoint!!");
        }
        gCameraTarget->f4 = temp_v0_2->f4;
        gCameraTarget->f8 = temp_v0_2->f8;
        gCameraTarget->fC = temp_v0_2->fC;
        gCameraRig->f9C = func_800340B4;
        temp_v0_2 = func_80017DEC(arg0->f70);
        if (temp_v0_2 != NULL) {
            gCameraRig->f4 = temp_v0_2->f4;
            gCameraRig->f8 = temp_v0_2->f8;
            gCameraRig->fC = temp_v0_2->fC;
            gCameraRig->f10 = temp_v0_2->f10;
            gCameraRig->f14 = temp_v0_2->f14;
            func_80033DC4(gCameraRig);
            func_800340B4(gCameraRig);
        } else {
            debugPrintf("Can't find quickcut camera #%d", arg0->f70);
        }
        gCameraTarget->f9C = func_8003930C;
        gCameraTarget->f64 = gCamSpeedScale * 0x19;
        gCameraTarget->f8 = func_800385AC(gCameraTarget);
        gCameraTarget->f10 = func_8002D260(gCameraRig->f10 + 0x8000);
        actorSetAnim(gCameraTarget, 2, 0x100);
        temp_v0_2 = spawnEffectObj(1, 0, 0, 0);
        temp_v0_2->f9C = func_80080AF0;
        temp_v0_2->f9C(temp_v0_2);
        arg0->f64 = 0x64;
    }
}
