void setTextColor(s32, s32, s32, s32);
s32 getImageAsset(s32);
void drawImage(s32, s32, s32, s32);
extern s32 gMeterPipImage;
extern s32 gMeterBackgroundImage;

/* Draws the HUD meter: the background, then one pip per 6 units of the value at arg0[0x90/4] (0..30), with the partly filled pip faded by its remainder. */
void drawMeterPips(s32 *meter) {
    s32 fullPips;
    s32 remainder;

    setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    drawImage(getImageAsset(gMeterBackgroundImage), 0x90, 0x68, 0);
    fullPips = meter[0x90 / 4] / 6;
    remainder = meter[0x90 / 4] % 6;
    switch (fullPips) {
    case 4:
        setTextColor(0xFF, 0xFF, 0xFF, remainder * 42);
        drawImage(getImageAsset(gMeterPipImage), 0x7E, 0x28, 0);
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawImage(getImageAsset(gMeterPipImage), 0x9E, 0x28, 0);
        drawImage(getImageAsset(gMeterPipImage), 0xBE, 0x28, 0);
        drawImage(getImageAsset(gMeterPipImage), 0xDE, 0x28, 0);
        drawImage(getImageAsset(gMeterPipImage), 0xFE, 0x28, 0);
        break;
    case 3:
        setTextColor(0xFF, 0xFF, 0xFF, remainder * 42);
        drawImage(getImageAsset(gMeterPipImage), 0x9E, 0x28, 0);
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawImage(getImageAsset(gMeterPipImage), 0xBE, 0x28, 0);
        drawImage(getImageAsset(gMeterPipImage), 0xDE, 0x28, 0);
        drawImage(getImageAsset(gMeterPipImage), 0xFE, 0x28, 0);
        break;
    case 2:
        setTextColor(0xFF, 0xFF, 0xFF, remainder * 42);
        drawImage(getImageAsset(gMeterPipImage), 0xBE, 0x28, 0);
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawImage(getImageAsset(gMeterPipImage), 0xDE, 0x28, 0);
        drawImage(getImageAsset(gMeterPipImage), 0xFE, 0x28, 0);
        break;
    case 1:
        setTextColor(0xFF, 0xFF, 0xFF, remainder * 42);
        drawImage(getImageAsset(gMeterPipImage), 0xDE, 0x28, 0);
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawImage(getImageAsset(gMeterPipImage), 0xFE, 0x28, 0);
        break;
    case 0:
        setTextColor(0xFF, 0xFF, 0xFF, remainder * 42);
        drawImage(getImageAsset(gMeterPipImage), 0xFE, 0x28, 0);
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        break;
    }
}
