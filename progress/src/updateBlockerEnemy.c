typedef struct Obj {
    char pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    char pad14[0x4C - 0x14];
    f32 x4C;
    f32 x50;
    f32 x54;
    char pad58[0x84 - 0x58];
    s32 x84;
    char pad88[0x9C - 0x88];
    void (*fn9C)(void);
    char padA0[0xD8 - 0xA0];
    void (*fnD8)(void);
} Obj;

struct Obj *findActor(s32, struct Obj *);
s32 randomRange(s32, s32);
s32 func_8002492C(f32, f32);
void func_8002ADFC(s32, s32, void *);
s32 approachAngle(s32, s32, s32);
s32 func_8002D260(s32);
void func_8002D3E4(void *, s32);
f32 getCameraTargetDist(void *, f32, s32 *);
f32 func_8002DD60(f32);
void func_80043328(void *, s32, s32);
void actorSetAnim(void *, s32, s32);
s32 func_8005FD88(void *, void *);
void func_8005FE24(void);
f32 sqrtf(f32);

extern f32 gBumpRadius;
extern u8 gFrameScale[];
extern u8 gCameraTarget[];
#define BD (*(Obj **)gCameraTarget)

/* Per-frame update for a blocker enemy: it shoves the player's camera target away when too close, turns to face it within range, and reverses direction when it bumps another blocker. */ void updateBlockerEnemy(Obj *enemy) {
    s32 angleToTarget;
    s32 distToTarget;
    s32 pushAmount;
    s32 dx;
    s32 dz;
    s32 timer;
    Obj *target;
    Obj *other;
    f32 x;
    f32 bumpRadius;
    f32 ex;
    f32 ez;

    distToTarget = getCameraTargetDist(enemy, 400.0f, &angleToTarget);
    if (distToTarget < 200) {
        target = BD;
        x = enemy->x4;
        pushAmount = 200 - distToTarget;
        dx = x - target->x4;
        dz = enemy->xC - target->xC;
        enemy->x4 = x + dx * (pushAmount / 4) / distToTarget;
        enemy->xC += dz * (pushAmount / 4) / distToTarget;
        target->x4 -= dx * (pushAmount * 3 / 4) / distToTarget;
        target->xC -= dz * (pushAmount * 3 / 4) / distToTarget;
        if (abs(func_8002D260(angleToTarget - enemy->x10)) < 0x1000) {
            if (func_8005FD88(BD, enemy) != 0) {
                func_8002ADFC(0x25, 500, enemy);
                actorSetAnim(enemy, 0x56, 0x100);
                enemy->x10 = angleToTarget;
            }
        }
    } else if (distToTarget < 400) {
        enemy->x10 = approachAngle(angleToTarget, enemy->x10, 0x100);
        func_8002D3E4(enemy, 150);
    }
    timer = enemy->x84 - *(s32 *)gFrameScale;
    enemy->x84 = timer;
    if (timer <= 0) {
        enemy->x84 = randomRange(150, 350);
        other = findActor(0x1018, NULL);
        if (other != NULL) {
            bumpRadius = gBumpRadius;
            do {
                if (other != enemy) {
                    ex = enemy->x4 - other->x4;
                    ez = enemy->xC - other->xC;
                    if (sqrtf(ex * ex + ez * ez) < bumpRadius) {
                        func_80043328(enemy, 0x58, 0x100);
                        enemy->fnD8 = enemy->fn9C;
                        enemy->fn9C = func_8005FE24;
                        enemy->x4C = -func_8002DD60(enemy->x4C);
                        enemy->x54 = -func_8002DD60(enemy->x54);
                        enemy->x10 = func_8002492C(enemy->x4C, enemy->x54);
                        func_8002D3E4(enemy, 150);
                        enemy->x10 += 0x8000;
                        return;
                    }
                }
                other = findActor(0x1018, other);
            } while (other != NULL);
        }
    }
}
