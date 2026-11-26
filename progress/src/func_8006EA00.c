typedef struct Obj {
    /* 0x00 */ u8 pad0[0x64];
    /* 0x64 */ s32 f64;
    /* 0x68 */ u8 pad68[0x14];
    /* 0x7C */ s32 f7C;
    /* 0x80 */ s32 f80;
    /* 0x84 */ s32 f84;
    /* 0x88 */ u8 pad88[0x14];
    /* 0x9C */ void *f9C;
} Obj;
typedef struct Rec {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 f18[4];
    /* 0x28 */ u8 f28[40];
    /* 0x50 */ s32 f50;
    /* 0x54 */ u8 pad54[0x60];
} Rec;
s16 coss(u16);
s32 getImageAsset(s32);
void setTextColorRgb(s32, s32, s32);
void setTextColor(s32, s32, s32, s32);
void func_80027158(s32, s32);
void drawInt(s32);
void drawImage(s32, s32, s32, s32);
void drawCenteredMessage(s32);
Obj *func_8006F88C(s32, s32, s32, s32, s32);
void func_8006E994();
extern s32 D_800B82C0[];
extern s32 gTextWaveTime[];
extern s32 D_80107040[];
extern Rec gSaveSlots[];
extern s32 D_8014ADE0[];
extern s32 D_8014ADE8[];
extern s32 D_8014ADEC[];

s32 func_8006EA00(Obj *arg0) {
    s32 flags;
    s32 x;
    s32 y;
    s32 sum;
    s32 n;
    Obj *o;
    s32 buf[2];

    flags = D_800B82C0[arg0->f84];
    if (arg0->f7C != 10) {
        arg0->f7C = 10;
        o = func_8006F88C(0x95, -0x6E, 0x77, 0x22B, 0x80);
        o->f9C = func_8006E994;
        o->f64 = 0x14;
        o = func_8006F88C(0x98, 0, 0x77, 0x22B, 0x80);
        o->f9C = func_8006E994;
        o->f64 = 0x14;
        o = func_8006F88C(0x1D6, 0x6E, 0x77, 0x22B, 0x80);
        o->f7C = 1;
        o->f9C = func_8006E994;
        o->f64 = 0x14;
        D_80107040[0] = 0;
    }
    y = ((coss(gTextWaveTime[0] * 300) * 127) >> 15) + 128;
    x = 255 - y / 2;
    setTextColorRgb(x, x, x);
    func_80027158(0xA0, 0xAA);
    drawCenteredMessage(0x5F);
    if (flags & 1) {
        drawImage(getImageAsset(D_8014ADE8[0]), 0x28, 0x46, 0);
    }
    if (flags & 2) {
        drawImage(getImageAsset(D_8014ADEC[0]), 0xF6, 0x46, 0);
    }
    y = 0;
    for (x = 0; x < 4; x++) {
        y += gSaveSlots[arg0->f84].f18[x];
    }
    sum = y;
    for (y = 0, x = 0; y < 40; y++) {
        if (gSaveSlots[arg0->f84].f28[y] != 0) {
            x++;
        }
    }
    n = x;
    for (y = 0, x = 0; y < 8; y++) {
        if ((gSaveSlots[arg0->f84].f50 >> y) & 1) {
            x++;
        }
    }
    setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    drawImage(getImageAsset(D_8014ADE0[arg0->f84 + 6]), 0x80, 0xA, 0);
    func_80027158(0x64, 0x49);
    drawInt(sum);
    func_80027158(0xA0, 0x49);
    drawInt(n);
    func_80027158(0xDC, 0x49);
    drawInt(x);
    return 0;
}
