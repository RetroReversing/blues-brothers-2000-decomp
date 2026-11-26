typedef struct { f32 x, y, z; } Vec3;
typedef struct { s32 x, y, z; } Vec3i;
typedef struct Obj72DA4 {
    s32 kind;
    f32 x, y, z;
    s32 angle;
    u8 pad14[0x64 - 0x14];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    u8 pad74[0x78 - 0x74];
    s32 unk78;
    u8 pad7C[0x80 - 0x7C];
    s32 unk80;
    u8 pad84[0xA0 - 0x84];
    void (*update)(struct Obj72DA4 *);
    struct Obj72DA4 *parent;
    u8 padA8[0xB8 - 0xA8];
    s32 unkB8;
} Obj72DA4;

s32 randomRange(s32, s32);
void func_8002ADFC(s32, s32, Obj72DA4 *);
s32 tickActorTimer(Obj72DA4 *);
void func_8002DAC8(f32 *, f32 *);
void func_8002DB6C(void *, void *, f32);
void mtxIdentity3(void *);
void mtxTransformVec3(void *, void *, void *, ...);
Obj72DA4 *func_8003B980(Obj72DA4 *);
s32 func_80050144(Obj72DA4 *, s32);
extern s32 D_800B8398[];
extern Obj72DA4 *gCameraTarget;
extern Vec3i gPlatformMaxOffsets[];
extern Vec3i gPlatformMinOffsets[];

/* Per-frame update for a moving platform: rotates its bounds by its angle, and if the camera target is standing on it, carries the target along. */ void updateMovingPlatform(Obj72DA4 *platform) {
    f32 rotMtx[10];
    f32 baseMtx[10];
    Vec3 boundMin;
    Vec3 boundMax;
    Vec3 tmpVec;
    f32 rad;
    f32 delta;
    s32 outside;
    s32 offIdx;
    Vec3i *minOff;
    Vec3i *maxOff;

    if (tickActorTimer(platform) != 0) {
        platform->unk64 = randomRange(100, 500);
        func_8002ADFC(D_800B8398[platform->unk78], 3000, platform);
    }
    if (func_80050144(platform, platform->unk70) != 0) {
        if (platform->parent != NULL) {
            platform->parent->unk80--;
        }
        platform->update(platform);
    }
    mtxIdentity3(baseMtx);
    rad = platform->angle;
    rad *= 6.283185307179586;
    rad *= (1.0 / 65536.0);
    func_8002DB6C(rotMtx, baseMtx, rad);
    offIdx = platform->unkB8;
    minOff = &gPlatformMinOffsets[offIdx];
    boundMin.x = minOff->x;
    boundMin.y = minOff->y;
    boundMin.z = minOff->z;
    maxOff = &gPlatformMaxOffsets[offIdx];
    boundMax.x = maxOff->x;
    boundMax.y = maxOff->y;
    boundMax.z = maxOff->z;
    mtxTransformVec3(&tmpVec, rotMtx, &boundMin, offIdx);
    boundMin.x = tmpVec.x;
    boundMin.y = tmpVec.y;
    boundMin.z = tmpVec.z;
    mtxTransformVec3(&tmpVec, rotMtx, &boundMax);
    boundMax.x = tmpVec.x;
    boundMax.y = tmpVec.y;
    boundMax.z = tmpVec.z;
    if (boundMax.x < boundMin.x) {
        func_8002DAC8(&boundMax.x, &boundMin.x);
    }
    if (boundMax.y < boundMin.y) {
        func_8002DAC8(&boundMax.y, &boundMin.y);
    }
    if (boundMax.z < boundMin.z) {
        func_8002DAC8(&boundMax.z, &boundMin.z);
    }
    delta = gCameraTarget->x - platform->x;
    outside = 0;
    if (delta > 0.0f) {
        if (boundMax.x < delta) {
            outside = 1;
        }
    }
    if (delta <= 0.0f) {
        if (delta < boundMin.x) {
            outside++;
        }
    }
    delta = gCameraTarget->z - platform->z;
    if (delta > 0.0f) {
        if (boundMax.z < delta) {
            outside++;
        }
    }
    if (delta <= 0.0f) {
        if (delta < boundMin.z) {
            outside++;
        }
    }
    if (outside == 0 && gCameraTarget->y <= platform->y + (f32)gPlatformMinOffsets[platform->unkB8].y && gCameraTarget->kind == 3) {
        func_8003B980(gCameraTarget);
    }
}
