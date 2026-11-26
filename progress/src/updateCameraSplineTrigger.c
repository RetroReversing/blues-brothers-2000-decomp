typedef struct { s32 x, y, z; } Pt;
typedef struct Obj Obj;
struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x34 - 0x14];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    u8 pad40[0x5C - 0x40];
    s32 unk5C;
    u8 pad60[0x64 - 0x60];
    s32 unk64;
    u8 pad68[0x6C - 0x68];
    Obj *unk6C;
    u8 pad70[0x7C - 0x70];
    s32 unk7C;
    s32 unk80;
    u8 pad84[0x9C - 0x84];
    void *unk9C;
    u8 padA0[0xA8 - 0xA0];
    s32 unkA8;
    u8 padAC[0xB0 - 0xAC];
    s32 unkB0;
    u8 padB4[0xC0 - 0xB4];
    s32 unkC0;
    u8 padC4[0xD0 - 0xC4];
    s32 unkD0;
    u8 padD4[0xDC - 0xD4];
    s32 unkDC;
    u8 padE0[0x104 - 0xE0];
    s32 unk104;
};

s16 coss(u16);
s16 sins(u16);
Obj *findActor(s32, s32);
s32 randomRange(s32, s32);
s32 func_8002D1A0(void);
void syncActorPrevPos(Obj *);
f32 func_8002DD60(f32);
void func_8003CAD4(Obj *, s32);
void func_80043328(Obj *, s32, s32);
void func_80075F58(s32);
Obj *func_8007B880(s32);
void initSpline(s32, s32);
void debugPrintf(char *);
extern char D_800094D0[];
extern Obj *gCameraRig;
extern s32 D_800B396C;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 gFrameScale;
extern Obj *gCameraTarget;
extern Pt *gSplineSrcPoints[];
void updateCameraView(void);
void func_80034F50(void);
void func_8007ACD4(void);
void func_8007AEBC(void);

/* Camera controller. On first use it resets the camera state and splines. Each frame it
 * looks for the path actor (type 0x120) and, when the camera target gets close to it,
 * hands the camera to the spline rig. While the target is in state 0x17 a charge timer
 * builds up, and when it passes 200 five sparks are spawned around the target. */
void updateCameraSplineTrigger(Obj *ctrl) {
    Obj *pathActor;
    Obj *spark;
    Pt *pathPts;
    f32 dx, dz, dy;
    s32 i;
    s32 count;
    u16 angle;

    if (ctrl->unk7C == 0) {
        ctrl->unk7C = 1;
        D_800B3970 = 0;
        D_800B3974 = 0;
        D_800B3978 = 0x40;
        D_800B396C = 0x3DE;
        ctrl->unk6C = NULL;
        ctrl->unkC0 = 0;
        initSpline(1, 0);
        initSpline(6, 0);
        func_80075F58(0);
    }
    pathActor = ctrl->unk6C;
    if (pathActor == NULL) {
        pathActor = findActor(0x120, 0);
        if (pathActor != NULL) {
            ctrl->unk6C = pathActor;
        }
    } else {
        dx = gCameraTarget->x - pathActor->x;
        dz = gCameraTarget->z - pathActor->z;
        dy = func_8002DD60(gCameraTarget->y - pathActor->y);
        if (dx * dx + dz * dz < 1960000.0f && dy < 500.0f) {
            func_8003CAD4(gCameraTarget, gCameraTarget->unk10);
            gCameraRig->unk9C = updateCameraView;
            gCameraRig->unkA8 = 0;
            pathPts = gSplineSrcPoints[1];
            if (pathPts == NULL) {
                debugPrintf(D_800094D0);
            }
            pathPts += 3;
            gCameraRig->x = pathPts->x;
            gCameraRig->y = pathPts->y;
            gCameraRig->z = pathPts->z;
            syncActorPrevPos(gCameraRig);
            gCameraRig->unk9C = func_80034F50;
            gCameraRig->unkA8 = 0;
            ctrl->unk9C = func_8007ACD4;
            ctrl->unk64 = 200;
            ctrl->unkC0 = 0;
            ctrl->unkDC = 0;
            ctrl->unkB0 = 0;
            ctrl->unkA8 = 0;
            ctrl->unk104 = 0;
        }
    }
    if (gCameraTarget->unkD0 == 0x17) {
        ctrl->unk80 += gFrameScale;
    } else {
        ctrl->unk80 = 0;
    }
    if (ctrl->unk80 > 200) {
        count = 5;
        for (i = 0; i < count; i++) {
            spark = func_8007B880(0);
            angle = func_8002D1A0();
            spark->x = gCameraTarget->x + ((coss(angle) * 75) >> 13);
            spark->y = gCameraTarget->y + 200.0f;
            spark->z = gCameraTarget->z + ((sins(angle) * 75) >> 13);
            spark->unk34 = 0x60;
            spark->unk38 = 0x60;
            spark->unk3C = 0x60;
            spark->unk9C = func_8007AEBC;
            spark->unk5C = 0;
            func_80043328(spark, 0x5F, randomRange(0x100, 0x190));
            spark->unk64 = 1000;
        }
        ctrl->unk80 = -10000;
    }
}
