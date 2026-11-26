typedef struct Unk80084504 {
    u8 pad0[0x64];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    u8 pad80[0x8C - 0x80];
    s32 unk8C;
    u8 pad90[0xAC - 0x90];
    f32 unkAC;
    u8 padB0[4];
    f32 unkB4;
    u8 padB8[4];
    s32 unkBC;
    u8 padC0[0xD8 - 0xC0];
    s32 (*unkD8)(struct Unk80084504 *);
    u8 padDC[0x104 - 0xDC];
    f32 unk104;
} Unk80084504;

extern s32 D_800B9B18;
extern char splineErrorMsg[];
extern char splineErrorMsgDefault[];

s32 func_80080DE0(s32 arg0);
void initSpline(s32 idx, s32 closed);
void syncActorPrevPos(void *arg0);
s32 randomRange(s32 arg0, s32 arg1);
s32 updateDistanceCull(void *arg0);
s32 tickActorTimer(void *arg0);
s32 fireActorEvents(void *arg0);
s32 func_80080594(void *arg0, s32 arg1);
s32 func_8002444C(void);
void func_80043328(void *arg0, s32 arg1, s32 arg2);
void debugPrintf(void *, ...);
void func_80083A28(void *);
s32 func_80084368(Unk80084504 *);
s32 func_80083CC4(Unk80084504 *);
s32 updatePursuitVehicle(Unk80084504 *);
s32 func_8006BB14(Unk80084504 *);
s32 func_80083E98(Unk80084504 *);

/* Spline-following state machine for a pursuit vehicle: sets up its spline on first run, then switches between its movement states from the state function's result. */
void updateSplineDriver(Unk80084504 *driver) {
    s32 moveResult;

    moveResult = 1;
    if (driver->unk7C == 0) {
        if (func_80080DE0(driver->unk70) == 0) {
            initSpline(driver->unk70, D_800B9B18);
        }
        driver->unk7C = 1;
        driver->unk78 = 0;
        syncActorPrevPos(driver);
        driver->unkD8 = NULL;
        if (driver->unkAC == 0.0f) {
            driver->unkAC = 0.015f;
        }
        if (driver->unk104 == 0.0f) {
            driver->unk104 = 300.0f;
        }
        driver->unkB4 = 0.0f;
        driver->unkBC = 1;
        driver->unk64 = randomRange(25, 30) * 100;
    }
    if (updateDistanceCull(driver) != 0) {
        return;
    }
    tickActorTimer(driver);
    if (driver->unkD8 != NULL) {
        moveResult = driver->unkD8(driver);
    }
    fireActorEvents(driver);
    if (moveResult != 0) {
        switch (driver->unk78) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 6:
            switch (moveResult) {
            case 1:
                driver->unk78 = 1;
                driver->unkD8 = func_80084368;
                break;
            case 2:
                driver->unk78 = 4;
                driver->unkD8 = func_80083CC4;
                break;
            case 3:
                driver->unk78 = 2;
                driver->unkD8 = updatePursuitVehicle;
                func_80080594(driver, 0);
                break;
            default:
                debugPrintf(splineErrorMsg);
                break;
            }
            break;
        default:
            switch (moveResult) {
            case 1:
                driver->unk78 = 3;
                driver->unkD8 = func_8006BB14;
                break;
            case 2:
                driver->unk78 = 4;
                driver->unkD8 = func_80083CC4;
                driver->unk8C = 0;
                break;
            case 3:
                driver->unk78 = 2;
                driver->unkD8 = updatePursuitVehicle;
                func_80080594(driver, 0);
                break;
            case 4:
                driver->unk64 = randomRange(25, 30) * 100;
                driver->unk78 = 0;
                driver->unkD8 = func_80083E98;
                if (func_8002444C() & 1) {
                    func_80080594(driver, 2);
                } else {
                    func_80080594(driver, 1);
                }
                break;
            default:
                debugPrintf(splineErrorMsgDefault);
                break;
            }
            break;
        }
        func_80043328(driver, driver->unk74 + driver->unk78, 0x100);
        if (driver->unkD8 != NULL) {
            driver->unkD8(driver);
        }
    }
    func_80083A28(driver);
}
