s32 tickActorTimer(void *);
s32 isEntryDisabled(s32, s32);
s32 pollMenuInput(s32);
void sendCommand(s32, s32);
typedef struct { u8 pad[0x9C]; void *f9C; } Obj232B4;
Obj232B4 *spawnEffectObj(s32, s32, s32, s32);
s32 func_80026188(s32);
void stepFadeUp(void *);
void setTextColor(s32, s32, s32, s32);
s32 getImageAsset(s32);
void drawImage(s32, s32, s32, s32);
void func_8006FEEC(void);
void func_8006DBB8(void);
void func_8006EFF8(void);
void func_8006ED34(void);
typedef struct { s32 f0; s32 f4; s32 f8; } Rec81F4;
extern u8 *gCameraRig;
extern u8 *D_800B3964;
extern Rec81F4 D_800B81F4[];
typedef struct { u8 pad[0x10]; s32 f10; s32 f14; } S14ADE0;
extern S14ADE0 D_8014ADE0;

/* Per-frame update for a two-row option menu item: moves the selection on up/down, confirms on A, and draws the two option images. */ s32 updateOptionMenu(u8 *menuItem) {
    s32 action;
    s32 pressed;
    s32 entry;
    s32 mask;
    Obj232B4 *fx;
    S14ADE0 *images;
    s32 color;

    action = 0;
    pressed = tickActorTimer(menuItem) != 0;
    entry = *(s32 *)(menuItem + 0xBC);
    if (entry != 0) {
        mask = D_800B81F4[entry].f4;
        if (isEntryDisabled(*(s32 *)(D_800B3964 + 0xBC), entry) != 0) {
            mask |= 0x28;
        }
        if (pressed) {
            action = pollMenuInput(mask);
        }
        if (action != 0) {
            if (action & 0x28) {
                *(void **)(gCameraRig + 0x9C) = func_8006FEEC;
                sendCommand(0xC, 0x80);
                sendCommand(8, 0xA1);
            } else if (action & 0x10) {
                *(void **)(menuItem + 0x98) = func_8006DBB8;
                *(void **)(menuItem + 0x9C) = func_8006EFF8;
                *(s32 *)(menuItem + 0x64) = 50;
                *(s32 *)(menuItem + 0x68) = -1;
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x9C);
            } else {
                *(s32 *)(D_800B3964 + 0x90) = action | 0x1000;
                sendCommand(0xC, 0x80);
                sendCommand(8, 0xA0);
            }
        }
        return 0;
    }
    if (pressed) {
        action = pollMenuInput(0x2C);
    }
    if (action & 4) {
        (*(s32 *)(menuItem + 0x88))--;
    }
    if (action & 8) {
        (*(s32 *)(menuItem + 0x88))++;
    }
    if (*(s32 *)(menuItem + 0x88) > 0) {
        *(s32 *)(menuItem + 0x88) = 1;
    }
    if (*(s32 *)(menuItem + 0x88) < 0) {
        *(s32 *)(menuItem + 0x88) = 0;
    }
    if (*(s32 *)(menuItem + 0x88) != *(s32 *)(menuItem + 0x8C)) {
        *(s32 *)(menuItem + 0x8C) = *(s32 *)(menuItem + 0x88);
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xA1);
    }
    if (action & 0x20) {
        if (*(s32 *)(menuItem + 0x88) == 0) {
            fx = spawnEffectObj(0x103, 0, 0, 0);
            fx->f9C = func_8006ED34;
            return ++*(s32 *)(gCameraRig + 0x74);
        }
        if (func_80026188(0) != 0 && func_80026188(1) != 0) {
            *(s32 *)(D_800B3964 + 0x90) = 0x2000;
        } else {
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x74);
        }
    }
    stepFadeUp(menuItem + 0x80);
    *(s32 *)(D_800B3964 + 0x88) = *(s32 *)(menuItem + 0x88);
    images = &D_8014ADE0;
    if (images->f10 == 0) {
        return;
    }
    if (*(s32 *)(menuItem + 0x88) == 0) {
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawImage(getImageAsset(images->f10), 0x60, 0x1E, 0);
        color = 0x80;
    } else {
        setTextColor(0x80, 0x80, 0x80, 0x80);
        drawImage(getImageAsset(images->f10), 0x60, 0x1E, 0);
        color = 0xFF;
    }
    setTextColor(color, color, color, color);
    drawImage(getImageAsset(images->f14), 0x60, 0x37, 0);
    return 0;
}
