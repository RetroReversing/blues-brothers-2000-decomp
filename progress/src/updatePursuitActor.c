s32 cameraGetMode(void);
f32 approachF32(f32, f32, f32);
void syncActorPrevPos(void *);
f32 func_8002DD60(f32);
void actorSetAnim(void *, s32, s32);
f32 sqrtf(f32);
void func_800340B4(void);
void func_800351D4(void);
void func_800393F4(void);
void animStepKeys(void);
void func_8007CB84(void);

typedef struct Obj {
    s32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    char pad10[0x44 - 0x10];
    f32 x44;
    char pad48[0x50 - 0x48];
    s32 x50;
    char pad54[0x74 - 0x54];
    s32 x74;
    char pad78[0x7C - 0x78];
    s32 x7C;
    char pad80[0x8C - 0x80];
    s32 x8C;
    s32 x90;
    char pad94[0x9C - 0x94];
    void (*fn9C)(void);
    char padA0[0xA8 - 0xA0];
    struct Obj *xA8;
} Obj;

extern f64 D_80009578;
extern f64 D_80009580;
extern f32 D_80009588;
extern f32 D_8000958C;
extern Obj *gCameraRig[];
extern u8 D_800B3964[];
extern u8 gCamSpeedScale[];
extern u8 gCameraTarget[];
extern u8 D_801700E0[];
extern u8 D_801700E4[];
#define BD (*(Obj **)gCameraTarget)
#define P60 (gCameraRig[0])
#define P64 (*(Obj **)D_800B3964)

/* Per-frame update for an actor that waits until the camera is in place, then closes in on the camera target, stops, and backs off when the target moves away. */ void updatePursuitActor(Obj *pursuer) {
    f32 dx;
    f32 dz;
    f32 dy;
    f32 dist;
    f32 r;
    Obj *target;
    s32 t;

    dx = pursuer->x4 - BD->x4;
    dz = pursuer->xC - BD->xC;
    dy = pursuer->x8 - BD->x8;
    dist = sqrtf(dx * dx + dz * dz);
    if (pursuer->x7C == 0) {
        if (cameraGetMode() == 0x3C) {
            P64->xA8 = pursuer;
            pursuer->x7C = 1;
            pursuer->x90 = 0;
            syncActorPrevPos(pursuer);
        }
        return;
    }
    if (pursuer->x90 != 0) {
        switch (pursuer->x90) {
        case 1:
            if (dist < D_80009578) {
                actorSetAnim(BD, 1, 0x100);
                {
                    Obj *b1 = BD;
                b1->fn9C = animStepKeys;
                b1->x0 = 3;
                b1->x50 = 0;
                b1->x90 = 1;
                }
                P60->fn9C = func_800351D4;
                pursuer->x90 = 2;
                pursuer->x8C = 0x898;
            }
            break;
        case 2:
            pursuer->x8 = approachF32(pursuer->x44 + (f32)pursuer->x8C, pursuer->x8, (f32)(*(s32 *)gCamSpeedScale * 10));
            BD->x8 = pursuer->x8 + (f32)*(s32 *)D_801700E4;
            if (pursuer->x8 == pursuer->x44 + (f32)pursuer->x8C) {
                BD->x74 = *(s32 *)D_801700E0;
                BD->fn9C = func_800393F4;
                pursuer->x90 = 3;
            }
            break;
        case 3:
            P60->fn9C = func_800340B4;
            if (D_80009580 < dist) {
                pursuer->x90 = 4;
            }
            break;
        case 4:
            pursuer->x8 = approachF32(pursuer->x44, pursuer->x8, (f32)(*(s32 *)gCamSpeedScale * 10));
            if (pursuer->x8 == pursuer->x44) {
                pursuer->x90 = 5;
            }
            break;
        case 5:
            if (func_8002DD60(dy) < D_80009588) {
                pursuer->x90 = 1;
            }
            break;
        }
    } else if (P64->x7C == 2 && dist < D_8000958C) {
        target = BD;
        if (target->x90 != 0) {
            *(s32 *)D_801700E0 = target->x74;
            target->x74 = 0;
            *(s32 *)D_801700E4 = target->x8 - pursuer->x8;
            P64->fn9C = func_8007CB84;
            P64->x7C = 0;
        }
    }
}
