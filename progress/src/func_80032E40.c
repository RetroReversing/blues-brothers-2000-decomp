s32 func_8001B990(s32, s32);
s32 getImageAsset(s32);
void func_80026C04(void *, s32, s32);
void setTextColor(s32, s32, s32, s32);
void setTextPos(s32, s32);
void drawImage(s32, s32, s32, s32);
void drawImageTiles(s32, s32, s32, s32, s32, s32);
void func_8002E838(s32);
void drawCenteredMessage(s32);
s16 coss(u16);

typedef struct Pos {
    s32 x;
    s32 y;
    s32 id;
} Pos;

typedef struct Obj {
    char pad0[0x6C];
    s32 x6C;
    char pad70[0xBC - 0x70];
    s32 xBC;
} Obj;

typedef struct Cnt {
    char pad0[0x14];
    s32 x14;
} Cnt;

extern s32 D_800A9540;
extern u8 D_800A954B;
extern Pos D_800A9598[];
extern Obj *D_800B3964;
extern Pos D_800B49AC[];
extern s32 gTextWaveTime;
extern s32 D_800BD07C;
extern Cnt D_800BD0E0;
extern s32 D_800BD168[];
extern s32 D_800BD1E4;
extern u8 D_800BD1F0[];
extern s32 D_8013FF78[];
extern s32 D_8013FF98;
extern s32 D_8013FF9C;

void func_80032E40(Obj *arg0) {
    u8 got[8];
    s32 i;
    s32 w;
    s32 c;

    func_8002E838(arg0->x6C / 2);
    func_80026C04(got, 0, 8);
    got[1] = D_800A954B & 2;
    got[2] = D_800A954B & 4;
    got[4] = D_800A954B & 1;
    got[6] = D_800A954B & 8;
    got[0] = func_8001B990(0x100, 0x24);
    got[3] = func_8001B990(0x100, 0x25);
    got[5] = func_8001B990(0x100, 0x26);
    setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    drawImage(getImageAsset(D_8013FF98), 0x65, 0x22, 0);
    for (i = 0; i < 7; i++) {
        if (got[i] == 0) {
            drawImage(getImageAsset(D_8013FF78[i]), D_800B49AC[i].x, D_800B49AC[i].y, 0);
        }
    }
    setTextColor(0xFF, 0xFF, 0xFF, arg0->x6C);
    w = D_800A9540 * 15 / 2;
    if (D_800BD0E0.x14 == 0) {
        D_800BD0E0.x14 = 2;
    }
    for (i = 0; i < D_800A9540; i++) {
        if (i < D_800BD0E0.x14) {
            drawImage(getImageAsset(D_800BD1E4), 160 + i * 15 - w, 20, 0);
        } else {
            drawImage(getImageAsset(D_800BD07C), 160 + i * 15 - w, 20, 0);
        }
    }
    drawImageTiles(getImageAsset(D_8013FF9C), 0x100, 0x2A, 0x30, 0x98, 0);
    for (i = 0; i < 10; i++) {
        if (D_800BD1F0[(D_800B3964->xBC - 1) * 10 + i] != 0) {
            setTextColor(0xFF, 0xFF, 0, 0xFF);
        } else {
            setTextColor(0x70, 0x70, 0x70, 0xFF);
        }
        drawImage(getImageAsset(D_800BD168[D_800A9598[i].id]), D_800A9598[i].x, D_800A9598[i].y + 0x37, 0);
    }
    c = 0xFF - (((coss((gTextWaveTime * 400) & 0xFFF0) * 127) >> 15) + 0x80) / 2;
    setTextColor(c, c, c, 0xFF);
    setTextPos(0xA0, 0xC8);
    drawCenteredMessage(0x71);
}
