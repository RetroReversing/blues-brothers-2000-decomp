typedef struct Obj {
    u8 pad0[0x58];
    s32 unk58;
    s32 unk5C;
    u8 pad60[0x68 - 0x60];
    s32 unk68;
    u8 pad6C[0x74 - 0x6C];
    s32 unk74;
    s32 unk78;
    u8 pad7C[0x94 - 0x7C];
    s32 unk94;
    void *unk98;
} Obj;

s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_800B7B0C;
extern s32 D_800B81D0;
extern s32 D_8014A924;
void drawActorModel(void);
void func_8001F9A8(void);
void func_8001FCF0(void);
extern u8 func_80023078[];

void func_8004E8B0(Obj *arg0, u32 arg1) {
    D_8014A924 = 1;
    switch (arg1) {
    case 0:
        arg0->unk58 = packDrawFlags(0, 1, 0, 3, D_800B7B0C, 0, 1, 0);
        arg0->unk98 = drawActorModel;
        arg0->unk68 = 2;
        arg0->unk5C = 0xFF;
        break;
    case 1:
        arg0->unk98 = func_80023078 + 8;
        arg0->unk68 = -1;
        break;
    case 3:
        arg0->unk58 = packDrawFlags(0, 1, 1, 1, D_800B7B0C, 0, 1, 0);
        arg0->unk98 = func_8001FCF0;
        arg0->unk68 = 10;
        arg0->unk5C = 0x20;
        D_8014A924 = 2;
        break;
    case 2:
        arg0->unk58 = packDrawFlags(0, 1, 1, 3, D_800B7B0C, 0, 1, 0);
        arg0->unk68 = 10;
        arg0->unk5C = 0x80;
        D_8014A924 = 2;
        break;
    case 7:
        arg0->unk58 = packDrawFlags(0, 1, 2, 3, D_800B7B0C, 0, 1, 0);
        arg0->unk68 = 2;
        arg0->unk5C = 0xFF;
        break;
    case 4:
    case 5:
    case 6:
        arg0->unk94 = 0x7D00;
        arg0->unk58 = packDrawFlags(0, 1, 1, 3, D_800B7B0C, 0, 1, 0);
        arg0->unk58 = packDrawFlags(0, 1, 4, 3, D_800B7B0C, 0, 1, 0);
        arg0->unk98 = func_8001F9A8;
        if (D_800B81D0 == 0) {
            arg0->unk68 = 10;
        } else {
            arg0->unk68 = 3;
        }
        arg0->unk5C = 0x40;
        if ((arg0->unk78 | arg0->unk74) == 0) {
            arg0->unk78 = -1;
            arg0->unk74 = 0;
        }
        D_8014A924 = 2;
        break;
    }
}
