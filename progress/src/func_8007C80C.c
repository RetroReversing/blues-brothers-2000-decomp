void setTextColor(s32, s32, s32, s32);
s32 getImageAsset(s32);
void drawImage(s32, s32, s32, s32);
extern s32 D_801700F0;
extern s32 D_80170100;

void func_8007C80C(s32 *arg0) {
    s32 q;
    s32 r;

    setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    drawImage(getImageAsset(D_80170100), 0x90, 0x68, 0);
    q = arg0[0x90 / 4] / 6;
    r = arg0[0x90 / 4] % 6;
    switch (q) {
    case 4:
        setTextColor(0xFF, 0xFF, 0xFF, r * 42);
        drawImage(getImageAsset(D_801700F0), 0x7E, 0x28, 0);
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawImage(getImageAsset(D_801700F0), 0x9E, 0x28, 0);
        drawImage(getImageAsset(D_801700F0), 0xBE, 0x28, 0);
        drawImage(getImageAsset(D_801700F0), 0xDE, 0x28, 0);
        drawImage(getImageAsset(D_801700F0), 0xFE, 0x28, 0);
        break;
    case 3:
        setTextColor(0xFF, 0xFF, 0xFF, r * 42);
        drawImage(getImageAsset(D_801700F0), 0x9E, 0x28, 0);
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawImage(getImageAsset(D_801700F0), 0xBE, 0x28, 0);
        drawImage(getImageAsset(D_801700F0), 0xDE, 0x28, 0);
        drawImage(getImageAsset(D_801700F0), 0xFE, 0x28, 0);
        break;
    case 2:
        setTextColor(0xFF, 0xFF, 0xFF, r * 42);
        drawImage(getImageAsset(D_801700F0), 0xBE, 0x28, 0);
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawImage(getImageAsset(D_801700F0), 0xDE, 0x28, 0);
        drawImage(getImageAsset(D_801700F0), 0xFE, 0x28, 0);
        break;
    case 1:
        setTextColor(0xFF, 0xFF, 0xFF, r * 42);
        drawImage(getImageAsset(D_801700F0), 0xDE, 0x28, 0);
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawImage(getImageAsset(D_801700F0), 0xFE, 0x28, 0);
        break;
    case 0:
        setTextColor(0xFF, 0xFF, 0xFF, r * 42);
        drawImage(getImageAsset(D_801700F0), 0xFE, 0x28, 0);
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        break;
    }
}
