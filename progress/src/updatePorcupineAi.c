typedef struct Obj {
    char pad0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    char pad14[0x44];
    s32 f58;
    char pad5C[8];
    s32 f64;
    char pad68[8];
    s32 f70;
    char pad74[4];
    s32 f78;
    char pad7C[8];
    s32 f84;
    char pad88[4];
    s32 f8C;
    char pad90[0xC];
    void *f9C;
    void (*fA0)(struct Obj *);
    char padA4[0x2C];
    s32 fD0;
    char padD4[4];
    s32 fD8;
    f32 fDC;
} Obj;
s32 cameraGetMode();
s32 spawnPuffEffect();
s32 randomRange();
s32 approachAngle(s32, s32, s32);
s32 tickActorTimer();
f32 func_8002DD60(f32);
s32 func_8003BF98();
s32 isTargetVulnerable();
Obj *func_80042F00();
s32 animStepKeys();
s32 func_80043328();
s32 actorSetAnim();
s32 updateDistanceCull();
s32 enemyTakeHit();
s32 fireActorEvents();
extern f32 D_801700D0;
extern s32 D_801700D4;
extern s32 gCamSpeedScale;
extern Obj *gCameraTarget;
extern s32 func_8007631C;

/* Porcupine enemy AI: hit and death reactions, idle animation cycling, the attack trigger, and a puff effect on one animation window. */
void updatePorcupineAi(Obj *porcupine) {
    f32 pos[4];
    char scratch[0xF8];
    f32 targetDist;
    f32 dy;
    s32 targetAngle;
    s32 id;
    Obj *spawned;
    s32 frame;

    if (updateDistanceCull() != 0) {
        return;
    }
    targetDist = D_801700D0;
    targetAngle = D_801700D4;
    dy = porcupine->y - gCameraTarget->y;
    tickActorTimer(porcupine);
    switch (enemyTakeHit(porcupine, porcupine->f64 > 0)) {
    case 1:
        actorSetAnim(spawned, 0x96, 0x100);
        porcupine->f64 = 0x64;
        break;
    case 2:
        spawned = func_80042F00(0x21, 0, 0, 0);
        actorSetAnim(spawned, 0x95, 0x100);
        spawned->f58 = porcupine->f58;
        spawned->f9C = &func_8007631C;
        spawned->fD8 = 0;
        spawned->x = porcupine->x;
        spawned->y = porcupine->y;
        spawned->z = porcupine->z;
        spawned->f10 = porcupine->f10;
        porcupine->fA0(porcupine);
        return;
    }
    fireActorEvents(porcupine);
    porcupine->f70 = animStepKeys(porcupine);
    if (porcupine->f70 != 0) {
        porcupine->f8C = porcupine->f8C - 1;
    }
    if (porcupine->f8C == 0) {
        porcupine->f84 = 0;
        if (porcupine->fD0 == 0x92) {
            func_80043328(porcupine, 0x93, 0x100);
        } else {
            func_80043328(porcupine, 0x92, 0x100);
        }
        porcupine->f8C = randomRange(1, 4);
    }
    porcupine->f10 = approachAngle(targetAngle, porcupine->f10, gCamSpeedScale << 9);
    if (targetDist < 885.0f) {
        if (func_8002DD60(dy) < 250.0f) {
            if (porcupine->f64 <= 0) {
                if (isTargetVulnerable(porcupine, 0, 1, 1) != 0) {
                    func_80043328(porcupine, 0x94, 0x100);
                    porcupine->f8C = 1;
                    if (350.0f < targetDist) {
                        if (10.0f < porcupine->fDC) {
                            if (porcupine->f84 == 0) {
                                func_8003BF98(porcupine);
                                porcupine->f84 = porcupine->f84 + 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (cameraGetMode() == 0x30) {
        if (porcupine->fD0 == 0x93) {
            frame = (s32) porcupine->fDC;
            if (frame >= 0x29) {
                frame -= 0x14;
            }
            if ((u32) (frame - 0x13) < 4) {
                if (porcupine->f78 == 0) {
                    pos[1] = porcupine->x;
                    pos[2] = porcupine->y;
                    pos[3] = porcupine->z;
                    spawnPuffEffect(pos);
                    porcupine->f78 = 1;
                }
            } else {
                porcupine->f78 = 0;
            }
        }
    }
}
