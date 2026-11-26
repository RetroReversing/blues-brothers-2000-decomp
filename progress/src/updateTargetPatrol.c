typedef struct {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[4];
    f32 unkC;
    u8 pad10[2];
    u16 unk12;
} Unk800BD06C_579E0;

typedef struct Unk80057CCC {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[4];
    f32 unkC;
    s32 unk10;
    u8 pad14[0x40 - 0x14];
    f32 unk40;
    u8 pad44[4];
    f32 unk48;
    u8 pad4C[0x64 - 0x4C];
    s32 unk64;
    u8 pad68[0x6C - 0x68];
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    u8 pad78[0x7C - 0x78];
    s32 unk7C;
    s32 unk80;
    u8 pad84[0x90 - 0x84];
    s32 unk90;
    u8 pad94[0x9C - 0x94];
    void *unk9C;
    u8 padA0[0xC0 - 0xA0];
    s32 unkC0;
    u8 padC4[0xD0 - 0xC4];
    s32 unkD0;
    u8 padD4[0xD8 - 0xD4];
    s32 (*unkD8)(struct Unk80057CCC *);
    u8 padDC[0x100 - 0xDC];
    f32 unk100;
} Unk80057CCC;

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
s32 enemyIdle(Unk80057CCC *);
s32 func_800571B0(Unk80057CCC *);
s32 enemyTurnAway(Unk80057CCC *);
s32 enemyLeashWander(Unk80057CCC *);
s32 enemyChase(Unk80057CCC *);

void func_8002D3E4(void *arg0, s32 arg1);
void func_8002DA80(void *arg0);
s32 tickActorTimer(void *arg0);
s32 func_8002444C(void);

/* Target-patrol behaviour: sweeps along one axis between two limits, flipping
   heading at each end. When close enough to the camera target it signals contact
   once, then hands over to the chase/attack animation state. */
void updateTargetPatrol(Unk80057CCC *arg0) {
    s32 animDone;
    s32 stepResult;
    s32 flagBits;
    s32 angle;
    f32 targetDist;
    f32 *axisPos;
    f32 *axisLimit;
    s32 baseAngle;

    if (arg0->unk7C == 0) {
        arg0->unk7C = 1;
        switch (arg0->unk70) {
        case 1:
            arg0->unk10 = 0x4000;
            break;
        case 2:
            arg0->unk10 = 0;
            break;
        }
    }
    animDone = animStepKeys(arg0);
    targetDist = getCameraTargetDist(arg0, 2000.0f, &angle);
    flagBits = arg0->unkC0;
    arg0->unk100 = targetDist;
    arg0->unk90 = angle;
    stepResult = enemyTakeHit(arg0, arg0->unk74);
    switch (stepResult) {
    case 1:
        arg0->unk74 = stepResult;
        if (flagBits & 0x40) {
            func_8002ADFC(0xAE, 6000, arg0);
        } else {
            sendCommand(12, 0x80);
            sendCommand(8, 0x2E);
            func_8002D124();
        }
        func_80043328(arg0, 0xC4, 0x100);
        break;
    case 2:
        arg0->unk10 = func_8002492C(gCameraTarget->unk4 - arg0->unk4, gCameraTarget->unkC - arg0->unkC);
        arg0->unk9C = func_800571B0;
        actorSetAnim(arg0, 0xC3, 0x100);
        return;
    }
    if (arg0->unk80 != 0) {
        enemyAlert(arg0);
        return;
    }
    if (arg0->unk74 != 0) {
        if (animDone != 0) {
            arg0->unk74 = 0;
        }
        return;
    }
    if (targetDist < 170.0f) {
        sendCommand(12, 0x80);
        sendCommand(8, 0x4C);
        arg0->unk80 = 1;
        return;
    }
    func_80043328(arg0, 0xC1, 0x100);
    func_8002D3E4(arg0, 100);
    func_8002DA80(arg0);
    switch (arg0->unk70) {
    case 1:
        axisPos = &arg0->unk4;
        axisLimit = &arg0->unk40;
        baseAngle = 0x4000;
        break;
    case 2:
        axisPos = &arg0->unkC;
        axisLimit = &arg0->unk48;
        baseAngle = 0;
        break;
    }
    if (*axisLimit + 300.0f < *axisPos) {
        arg0->unk10 = baseAngle + 0x8000;
    }
    if (*axisPos < *axisLimit + -300.0f) {
        arg0->unk10 = baseAngle;
    }
    if (tickActorTimer(arg0) != 0) {
        if ((func_8002444C() & 1) && arg0->unk80 == 0) {
            func_8002ADFC(0x4C, 3000, arg0);
            arg0->unk80 = 1;
        }
        arg0->unk64 = randomRange(100, 300);
    }
}
