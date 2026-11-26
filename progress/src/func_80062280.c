typedef struct Obj {
    s32 unk0;
    f32 x;
    f32 y;
    f32 z;
    s32 rot;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x70 - 0x1C];
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    u8 pad88[0x98 - 0x88];
    void *cb98;
    void *cb9C;
    u8 padA0[0xB8 - 0xA0];
    s32 model;
} Obj;

typedef struct {
    u8 *name;
    u8 pad4[0x24];
} ModelNode;

typedef struct {
    u8 pad0[0xC];
    s16 count;
    u8 padE[6];
    ModelNode *nodes;
} Model;

typedef struct {
    f32 m[4][4];
} Mtx;

typedef struct {
    s32 *unk0;
    Obj *unk4;
    Obj *unk8;
    Obj *unkC;
    Obj *unk10;
    Model *model;
    s32 node[6];
    Mtx mtx[6];
    u8 pad1B0[0x3F4 - 0x1B0];
    s32 unk3F4;
    s32 unk3F8;
} Scene;

extern Scene *D_800B7FE0;
extern Obj *gCameraRig;
extern s32 D_800B9C70;
extern s32 D_800FB038[];
extern char D_800089D0[];
extern char D_800089DC[];
extern char D_800089FC[];
extern char D_80008A10[];
extern char D_80008A38[];
extern char D_80008A40[];
extern char D_80008A60[];
extern char D_80008A70[];
extern char D_80008A94[];
extern char D_80008A9C[];
extern char D_80008ABC[];
extern char D_80008ACC[];

void func_80023C58(s32);
void func_8002E7B8(s32, s32);
void *heapAlloc(s32);
void func_80026C04(void *, s32, s32);
void func_80023A74(s32, s32);
void setSlotAsset(s32, s32, s32);
void func_800242A8(s32, s32, s32);
s32 *func_8002E374(s32);
Obj *func_80042F00(s32, s32, s32, s32);
void actorSetAnim(Obj *, s32, s32);
Obj *func_8004811C(void *, Scene *);
Obj *func_80048248(void *);
Model *getImageAsset(s32);
s32 func_80026B50(u8 *, char *);
void debugPrintf(char *);
void func_8004BA40(Mtx *, f32, f32, f32);
void func_80088F40(void);
void func_8002A360(s32, s32);
void updateCameraView(Obj *);
void animStepKeys(Obj *);
void func_80062D64(Obj *);
void func_80062DA0(Obj *);

void func_80062280(void) {
    Obj *o;
    s32 *p;
    s32 i;
    f32 unused[8];

    func_80023C58(0x10F);
    func_8002E7B8(0, 0);
    D_800B9C70 = 1;
    D_800B7FE0 = heapAlloc(0x400);
    func_80026C04(D_800B7FE0, 0, 0x400);
    func_80023A74(0x5E, 0x865);
    setSlotAsset(0x165, 0x866, 1);
    func_80023A74(0x5F, 0x863);
    setSlotAsset(0x166, 0x864, 1);
    func_80023A74(0x60, 0x867);
    setSlotAsset(0x167, 0x868, 1);
    func_80023A74(0x61, 0x861);
    setSlotAsset(0x168, 0x862, 1);
    func_80023A74(0x62, 0x869);
    setSlotAsset(0x169, 0x86A, 1);
    func_80023A74(0x63, 0x86B);
    setSlotAsset(0x16A, 0x86C, 1);
    func_800242A8(0xA9, 0x86D, 0x10);
    gCameraRig->x = 0.0f;
    gCameraRig->y = 400.0f;
    gCameraRig->z = -2700.0f;
    gCameraRig->rot = 0;
    gCameraRig->unk14 = 0;
    gCameraRig->unk18 = 0;
    gCameraRig->cb9C = updateCameraView;
    p = func_8002E374(0xA9);
    D_800B7FE0->unk0 = p;
    *p = 0x102;
    D_800B7FE0->unk4 = func_80042F00(0x5E, 0, 0, 0);
    actorSetAnim(D_800B7FE0->unk4, 0x165, 0xEB);
    o = func_80042F00(0x5F, 0, 0, 0);
    actorSetAnim(o, 0x166, 0xEB);
    o->cb9C = animStepKeys;
    o = func_80042F00(0x60, 0, 0, 0);
    actorSetAnim(o, 0x167, 0xEB);
    o->cb9C = animStepKeys;
    o = func_80042F00(0x61, 0, 0, 0);
    o->cb9C = animStepKeys;
    actorSetAnim(o, 0x168, 0xEB);
    o = func_80042F00(0x62, 0, 0, 0);
    o->cb9C = animStepKeys;
    actorSetAnim(o, 0x169, 0xEB);
    o = func_80042F00(0x63, 0, 0, 0);
    o->cb9C = animStepKeys;
    actorSetAnim(o, 0x16A, 0xEB);
    D_800B7FE0->unk4->cb9C = func_80062D64;
    D_800B7FE0->unk4->cb98 = func_80062DA0;
    D_800B7FE0->unk8 = func_8004811C(0, D_800B7FE0);
    D_800B7FE0->unk8->unk70 = 0x46;
    D_800B7FE0->unk8->unk74 = 0x46;
    D_800B7FE0->unk8->unk78 = 0x46;
    D_800B7FE0->unk8->unk7C = 100;
    D_800B7FE0->unk8->unk80 = 50000;
    D_800B7FE0->unk8->unk84 = 0;
    D_800B7FE0->unkC = func_80048248(0);
    D_800B7FE0->unkC->unk70 = 0xEB;
    D_800B7FE0->unkC->unk74 = 0xEB;
    D_800B7FE0->unkC->unk78 = 0xEB;
    D_800B7FE0->unkC->unk7C = 100;
    D_800B7FE0->unkC->unk80 = 50000;
    D_800B7FE0->unkC->unk84 = 0;
    D_800B7FE0->unk10 = func_80048248(0);
    D_800B7FE0->unk10->unk70 = 0xEB;
    D_800B7FE0->unk10->unk74 = 0xEB;
    D_800B7FE0->unk10->unk78 = 0xEB;
    D_800B7FE0->unk10->unk7C = 100;
    D_800B7FE0->unk10->unk80 = 50000;
    D_800B7FE0->unk10->unk84 = 0;
    D_800B7FE0->unk3F4 = 0;
    D_800B7FE0->model = getImageAsset(D_800FB038[D_800B7FE0->unk4->model]);
    for (i = 0; i < D_800B7FE0->model->count; i++) {
        if (func_80026B50(D_800B7FE0->model->nodes[i].name, D_800089D0) == 0) {
            break;
        }
    }
    if (i >= D_800B7FE0->model->count) {
        debugPrintf(D_800089DC);
    }
    D_800B7FE0->node[0] = i;
    for (i = 0; i < D_800B7FE0->model->count; i++) {
        if (func_80026B50(D_800B7FE0->model->nodes[i].name, D_800089FC) == 0) {
            break;
        }
    }
    if (i >= D_800B7FE0->model->count) {
        debugPrintf(D_80008A10);
    }
    D_800B7FE0->node[1] = i;
    for (i = 0; i < D_800B7FE0->model->count; i++) {
        if (func_80026B50(D_800B7FE0->model->nodes[i].name, D_80008A38) == 0) {
            break;
        }
    }
    if (i >= D_800B7FE0->model->count) {
        debugPrintf(D_80008A40);
    }
    D_800B7FE0->node[2] = i;
    for (i = 0; i < D_800B7FE0->model->count; i++) {
        if (func_80026B50(D_800B7FE0->model->nodes[i].name, D_80008A60) == 0) {
            break;
        }
    }
    if (i >= D_800B7FE0->model->count) {
        debugPrintf(D_80008A70);
    }
    D_800B7FE0->node[3] = i;
    for (i = 0; i < D_800B7FE0->model->count; i++) {
        if (func_80026B50(D_800B7FE0->model->nodes[i].name, D_80008A94) == 0) {
            break;
        }
    }
    if (i >= D_800B7FE0->model->count) {
        debugPrintf(D_80008A9C);
    }
    D_800B7FE0->node[4] = i;
    for (i = 0; i < D_800B7FE0->model->count; i++) {
        if (func_80026B50(D_800B7FE0->model->nodes[i].name, D_80008ABC) == 0) {
            break;
        }
    }
    if (i >= D_800B7FE0->model->count) {
        debugPrintf(D_80008ACC);
    }
    D_800B7FE0->node[5] = i;
    func_8004BA40(&D_800B7FE0->mtx[0], 0.0f, 1000.0f, -1000.0f);
    func_8004BA40(&D_800B7FE0->mtx[1], 0.0f, 0.0f, 0.0f);
    func_8004BA40(&D_800B7FE0->mtx[2], 0.0f, 2000.0f, 0.0f);
    func_8004BA40(&D_800B7FE0->mtx[3], 0.0f, 0.0f, 0.0f);
    func_8004BA40(&D_800B7FE0->mtx[4], 0.0f, 2000.0f, 0.0f);
    func_8004BA40(&D_800B7FE0->mtx[5], 0.0f, 0.0f, 0.0f);
    func_80088F40();
    func_8002A360(4, 0);
    func_8002A360(0x1F, 0);
    func_8002A360(0x1C, 0);
    D_800B7FE0->unk3F8 = 0;
}
