typedef struct {
    s32 x, y, z;
} Vec3i_50144;

typedef struct {
    f32 x, y, z;
} Vec3f_50144;

typedef struct {
    u8 pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    u8 pad14[0x6C - 0x14];
    s32 unk6C;
    u8 pad70[0x74 - 0x70];
    s32 unk74;
    u8 pad78[0x80 - 0x78];
    s32 unk80;
    s32 unk84;
    s32 unk88;
} Unk80050144;

extern s32 gSplinePointCount[];
extern Vec3i_50144 *gSplineSrcPoints[];
extern s32 gCamSpeedScale;
extern char splineNoPointsMsg[];

void debugPrintf(void *, ...);
s32 vec3Sub(void *arg0, void *arg1, void *arg2);
s32 func_8002E1CC(void *arg0, void *arg1, f32 arg2);
s32 func_8002E234(void *arg0, void *arg1, void *arg2);
s32 func_8002492C(f32, f32);
s32 approachAngle(s32 arg0, s32 arg1, s32 arg2);

/* Moves a follower along one spline path: advances the segment and progress, reverses at the ends if the path loops back, and sets the follower's position and heading. Returns 1 when it reaches the end. */
s32 stepSplinePath(Unk80050144 *follower, s32 pathIndex) {
    s32 *count;
    Vec3i_50144 *pathPoints;
    s32 pointIndex;
    s32 nextIndex;
    s32 reachedEnd;
    Vec3f_50144 segStart;
    Vec3f_50144 segEnd;
    Vec3f_50144 segDelta;
    Vec3f_50144 pos;
    f32 segT;
    f32 dx;
    f32 dz;
    s32 angle;
    s32 speed;

    pointIndex = follower->unk88;
    pathPoints = gSplineSrcPoints[pathIndex];
    count = &gSplinePointCount[pathIndex];
    reachedEnd = 0;
    if (*count == 0) {
        debugPrintf(splineNoPointsMsg, pathIndex);
    }
    nextIndex = pointIndex + 1;
    if (nextIndex >= *count - 1) {
        nextIndex = 0;
    }
    segStart.x = pathPoints[pointIndex].x;
    segStart.y = pathPoints[pointIndex].y;
    segStart.z = pathPoints[pointIndex].z;
    segEnd.x = pathPoints[nextIndex].x;
    segEnd.y = pathPoints[nextIndex].y;
    segEnd.z = pathPoints[nextIndex].z;
    segT = (f32)follower->unk84 * 0.00390625f;
    dx = segEnd.x - segStart.x;
    dz = segEnd.z - segStart.z;
    vec3Sub(&segDelta, &segEnd, &segStart);
    func_8002E1CC(&pos, &segDelta, segT);
    func_8002E234(&pos, &pos, &segStart);
    if (follower->unk84 >= 0x100) {
        if (follower->unk88 + 1 < *count - 2) {
            follower->unk84 -= 0x100;
            follower->unk88++;
        } else {
            reachedEnd = 1;
            follower->unk84 = 0xFF;
            if (follower->unk74 != 0) {
                follower->unk80 = -follower->unk80;
                return reachedEnd;
            }
        }
    }
    if (follower->unk84 < 0) {
        if (follower->unk88 - 1 >= 0) {
            follower->unk84 += 0x100;
            follower->unk88--;
        } else {
            reachedEnd++;
            follower->unk84 = 1;
            if (follower->unk74 != 0) {
                follower->unk80 = -follower->unk80;
                return 1;
            }
        }
    }
    if (reachedEnd == 0) {
        speed = gCamSpeedScale * 2;
        follower->unk84 += follower->unk80 * speed;
    }
    follower->unk4 = pos.x;
    follower->unk8 = pos.y;
    follower->unkC = pos.z;
    angle = func_8002492C(dx, dz);
    if (follower->unk6C == 0xB94598) {
        follower->unk10 = approachAngle(angle + (angle - follower->unk10) * 2, follower->unk10, gCamSpeedScale << 5);
    }
    if (follower->unk6C == 0xB8FD2A) {
        follower->unk10 = approachAngle(angle, follower->unk10, gCamSpeedScale << 9);
    } else {
        follower->unk10 = approachAngle(angle, follower->unk10, gCamSpeedScale << 6);
    }
    return reachedEnd;
}
