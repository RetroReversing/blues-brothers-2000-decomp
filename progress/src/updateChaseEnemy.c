typedef struct {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[4];
    f32 unkC;
    u8 pad10[2];
    u16 unk12;
} Unk800BD06C_579E0;

typedef struct Unk800579E0 {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[4];
    f32 unkC;
    s32 unk10;
    u8 pad14[0x64 - 0x14];
    s32 unk64;
    u8 pad68[0x6C - 0x68];
    s32 unk6C;
    u8 pad70[0x7C - 0x70];
    s32 unk7C;
    u8 pad80[0x90 - 0x80];
    s32 unk90;
    u8 pad94[0x9C - 0x94];
    void *unk9C;
    u8 padA0[0xC0 - 0xA0];
    s32 unkC0;
    u8 padC4[0xD0 - 0xC4];
    s32 unkD0;
    u8 padD4[0xD8 - 0xD4];
    s32 (*unkD8)(struct Unk800579E0 *);
    u8 padDC[0x100 - 0xDC];
    f32 unk100;
} Unk800579E0;

extern Unk800BD06C_579E0 *gCameraTarget;

s32 animStepKeys(void *arg0_in);
s32 enemyTakeHit(void *o, s32 arg1);
s16 sins(u16);
s16 coss(u16);
void func_8002ADFC(s32 ch, s32 range, void *src);
void sendCommand(s32, s32);
void func_8002D124(void);
void func_80043328(void *arg0, s32 arg1, s32 arg2);
s32 func_8002492C(f32, f32);
void actorSetAnim(void *arg0, s32 arg1, s32 arg2);
f32 getCameraTargetDist(void *o, f32 r, s32 *ang);
s16 *func_800851D8(void *arg0);
s32 enemyAlert(void *arg0);
s32 randomRange(s32 arg0, s32 arg1);
s32 enemyIdle(Unk800579E0 *);
s32 func_800571B0(Unk800579E0 *);
s32 enemyTurnAway(Unk800579E0 *);
s32 enemyLeashWander(Unk800579E0 *);
s32 enemyChase(Unk800579E0 *);

/* Per-frame AI for a chasing enemy: handles hit reactions, the idle/chase/turn/alert states and the attack trigger. */
void updateChaseEnemy(Unk800579E0 *enemy) {
    s32 animDone;
    s32 hitResult;
    s32 flags;
    s32 angle;
    f32 dist;

    if (enemy->unk6C == 0) {
        enemy->unk6C = 1;
        enemy->unkD8 = enemyIdle;
    }
    animDone = animStepKeys(enemy);
    flags = enemy->unkC0;
    hitResult = enemyTakeHit(enemy, enemy->unk7C);
    switch (hitResult) {
    case 1:
        enemy->unk4 += (f32)((sins(gCameraTarget->unk12) * 5) >> 14);
        enemy->unkC += (f32)((coss(gCameraTarget->unk12) * 5) >> 14);
        enemy->unk7C = hitResult;
        if (flags & 0x40) {
            func_8002ADFC(0xAE, 6000, enemy);
        } else {
            sendCommand(12, 0x80);
            sendCommand(8, 0x2E);
            func_8002D124();
        }
        func_80043328(enemy, 0xC4, 0x100);
        animDone = 0;
        break;
    case 2:
        enemy->unk10 = func_8002492C(gCameraTarget->unk4 - enemy->unk4, gCameraTarget->unkC - enemy->unkC);
        enemy->unk9C = func_800571B0;
        actorSetAnim(enemy, 0xC3, 0x100);
        return;
    }
    if (enemy->unk7C != 0) {
        if (animDone != 0) {
            enemy->unk7C = 0;
        }
        return;
    }
    dist = getCameraTargetDist(enemy, 2000.0f, &angle);
    enemy->unk100 = dist;
    enemy->unk90 = angle;
    if (dist < func_800851D8(enemy)[1]) {
        sendCommand(12, 0x80);
        sendCommand(8, 0x4C);
        if (enemyAlert(enemy) == 0) {
            return;
        }
    }
    animDone = 0;
    if (enemy->unkD8 != NULL) {
        animDone = enemy->unkD8(enemy);
    }
    if (animDone == 0) {
        return;
    }
    switch (enemy->unkD0) {
    case 0xC1:
        if (animDone == 1) {
            enemy->unkD8 = enemyTurnAway;
            enemy->unk64 = randomRange(180, 400);
        } else {
            enemy->unkD8 = enemyLeashWander;
        }
        break;
    case 0xC5:
        enemy->unkD8 = enemyTurnAway;
        enemy->unk64 = randomRange(180, 400);
        break;
    case 0xC0:
        if (animDone == 1) {
            enemy->unkD8 = enemyChase;
            enemy->unk64 = randomRange(100, 200);
        } else {
            enemy->unkD8 = enemyLeashWander;
        }
        break;
    }
}
