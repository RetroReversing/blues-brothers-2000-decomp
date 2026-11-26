typedef struct { f32 x, y, z; } Vec3;
typedef struct { s32 x, y, z; } Vec3i;
typedef struct Obj72DA4 {
    s32 kind;
    f32 x, y, z;
    s32 angle;
    u8 pad14[0x40 - 0x14];
    f32 unk40;
    u8 pad44[0x64 - 0x44];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    u8 pad74[0x78 - 0x74];
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    u8 pad84[0x8C - 0x84];
    s32 unk8C;
    u8 pad90[0xA0 - 0x90];
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

f32 approachF32(f32, f32, f32);
void debugPrintf(char *);
extern char D_800091FC[];
extern Obj72DA4 *D_800B3964;
extern s32 gCamSpeedScale;

/* Moves a truck platform between its raised and lowered positions, driven by the state in
   unk8C, and carries the player along when the player stands on it (kind 3). */
void updateTruckPlatform(Obj72DA4 *truck) {
    f32 rotMtx[10];
    f32 identityMtx[10];
    Vec3 boxMin;
    Vec3 boxMax;
    Vec3 tmpPos;
    f32 angle;
    f32 delta;
    f32 newX;
    s32 i;
    s32 flag;
    Vec3i *minBox;
    Vec3i *maxBox;

    flag = 0;
    if (truck->unk7C == 0) {
        truck->unk7C = 1;
        truck->unk8C = 0;
        truck->x = truck->unk40 + 12500.0f;
    }
    switch (truck->unk8C) {
    case 0:
        truck->kind = 0x144;
        if (D_800B3964->unk8C != 0) {
            truck->unk8C++;
        }
        break;
    case 1:
        flag = 1;
        truck->kind = 0x102;
        newX = approachF32(truck->unk40, truck->x, gCamSpeedScale * 12);
        truck->x = newX;
        if (newX == truck->unk40) {
            truck->unk8C++;
        }
        break;
    case 2:
        if (D_800B3964->unk8C == 0) {
            truck->unk8C++;
        }
        break;
    case 3:
        newX = approachF32(truck->unk40 - 12500.0f, truck->x, gCamSpeedScale * 15);
        flag = 1;
        truck->x = newX;
        if (newX == truck->unk40 - 12500.0f) {
            truck->unk8C++;
        }
        break;
    case 4:
        truck->unk7C = 0;
        break;
    default:
        debugPrintf(D_800091FC);
        break;
    }
    if (flag != 0) {
        mtxIdentity3(identityMtx);
        angle = truck->angle;
        angle *= 6.283185307179586;
        angle *= (1.0 / 65536.0);
        func_8002DB6C(rotMtx, identityMtx, angle);
        i = truck->unkB8;
        minBox = &gPlatformMinOffsets[i];
        boxMin.x = minBox->x;
        boxMin.y = minBox->y;
        boxMin.z = minBox->z;
        maxBox = &gPlatformMaxOffsets[i];
        boxMax.x = maxBox->x;
        boxMax.y = maxBox->y;
        boxMax.z = maxBox->z;
        mtxTransformVec3(&tmpPos, rotMtx, &boxMin, i);
        boxMin.x = tmpPos.x;
        boxMin.y = tmpPos.y;
        boxMin.z = tmpPos.z;
        mtxTransformVec3(&tmpPos, rotMtx, &boxMax);
        boxMax.x = tmpPos.x;
        boxMax.y = tmpPos.y;
        boxMax.z = tmpPos.z;
        if (boxMax.x < boxMin.x) {
            func_8002DAC8(&boxMax.x, &boxMin.x);
        }
        if (boxMax.y < boxMin.y) {
            func_8002DAC8(&boxMax.y, &boxMin.y);
        }
        if (boxMax.z < boxMin.z) {
            func_8002DAC8(&boxMax.z, &boxMin.z);
        }
        delta = gCameraTarget->x - truck->x;
        flag = 0;
        if (delta > 0.0f) {
            if (boxMax.x < delta) {
                flag = 1;
            }
        }
        if (delta <= 0.0f) {
            if (delta < boxMin.x) {
                flag++;
            }
        }
        delta = gCameraTarget->z - truck->z;
        if (delta > 0.0f) {
            if (boxMax.z < delta) {
                flag++;
            }
        }
        if (delta <= 0.0f) {
            if (delta < boxMin.z) {
                flag++;
            }
        }
        if (flag == 0 && gCameraTarget->y <= truck->y + (f32)gPlatformMinOffsets[truck->unkB8].y && gCameraTarget->kind == 3) {
            func_8003B980(gCameraTarget);
        }
    }
}
