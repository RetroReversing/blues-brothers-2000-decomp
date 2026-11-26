typedef struct Obj19A2C {
    u8 pad0[0x5C];
    s32 unk5C;
    u8 pad60[0x64 - 0x60];
    s32 unk64;
    u8 pad68[0x7C - 0x68];
    s32 unk7C;
    u8 pad80[0x84 - 0x80];
    s32 unk84;
    u8 pad88[0x8C - 0x88];
    s32 unk8C;
} Obj19A2C;

s32 tickActorTimer(Obj19A2C *);
void sendCommand(s32, s32);
void func_80027038(s32);
void setTextColor(s32, s32, s32, s32);
s32 getImageAsset(s32);
void drawImage(s32, s32, s32, s32);
extern s32 D_800AB9B4;
extern Obj19A2C *D_800B3964;
extern s32 gCamSpeedScale;
extern s32 D_800BCFF8;
extern s32 D_800BD000[];
extern s32 D_800BD050;
extern s32 D_800BD084;

void func_80019A2C(Obj19A2C *arg0) {
    s32 digits[2];
    s32 v;
    s32 x;

    x = 75;
    if (tickActorTimer(arg0) != 0) {
        arg0->unk64 = 101;
        if (D_800AB9B4 == 0) {
            sendCommand(12, 0x80);
            sendCommand(8, 0x75);
        }
    }
    func_80027038(0);
    setTextColor(0xFF, 0xFF, 0xFF, arg0->unk5C);
    arg0->unk5C += gCamSpeedScale * 4;
    if (arg0->unk5C >= 256) {
        arg0->unk5C = 255;
    }
    v = D_800B3964->unk8C / 100;
    digits[0] = v % 10;
    digits[1] = (v / 10) % 10;
    drawImage(getImageAsset(D_800BD000[digits[1]]), 0xB2, 0x19, 0);
    drawImage(getImageAsset(D_800BD000[digits[0]]), 0xCE, 0x19, 0);
    if (D_800B3964->unk7C < 4) {
        drawImage(getImageAsset(D_800BD050), x - 52, 0xB4, 0);
        drawImage(getImageAsset(D_800BD050), x - 16, 0xB4, 0);
        drawImage(getImageAsset(D_800BD050), x + 20, 0xB4, 0);
        if (D_800B3964->unk84 > 0) {
            drawImage(getImageAsset(D_800BCFF8), x - 52, 0xB4, 0);
        }
        if (D_800B3964->unk84 >= 2) {
            drawImage(getImageAsset(D_800BCFF8), x - 16, 0xB4, 0);
        }
        if (D_800B3964->unk84 >= 3) {
            drawImage(getImageAsset(D_800BCFF8), x + 20, 0xB4, 0);
        }
        if (D_800B3964->unk84 >= 2) {
            drawImage(getImageAsset(D_800BD084), x - 52, 0xB4, 0);
        }
        if (D_800B3964->unk84 >= 3) {
            drawImage(getImageAsset(D_800BD084), x - 16, 0xB4, 0);
        }
        if (D_800B3964->unk84 >= 4) {
            drawImage(getImageAsset(D_800BD084), x + 20, 0xB4, 0);
        }
    }
}
