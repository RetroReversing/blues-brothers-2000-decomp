typedef struct {
    u8 pad0[8];
    s32 unk8;
} Unk801070A0;

extern s32 D_801070A8;
extern s32 D_80107048;
extern Unk801070A0 gPadPressed;
extern s32 soundTestSfxId;
extern s32 soundTestTuneId;
extern s32 soundTestPlayState;
extern s32 soundTestToggleState;
extern char sfxLabel[];
extern char tuneLabel[];

s32 tickActorTimer(void *arg0);
void func_80027038(s32);
void func_800226A0(s32);
void setTextColorRgb(s32, s32, s32);
void func_80027158(s32, s32);
void drawText(char *);
void drawInt(s32);
void sendCommand(s32, s32);

/* Sound test debug screen: shows the SFX and TUNE numbers, steps them with the pad, and plays or stops them with the buttons. */
void updateSoundTestMenu(void *actor) {
    s32 held;
    s32 held2;
    s32 other;
    Unk801070A0 *pad;

    if (tickActorTimer(actor) != 0) {
        *(s32 *)((u8 *)actor + 0x64) = 15;
        if (D_801070A8 & 0x200) {
            soundTestSfxId++;
        }
        if (D_801070A8 & 0x100) {
            soundTestSfxId--;
        }
        if (D_80107048 & 0x800) {
            soundTestSfxId++;
        }
        if (D_80107048 & 0x400) {
            soundTestSfxId--;
        }
        if (D_801070A8 & 2) {
            soundTestTuneId++;
        }
        if (D_801070A8 & 1) {
            soundTestTuneId--;
        }
    }
    if (soundTestSfxId < 0) {
        soundTestSfxId = 219;
    }
    if (soundTestSfxId >= 220) {
        soundTestSfxId = 0;
    }
    if (soundTestTuneId < 0) {
        soundTestTuneId = 10;
    }
    if (soundTestTuneId >= 11) {
        soundTestTuneId = 0;
    }
    func_80027038(0);
    func_800226A0(0);
    setTextColorRgb(0x60, 0x60, 0xFF);
    func_80027158(30, 90);
    drawText(sfxLabel);
    func_80027158(120, 90);
    drawInt(soundTestSfxId);
    func_80027158(30, 110);
    drawText(tuneLabel);
    func_80027158(120, 110);
    drawInt(soundTestTuneId);
    pad = &gPadPressed;
    if (pad->unk8 & 0x8000) {
        sendCommand(9, soundTestSfxId);
    }
    if (pad->unk8 & 0x4000) {
        sendCommand(3, soundTestTuneId);
    }
    if (pad->unk8 & 8) {
        sendCommand(4, 0);
    }
    if (pad->unk8 & 4) {
        sendCommand(10, 0);
    }
    if (pad->unk8 & 0x20) {
        if (soundTestPlayState == 0) {
            sendCommand(0x1C, 0);
            soundTestPlayState = 1;
        } else if (soundTestPlayState == 1) {
            sendCommand(0x1D, 0);
            sendCommand(0x1C, 1);
            soundTestPlayState = 2;
        } else if (soundTestPlayState == 2) {
            sendCommand(0x1D, 0);
            soundTestPlayState = 0;
        }
    }
    if (D_801070A8 & 0x10) {
        if (soundTestToggleState == 0) {
            sendCommand(0x1E, 0);
            soundTestToggleState = 1;
        } else {
            sendCommand(0x1F, 0);
            soundTestToggleState = 0;
        }
    }
}
