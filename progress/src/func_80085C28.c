s32 cameraGetMode(void);
s32 randomRange(s32, s32);
s32 func_8002444C(void);
void tickActorTimer(void *);
void syncActorPrevPos(void *);
void func_80043328(void *, s32, s32);
s32 func_8006BB14(void *);
s32 func_80076080(void *);
void func_80080594(void *, s32);
s32 func_80080DE0(s32);
void initSpline(s32, s32);
void func_80083A28(void *);
s32 func_80083CC4(void *);
s32 func_80083E98(void *);
void func_800853E8(void *);
s32 func_80085900(void *);
s32 func_80085A5C(void *);
s32 func_80085B8C(void *);
void debugPrintf(char *, s32);
void func_80084504(void);

typedef struct Ent {
    char pad0[4];
    s32 x4;
} Ent;

typedef struct Obj {
    char pad0[8];
    f32 x8;
    char padC[0x64 - 0xC];
    s32 x64;
    char pad68[0x70 - 0x68];
    s32 x70;
    s32 x74;
    s32 x78;
    s32 x7C;
    char pad80[0x8C - 0x80];
    s32 x8C;
    char pad90[0x9C - 0x90];
    void (*fn9C)(void);
    char padA0[0xAC - 0xA0];
    f32 xAC;
    char padB0[0xB4 - 0xB0];
    f32 xB4;
    s32 xB8;
    s32 xBC;
    char padC0[0xD8 - 0xC0];
    s32 (*fnD8)(struct Obj *);
    char padDC[0x104 - 0xDC];
    f32 x104;
} Obj;

extern char D_80009B04[];
extern char D_80009B1C[];
extern f32 D_80009B34;
extern f32 D_80009B38;
extern f32 D_80009B3C;
extern u8 D_800B9B18[];
extern Ent *gSplineSrcPoints[];

void func_80085C28(Obj *arg0) {
    s32 ret;

    ret = 1;
    if (arg0->x7C == 0) {
        if (func_80080DE0(arg0->x70) == 0) {
            initSpline(arg0->x70, *(s32 *)D_800B9B18);
        }
        arg0->x7C = 1;
        arg0->x78 = 0;
        arg0->fnD8 = NULL;
        syncActorPrevPos(arg0);
        if (arg0->xAC == 0.0f) {
            arg0->xAC = D_80009B34;
        }
        if (arg0->x104 == 0.0f) {
            arg0->x104 = D_80009B38;
        }
        arg0->xB4 = 0.0f;
        arg0->xBC = 1;
        arg0->x8 = gSplineSrcPoints[arg0->x70]->x4;
        if (cameraGetMode() == 0x30 && arg0->xB8 == 12) {
            arg0->x8 -= D_80009B3C;
        }
        if (func_80085900(arg0) == 0) {
            arg0->x7C = 0;
            arg0->fn9C = func_80084504;
            return;
        }
        arg0->x64 = randomRange(25, 30) * 100;
    }
    if (func_80076080(arg0) != 0) {
        return;
    }
    tickActorTimer(arg0);
    if (arg0->fnD8 != NULL) {
        ret = arg0->fnD8(arg0);
    }
    func_800853E8(arg0);
    if (ret != 0) {
        switch (arg0->x78) {
        case 0:
        case 2:
        case 3:
        case 4:
            switch (ret) {
            case 1:
                arg0->x78 = ret;
                arg0->fnD8 = func_80085A5C;
                break;
            case 2:
                arg0->x78 = 4;
                arg0->fnD8 = func_80083CC4;
                arg0->x8C = 0;
                break;
            default:
                debugPrintf(D_80009B04, ret);
                break;
            }
            break;
        case 6:
            arg0->x78 = 4;
            arg0->fnD8 = func_80083CC4;
            arg0->x8C = 0;
            break;
        default:
            switch (ret) {
            case 1:
                arg0->x64 = randomRange(25, 30) * 100;
                arg0->x78 = 0;
                arg0->fnD8 = func_80083E98;
                if (func_8002444C() & 1) {
                    func_80080594(arg0, 2);
                } else {
                    func_80080594(arg0, 1);
                }
                break;
            case 2:
                arg0->x78 = 3;
                arg0->fnD8 = func_8006BB14;
                break;
            case 3:
                arg0->x78 = 4;
                arg0->fnD8 = func_80083CC4;
                arg0->x8C = 0;
                break;
            case 4:
                arg0->x78 = 2;
                arg0->fnD8 = func_80085B8C;
                func_80080594(arg0, 0);
                break;
            default:
                debugPrintf(D_80009B1C, ret);
                break;
            }
            break;
        }
        func_80043328(arg0, arg0->x74 + arg0->x78, 0x100);
        if (arg0->fnD8 != NULL) {
            arg0->fnD8(arg0);
        }
    }
    func_80083A28(arg0);
}
