typedef struct ObjR ObjR;
typedef s32 (*ObjRFn)(ObjR *);
struct ObjR {
    u8 pad0[0x64];
    s32 f64;
    u8 pad68[0x74 - 0x68];
    s32 f74;
    s32 f78;
    s32 f7C;
    u8 pad80[0x8C - 0x80];
    s32 f8C;
    u8 pad90[0xAC - 0x90];
    f32 fAC;
    u8 padB0[0xD8 - 0xB0];
    ObjRFn fD8;
    u8 padDC[0x104 - 0xDC];
    f32 f104;
};

void syncActorPrevPos(ObjR *);
s32 randomRange(s32, s32);
s32 updateDistanceCull(ObjR *);
s32 tickActorTimer(ObjR *);
void fireActorEvents(ObjR *);
s32 func_8002444C(void);
void func_80080594(ObjR *, s32);
void debugPrintf(char *);
void func_80043328(ObjR *, s32, s32);
void func_80083A28(ObjR *);
s32 func_80083B04(ObjR *);
s32 func_80083CC4(ObjR *);
s32 func_80083E98(ObjR *);
s32 func_80083EDC(ObjR *);
s32 func_8006BB14(ObjR *);
extern char D_800099B0[];
extern char D_800099C0[];

void func_80084000(ObjR *arg0) {
    s32 ret;

    ret = 1;
    if (arg0->f7C == 0) {
        arg0->f7C = 1;
        arg0->f78 = 0;
        arg0->fD8 = NULL;
        syncActorPrevPos(arg0);
        if (arg0->fAC == 0.0f) {
            arg0->fAC = 0.015f;
        }
        if (arg0->f104 == 0.0f) {
            arg0->f104 = 700.0f;
        }
        arg0->f64 = randomRange(25, 30) * 100;
    }
    if (updateDistanceCull(arg0) != 0) {
        return;
    }
    tickActorTimer(arg0);
    if (arg0->fD8 != NULL) {
        ret = arg0->fD8(arg0);
    }
    fireActorEvents(arg0);
    if (ret != 0) {
        switch (arg0->f78) {
            case 0:
            case 2:
            case 3:
            case 4:
                switch (ret) {
                    case 1:
                        arg0->f78 = 1;
                        arg0->fD8 = func_80083B04;
                        break;
                    case 2:
                        arg0->f78 = 4;
                        arg0->fD8 = func_80083CC4;
                        arg0->f8C = 0;
                        break;
                    default:
                        debugPrintf(D_800099B0);
                        break;
                }
                break;
            case 6:
                arg0->f78 = 4;
                arg0->fD8 = func_80083CC4;
                arg0->f8C = 0;
                break;
            default:
                switch (ret) {
                    case 1:
                        arg0->f64 = randomRange(25, 30) * 100;
                        arg0->f78 = 0;
                        arg0->fD8 = func_80083E98;
                        if (func_8002444C() & 1) {
                            func_80080594(arg0, 2);
                        } else {
                            func_80080594(arg0, 1);
                        }
                        break;
                    case 2:
                        arg0->f78 = 2;
                        arg0->fD8 = func_80083EDC;
                        func_80080594(arg0, 0);
                        break;
                    case 3:
                        arg0->f78 = 3;
                        arg0->fD8 = func_8006BB14;
                        break;
                    case 4:
                        arg0->f8C = 0;
                        return;
                    case 5:
                        arg0->f78 = 4;
                        arg0->fD8 = func_80083CC4;
                        arg0->f8C = 0;
                        break;
                    default:
                        debugPrintf(D_800099C0);
                        break;
                }
                break;
        }
        func_80043328(arg0, arg0->f74 + arg0->f78, 0x100);
        if (arg0->fD8 != NULL) {
            arg0->fD8(arg0);
        }
    }
    func_80083A28(arg0);
}
