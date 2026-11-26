typedef struct Actor71B08 {
    s32 unk0;
    f32 x;
    f32 y;
    f32 z;
    s32 unk10;
    u8 pad14[0x40 - 0x14];
    f32 unk40[3];
    u8 pad4C[0x64 - 0x4C];
    s32 unk64;
    u8 pad68[0x9C - 0x68];
    void (*unk9C)(struct Actor71B08 *);
} Actor71B08;

s16 sins(u16);
s16 coss(u16);
f32 func_8002DD60(f32);
void func_8002E100(f32 *, f32 *);
f32 func_8002E0D0(f32 *, f32 *);
f32 *vec3Sub(f32 *, f32 *, f32 *);
void func_8002E1CC(f32 *, f32 *, f32);
void func_8002E234(f32 *, f32 *, f32 *);
void syncActorPrevPos(Actor71B08 *);
void func_80033BDC(s32);
f32 func_800379C8(Actor71B08 *);
void actorSetAnim(Actor71B08 *, s32, s32);
Actor71B08 *func_800232B4(s32, s32, s32, s32);
void func_80071ACC(Actor71B08 *);
void func_80080AF0(Actor71B08 *);
extern Actor71B08 *gCameraRig;
extern Actor71B08 *gCameraTarget;

/* Checks whether the player's car crosses this wall segment; if so, bounces the player off it and spawns a hit effect. */ void collidePlayerWithWall(Actor71B08 *wall) {
    f32 hit[3];
    f32 dir[3];
    f32 rel[3];
    f32 dxToPlayer;
    f32 dyToPlayer;
    f32 dzToPlayer;
    f32 maxDist;
    f32 sideBefore;
    f32 sideAfter;
    f32 wallMin;
    f32 wallMax;
    f32 t;
    f32 crossT;
    Actor71B08 *a;

    dxToPlayer = gCameraTarget->x - wall->x;
    dyToPlayer = gCameraTarget->y - wall->y;
    dzToPlayer = gCameraTarget->z - wall->z;
    maxDist = 2000.0f;
    if (maxDist < func_8002DD60(dxToPlayer)) {
        return;
    }
    if (maxDist < func_8002DD60(dyToPlayer)) {
        return;
    }
    if (maxDist < func_8002DD60(dzToPlayer)) {
        return;
    }
    dir[0] = sins(wall->unk10);
    dir[1] = 0.0f;
    dir[2] = coss(wall->unk10);
    func_8002E100(dir, dir);
    sideBefore = func_8002E0D0(dir, vec3Sub(rel, gCameraTarget->unk40, &wall->x));
    sideAfter = func_8002E0D0(dir, vec3Sub(rel, &gCameraTarget->x, &wall->x));
    wallMin = wall->x + (-(coss(wall->unk10) * 200) >> 15);
    wallMax = wall->x + ((coss(wall->unk10) * 25) >> 12);
    if (wallMax < wallMin) {
        t = wallMin;
        wallMin = wallMax;
        wallMax = t;
    }
    if (0.0f <= sideBefore && sideAfter < 0.0f) {
        crossT = sideBefore / (sideBefore - sideAfter);
        vec3Sub(rel, &gCameraTarget->x, gCameraTarget->unk40);
        func_8002E1CC(rel, rel, crossT);
        func_8002E234(hit, rel, gCameraTarget->unk40);
        if (wallMin <= hit[0] && hit[0] <= wallMax && wall->y - 50.0f <= hit[1] && hit[1] < hit[1] + 400.0f) {
            gCameraRig->unk10 = wall->unk10;
            func_80033BDC(2);
            gCameraTarget->x = wall->x + ((sins(wall->unk10 - 0x8000) * 75) >> 14);
            gCameraTarget->z = wall->z + ((coss(wall->unk10 - 0x8000) * 75) >> 14);
            gCameraTarget->unk9C = func_80071ACC;
            gCameraTarget->unk64 = 100;
            syncActorPrevPos(gCameraTarget);
            gCameraTarget->y = func_800379C8(gCameraTarget);
            actorSetAnim(gCameraTarget, 1, 0x100);
            a = func_800232B4(1, 0, 0, 0);
            a->unk9C = func_80080AF0;
            a->unk9C(a);
        }
    }
    if (sideBefore <= 0.0f && 0.0f < sideAfter) {
        crossT = sideBefore / (sideBefore - sideAfter);
        vec3Sub(rel, &gCameraTarget->x, gCameraTarget->unk40);
        func_8002E1CC(rel, rel, crossT);
        func_8002E234(hit, rel, gCameraTarget->unk40);
        if (wallMin <= hit[0] && hit[0] <= wallMax && wall->y - 50.0f <= hit[1] && hit[1] < hit[1] + 400.0f) {
            gCameraRig->unk10 = wall->unk10 + 0x8000;
            func_80033BDC(0);
            gCameraTarget->x = wall->x + ((sins(wall->unk10) * 75) >> 14);
            gCameraTarget->z = wall->z + ((coss(wall->unk10) * 75) >> 14);
            gCameraTarget->unk9C = func_80071ACC;
            gCameraTarget->unk64 = 100;
            gCameraTarget->y = func_800379C8(gCameraTarget);
            actorSetAnim(gCameraTarget, 1, 0x100);
            syncActorPrevPos(gCameraTarget);
            a = func_800232B4(1, 0, 0, 0);
            a->unk9C = func_80080AF0;
            a->unk9C(a);
        }
    }
}
