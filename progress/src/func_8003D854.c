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
void func_8002A360(s32, s32);
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
extern s32 D_801073B0;
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

void func_8003D854(Obj *arg0) {
    s32 moved;

    moved = func_8003D654();
    if (arg0->unk88 < 0) {
        arg0->unk88 = 0;
        moved = 0;
    }
    if (arg0->unk88 >= D_800B5DD8) {
        arg0->unk88 = D_800B5DD8 - 1;
        moved = 0;
    }
    if (moved != 0) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x90);
    }
    if (gPadPressed & 0x8000) {
        switch (arg0->unk88) {
        case 0:
            arg0->unk9C = func_8003D3C8;
            D_800AB9B4 = 0;
            D_800B5DD4 = 1;
            D_80140228 = arg0->unk74;
            func_800256A4(0x12345678);
            func_8002A360(0, gAudioVolume * 0x147);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
            gTextWaveTime = D_80140250;
            return;
        case 1:
            arg0->unk94 = 1;
            arg0->unk98 = func_8006CEF8;
            arg0->unk80 = 0;
            arg0->unk9C = func_80023078 + 8;
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            break;
        case 2:
            arg0->unk9C = func_8003DD70;
            arg0->unk98 = drawAudioOptionsMenu;
            arg0->unk88 = 0;
            D_800B5DCC = 2;
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA2);
            break;
        case 3:
            arg0->unk9C = func_8003D558;
            func_8002E7B8(1, 0);
            D_800B5DD4 = 1;
            arg0->unk70 = 2;
            D_800B81D4 = 1;
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9D);
            break;
        case 4:
            arg0->unk98 = func_8006DBB8;
            arg0->unk9C = func_8003D7A8;
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA3);
            break;
        }
    }
    if ((gPadPressed & 0x200) || (D_801073B0 < -30)) {
        arg0->unk7C--;
    }
    if ((gPadPressed & 0x100) || (D_801073B0 >= 31)) {
        arg0->unk7C++;
    }
    if (gPadPressed & 0x1000) {
        arg0->unk9C = func_8003D3C8;
        D_800AB9B4 = 0;
        D_800B5DD4 = 1;
        D_80140228 = arg0->unk74;
        func_8002A360(0, gAudioVolume * 0x147);
        gTextWaveTime = D_80140250;
    }
}
