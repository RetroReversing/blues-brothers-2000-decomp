typedef struct {
    s32 w[8];
} Blob20;

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0x28 - 0x18];
    u8 name[0x28];
    s32 unk50;
    Blob20 sub54;
    u8 data74[0x40];
} SaveRec;

typedef struct {
    u8 pad0[0x5C];
    s32 unk5C;
    u8 pad60[0x80 - 0x60];
    s32 state;
    s32 unk84;
    u8 pad88[0x8C - 0x88];
    s32 unk8C;
} Menu;

s32 func_8001B990(s32, s32);
s32 initControllerPaks(void);
s32 func_800261B8(s32);
s32 refreshControllerPak(s32);
s32 func_8002621C(s32);
void func_800262FC(s32);
s32 func_80026370(s32);
void func_800263F4(void);
void func_8002642C(void);
s32 func_80026848(s32);
void setTextColorRgb(s32, s32, s32);
void func_80027158(s32, s32);
void sendCommand(s32, s32);
void func_80032830(void);
void func_80032980(void);
void drawCenteredMessage(s32);
void drawSaveSummary(Menu *);
extern s32 D_800A9540;
extern s32 D_800A9548;
extern s32 gPakInitWarn;
extern s32 gPakInitError;
extern s32 D_800AE19C;
extern s32 D_800B81C0;
extern s32 D_800B81C4;
extern s32 D_800B81C8;
extern s32 D_800B81D4;
extern u8 D_800BCFB8[0x40];
extern Blob20 D_800BD0B8;
extern u8 D_800BD1F0[0x28];
extern SaveRec gSaveSlots[];
extern u32 gPadPressed;

void func_8006CF34(Menu *arg0) {
    s32 i;
    s32 r;

    switch (arg0->state) {
    case 0:
        D_800B81C4 = 0;
        gPakInitWarn = 0;
        refreshControllerPak(0);
        gPakInitError = 0;
        switch (initControllerPaks()) {
        case 0:
            arg0->state = 1;
            break;
        case 1:
            arg0->state = 2;
            break;
        case 2:
            arg0->state = 3;
            break;
        case 3:
            arg0->state = 2;
            break;
        default:
            arg0->state = 2;
            break;
        }
        break;
    case 1:
        gPakInitWarn = 0;
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0x76);
        drawCenteredMessage(0x77);
        drawCenteredMessage(0x78);
        drawCenteredMessage(0x79);
        drawCenteredMessage(0x56);
        drawCenteredMessage(0x7A);
        if (gPadPressed & 0x8000) {
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            arg0->state = 4;
        }
        if (gPadPressed & 0x4000) {
            D_800B81C0 = 0;
            D_800B81C8 = 0;
            func_80032980();
            D_800B81D4 = 0;
            D_800A9540 = 2;
            D_800BD0B8 = *&gSaveSlots[D_800B81C8].sub54;
            {
                u8 *p;
                u8 *q;

                for (i = 0x3F, p = &D_800BCFB8[i]; i >= 0; i--) {
                    *p-- = 0;
                }
                for (i = 0x27, q = &D_800BD1F0[i]; i >= 0; i--) {
                    *q-- = 0;
                }
            }
            D_800A9548 = 0;
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x9C);
            arg0->state = 5;
        }
        break;
    case 2:
        drawSaveSummary(arg0);
        if (gPadPressed & 0x8000) {
            D_800B81C0 = 1;
            D_800B81C8 = arg0->unk84;
            if (gSaveSlots[D_800B81C8].unk14 != 0) {
                D_800B81D4 = 1;
            } else {
                D_800B81D4 = 0;
            }
            D_800A9540 = 2;
            D_800BD0B8 = *&gSaveSlots[D_800B81C8].sub54;
            if (func_8001B990(0x100, 0x32) != 0) {
                D_800A9540++;
            }
            if (func_8001B990(0x100, 0x33) != 0) {
                D_800A9540++;
            }
            if (func_8001B990(0x100, 0x34) != 0) {
                D_800A9540++;
            }
            if (func_8001B990(0x100, 0x35) != 0) {
                D_800A9540++;
            }
            if (func_8001B990(0x100, 0x36) != 0) {
                D_800A9540++;
            }
            for (i = 0; i < 0x40; i++) {
                D_800BCFB8[i] = gSaveSlots[D_800B81C8].data74[i];
            }
            for (i = 0; i < 0x28; i++) {
                D_800BD1F0[i] = gSaveSlots[D_800B81C8].name[i];
            }
            D_800A9548 = gSaveSlots[D_800B81C8].unk50;
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            arg0->state = 5;
        }
        break;
    case 3:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0x76);
        drawCenteredMessage(0x7B);
        drawCenteredMessage(0x7C);
        drawCenteredMessage(0x78);
        drawCenteredMessage(0x79);
        drawCenteredMessage(0x56);
        drawCenteredMessage(0x7A);
        if (gPadPressed & 0x8000) {
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            arg0->state = 4;
        }
        if (gPadPressed & 0x4000) {
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x9C);
            arg0->state = 0xD;
        }
        break;
    case 4:
        if (refreshControllerPak(0) == 0) {
            arg0->state = 1;
        } else {
            func_800263F4();
            r = func_80026848(1);
            func_8002642C();
            if (r != 0) {
                if (D_800AE19C != 0) {
                    func_80032830();
                }
                arg0->state = 2;
            } else if (gPakInitWarn != 0 && func_800261B8(0) == 0) {
                if (func_8002621C(0) != 0) {
                    arg0->state = 3;
                } else if (D_800B81C4 != 0) {
                    arg0->state = 9;
                } else {
                    arg0->state = 7;
                }
            } else if (func_8002621C(0) != 0) {
                arg0->state = 3;
            } else {
                arg0->state = 7;
            }
        }
        break;
    case 5:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0x7D);
        drawCenteredMessage(0x7E);
        drawCenteredMessage(0x7F);
        drawCenteredMessage(0x5F);
        drawCenteredMessage(0x80);
        drawCenteredMessage(0x56);
        drawCenteredMessage(0x81);
        if (gPadPressed & 0x8000) {
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            arg0->state = 6;
        }
        if (gPadPressed & 0x4000) {
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x9C);
            arg0->state = 0xD;
        }
        break;
    case 6:
        if (func_8002621C(0) != 0) {
            arg0->state = 0xD;
        } else {
            arg0->state = 5;
        }
        break;
    case 7:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0x82);
        drawCenteredMessage(0x83);
        drawCenteredMessage(0x84);
        drawCenteredMessage(0x85);
        drawCenteredMessage(0x86);
        drawCenteredMessage(0x87);
        drawCenteredMessage(0x88);
        drawCenteredMessage(0x56);
        drawCenteredMessage(0x7A);
        if (gPadPressed & 0x8000) {
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            arg0->state = 0xF;
        }
        if (gPadPressed & 0x4000) {
            func_800262FC(0);
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x9C);
            arg0->state = 1;
        }
        break;
    case 15:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0xF);
        drawCenteredMessage(0x58);
        drawCenteredMessage(0x59);
        drawCenteredMessage(0x89);
        drawCenteredMessage(0x8A);
        if (gPadPressed & 0x8000) {
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            arg0->state = 8;
        }
        if (gPadPressed & 0x4000) {
            func_800262FC(0);
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x9C);
            arg0->state = 1;
        }
        break;
    case 8:
        if (func_80026370(0) != 0) {
            func_800262FC(0);
            arg0->state = 1;
        } else {
            D_800B81C4 = 1;
            arg0->state = 4;
        }
        break;
    case 9:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0x5E);
        drawCenteredMessage(0x8B);
        drawCenteredMessage(0x8C);
        drawCenteredMessage(0x5F);
        drawCenteredMessage(0x7A);
        drawCenteredMessage(0);
        if (gPadPressed & 0x8000) {
            func_800262FC(0);
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            arg0->state = 1;
        }
        if (gPadPressed & 0x4000) {
            func_800262FC(0);
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            arg0->state = 0;
        }
        break;
    case 13:
        func_8002621C(1);
        func_8002621C(2);
        func_8002621C(3);
        D_800B81C4 = 0;
        arg0->state = 0;
        arg0->unk5C = 0;
        arg0->unk8C = 1;
        break;
    }
}
