typedef struct Actor64130 {
    s32 unk0;
    f32 x;
    f32 y;
    f32 z;
    s32 unk10;
    u8 pad14[0x50 - 0x14];
    s32 unk50;
    u8 pad54[0x5C - 0x54];
    s32 unk5C;
    u8 pad60[0x64 - 0x60];
    s32 unk64;
    s32 unk68;
    u8 pad6C[0x70 - 0x6C];
    s32 unk70;
    u8 pad74[0x7C - 0x74];
    s32 unk7C;
    u8 pad80[0x90 - 0x80];
    s32 unk90;
    u8 pad94[0x9C - 0x94];
    void (*unk9C)(struct Actor64130 *);
    void (*unkA0)(struct Actor64130 *);
    u8 padA4[0xC0 - 0xA4];
    s32 unkC0;
} Actor64130;

s32 func_8000C43C(void);
s32 func_8001B990(s32, s32);
void func_800232B4(s32, s32, s32, s32);
Actor64130 *func_80023874(s32, s32);
s32 func_80023DBC(s32);
s32 func_8002D260(s32);
s32 func_8002D5CC(Actor64130 *);
void func_8002D620(Actor64130 *);
void func_80036DB4(Actor64130 *);
void func_800393F4(Actor64130 *);
void func_8004303C(Actor64130 *);
void func_800433A8(Actor64130 *, s32, s32);
s32 func_800520D0(s32);
s32 func_80052100(s32);
void func_80052130(s32, s32);
s32 *func_80052444(s32);
void func_80052A5C(s32);
s32 func_80052B24(s32, char *, Actor64130 *);
Actor64130 *func_8005EA88(Actor64130 *);
Actor64130 *func_80063D00(void);
void func_80063D3C(Actor64130 *);
void func_80063E50(void);
void func_80063EFC(Actor64130 *);
void func_80063F98(Actor64130 *);
void func_80064024(Actor64130 *);
extern u8 D_80023080[];
extern s32 D_800B4988;
extern s32 D_800B5DD4;
extern Actor64130 *D_800B3960;
extern u8 D_800BCFB8[];
extern Actor64130 *D_800BD06C;
extern s32 D_801070A0;

void func_80064130(Actor64130 *arg0) {
    Actor64130 *a;

    if (arg0->unk7C != -1) {
        D_800B4988 = 30;
        D_800B5DD4 = 0;
    }
    switch (arg0->unk7C) {
    case 0:
        a = func_80023874(0x140, 0);
        if (a != NULL) {
            a->unk9C = (void *)D_80023080;
            a->unk68 = -1;
        }
        D_800B3960->unk9C = func_80036DB4;
        a = func_80023874(0x11E, 0);
        if (a == NULL) {
            break;
        }
        D_800B3960->unk9C = func_80036DB4;
        D_800B3960->x = a->x;
        D_800B3960->y = a->y;
        D_800B3960->z = a->z;
        D_800B3960->unkC0 = 0;
        func_8002D620(D_800B3960);
        D_800B3960->unk9C(D_800B3960);
        D_800BD06C->unk10 = func_8002D260(D_800B3960->unk10 + 0x8000);
        arg0->unk7C++;
        if (func_8001B990(0x100, 0x3E) == 0) {
            break;
        }
        arg0->unk7C = -1;
        D_800B4988 = 0;
        D_800B5DD4 = 1;
        if (D_800BCFB8[func_8000C43C()] == 0) {
            func_80063E50();
        }
        goto tail;
    case 1:
        arg0->unk90 = 0;
        arg0->unk7C++;
        D_800BD06C->unk68 = -1;
        D_800BD06C->unk9C = func_8004303C;
        func_800232B4(0x801, 0, 0, 0);
        break;
    case 2:
        *func_80052444(0) = 0x13D;
        func_80052130(0x13D, 2);
        arg0->unk7C++;
        break;
    case 3:
        if (func_800520D0(0x13D) != 1) {
            break;
        }
        a = func_80063D00();
        a->unk64 = 3000;
        a->unkA0 = func_80063D3C;
        arg0->unk64 = 1000;
        arg0->unk7C++;
        a->unk5C = 10;
        a->unk70 = 4;
        break;
    case 4:
        arg0->unk90++;
        if (func_8002D5CC(arg0) != 0 || (D_801070A0 & 0x9000)) {
            if (arg0->unk90 >= 11) {
                D_801070A0 = 0;
                a = func_80023874(0x13E, 0);
                if (a != NULL) {
                    a->unk70 = -8;
                }
                func_80052130(0x13D, 3);
                arg0->unk7C++;
            }
        }
        if (arg0->unk90 >= 101) {
            arg0->unk90 = 100;
        }
        break;
    case 5:
        if (func_800520D0(0x13E) == -1 && func_800520D0(0x13D) == 7) {
            arg0->unk7C++;
        }
        a = func_80023874(0x801, 0);
        if (a != NULL) {
            a->unkA0(a);
        }
        break;
    case 6:
        D_800BD06C->unk0 = 3;
        D_800BD06C->unk50 = 0;
        D_800BD06C->unk90 = 1;
        if (func_80052B24(func_80023DBC(0xE39), "elroom_start", D_800BD06C) != 0) {
            arg0->unk7C++;
        }
        break;
    case 7:
        if (func_80023874(0x801, 0) == NULL) {
            arg0->unk7C++;
        }
        break;
    case 8:
        arg0->unk7C++;
        if (func_80023874(0x11E, 0) == NULL) {
            break;
        }
        func_80052130(0x13D, 5);
        a = func_8005EA88(D_800BD06C);
        a->unk9C = func_80063F98;
        a->x = -3.0f;
        a->y = 53.0f;
        a->z = -1000.0f;
        func_800433A8(a, 0xDF, 0x100);
        a->unk10 = 0;
        a->unk0 = 0x13D;
        break;
    case 9:
        if (func_80052100(0x13D) != 0xDE) {
            break;
        }
        func_80052A5C(0x569);
        func_80052B24(func_80023DBC(0xE39), "guard", D_800BD06C);
        arg0->unk7C++;
        break;
    case 10:
        if (func_80023874(0x801, 0) == NULL) {
            arg0->unk7C++;
        }
        break;
    case 11:
        a = func_80023874(0x13D, 0);
        a->unk10 = 0x8000;
        a->unk9C = func_80063EFC;
        a->unk64 = 50;
        arg0->unk64 = 500;
        arg0->unk7C++;
        break;
    default:
        if (func_8002D5CC(arg0) == 0) {
            break;
        }
        func_80052130(0x13D, 4);
    tail:
        arg0->unk9C = (void *)D_80023080;
        D_800BD06C->unk9C = func_800393F4;
        D_800BD06C->unk68 = 3;
        D_800BD06C->unk10 = 0x8000;
        func_8001B990(0x200, 0x3E);
        D_800B5DD4 = 1;
        D_800B3960->unk9C = func_80064024;
        D_800B3960->x = -881.0f;
        D_800B3960->z = 58.0f;
        D_800B3960->y = 684.0f;
        func_8002D620(D_800B3960);
        func_8002D620(D_800B3960);
        break;
    }
}
