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
s32 func_80025FF8(void);
s32 func_800261D4(s32);
s32 func_8002621C(s32);
void func_800262FC(s32);
s32 func_80026370(s32);
void func_800263F4(void);
void func_8002642C(void);
void func_80026780(void);
s32 func_80026848(s32);
void func_800270A8(s32, s32, s32);
void func_8002713C(s32, s32);
void func_80027158(s32, s32);
void func_8002A360(s32, s32);
s32 func_8002D5CC(Menu *);
void func_8002E6E4(void);
void func_8002E79C(void);
void func_8002E838(s32);
void func_8003245C(void);
void func_8003CDA0(s32);
void func_8003D854(void);
void func_8003DEF0(void);
extern s32 D_800A9550;
extern s32 D_800AE174;
extern s32 D_800AE178;
extern s32 D_800AE19C;
extern s32 D_800AE1A0;
extern s32 D_800AE1A4;
extern s32 D_800AE1A8;
extern s32 D_800B81C4;
extern u32 D_801070A0;

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
        D_800AE174 = 0;
        func_800261D4(0);
        D_800AE178 = 0;
        switch (func_80025FF8()) {
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
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0x8D);
        func_8003CDA0(0x77);
        func_8003CDA0(0x78);
        func_8003CDA0(0x5F);
        func_8003CDA0(0x8E);
        func_8003CDA0(0x56);
        func_8003CDA0(0x60);
        if (D_801070A0 & 0x8000) {
            D_800AE174 = 0;
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 4;
        }
        if (D_801070A0 & 0x4000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
            arg0->state = 5;
        }
        break;
    case 2:
        if (D_800AE174 == 0) {
            func_8003245C();
            func_800263F4();
            func_80026848(1);
            func_8002642C();
            func_80026780();
            if (D_800AE1A4 == 0 && D_800AE1A8 == 0 && D_800AE174 == 0) {
                arg0->state = 0xE;
                arg0->unk64 = 0xFA;
                break;
            }
        }
        arg0->state = 7;
        break;
    case 14:
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_8002713C(0xA0, 0x6F);
        func_8003CDA0(0x13);
        if (func_8002D5CC(arg0) != 0 || (D_801070A0 & 0xD000)) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 5;
        }
        break;
    case 3:
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0x8D);
        func_8003CDA0(0x7B);
        func_8003CDA0(0x7C);
        func_8003CDA0(0x78);
        func_8003CDA0(0x5F);
        func_8003CDA0(0x8E);
        func_8003CDA0(0x56);
        func_8003CDA0(0x60);
        if (D_801070A0 & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 4;
        }
        if (D_801070A0 & 0x4000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
            arg0->state = 0xD;
        }
        break;
    case 4:
        if (func_8002621C(0) != 0) {
            D_800AE174 = 0;
            arg0->state = 3;
        } else if (func_800261D4(0) == 0) {
            D_800AE174 = 0;
            arg0->state = 1;
        } else if (D_800AE174 != 0) {
            if (D_800B81C4 != 0) {
                arg0->state = 9;
            } else {
                arg0->state = 7;
            }
        } else if (D_800AE178 == 0) {
            func_800263F4();
            func_80026848(1);
            func_8002642C();
        } else {
            func_80026780();
            func_800263F4();
            r = func_80026848(D_800AE1A4 | D_800AE1A8 | D_800AE174);
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
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0x8F);
        func_8003CDA0(0x90);
        func_8003CDA0(0x91);
        func_8003CDA0(0x5C);
        if (D_801070A0 & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 4;
        }
        break;
    case 11:
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0x92);
        func_8003CDA0(0x5C);
        func_8003CDA0(0x56);
        func_8003CDA0(0x60);
        if (D_801070A0 & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 2;
        }
        if (D_801070A0 & 0x4000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
            arg0->state = 1;
        }
        break;
    case 12:
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0x8B);
        func_8003CDA0(0x93);
        func_8003CDA0(0x94);
        func_8003CDA0(0x5F);
        func_8003CDA0(0x95);
        if (D_801070A0 & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 1;
        }
        break;
    case 5:
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0x7D);
        func_8003CDA0(0x7E);
        func_8003CDA0(0x7F);
        func_8003CDA0(0x5F);
        func_8003CDA0(0x96);
        func_8003CDA0(0x56);
        func_8003CDA0(0x97);
        if (D_801070A0 & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 6;
        }
        if (D_801070A0 & 0x4000) {
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
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0x82);
        func_8003CDA0(0x83);
        func_8003CDA0(0x84);
        func_8003CDA0(0x85);
        func_8003CDA0(0x86);
        func_8003CDA0(0x87);
        func_8003CDA0(0x88);
        func_8003CDA0(0x56);
        func_8003CDA0(0x60);
        if (D_801070A0 & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 0xF;
        }
        if (D_801070A0 & 0x4000) {
            func_800262FC(0);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
            arg0->state = 1;
        }
        break;
    case 15:
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0xF);
        func_8003CDA0(0x58);
        func_8003CDA0(0x59);
        func_8003CDA0(0x89);
        func_8003CDA0(0x8A);
        if (D_801070A0 & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 8;
        }
        if (D_801070A0 & 0x4000) {
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
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0x5E);
        func_8003CDA0(0x8B);
        func_8003CDA0(0x8C);
        func_8003CDA0(0x5F);
        func_8003CDA0(0x60);
        func_8003CDA0(0);
        if (D_801070A0 & 0x8000) {
            func_800262FC(0);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 5;
        }
        if (D_801070A0 & 0x4000) {
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
