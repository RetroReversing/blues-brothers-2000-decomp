s32 tickActorTimer(void *);
f32 approachF32(f32, f32, f32);
void syncActorPrevPos(void *);
f32 func_8002D858(void *, s32);
typedef struct Obj {
    s32 unk0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x24];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    u8 pad40[4];
    f32 unk44;
    u8 pad48[0x1C];
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    u8 pad70[0xC];
    s32 unk7C;
    u8 pad80[0x10];
    s32 unk90;
    u8 pad94[0xC];
    void (*unkA0)(struct Obj *);
    u8 padA4[4];
    struct Obj *unkA8;
} Obj;
Obj *func_8002E374(s32);
extern Obj *D_800B3964;

void func_800740A8(Obj *arg0)
{
    Obj *child;

    if (arg0->unk7C == 0) {
        arg0->unk7C = 1;
        arg0->unk68 = -1;
    }
    if (arg0->unkA8 == NULL) {
        if (tickActorTimer(arg0) != 0) {
            child = func_8002E374(D_800B3964->unk6C);
            child->x = arg0->x;
            child->y = arg0->y;
            child->z = arg0->z;
            child->unk34 = child->unk34 * 3;
            child->unk38 = child->unk34;
            child->unk0 = 0x129;
            child->unk3C = child->unk34;
            syncActorPrevPos(child);
            child->y -= 150.0f;
            arg0->unkA8 = child;
        }
    } else {
        child = arg0->unkA8;
        child->y = approachF32(child->unk44, child->y, 15.0f);
        if (!(150.0f < func_8002D858(arg0, 0)) && D_800B3964->unk90 < 5) {
            child->unkA0(child);
            D_800B3964->unk90++;
            arg0->unk64 = 100;
            arg0->unkA8 = NULL;
        }
    }
}
