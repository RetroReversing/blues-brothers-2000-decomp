typedef struct Obj142A0 {
    s32 flags;
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x74 - 0x14];
    s32 unk74;
    u8 pad78[0x8C - 0x78];
    s32 unk8C;
    s32 unk90;
    u8 pad94[0xA0 - 0x94];
    void (*update)(struct Obj142A0 *);
    u8 padA4[0xB8 - 0xA4];
    s32 unkB8;
    u8 padBC[0xC0 - 0xBC];
    s32 unkC0;
    u8 padC4[0xE4 - 0xC4];
    s32 unkE4;
    u8 padE8[0x108 - 0xE8];
} Obj142A0;

f32 getCameraTargetDist(Obj142A0 *, f32, s32 *);
void func_8002DA80(Obj142A0 *);
void func_80017CF0(Obj142A0 *);
s32 func_80023E3C(s32);
void collectCollisionCells(f32 *, f32 *, s32);
s32 func_80048CD8(f32, f32, f32, f32, f32, f32, s32);
s32 func_8000F7A0(Obj142A0 *);
Obj142A0 *getObjPoolStart(s32);
Obj142A0 *getObjPoolEnd(s32);
void func_800851D8(Obj142A0 *);
f32 func_8002DD60(f32);
extern s32 D_800B4CE4;
extern s32 gFrameScale;
extern s32 gCamSpeedScale;
extern Obj142A0 *gCameraTarget;

/* Per-frame update for a projectile: spins it, expires after 1500 frames or when it nears the camera target, and ends it on a collision hit or on a nearby flagged object. */ void updateProjectile(Obj142A0 *proj) {
    f32 boxMin[3];
    f32 boxMax[3];
    s32 targetInfo;
    s32 targetDist;
    Obj142A0 *other;
    Obj142A0 *poolEnd;
    Obj142A0 *poolStart;
    f32 dx;
    f32 dy;
    f32 dz;

    targetDist = getCameraTargetDist(proj, 8000.0f, &targetInfo);
    proj->unk10 += gCamSpeedScale << 10;
    func_8002DA80(proj);
    if (proj->unk90 != 0) {
        func_80017CF0(proj);
    }
    proj->unk90 ^= 1;
    proj->unk8C += gFrameScale;
    if (proj->unk8C >= 1501 || (targetDist < 200 && proj->unk74 != 0)) {
        gCameraTarget->unkB8 = 1;
        gCameraTarget->unkE4 = func_80023E3C(1);
        D_800B4CE4 = 0;
        proj->update(proj);
        return;
    }
    boxMin[0] = -50.0f;
    boxMin[1] = -75.0f;
    boxMin[2] = -50.0f;
    boxMax[0] = 50.0f;
    boxMax[1] = 75.0f;
    boxMax[2] = 50.0f;
    boxMin[0] = proj->x + -50.0f;
    boxMax[0] = proj->x + 50.0f;
    boxMin[1] = proj->y + -75.0f;
    boxMax[1] = proj->y + 75.0f;
    boxMin[2] = proj->z + -50.0f;
    boxMax[2] = proj->z + 50.0f;
    collectCollisionCells(boxMin, boxMax, 0);
    if (func_80048CD8(boxMin[0], boxMax[0], boxMin[1], boxMax[1], boxMin[2], boxMax[2], 0) != 0) {
        goto hit;
    found:
        other->unkC0 |= 0x5E;
    hit:
        proj->update(proj);
        D_800B4CE4 = 0;
        gCameraTarget->unkB8 = 1;
        gCameraTarget->unkE4 = func_80023E3C(1);
        return;
    }
    if (func_8000F7A0(proj) != 0) {
        proj->update(proj);
        D_800B4CE4 = 0;
        gCameraTarget->unkB8 = 1;
        gCameraTarget->unkE4 = func_80023E3C(1);
    }
    poolStart = getObjPoolStart(0);
    poolEnd = getObjPoolEnd(0);
    for (other = poolStart; other <= poolEnd; other++) {
        if (other == proj) {
            continue;
        }
        if (!(other->flags & 0x1000)) {
            continue;
        }
        func_800851D8(proj);
        dx = proj->x - other->x;
        dy = proj->y - other->y;
        dz = proj->z - other->z;
        if (200.0f < func_8002DD60(dx)) {
            continue;
        }
        if (300.0f < func_8002DD60(dy)) {
            continue;
        }
        if (200.0f < func_8002DD60(dz)) {
            continue;
        }
        goto found;
    }
}
