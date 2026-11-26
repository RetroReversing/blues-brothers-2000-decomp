s32 tickActorTimer(void *);
s32 func_8006DAA0(s32, s32);
s32 func_8006DAE8(s32);
void func_8002A360(s32, s32);
typedef struct { u8 pad[0x9C]; void *f9C; } Obj232B4;
Obj232B4 *func_800232B4(s32, s32, s32, s32);
s32 func_80026188(s32);
void func_8006D8E0(void *);
void setTextColor(s32, s32, s32, s32);
s32 getImageAsset(s32);
void drawImage(s32, s32, s32, s32);
void func_8006FEEC(void);
void func_8006DBB8(void);
void func_8006EFF8(void);
void func_8006ED34(void);
typedef struct { s32 f0; s32 f4; s32 f8; } Rec81F4;
extern u8 *gCameraRig;
extern u8 *D_800B3964;
extern Rec81F4 D_800B81F4[];
typedef struct { u8 pad[0x10]; s32 f10; s32 f14; } S14ADE0;
extern S14ADE0 D_8014ADE0;

s32 func_8006F300(u8 *arg0) {
    s32 res;
    s32 have;
    s32 k;
    s32 flags;
    Obj232B4 *obj;
    S14ADE0 *p;
    s32 c;

    res = 0;
    have = tickActorTimer(arg0) != 0;
    k = *(s32 *)(arg0 + 0xBC);
    if (k != 0) {
        flags = D_800B81F4[k].f4;
        if (func_8006DAA0(*(s32 *)(D_800B3964 + 0xBC), k) != 0) {
            flags |= 0x28;
        }
        if (have) {
            res = func_8006DAE8(flags);
        }
        if (res != 0) {
            if (res & 0x28) {
                *(void **)(gCameraRig + 0x9C) = func_8006FEEC;
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0xA1);
            } else if (res & 0x10) {
                *(void **)(arg0 + 0x98) = func_8006DBB8;
                *(void **)(arg0 + 0x9C) = func_8006EFF8;
                *(s32 *)(arg0 + 0x64) = 50;
                *(s32 *)(arg0 + 0x68) = -1;
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x9C);
            } else {
                *(s32 *)(D_800B3964 + 0x90) = res | 0x1000;
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0xA0);
            }
        }
        return 0;
    }
    if (have) {
        res = func_8006DAE8(0x2C);
    }
    if (res & 4) {
        (*(s32 *)(arg0 + 0x88))--;
    }
    if (res & 8) {
        (*(s32 *)(arg0 + 0x88))++;
    }
    if (*(s32 *)(arg0 + 0x88) > 0) {
        *(s32 *)(arg0 + 0x88) = 1;
    }
    if (*(s32 *)(arg0 + 0x88) < 0) {
        *(s32 *)(arg0 + 0x88) = 0;
    }
    if (*(s32 *)(arg0 + 0x88) != *(s32 *)(arg0 + 0x8C)) {
        *(s32 *)(arg0 + 0x8C) = *(s32 *)(arg0 + 0x88);
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0xA1);
    }
    if (res & 0x20) {
        if (*(s32 *)(arg0 + 0x88) == 0) {
            obj = func_800232B4(0x103, 0, 0, 0);
            obj->f9C = func_8006ED34;
            return ++*(s32 *)(gCameraRig + 0x74);
        }
        if (func_80026188(0) != 0 && func_80026188(1) != 0) {
            *(s32 *)(D_800B3964 + 0x90) = 0x2000;
        } else {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x74);
        }
    }
    func_8006D8E0(arg0 + 0x80);
    *(s32 *)(D_800B3964 + 0x88) = *(s32 *)(arg0 + 0x88);
    p = &D_8014ADE0;
    if (p->f10 == 0) {
        return;
    }
    if (*(s32 *)(arg0 + 0x88) == 0) {
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawImage(getImageAsset(p->f10), 0x60, 0x1E, 0);
        c = 0x80;
    } else {
        setTextColor(0x80, 0x80, 0x80, 0x80);
        drawImage(getImageAsset(p->f10), 0x60, 0x1E, 0);
        c = 0xFF;
    }
    setTextColor(c, c, c, c);
    drawImage(getImageAsset(p->f14), 0x60, 0x37, 0);
    return 0;
}
