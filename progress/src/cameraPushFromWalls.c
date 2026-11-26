typedef struct { f32 x, y, z; } Vec3;
f32 __cosf(f32);
s32 func_80024AC4(s32, s32);
void func_8002DAE0(void *, void *, f32);
void func_8002DB6C(void *, void *, f32);
void mtxIdentity3(void *);
void mtxTransformVec3(void *, void *, void *);
s32 raycastCollision(void *, void *, s32);
void expandBoundsToSegment(void *, void *, void *, void *);
void initBoundsToSegment(void *, void *, void *, void *);
void collectCollisionCells(void *, void *, s32);
f32 sinApprox(f32);
extern Vec3 cameraRayDirs[];
extern f32 *gCameraTarget;
extern s32 gCameraOffsetZ;
extern s32 gCameraOffsetX;

/* Casts five rays from the camera target toward the camera position; for each ray that hits geometry, nudges the camera offset (X and Z) away from that side. */
void cameraPushFromWalls(s32 *cam) {
    f32 targetPos[8];
    f32 camPos[4];
    f32 matA[10];
    f32 matB[10];
    Vec3 rayEnds[5];
    f32 boundsMin[4];
    f32 boundsMax[4];
    s32 stepUnits;
    f32 dist;
    f32 pitch;
    f32 yaw;
    f32 horizDist;
    f32 k;
    s32 i;
    s32 hitMask;
    s32 hitBit;
    s32 offX;
    s32 offZ;

    gCameraOffsetX -= func_80024AC4(gCameraOffsetX * 3, 3);
    stepUnits = func_80024AC4(gCameraOffsetZ * 3, 3);
    pitch = cam[0x14 / 4];
    pitch *= (3.1415926 / 32768.0);
    yaw = cam[0x10 / 4];
    yaw *= (3.1415926 / 32768.0);
    dist = cam[0x78 / 4];
    camPos[0] = ((f32 *)cam)[1];
    camPos[1] = ((f32 *)cam)[2];
    camPos[2] = ((f32 *)cam)[3];
    targetPos[0] = gCameraTarget[1];
    gCameraOffsetZ -= stepUnits;
    targetPos[1] = gCameraTarget[2] + 200.0f;
    targetPos[2] = gCameraTarget[3];
    mtxIdentity3(matA);
    mtxIdentity3(matB);
    func_8002DB6C(matA, matB, yaw);
    func_8002DAE0(matB, matA, -pitch);
    k = dist * __cosf(pitch);
    k *= sinApprox(yaw);
    camPos[0] = targetPos[0] - k;
    camPos[1] = targetPos[1] - dist * sinApprox(pitch);
    dist *= __cosf(pitch);
    dist *= __cosf(yaw);
    camPos[2] = targetPos[2] - dist;
    hitMask = 0;
    hitBit = 1;
    for (i = 1; i < 5; i++) {
        mtxTransformVec3(&rayEnds[i], matB, &cameraRayDirs[i]);
        rayEnds[i].x += camPos[0];
        rayEnds[i].y += camPos[1];
        rayEnds[i].z += camPos[2];
        if (i == 1) {
            initBoundsToSegment(boundsMin, boundsMax, &rayEnds[1], targetPos);
        } else {
            expandBoundsToSegment(boundsMin, boundsMax, &rayEnds[i], targetPos);
        }
    }
    collectCollisionCells(boundsMin, boundsMax, 3);
    for (i = 1; i < 5; i++) {
        if (raycastCollision(targetPos, &rayEnds[i], 0) != 0) {
            hitMask |= hitBit;
        }
        hitBit <<= 1;
    }
    if (hitMask != 0) {
        offZ = 0;
        offX = 0;
        if ((hitMask & 6) == 6) {
            offZ = -0x200;
        }
        if ((hitMask & 9) == 9) {
            offZ += 0x200;
        }
        if ((hitMask & 3) == 3) {
            offX = 0x200;
        }
        if ((hitMask & 0xC) == 0xC) {
            offX -= 0x200;
        }
        if ((hitMask & 0xD) == 0xD) {
            offX -= 0x200;
        }
        if ((hitMask & 7) == 7) {
            offX -= 0x200;
        }
        if ((hitMask & 0xE) == 0xE) {
            offX -= 0x200;
        }
        if ((hitMask & 0xB) == 0xB) {
            offX -= 0x200;
        }
        if ((hitMask & 0xF) == 0xF) {
            offX -= 0x200;
        }
        gCameraOffsetX += offX;
        gCameraOffsetZ += offZ;
    }
}
