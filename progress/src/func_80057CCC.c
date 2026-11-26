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
s32 func_80083920(void *o, s32 arg1);
s16 sins(u16);
s16 coss(u16);
void func_8002ADFC(s32 ch, s32 range, void *src);
void func_8002A360(s32, s32);
void func_8002D124(void);
void func_80043328(void *arg0, s32 arg1, s32 arg2);
s32 func_8002492C(f32, f32);
void actorSetAnim(void *arg0, s32 arg1, s32 arg2);
f32 getCameraTargetDist(void *o, f32 r, s32 *ang);
s16 *func_800851D8(void *arg0);
s32 func_800571F4(void *arg0);
s32 randomRange(s32 arg0, s32 arg1);
s32 func_8005738C(Unk80057CCC *);
s32 func_800571B0(Unk80057CCC *);
s32 func_80057858(Unk80057CCC *);
s32 func_80057658(Unk80057CCC *);
s32 func_800574D8(Unk80057CCC *);

void func_8002D3E4(void *arg0, s32 arg1);
void func_8002DA80(void *arg0);
s32 tickActorTimer(void *arg0);
s32 func_8002444C(void);

void func_80057CCC(Unk80057CCC *arg0) {
    s32 done;
    s32 result;
    s32 flags;
    s32 angle;
    f32 dist;
    f32 *pos;
    f32 *limit;
    s32 base;

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
    done = animStepKeys(arg0);
    dist = getCameraTargetDist(arg0, 2000.0f, &angle);
    flags = arg0->unkC0;
    arg0->unk100 = dist;
    arg0->unk90 = angle;
    result = func_80083920(arg0, arg0->unk74);
    switch (result) {
    case 1:
        arg0->unk74 = result;
        if (flags & 0x40) {
            func_8002ADFC(0xAE, 6000, arg0);
        } else {
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x2E);
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
        func_800571F4(arg0);
        return;
    }
    if (arg0->unk74 != 0) {
        if (done != 0) {
            arg0->unk74 = 0;
        }
        return;
    }
    if (dist < 170.0f) {
        func_8002A360(12, 0x80);
        func_8002A360(8, 0x4C);
        arg0->unk80 = 1;
        return;
    }
    func_80043328(arg0, 0xC1, 0x100);
    func_8002D3E4(arg0, 100);
    func_8002DA80(arg0);
    switch (arg0->unk70) {
    case 1:
        pos = &arg0->unk4;
        limit = &arg0->unk40;
        base = 0x4000;
        break;
    case 2:
        pos = &arg0->unkC;
        limit = &arg0->unk48;
        base = 0;
        break;
    }
    if (*limit + 300.0f < *pos) {
        arg0->unk10 = base + 0x8000;
    }
    if (*pos < *limit + -300.0f) {
        arg0->unk10 = base;
    }
    if (tickActorTimer(arg0) != 0) {
        if ((func_8002444C() & 1) && arg0->unk80 == 0) {
            func_8002ADFC(0x4C, 3000, arg0);
            arg0->unk80 = 1;
        }
        arg0->unk64 = randomRange(100, 300);
    }
}
