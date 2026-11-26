s32 func_80023D58(s32);
void func_80026C04(void *, s32, s32, void *);
void sendCommand(s32, void *);
void func_80033BC0(void);
void actorSetAnim(s32, s32, s32);
void func_80081C10(void);
void func_80087160(s32);
void func_800823F0(void);
void func_80082BE0(void);
void func_800836E4(void);

typedef struct Obj {
    char pad0[0x70];
    s32 x70;
    s32 x74;
    char pad78[0x80 - 0x78];
    s32 x80;
    char pad84[0x9C - 0x84];
    void (*fn9C)(void);
    char padA0[0xAC - 0xA0];
    f32 xAC;
    f32 xB0;
    f32 xB4;
} Obj;

extern Obj *gCameraRig;
extern s32 D_800B87E4;
extern s32 D_800B87EC;
extern s32 gSplinePointCount[];
extern s32 gComboActorA;
extern s32 gComboActorB;
extern s32 gComboSlots[];
extern s32 D_80171A54;

void func_80082D00(Obj *arg0) {
    if (arg0->x80 == 0) {
        func_80087160(func_80023D58(0x21C));
    }
    if (arg0->x80 == 1) {
        func_80087160(func_80023D58(0x21D));
    }
    if (arg0->x80 == 2) {
        func_80087160(func_80023D58(0x21E));
    }
    if (arg0->x80 == 3) {
        func_80087160(func_80023D58(0x21F));
    }
    if (arg0->x80 == 4) {
        func_80087160(func_80023D58(0x220));
    }
    D_80171A54 = arg0->x80;
    func_80081C10();
    D_800B87E4 = 0;
    D_800B87EC = 0;
    sendCommand(4, 0);
    sendCommand(0x1F, 0);
    sendCommand(0x16, func_800823F0);
    sendCommand(0x1E, 0);
    arg0->fn9C = func_80082BE0;
    actorSetAnim(gComboActorA, 0x18A, 0x100);
    actorSetAnim(gComboActorB, 0x19A, 0x100);
    func_80033BC0();
    gCameraRig->fn9C = func_800836E4;
    gCameraRig->x74 = 0;
    gCameraRig->x70 = 1;
    gCameraRig->xB4 = gSplinePointCount[1] / 2;
    gCameraRig->xB0 = gSplinePointCount[gCameraRig->x70] / 2;
    gCameraRig->xAC = gSplinePointCount[gCameraRig->x70] / 2;
    func_80026C04(gComboSlots, 0, 0x50, gCameraRig);
}
