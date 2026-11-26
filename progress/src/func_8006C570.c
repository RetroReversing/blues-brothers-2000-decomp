typedef struct {
    u8 pad0[0x64];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    u8 pad74[0x80 - 0x74];
    s32 state;
    u8 pad84[0x88 - 0x84];
    s32 unk88;
    u8 pad8C[0x98 - 0x8C];
    void *unk98;
    void *unk9C;
} Menu;

void func_8000F310(void);
void func_80023078(void);
s32 initControllerPaks(void);
s32 refreshControllerPak(s32);
s32 func_8002621C(s32);
void func_800262FC(s32);
s32 func_80026370(s32);
void func_800263F4(void);
void func_8002642C(void);
void func_80026780(void);
s32 func_80026848(s32);
void setTextColorRgb(s32, s32, s32);
void setTextPos(s32, s32);
void func_80027158(s32, s32);
void func_8002A360(s32, s32);
s32 tickActorTimer(Menu *);
void func_8002E6E4(void);
void func_8002E79C(void);
void func_8002E838(s32);
void func_8003245C(void);
void drawCenteredMessage(s32);
void func_8003D854(void);
void func_8003DEF0(void);
extern s32 D_800A9550;
extern s32 gPakInitWarn;
extern s32 gPakInitError;
extern s32 D_800AE19C;
extern s32 D_800AE1A0;
extern s32 D_800AE1A4;
extern s32 D_800AE1A8;
extern s32 D_800B81C4;
extern u32 gPadPressed;

void func_8006C570(Menu *arg0) {
    s32 r;

    if (D_800A9550 == 0) {
        func_8002E838(arg0->unk70 / 2);
    } else {
        func_8002E6E4();
    }
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
            arg0->state = 4;
            break;
        case 2:
            arg0->state = 3;
            break;
        default:
            arg0->state = 4;
            break;
        }
        break;
    case 1:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0x8D);
        drawCenteredMessage(0x77);
        drawCenteredMessage(0x78);
        drawCenteredMessage(0x5F);
        drawCenteredMessage(0x8E);
        drawCenteredMessage(0x56);
        drawCenteredMessage(0x60);
        if (gPadPressed & 0x8000) {
            gPakInitWarn = 0;
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 4;
        }
        if (gPadPressed & 0x4000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
            arg0->state = 5;
        }
        break;
    case 2:
        if (gPakInitWarn == 0) {
            func_8003245C();
            func_800263F4();
            func_80026848(1);
            func_8002642C();
            func_80026780();
            if (D_800AE1A4 == 0 && D_800AE1A8 == 0 && gPakInitWarn == 0) {
                arg0->state = 0xE;
                arg0->unk64 = 0xFA;
                break;
            }
        }
        arg0->state = 7;
        break;
    case 14:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        setTextPos(0xA0, 0x6F);
        drawCenteredMessage(0x13);
        if (tickActorTimer(arg0) != 0 || (gPadPressed & 0xD000)) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 5;
        }
        break;
    case 3:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0x8D);
        drawCenteredMessage(0x7B);
        drawCenteredMessage(0x7C);
        drawCenteredMessage(0x78);
        drawCenteredMessage(0x5F);
        drawCenteredMessage(0x8E);
        drawCenteredMessage(0x56);
        drawCenteredMessage(0x60);
        if (gPadPressed & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 4;
        }
        if (gPadPressed & 0x4000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
            arg0->state = 0xD;
        }
        break;
    case 4:
        if (func_8002621C(0) != 0) {
            gPakInitWarn = 0;
            arg0->state = 3;
        } else if (refreshControllerPak(0) == 0) {
            gPakInitWarn = 0;
            arg0->state = 1;
        } else if (gPakInitWarn != 0) {
            if (D_800B81C4 != 0) {
                arg0->state = 9;
            } else {
                arg0->state = 7;
            }
        } else if (gPakInitError == 0) {
            func_800263F4();
            func_80026848(1);
            func_8002642C();
        } else {
            func_80026780();
            func_800263F4();
            r = func_80026848(D_800AE1A4 | D_800AE1A8 | gPakInitWarn);
            func_8002642C();
            if (D_800AE1A8 != 0) {
                if (D_800AE1A0 / 256 < 3 || D_800AE19C == 16) {
                    arg0->state = 0xC;
                } else {
                    arg0->state = 0xB;
                }
            } else if (D_800AE1A4 != 0) {
                arg0->state = 0xA;
                D_800AE1A4 = 0;
            } else if (r != 0) {
                arg0->state = 2;
            }
        }
        break;
    case 10:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0x8F);
        drawCenteredMessage(0x90);
        drawCenteredMessage(0x91);
        drawCenteredMessage(0x5C);
        if (gPadPressed & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 4;
        }
        break;
    case 11:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0x92);
        drawCenteredMessage(0x5C);
        drawCenteredMessage(0x56);
        drawCenteredMessage(0x60);
        if (gPadPressed & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 2;
        }
        if (gPadPressed & 0x4000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
            arg0->state = 1;
        }
        break;
    case 12:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0x8B);
        drawCenteredMessage(0x93);
        drawCenteredMessage(0x94);
        drawCenteredMessage(0x5F);
        drawCenteredMessage(0x95);
        if (gPadPressed & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 1;
        }
        break;
    case 5:
        setTextColorRgb(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        drawCenteredMessage(0x7D);
        drawCenteredMessage(0x7E);
        drawCenteredMessage(0x7F);
        drawCenteredMessage(0x5F);
        drawCenteredMessage(0x96);
        drawCenteredMessage(0x56);
        drawCenteredMessage(0x97);
        if (gPadPressed & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 6;
        }
        if (gPadPressed & 0x4000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
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
        drawCenteredMessage(0x60);
        if (gPadPressed & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 0xF;
        }
        if (gPadPressed & 0x4000) {
            func_800262FC(0);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
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
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 8;
        }
        if (gPadPressed & 0x4000) {
            func_800262FC(0);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
            arg0->state = 1;
        }
        break;
    case 8:
        if (func_80026370(0) != 0) {
            func_800263F4();
            func_80026848(1);
            func_8002642C();
            func_800262FC(0);
            D_800B81C4 = 1;
            arg0->state = 9;
        } else {
            func_800263F4();
            r = func_80026848(1);
            func_8002642C();
            if (r != 0) {
                D_800B81C4 = 1;
            } else {
                D_800B81C4 = 0;
            }
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
        drawCenteredMessage(0x60);
        drawCenteredMessage(0);
        if (gPadPressed & 0x8000) {
            func_800262FC(0);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 5;
        }
        if (gPadPressed & 0x4000) {
            func_800262FC(0);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 0;
        }
        break;
    case 13:
        if (D_800A9550 == 0) {
            arg0->unk98 = func_8003DEF0;
            arg0->unk9C = func_8003D854;
        } else {
            func_8002E79C();
            arg0->unk98 = (void *)((u8 *)func_80023078 + 8);
            arg0->unk9C = func_8000F310;
        }
        arg0->unk88 = 0;
        D_800B81C4 = 0;
        break;
    }
}
