typedef struct Obj {
    u8 pad0[0x70];
    s32 unk70;
    s32 unk74;
    u8 pad78[0x7C - 0x78];
    s32 unk7C;
    s32 unk80;
    u8 pad84[0x88 - 0x84];
    s32 unk88;
    u8 pad8C[0x94 - 0x8C];
    s32 unk94;
    void *unk98;
    void *unk9C;
} Obj;

void func_800256A4(s32);
void sendCommand(s32, s32);
void func_8002E7B8(s32, s32);
s32 func_8003D654(void);
extern s32 D_800AB9B4;
extern s32 D_800B5DCC;
extern s32 D_800B5DD4;
extern s32 D_800B5DD8;
extern s32 D_800B81D4;
extern s32 gAudioVolume;
extern s32 gTextWaveTime;
extern s32 gPadPressed;
extern s32 gStickX;
extern s32 D_80140228;
extern s32 D_80140250;
extern u8 func_80023078[];
void func_8003D3C8(void);
void func_8003D558(void);
void func_8003D7A8(void);
void func_8003DD70(void);
void drawAudioOptionsMenu(void);
void func_8006CEF8(void);
void func_8006DBB8(void);

/* Main menu input: moves the cursor with up/down, clamps it to the item count, and
   on A runs the selected item (start, options, and so on) by setting the next state
   and its draw/update callbacks. Left/right and Start also adjust the menu value. */
/* Main menu input: moves the cursor up and down, clamps it to the item count, and on A runs the selected item by setting the next state and its update/draw callbacks. Left/right change the value at unk7C; Start resets to the default state. */ void updateMainMenu(Obj *menu) {
    s32 selectionMoved;

    selectionMoved = func_8003D654();
    if (menu->unk88 < 0) {
        menu->unk88 = 0;
        selectionMoved = 0;
    }
    if (menu->unk88 >= D_800B5DD8) {
        menu->unk88 = D_800B5DD8 - 1;
        selectionMoved = 0;
    }
    if (selectionMoved != 0) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x90);
    }
    if (gPadPressed & 0x8000) {
        switch (menu->unk88) {
        case 0:
            menu->unk9C = func_8003D3C8;
            D_800AB9B4 = 0;
            D_800B5DD4 = 1;
            D_80140228 = menu->unk74;
            func_800256A4(0x12345678);
            sendCommand(0, gAudioVolume * 0x147);
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x9C);
            gTextWaveTime = D_80140250;
            return;
        case 1:
            menu->unk94 = 1;
            menu->unk98 = func_8006CEF8;
            menu->unk80 = 0;
            menu->unk9C = func_80023078 + 8;
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            break;
        case 2:
            menu->unk9C = func_8003DD70;
            menu->unk98 = drawAudioOptionsMenu;
            menu->unk88 = 0;
            D_800B5DCC = 2;
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA2);
            break;
        case 3:
            menu->unk9C = func_8003D558;
            func_8002E7B8(1, 0);
            D_800B5DD4 = 1;
            menu->unk70 = 2;
            D_800B81D4 = 1;
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x9D);
            break;
        case 4:
            menu->unk98 = func_8006DBB8;
            menu->unk9C = func_8003D7A8;
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            break;
        }
    }
    if ((gPadPressed & 0x200) || (gStickX < -30)) {
        menu->unk7C--;
    }
    if ((gPadPressed & 0x100) || (gStickX >= 31)) {
        menu->unk7C++;
    }
    if (gPadPressed & 0x1000) {
        menu->unk9C = func_8003D3C8;
        D_800AB9B4 = 0;
        D_800B5DD4 = 1;
        D_80140228 = menu->unk74;
        sendCommand(0, gAudioVolume * 0x147);
        gTextWaveTime = D_80140250;
    }
}
