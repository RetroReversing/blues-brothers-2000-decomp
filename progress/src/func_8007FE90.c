typedef struct Obj Obj;
struct Obj {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 unk10;
    s32 unk14;
    u8 pad18[0x64 - 0x18];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    u8 pad74[0x78 - 0x74];
    s32 unk78;
    s32 unk7C;
    u8 pad80[0x88 - 0x80];
    s32 unk88;
    s32 unk8C;
    u8 pad90[0x98 - 0x90];
    void *unk98;
    u8 pad9C[0xA0 - 0x9C];
    void (*unkA0)(Obj *);
    u8 padA4[0xA8 - 0xA4];
    Obj *unkA8;
};

Obj *findActor(s32, s32);
void sendCommand(s32, s32);
void func_8002D3B0(Obj *);
void func_8002D4E0(Obj *, s32);
s32 tickActorTimer(Obj *);
void func_8002D604(Obj *);
void syncActorPrevPos(Obj *);
void func_8007FE5C(Obj *);
void debugPrintf(char *);
float sqrtf(float);
extern char D_80009700[];
extern Obj *gCameraRig;
extern Obj *D_800B3964;
extern s32 D_80107040;
void drawActorModel(void);

void func_8007FE90(Obj *arg0) {
    Obj *other;
    Obj *src;
    f32 dx, dy, dz;

    if (arg0->unk7C == 0) {
        arg0->unk98 = drawActorModel;
        src = gCameraRig;
        arg0->x = src->x;
        arg0->y = src->y;
        arg0->z = src->z;
        arg0->unk10 = src->unk10;
        arg0->unk14 = src->unk14;
        arg0->unk64 = 500;
        arg0->unk7C++;
        arg0->unkA8 = findActor(0x102E, 0);
        func_8002D4E0(arg0, 200);
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xD8);
        syncActorPrevPos(arg0);
    }
    D_80107040 &= ~0x2000;
    func_8002D3B0(arg0);
    func_8002D604(arg0);
    other = arg0->unkA8;
    if (other == NULL) {
        debugPrintf(D_80009700);
    }
    dx = arg0->x - other->x;
    dy = arg0->y - other->y;
    dz = arg0->z - other->z;
    if (sqrtf(dx * dx + dy * dy + dz * dz) < 1000.0f) {
        other = findActor(0x102D, 0);
        if (other != NULL && other->unk78 == 5) {
            D_800B3964->unk88 = 1;
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xB7);
        }
        D_800B3964->unk70--;
        func_8007FE5C(arg0);
        arg0->unkA0(arg0);
        return;
    }
    if (arg0->y < -2170.0f) {
        arg0->unk64 = 0;
    }
    if (tickActorTimer(arg0) != 0) {
        D_800B3964->unk8C = 0;
        D_800B3964->unk70--;
        func_8007FE5C(arg0);
        arg0->unkA0(arg0);
    }
}
