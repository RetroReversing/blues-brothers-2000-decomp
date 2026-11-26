typedef struct {
    u8 pad0[8];
    s32 unk8;
} Unk801070A0;

extern s32 D_801070A8;
extern s32 D_80107048;
extern Unk801070A0 gPadPressed;
extern s32 D_800AA1F8;
extern s32 D_800AA1FC;
extern s32 D_800AA200;
extern s32 D_800AA204;
extern char D_800007A4[];
extern char D_800007AC[];

s32 tickActorTimer(void *arg0);
void func_80027038(s32);
void func_800226A0(s32);
void setTextColorRgb(s32, s32, s32);
void func_80027158(s32, s32);
void drawText(char *);
void drawInt(s32);
void sendCommand(s32, s32);

void func_80012CD8(void *arg0) {
    s32 held;
    s32 held2;
    s32 other;
    Unk801070A0 *pad;

    if (tickActorTimer(arg0) != 0) {
        *(s32 *)((u8 *)arg0 + 0x64) = 15;
        if (D_801070A8 & 0x200) {
            D_800AA1F8++;
        }
        if (D_801070A8 & 0x100) {
            D_800AA1F8--;
        }
        if (D_80107048 & 0x800) {
            D_800AA1F8++;
        }
        if (D_80107048 & 0x400) {
            D_800AA1F8--;
        }
        if (D_801070A8 & 2) {
            D_800AA1FC++;
        }
        if (D_801070A8 & 1) {
            D_800AA1FC--;
        }
    }
    if (D_800AA1F8 < 0) {
        D_800AA1F8 = 219;
    }
    if (D_800AA1F8 >= 220) {
        D_800AA1F8 = 0;
    }
    if (D_800AA1FC < 0) {
        D_800AA1FC = 10;
    }
    if (D_800AA1FC >= 11) {
        D_800AA1FC = 0;
    }
    func_80027038(0);
    func_800226A0(0);
    setTextColorRgb(0x60, 0x60, 0xFF);
    func_80027158(30, 90);
    drawText(D_800007A4);
    func_80027158(120, 90);
    drawInt(D_800AA1F8);
    func_80027158(30, 110);
    drawText(D_800007AC);
    func_80027158(120, 110);
    drawInt(D_800AA1FC);
    pad = &gPadPressed;
    if (pad->unk8 & 0x8000) {
        sendCommand(9, D_800AA1F8);
    }
    if (pad->unk8 & 0x4000) {
        sendCommand(3, D_800AA1FC);
    }
    if (pad->unk8 & 8) {
        sendCommand(4, 0);
    }
    if (pad->unk8 & 4) {
        sendCommand(10, 0);
    }
    if (pad->unk8 & 0x20) {
        if (D_800AA200 == 0) {
            sendCommand(0x1C, 0);
            D_800AA200 = 1;
        } else if (D_800AA200 == 1) {
            sendCommand(0x1D, 0);
            sendCommand(0x1C, 1);
            D_800AA200 = 2;
        } else if (D_800AA200 == 2) {
            sendCommand(0x1D, 0);
            D_800AA200 = 0;
        }
    }
    if (D_801070A8 & 0x10) {
        if (D_800AA204 == 0) {
            sendCommand(0x1E, 0);
            D_800AA204 = 1;
        } else {
            sendCommand(0x1F, 0);
            D_800AA204 = 0;
        }
    }
}
