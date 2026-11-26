typedef struct Unk80061800 {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x64 - 0x14];
    s32 unk64;
    u8 pad68[0x6C - 0x68];
    s32 unk6C;
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
    s32 unkC0;
    u8 padC4[0xD8 - 0xC4];
    s32 (*unkD8)(struct Unk80061800 *);
    u8 padDC[0x104 - 0xDC];
    f32 unk104;
} Unk80061800;

extern s32 D_800B9B18;
extern char D_800099F8[];
extern char D_80009A0C[];

s32 func_80080DE0(s32 arg0);
void initSpline(s32 idx, s32 closed);
void syncActorPrevPos(void *arg0);
s32 randomRange(s32 arg0, s32 arg1);
s32 func_80076080(void *arg0);
s32 tickActorTimer(void *arg0);
s32 func_800853E8(void *arg0);
s32 func_80080594(void *arg0, s32 arg1);
s32 func_8002444C(void);
void func_80043328(void *arg0, s32 arg1, s32 arg2);
void debugPrintf(void *, ...);
void func_80083A28(void *);
s32 func_80084368(Unk80061800 *);
s32 func_80083CC4(Unk80061800 *);
s32 updatePursuitVehicle(Unk80061800 *);
s32 func_8006BB14(Unk80061800 *);
s32 func_80083E98(Unk80061800 *);

extern char D_80008978[];
extern char D_80008990[];
extern void *D_800B7FC0[];
s32 func_80083B04(Unk80061800 *);
s32 func_80083EDC(Unk80061800 *);
s32 func_80061B00(Unk80061800 *);
s32 func_8002D260(s32 arg0);
void func_80061B44(void *arg0);

/* Per-frame spider AI: runs the current behaviour state and, when it returns a
   result, switches to the next state. Clears the pending-event flag at the end. */
void updateSpiderAi(Unk80061800 *spider) {
    s32 stepResult;
    s32 stateIndex;

    stepResult = 1;
    if (spider->unk7C == 0) {
        spider->unk7C = 1;
        spider->unk78 = 0;
        spider->unkD8 = NULL;
        syncActorPrevPos(spider);
        if (spider->unkAC == 0.0f) {
            spider->unkAC = 0.015f;
        }
        if (spider->unk104 == 0.0f) {
            spider->unk104 = 700.0f;
        }
        spider->unk64 = randomRange(25, 30) * 100;
    }
    if (func_80076080(spider) != 0) {
        return;
    }
    tickActorTimer(spider);
    if (spider->unkD8 != NULL) {
        stepResult = spider->unkD8(spider);
    }
    func_800853E8(spider);
    if (stepResult != 0) {
        spider->unk8C = 0;
        for (stateIndex = 0; D_800B7FC0[stateIndex] != NULL; stateIndex++) {
            if (D_800B7FC0[stateIndex] == spider->unkD8) {
                break;
            }
        }
        switch (stateIndex) {
        case 0:
        case 1:
        case 2:
        case 3:
            switch (stepResult) {
            case 1:
                spider->unk78 = 1;
                spider->unkD8 = func_80083B04;
                break;
            case 2:
                spider->unk78 = 2;
                spider->unkD8 = func_80083CC4;
                break;
            default:
                debugPrintf(D_80008978);
                break;
            }
            break;
        case 4:
            spider->unk78 = 2;
            spider->unkD8 = func_80083CC4;
            spider->unk8C = 0;
            break;
        case 5:
            switch (stepResult) {
            case 1:
                spider->unk64 = randomRange(25, 30) * 100;
                spider->unk78 = 0;
                spider->unkD8 = func_80083E98;
                if (func_8002444C() & 1) {
                    func_80080594(spider, 2);
                } else {
                    func_80080594(spider, 1);
                }
                break;
            case 2:
                spider->unk78 = 1;
                spider->unkD8 = func_80083EDC;
                func_80080594(spider, 0);
                break;
            case 3:
                spider->unk78 = 1;
                spider->unkD8 = func_80061B00;
                spider->unk6C = func_8002D260(spider->unk10 + 0x8000);
                break;
            case 5:
                spider->unk78 = 2;
                spider->unkD8 = func_80083CC4;
                spider->unk8C = 0;
                break;
            default:
                debugPrintf(D_80008990);
                break;
            }
            break;
        default:
            spider->unk78 = 1;
            spider->unkD8 = func_80083B04;
            break;
        }
        func_80043328(spider, spider->unk74 + spider->unk78, 0x100);
    }
    spider->unkC0 &= ~4;
    func_80061B44(spider);
}
