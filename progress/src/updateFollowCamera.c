typedef struct { f32 x, y, z; } Vec3;
typedef struct Obj349E4 {
    s32 kind;
    f32 x, y, z;
    union { s32 v; struct { u16 hi; u16 lo; } h; } r10;
    union { s32 v; struct { u16 hi; u16 lo; } h; } r14;
    u8 pad18[0x40 - 0x18];
    f32 unk40;
    f32 unk44;
    f32 unk48;
    u8 pad4C[0x6C - 0x4C];
    s32 unk6C;
    u8 pad70[0x74 - 0x70];
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
} Obj349E4;

typedef struct {
    s32 x, y, z;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} State349E4;

s16 sins(u16);
s16 coss(u16);
void updateCameraView(Obj349E4 *);
s32 func_80024AC4(s32, s32);
s32 func_80024AE8(s32, s32);
s32 func_8002D1C4(s32, s32, s32);
void clipCameraToTrack(Obj349E4 *);
void initBoundsToSegment(void *, void *, void *, void *);
void collectCollisionCells(void *, void *, s32);
extern Vec3 D_800B4AE4[];
extern s32 D_800B9E88;
extern f32 D_800B9EC4;
extern Obj349E4 *gCameraTarget;
extern State349E4 gCameraSnapshot;
extern s32 D_80140030;

/* Chase camera: eases toward the target, orbits it by yaw/pitch, and clips against the track. */ void updateFollowCamera(Obj349E4 *cam) {
    f32 sp10[4];
    Vec3 delta;
    f32 sp30[12];
    Vec3 camPos;
    Vec3 lookAt;
    u8 sp80[0x90];
    u8 sp110[16];
    u8 sp120[16];

    if (gCameraTarget == NULL) {
        updateCameraView(cam);
        return;
    }
    {
        gCameraSnapshot.x = cam->x;
        gCameraSnapshot.y = cam->y;
        gCameraSnapshot.z = cam->z;
        gCameraSnapshot.unkC = cam->r10.v;
        gCameraSnapshot.unk10 = cam->r14.v;
        gCameraSnapshot.unk14 = cam->unk74;
        D_800B9E88 = 100;
        cam->unk78 += func_80024AC4(cam->unk7C - cam->unk78, 3);
        if (cam->unk78 >= 5001) {
            cam->unk78 = 5000;
        }
        if (cam->unk78 < 1000) {
            cam->unk78 = 1000;
        }
        D_80140030 = func_80024AE8(D_80140030, 1);
        cam->r10.v = func_8002D1C4(cam->unk74, cam->r10.v, 3);
        cam->r14.v = func_8002D1C4(cam->unk80, cam->r14.v, 2);
        delta.x = gCameraTarget->x - cam->unk40;
        delta.y = gCameraTarget->y - cam->unk44;
        delta.z = gCameraTarget->z - cam->unk48;
        delta.x *= D_800B4AE4[cam->unk6C].x * D_800B9EC4;
        delta.y *= D_800B4AE4[cam->unk6C].y * D_800B9EC4;
        delta.z *= D_800B4AE4[cam->unk6C].z * D_800B9EC4;
        cam->unk40 += delta.x;
        cam->unk44 += delta.y;
        cam->unk48 += delta.z;
        cam->x = cam->unk40 + ((((-cam->unk78 * sins(cam->r10.h.lo)) >> 15) * coss(cam->r14.h.lo)) >> 15);
        cam->z = cam->unk48 + ((((-cam->unk78 * coss(cam->r10.h.lo)) >> 15) * coss(cam->r14.h.lo)) >> 15);
        cam->y = cam->unk44 + ((-cam->unk78 * sins(cam->r14.h.lo)) >> 15) + 200.0f;
        cam->x = gCameraTarget->x + ((((-cam->unk78 * sins(cam->r10.h.lo)) >> 15) * coss(cam->r14.h.lo)) >> 15);
        cam->z = gCameraTarget->z + ((((-cam->unk78 * coss(cam->r10.h.lo)) >> 15) * coss(cam->r14.h.lo)) >> 15);
        cam->y = gCameraTarget->y + ((-cam->unk78 * sins(cam->r14.h.lo)) >> 15) + 200.0f;
        camPos.x = cam->x;
        camPos.y = cam->y;
        camPos.z = cam->z;
        lookAt.x = gCameraTarget->x;
        lookAt.y = gCameraTarget->y + 200.0f;
        lookAt.z = gCameraTarget->z;
        initBoundsToSegment(sp110, sp120, &camPos, &lookAt);
        collectCollisionCells(sp110, sp120, 3);
        clipCameraToTrack(cam);
    }
    updateCameraView(cam);
}
