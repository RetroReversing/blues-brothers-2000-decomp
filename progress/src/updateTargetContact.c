typedef struct {
    s32 x, y, z;
} Vec3i_552C4;

typedef struct {
    u8 pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 pad10[2];
    u16 unk12;
} Player_552C4;

typedef struct {
    u8 pad0[8];
    f32 unk8;
    u8 padC[0x5C - 0xC];
    s32 unk5C;
    u8 pad60[0x74 - 0x60];
    s32 unk74;
    s32 unk78;
    u8 pad7C[0xB8 - 0x7C];
    s32 unkB8;
    u8 padBC[4];
    s32 unkC0;
} Unk800552C4;

extern Vec3i_552C4 gPlatformMaxOffsets[];
extern Vec3i_552C4 gPlatformMinOffsets[];
extern Player_552C4 *gCameraTarget;

f32 getCameraTargetDist(void *o, f32 r, s32 *ang);
f32 func_8002DD60(f32 arg0);
s32 func_800137F8(void *);
s16 sins(u16);
s16 coss(u16);
void *func_80012474(s32 arg0, s32 arg1, s32 arg2);
void func_80058F74(void *arg0, s32 (*arg1)());
s32 func_80013654(void *o);
s32 func_80013784(void *arg0);
s32 func_80055130();
s32 func_80054EC4();

/* Checks the camera target against this actor and reacts to a nearby hit or a stand: returns 0 when out of range, 2 when the target is standing on the actor, otherwise 1. */
s32 updateTargetContact(Unk800552C4 *actor) {
    f32 radius;
    f32 boundLo;
    f32 boundHi;
    f32 x;
    f32 y;
    f32 z;

    radius = 350.0f;
    boundLo = actor->unk8 + gPlatformMaxOffsets[actor->unkB8].y;
    boundHi = actor->unk8 + gPlatformMinOffsets[actor->unkB8].y;
    actor->unkC0 = 0;
    if (getCameraTargetDist(actor, radius, NULL) == radius) {
        return 0;
    }
    if (func_8002DD60(actor->unk8 - gCameraTarget->unk8) < radius && func_800137F8(gCameraTarget) != 0) {
        actor->unkC0 |= 2;
        x = gCameraTarget->unk4 + ((sins(gCameraTarget->unk12) * 45) >> 13);
        y = gCameraTarget->unk8 + 160.0f;
        z = gCameraTarget->unkC + ((coss(gCameraTarget->unk12) * 45) >> 13);
        func_80012474(x, y, z);
        actor->unk5C = 0xFF;
        actor->unk74 += 20;
        actor->unk78 -= 20;
        func_80058F74(actor, func_80055130);
    }
    if (func_80013654(gCameraTarget) != 0) {
        actor->unkC0 |= 2;
        x = gCameraTarget->unk4 + ((sins(gCameraTarget->unk12) * 45) >> 13);
        y = gCameraTarget->unk8 + 160.0f;
        z = gCameraTarget->unkC + ((coss(gCameraTarget->unk12) * 45) >> 13);
        func_80012474(x, y, z);
        actor->unk5C = 0xFF;
        actor->unk74 += 100;
        actor->unk78 -= 100;
        func_80058F74(actor, func_80054EC4);
        return 1;
    }
    if (func_80013784(gCameraTarget) != 0) {
        if (gCameraTarget->unk8 <= boundLo && boundHi <= gCameraTarget->unk8) {
            actor->unkC0 |= 4;
        }
        return 2;
    }
    return 1;
}
