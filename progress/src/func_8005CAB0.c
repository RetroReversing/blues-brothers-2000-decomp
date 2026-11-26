typedef struct Actor {
    u8 pad0[0x5C];
    s32 unk5C;
    u8 pad60[0x70 - 0x60];
    s32 unk70;
    s32 unk74;
    u8 pad78[0x8C - 0x78];
    s32 unk8C;
    s32 unk90;
    u8 pad94[0xA0 - 0x94];
    void (*unkA0)(struct Actor *);
    struct Actor *unkA4;
    s32 unkA8;
} Actor;

s32 func_80043248(Actor *);
extern s32 gCamSpeedScale;

void func_8005CAB0(Actor *arg0) {
    s32 temp_v1;
    Actor *temp_s1;

    temp_s1 = arg0->unkA4;
    if (arg0->unk70 == 0) {
        if ((temp_s1 == NULL) || ((temp_s1->unk90 >= 2) && (temp_s1->unk8C >= 2))) {
            arg0->unk70 = 1;
        }
        if (arg0->unk70 != 0) {
            goto block_6;
        }
    } else {
block_6:
        if (func_80043248(arg0) != 0) {
            arg0->unk74 = 1;
        }
    }
    if (arg0->unk74 != 0) {
        temp_v1 = arg0->unk5C - (gCamSpeedScale * 0xC);
        arg0->unk5C = temp_v1;
        if (temp_v1 < 0xA) {
            if (temp_s1 != NULL) {
                temp_s1->unkA8 = 0;
            }
            arg0->unkA0(arg0);
        }
    }
}
