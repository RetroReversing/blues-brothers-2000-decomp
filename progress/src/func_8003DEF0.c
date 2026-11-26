extern s32 gTextWaveTime;
extern s32 D_800B5DD8;
void func_80027038(s32 a);
void func_8002E838(s32 a);
void setTextColor(s32 a, s32 b, s32 c, s32 d);
void setTextPos(s32 a, s32 b);
void drawCenteredMessage(s32 a);
s16 coss(u16 a);
void func_80027060(s32 a, s32 b, s32 c, s32 d);
s32 func_80023D58(s32 a);
void func_8001B7C4(void *a);

typedef struct {
    u8 pad[0x5C];
    s32 f5C;
    s32 f60;
    u8 pad64[0x70 - 0x64];
    s32 f70;
    u8 pad74[0x7C - 0x74];
    s32 f7C;
    u8 pad80[0x88 - 0x80];
    s32 f88;
} ObjD;

void func_8003DEF0(ObjD *arg0) {
    s32 i;
    s32 y;
    s32 c;
    s32 b;

    func_80027038(0);
    func_8002E838(arg0->f70 / 2);
    setTextColor(0xCE, 0x10, 0x25, arg0->f70);
    setTextPos(0xA0, 0x14);
    drawCenteredMessage(0x9A);
    setTextPos(0xA0, 0x28);
    b = 0xFF - (((coss((gTextWaveTime * 400) & 0xFFF0) * 127) >> 15) + 0x80) / 2;
    func_80027060(b, b, b, arg0->f70);
    setTextPos(0xA0, 0xCD);
    drawCenteredMessage(0xA2);
    for (i = 0; i < D_800B5DD8; i++) {
        setTextPos(0xA0, i * 15 + 0x3C);
        if (i == arg0->f88) {
            c = 0xFF;
        } else {
            c = 0x77;
        }
        setTextColor(c, c, c, arg0->f70);
        switch (i) {
        case 0:
            drawCenteredMessage(0xA4);
            break;
        case 1:
            drawCenteredMessage(0xA5);
            break;
        case 2:
            drawCenteredMessage(0xA6);
            break;
        case 3:
            drawCenteredMessage(0x1A);
            break;
        case 4:
            drawCenteredMessage(0x18);
            break;
        }
    }
    arg0->f7C = 0x3C;
    arg0->f60 = func_80023D58(0xD84);
    arg0->f5C = arg0->f70;
    func_8001B7C4(arg0);
}
