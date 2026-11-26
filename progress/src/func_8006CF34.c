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
s32 func_80025FF8(void);
s32 func_800261B8(s32);
s32 func_800261D4(s32);
s32 func_8002621C(s32);
void func_800262FC(s32);
s32 func_80026370(s32);
void func_800263F4(void);
void func_8002642C(void);
s32 func_80026848(s32);
void func_800270A8(s32, s32, s32);
void func_80027158(s32, s32);
void func_8002A360(s32, s32);
void func_80032830(void);
void func_80032980(void);
void func_8003CDA0(s32);
void func_8006EA00(Menu *);
extern s32 D_800A9540;
extern s32 D_800A9548;
extern s32 D_800AE174;
extern s32 D_800AE178;
extern s32 D_800AE19C;
extern s32 D_800B81C0;
extern s32 D_800B81C4;
extern s32 D_800B81C8;
extern s32 D_800B81D4;
extern u8 D_800BCFB8[0x40];
extern Blob20 D_800BD0B8;
extern u8 D_800BD1F0[0x28];
extern SaveRec D_8014ABC0[];
extern u32 D_801070A0;

void func_8006CF34(Menu *arg0) {
    s32 i;
    s32 r;

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
        D_800AE174 = 0;
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0x76);
        func_8003CDA0(0x77);
        func_8003CDA0(0x78);
        func_8003CDA0(0x79);
        func_8003CDA0(0x56);
        func_8003CDA0(0x7A);
        if (D_801070A0 & 0x8000) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 4;
        }
        if (D_801070A0 & 0x4000) {
            D_800B81C0 = 0;
            D_800B81C8 = 0;
            func_80032980();
            D_800B81D4 = 0;
            D_800A9540 = 2;
            D_800BD0B8 = *&D_8014ABC0[D_800B81C8].sub54;
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
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
            arg0->state = 5;
        }
        break;
    case 2:
        func_8006EA00(arg0);
        if (D_801070A0 & 0x8000) {
            D_800B81C0 = 1;
            D_800B81C8 = arg0->unk84;
            if (D_8014ABC0[D_800B81C8].unk14 != 0) {
                D_800B81D4 = 1;
            } else {
                D_800B81D4 = 0;
            }
            D_800A9540 = 2;
            D_800BD0B8 = *&D_8014ABC0[D_800B81C8].sub54;
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
                D_800BCFB8[i] = D_8014ABC0[D_800B81C8].data74[i];
            }
            for (i = 0; i < 0x28; i++) {
                D_800BD1F0[i] = D_8014ABC0[D_800B81C8].name[i];
            }
            D_800A9548 = D_8014ABC0[D_800B81C8].unk50;
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 5;
        }
        break;
    case 3:
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0x76);
        func_8003CDA0(0x7B);
        func_8003CDA0(0x7C);
        func_8003CDA0(0x78);
        func_8003CDA0(0x79);
        func_8003CDA0(0x56);
        func_8003CDA0(0x7A);
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
        if (func_800261D4(0) == 0) {
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
            } else if (D_800AE174 != 0 && func_800261B8(0) == 0) {
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
        func_800270A8(0xFF, 0xFF, 0xFF);
        func_80027158(0xA0, 0x32);
        func_8003CDA0(0x7D);
        func_8003CDA0(0x7E);
        func_8003CDA0(0x7F);
        func_8003CDA0(0x5F);
        func_8003CDA0(0x80);
        func_8003CDA0(0x56);
        func_8003CDA0(0x81);
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
        func_8003CDA0(0x7A);
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
            func_800262FC(0);
            arg0->state = 1;
        } else {
            D_800B81C4 = 1;
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
        func_8003CDA0(0x7A);
        func_8003CDA0(0);
        if (D_801070A0 & 0x8000) {
            func_800262FC(0);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            arg0->state = 1;
        }
        if (D_801070A0 & 0x4000) {
            func_800262FC(0);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
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
