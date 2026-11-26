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

void updateSpiderAi(Unk80061800 *arg0) {
    s32 result;
    s32 i;

    result = 1;
    if (arg0->unk7C == 0) {
        arg0->unk7C = 1;
        arg0->unk78 = 0;
        arg0->unkD8 = NULL;
        syncActorPrevPos(arg0);
        if (arg0->unkAC == 0.0f) {
            arg0->unkAC = 0.015f;
        }
        if (arg0->unk104 == 0.0f) {
            arg0->unk104 = 700.0f;
        }
        arg0->unk64 = randomRange(25, 30) * 100;
    }
    if (func_80076080(arg0) != 0) {
        return;
    }
    tickActorTimer(arg0);
    if (arg0->unkD8 != NULL) {
        result = arg0->unkD8(arg0);
    }
    func_800853E8(arg0);
    if (result != 0) {
        arg0->unk8C = 0;
        for (i = 0; D_800B7FC0[i] != NULL; i++) {
            if (D_800B7FC0[i] == arg0->unkD8) {
                break;
            }
        }
        switch (i) {
        case 0:
        case 1:
        case 2:
        case 3:
            switch (result) {
            case 1:
                arg0->unk78 = 1;
                arg0->unkD8 = func_80083B04;
                break;
            case 2:
                arg0->unk78 = 2;
                arg0->unkD8 = func_80083CC4;
                break;
            default:
                debugPrintf(D_80008978);
                break;
            }
            break;
        case 4:
            arg0->unk78 = 2;
            arg0->unkD8 = func_80083CC4;
            arg0->unk8C = 0;
            break;
        case 5:
            switch (result) {
            case 1:
                arg0->unk64 = randomRange(25, 30) * 100;
                arg0->unk78 = 0;
                arg0->unkD8 = func_80083E98;
                if (func_8002444C() & 1) {
                    func_80080594(arg0, 2);
                } else {
                    func_80080594(arg0, 1);
                }
                break;
            case 2:
                arg0->unk78 = 1;
                arg0->unkD8 = func_80083EDC;
                func_80080594(arg0, 0);
                break;
            case 3:
                arg0->unk78 = 1;
                arg0->unkD8 = func_80061B00;
                arg0->unk6C = func_8002D260(arg0->unk10 + 0x8000);
                break;
            case 5:
                arg0->unk78 = 2;
                arg0->unkD8 = func_80083CC4;
                arg0->unk8C = 0;
                break;
            default:
                debugPrintf(D_80008990);
                break;
            }
            break;
        default:
            arg0->unk78 = 1;
            arg0->unkD8 = func_80083B04;
            break;
        }
        func_80043328(arg0, arg0->unk74 + arg0->unk78, 0x100);
    }
    arg0->unkC0 &= ~4;
    func_80061B44(arg0);
}
