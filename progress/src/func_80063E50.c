void *findActor(s32, s32);
void syncActorPrevPos(void *);
void func_80023078(void *);
void func_80063DB8(void *);
extern void *gCameraTarget;

typedef struct {
    u8 pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 pad10[0x3C];
    s32 unk4C;
    f32 unk50;
    s32 unk54;
    u8 pad58[0xC];
    s32 unk64;
    s32 unk68;
    u8 pad6C[0x30];
    void *unk9C;
} Obj;

void func_80063E50(void) {
    Obj *obj;

    obj = findActor(0x140, 0);
    if (obj != NULL && obj->unk9C == (void *)((s8 *)&func_80023078 + 8)) {
        obj->unk4 = 200.0f;
        obj->unk8 = ((Obj *)gCameraTarget)->unk8 + 105.0f;
        obj->unkC = -500.0f;
        syncActorPrevPos(obj);
        obj->unk68 = 3;
        obj->unk9C = func_80063DB8;
        obj->unk4C = 0;
        obj->unk54 = 0;
        obj->unk64 = 0x15E;
        obj->unk50 = 2500.0f;
    }
}
