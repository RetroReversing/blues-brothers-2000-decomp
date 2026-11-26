typedef struct Obj6074 {
    char pad0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 rx;
    s32 ry;
    char pad18[0x54];
    s32 idx;
    char pad70[8];
    s32 o78;
    s32 o7C;
} Obj6074;

typedef struct Cam6074 {
    s32 pad0;
    f32 x;
    f32 y;
    f32 z;
} Cam6074;

typedef struct Vec6074 {
    f32 x;
    f32 y;
    f32 z;
} Vec6074;

typedef struct Rec6074 {
    s32 dist;
    s32 pad;
} Rec6074;

extern f32 __cosf(f32);
extern f32 sinApprox(f32);
f32 sqrtf(f32);
extern void mtxIdentity3(s32 *);
extern void func_8002DB6C(s32 *, s32 *, f32);
extern void func_8002DAE0(s32 *, s32 *, f32);
extern void mtxTransformVec3(Vec6074 *, s32 *, f32 *);
extern void initBoundsToSegment(f32 *, f32 *, Vec6074 *, f32 *);
extern void expandBoundsToSegment(f32 *, f32 *, Vec6074 *, f32 *);
extern void collectCollisionCells(f32 *, f32 *, s32);
extern s32 raycastCollision(f32 *, Vec6074 *, Vec6074 *);
extern s32 vec3Sub(f32 *, Vec6074 *, f32 *);
extern f32 vec3Length(s32);
extern f64 D_80001428;
extern f32 D_80001430;
extern f32 D_80001434;
extern f32 D_80001438;
extern f32 D_8000143C;
extern f32 D_80001440;
extern f32 D_80001444;
extern f64 D_80001448;
extern Rec6074 cameraDistTable[];
extern f32 cameraRayDirs[][3];
extern u8 gCameraTarget[];

#define CAM (*(Cam6074 **)gCameraTarget)

/* Pulls the camera in when rays from the camera hit walls. Returns 1 if the wall is too close,
   the mask of still-blocked rays if pulling in was not enough, or 0 and stores the new distance
   in obj->o78/o7C when the view is clear. */
s32 cameraAvoidWalls(Obj6074 *obj) {
    f32 camPos[8];
    f32 probeOrigin[4];
    s32 tmpMtx[10];
    s32 rayMtx[10];
    Vec6074 rayEnds[5];
    f32 boxMin[4];
    f32 boxMax[8];
    f32 hitDelta[4];
    Vec6074 rayHits[5];
    f32 pitch;
    f32 yaw;
    f32 dist;
    f32 tmp;
    s32 i;
    s32 newDist;
    s32 rayBit;
    s32 hitMask;
    f32 hitDist;

    pitch = obj->ry;
    yaw = obj->rx;
    pitch *= D_80001428;
    yaw *= D_80001428;
    dist = (f32) cameraDistTable[obj->idx].dist;
    probeOrigin[0] = obj->x;
    probeOrigin[1] = obj->y;
    probeOrigin[2] = obj->z;
    camPos[0] = CAM->x;
    camPos[1] = CAM->y + D_80001430;
    camPos[2] = CAM->z;
    mtxIdentity3(tmpMtx);
    mtxIdentity3(rayMtx);
    func_8002DB6C(tmpMtx, rayMtx, yaw);
    func_8002DAE0(rayMtx, tmpMtx, -pitch);
    tmp = dist * __cosf(pitch);
    tmp *= sinApprox(yaw);
    probeOrigin[0] = camPos[0] - tmp;
    probeOrigin[1] = camPos[1] - dist * sinApprox(pitch);
    tmp = dist * __cosf(pitch);
    tmp *= __cosf(yaw);
    probeOrigin[2] = camPos[2] - tmp;
    hitMask = 0;
    rayBit = 1;
    dist = D_80001434;
    for (i = 1; i < 5; i++) {
        mtxTransformVec3(&rayEnds[i], rayMtx, cameraRayDirs[i]);
        rayEnds[i].x += probeOrigin[0];
        rayEnds[i].y += probeOrigin[1];
        rayEnds[i].z += probeOrigin[2];
        if (i == 1) {
            initBoundsToSegment(boxMin, boxMax, &rayEnds[1], camPos);
        } else {
            expandBoundsToSegment(boxMin, boxMax, &rayEnds[i], camPos);
        }
    }
    collectCollisionCells(boxMin, boxMax, 3);
    for (i = 1; i < 5; i++) {
        if (raycastCollision(camPos, &rayEnds[i], &rayHits[i]) != 0) {
            hitDist = vec3Length(vec3Sub(hitDelta, &rayHits[i], camPos));
            if (hitDist < dist) {
                dist = hitDist;
            }
            hitMask |= rayBit;
        }
        rayBit <<= 1;
    }
    if (hitMask == 0) {
        return 0;
    }
    dist -= D_80001438;
    if (dist < D_8000143C) {
        return 1;
    }
    dist = sqrtf(dist * dist - D_80001440 - D_80001444) + D_80001448;
    tmp = dist * __cosf(pitch);
    tmp *= sinApprox(yaw);
    probeOrigin[0] = camPos[0] - tmp;
    probeOrigin[1] = camPos[1] - dist * sinApprox(pitch);
    tmp = dist * __cosf(pitch);
    tmp *= __cosf(yaw);
    probeOrigin[2] = camPos[2] - tmp;
    hitMask = 0;
    for (i = 1; i < 5; i++) {
        mtxTransformVec3(&rayEnds[i], rayMtx, cameraRayDirs[i]);
        rayEnds[i].x += probeOrigin[0];
        rayEnds[i].y += probeOrigin[1];
        rayEnds[i].z += probeOrigin[2];
        if (raycastCollision(camPos, &rayEnds[i], NULL) != 0) {
            hitMask |= rayBit;
        }
        rayBit <<= 1;
    }
    if (hitMask != 0) {
        return hitMask;
    }
    newDist = dist;
    obj->o78 = newDist;
    obj->o7C = newDist;
    return 0;
}
