typedef struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 f10;
    /* 0x14 */ u8 pad14[0x50];
    /* 0x64 */ s32 f64;
    /* 0x68 */ u8 pad68[0x24];
    /* 0x8C */ s32 f8C;
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[0x3C];
    /* 0xD0 */ s32 fD0;
    /* 0xD4 */ u8 padD4[8];
    /* 0xDC */ f32 fDC;
} Obj;
void sendCommand(s32, s32);
void func_8002ADFC(s32, s32, Obj *);
s32 tickActorTimer(Obj *);
f32 func_8002DD60(f32);
s32 isTargetVulnerable(Obj *, s32, s32, s32);
s32 animStepKeys(Obj *);
void func_80043328(Obj *, s32, s32);
void func_8005F470(Obj *);
s32 updateDistanceCull(void);
extern f32 D_80008840;
extern f32 D_8000885C;
extern f32 D_80008860;
extern f64 D_80008880;
extern f64 D_80008888;
extern f32 D_80008890;
extern f64 D_80008898;
extern f64 D_800088A0;
extern f32 D_800088A8;
extern f32 D_800088AC;
extern f32 D_800088B0;
extern s32 D_800B4CF0[];
extern char gCameraTarget[];
extern s32 D_80140200[];

/* Enemy AI: idles until the player is close, then chases, swipes at the player, and backs off. */ void updateChaserEnemy(Obj *enemy) {
    f32 dxToPlayer;
    f32 dyToPlayer;
    f32 heightRange;
    s32 animDone;

    if (updateDistanceCull() != 0) {
        return;
    }
    dxToPlayer = (*(Obj **)gCameraTarget)->x - enemy->x;
    dyToPlayer = ((*(Obj **)gCameraTarget)->y + D_80008840) - enemy->y;
    animDone = animStepKeys(enemy);
    switch (enemy->f90) {
    case 0:
        enemy->f10 = 0x8000;
        enemy->f90 = 1;
        enemy->f8C = 0;
        break;
    case 1:
        if (enemy->f8C != 0) {
            break;
        }
        func_80043328(enemy, 0x74, 0x100);
        if (animDone != 0) {
            func_8002ADFC(0x4A, 0x3E8, enemy);
        }
        if (tickActorTimer(enemy) == 0) {
            break;
        }
        if (func_8002DD60(dyToPlayer) < 400.0f && isTargetVulnerable(enemy, 1, 0, 0) != 0) {
            if (func_8002DD60(dxToPlayer) < 400.0f) {
                enemy->f90 = 2;
                enemy->f8C = 0;
            }
            if (func_8002DD60(dxToPlayer) < D_80008860 && D_80140200[0] > D_800B4CF0[0]) {
                enemy->f90 = 2;
                enemy->f8C = 0;
            }
        }
        break;
    case 2:
        switch (enemy->f8C) {
        case 0:
            if ((*(Obj **)gCameraTarget)->fD0 == 0x16) {
                break;
            }
            if (dxToPlayer >= 0.0f) {
                func_80043328(enemy, 0x75, 0x100);
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x16);
                enemy->f8C = 1;
            } else {
                func_80043328(enemy, 0x76, 0x100);
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x16);
                enemy->f8C = 2;
            }
            break;
        case 1:
            if (D_80008880 <= enemy->fDC && enemy->fDC <= D_80008888 && func_8002DD60(dxToPlayer) < D_80008890) {
                enemy->f8C = 3;
                break;
            }
            if (animDone != 0) {
                func_80043328(enemy, 0x74, 0x100);
                enemy->f90 = 1;
                enemy->f8C = 0;
                enemy->f64 = 0x23;
            }
            break;
        case 2:
            if (D_80008898 <= enemy->fDC && enemy->fDC <= D_800088A0 && func_8002DD60(dxToPlayer) < D_800088A8) {
                enemy->f8C = 3;
                break;
            }
            if (animDone != 0) {
                func_80043328(enemy, 0x74, 0x100);
                enemy->f90 = 1;
                enemy->f8C = 0;
                enemy->f64 = 0x23;
            }
            break;
        case 3:
            enemy->f64 = 0x23;
            heightRange = D_800088AC;
            if (func_8002DD60(enemy->y - (*(Obj **)gCameraTarget)->y + heightRange) < heightRange || D_800088B0 < func_8002DD60(dxToPlayer)) {
                enemy->f90 = 1;
                enemy->f8C = 0;
                break;
            }
            func_8005F470(*(Obj **)gCameraTarget);
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x2D);
            enemy->f8C = 4;
            break;
        case 4:
            if (animDone != 0) {
                func_80043328(enemy, 0x74, 0x100);
                enemy->f90 = 1;
                enemy->f8C = 0;
            }
            break;
        }
        break;
    case 3:
        break;
    case 4:
        break;
    }
}
