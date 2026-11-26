s32 cameraGetMode(void);
s32 func_8000F294(void *);
void func_80023620(s32);
void func_80023730(void *, s32, s32);
void *findActor(s32, s32);
void func_8002A360(s32, s32);
void func_8002E79C(void);
void func_8002E7B8(s32, s32);
void func_8002E944(void);
void actorSetAnim(void *, s32, s32);
void func_8000F178();
void func_8000F1FC();
extern char func_80023078[];
void func_800393F4();
void animStepKeys();
void func_8006CEF8();
typedef struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ u8 pad4[0x4C];
    /* 0x50 */ s32 f50;
    /* 0x54 */ u8 pad54[0x14];
    /* 0x68 */ s32 f68;
    /* 0x6C */ u8 pad6C[0xC];
    /* 0x78 */ s32 f78;
    /* 0x7C */ u8 pad7C[4];
    /* 0x80 */ s32 f80;
    /* 0x84 */ u8 pad84[0xC];
    /* 0x90 */ s32 f90;
    /* 0x94 */ s32 f94;
    /* 0x98 */ void *f98;
    /* 0x9C */ void *f9C;
} Obj;
extern s32 D_800A9550;
extern u32 D_800AA1B4;
extern s32 D_800AB9C8;
extern s32 D_800B5DD4;
extern void *D_800BCFA0;
extern s32 D_800BCFA4;
extern u8 D_800BCFB8[];
extern Obj *gCameraTarget;
extern u8 D_800BD120[];
extern s32 gPadPressed;
extern s32 D_8013FB20;

void func_8000F310(Obj *arg0) {
    Obj *o;

    switch (D_800AA1B4) {
    case 0:
        D_800B5DD4 = 0;
        D_800AA1B4 = 1;
        func_8002E7B8(1, 0);
        break;
    case 1:
        if (D_8013FB20 == 0xFF) {
            func_80023620(1);
            func_80023730(arg0, 0x100, 0x1031);
            D_800BCFA4 = arg0->f78;
            D_800BCFA0 = arg0->f98;
            if (D_800BD120[cameraGetMode()] == 0 && func_8000F294(arg0) != 0) {
                D_800BD120[cameraGetMode()] = 1;
                D_800AB9C8 = 0x1000;
                actorSetAnim(gCameraTarget, 1, 0x100);
                gCameraTarget->f9C = animStepKeys;
                gCameraTarget->f0 = 3;
                gCameraTarget->f50 = 0;
                gCameraTarget->f90 = 1;
                func_8002E944();
                arg0->f98 = func_8000F1FC;
                D_800AA1B4 = 2;
                o = findActor(6, 0);
                if (o != 0) {
                    o->f68 = -1;
                }
            } else {
                func_8002E79C();
                D_800AA1B4 = 5;
            }
            D_800BCFB8[cameraGetMode()] = 1;
        }
        break;
    case 2:
        if (gPadPressed & 0x8000) {
            D_800AA1B4 = 3;
        } else if (gPadPressed & 0x4000) {
            func_8002E79C();
            D_800AA1B4 = 4;
        }
        break;
    case 3:
        arg0->f94 = 1;
        arg0->f98 = func_8006CEF8;
        arg0->f9C = func_80023078 + 8;
        D_800A9550 = 1;
        arg0->f80 = 0;
        D_800AA1B4 = 4;
        break;
    case 4:
        o = findActor(6, 0);
        if (o != 0) {
            o->f68 = 0xF;
        }
        D_800AA1B4 = 5;
        break;
    case 5:
        D_800A9550 = 0;
        D_800AB9C8 = 0;
        func_8002A360(4, 0);
        func_8002A360(0x1F, 0);
        func_8002A360(2, 0);
        D_800AA1B4 = 0;
        arg0->f78 = D_800BCFA4;
        arg0->f98 = D_800BCFA0;
        arg0->f9C = func_8000F178;
        gCameraTarget->f9C = func_800393F4;
        break;
    }
}
